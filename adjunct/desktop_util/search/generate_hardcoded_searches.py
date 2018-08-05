#!/usr/bin/env python

# Copyright (C) 1995-2011 Opera Software AS.  All rights reserved.
#
# This file is part of the Opera web browser.
# It may not be distributed under any circumstances.
#
# This script parses search.ini files from translations subdirs and generates
# C++ source file with hardcoded search engines.
#
# No arguments needed - script reads all search.ini files it can find in
# adjunct/resources/locale and adjunct/resources/region, plus
# adjunct/resources/defaults/search.ini.
# Output is written to hardcoded_searches.inl file in script's directory
# (if different than current contents of that file).
#
# Output consists of two data structures:
# 1. Single compressed search.ini configuration stored in g_hardcoded_engines
#    array. Generated search.ini string contains default and speed dial search
#    engines from all visited search.ini files, with duplicates removed.
#    Hash is generated for each search engine and they are sorted by hashes
#    in the output. Hashes are also stored in the output as 'Hash' keys.
# 2. Array of search configurations. Each search configuration specifies
#    indexes of default search engine and speed dial search engine to be used
#    in given region and/or for given language. For search configurations
#    from adjunct/resources/locale region is empty and language is always
#    set. For search configurations from adjunct/resources/region region is
#    always set, and language may be set or empty.
#    For regions/languages without custom search.ini files this script writes
#    two global constants to the output: g_global_default_search_index and
#    g_global_default_speeddial_index (they are initialized from
#    adjunct/resources/defaults/search.ini).

import os
import sys
import StringIO
import hashlib
import array
import zlib

if len(sys.argv) >= 1:
    g_scriptname = os.path.split(sys.argv[0])[1]
else:
    g_scriptname = 'generate_hardcoded_searches.py'

g_quiet = False

def info(msg):
    if not g_quiet:
        sys.stdout.write('%s: %s\n' % (g_scriptname, msg))

def warning(msg):
    sys.stdout.write('%s: warning: %s\n' % (g_scriptname, msg))

def error(msg):
    sys.stdout.write('%s: error: %s\n' % (g_scriptname, msg))
    sys.exit(1)


# recognized keys in [Search Engine x] sections
g_search_options_list = ['UNIQUEID','Name','Hash','URL','ICON','Query','Key','Verbtext',
                         'Default Tracking Code','SpeedDial Tracking Code','Is post','UseTLD',
                         'Has endseparator','Encoding','Search Type','Position','Nameid',
                         'Suggest Protocol','Suggest URL']
g_search_options_set = frozenset(g_search_options_list)


class SearchEngine:
    """
    Single search engine read from search.ini file.
    """
    def __init__(self):
        self.options = {}
        self.hash_key = 'Hash'

    def AddOption(self, name, value):
        self.options[name] = value
        if self.options.has_key(self.hash_key):
            self.options.pop(self.hash_key)

    def HasOption(self, name):
        return self.options.has_key(name)

    def GetValue(self, name):
        return self.options[name]

    def GetHash(self):
        if not self.options.has_key(self.hash_key):
            hasher = hashlib.md5()
            for name in g_search_options_list:
                if self.HasOption(name):
                    hasher.update(self.GetValue(name))
                else:
                    hasher.update("")
            self.options[self.hash_key] = hasher.hexdigest()
        return self.options[self.hash_key]


class SearchConfiguration:
    """
    Default and speed dial search configuration for given region and/or language.
    """
    def __init__(self, region, lang, default_engine_hash, speeddial_engine_hash):
        self.region = '' if region == None else region
        self.language = '' if lang == None else lang
        self.default_engine_hash = default_engine_hash
        self.speeddial_engine_hash = speeddial_engine_hash

    def GetDefaultEngineHash(self):
        return self.default_engine_hash

    def GetSpeedDialEngineHash(self):
        return self.speeddial_engine_hash

    def GetRegion(self):
        return self.region

    def GetLanguage(self):
        return self.language

    def IsGlobalConfiguration(self):
        return self.region == '' and self.language == ''


    @staticmethod
    def Compare(a, b):
        result = cmp(a.GetRegion(), b.GetRegion())
        if result == 0:
            result = cmp(a.GetLanguage(), b.GetLanguage())
        return result


class OutputGenerator:
    def __init__(self):
        self.output = StringIO.StringIO()

    def Generate(self, search_engines_list_in, search_configs_list_in):
        self.output.truncate(0)

        self.output.write('// Generated automatically by adjunct/desktop_util/search/')
        self.output.write(g_scriptname)
        self.output.write('\n// DO NOT EDIT THIS FILE MANUALLY. To update edit search.ini file(s) in adjunct/resources.\n')

        # generate INI string with definitions of Search engines

        search_engines_ini = StringIO.StringIO()

        hash_to_index_map = {} # SearchEngine hash -> index in sorted array
        search_engines_sorted = sorted(search_engines_list_in, None, lambda x: x.GetHash())
        search_configs_sorted = sorted(search_configs_list_in, SearchConfiguration.Compare)

        index = 0
        for engine in search_engines_sorted:
            self.__write_search_engine(search_engines_ini, engine, index)
            hash_to_index_map[engine.GetHash()] = index
            index += 1

        self.__write_const_size_t(self.output, 'g_hardcoded_engines_count', len(search_engines_sorted))
        self.__write_const_size_t(self.output, 'g_hardcoded_engines_uncompressed_size', search_engines_ini.len)

        # output compressed search_engines_ini
        self.output.write('\nconst unsigned char g_hardcoded_engines[] = {\n')
        self.__write_compressed(self.output, search_engines_ini.getvalue())
        self.output.write('};\n')

        global_default_engine_index = len(search_engines_sorted) # interpreted as 'does not exist'
        global_speeddial_engine_index = len(search_engines_sorted) # interpreted as 'does not exist'

        search_configs_count = len(search_configs_sorted)

        self.output.write('\nconst SearchConfiguration g_hardcoded_configurations[] = {\n')
        for i in range(len(search_configs_sorted)):
            default_index = hash_to_index_map[search_configs_sorted[i].GetDefaultEngineHash()]
            speeddial_index = hash_to_index_map[search_configs_sorted[i].GetSpeedDialEngineHash()]
            if search_configs_sorted[i].IsGlobalConfiguration():
                global_default_engine_index = default_index
                global_speeddial_engine_index = speeddial_index
                search_configs_count -= 1
            else:
                region = search_configs_sorted[i].GetRegion()
                lang = search_configs_sorted[i].GetLanguage()
                self.__write_search_configuration(self.output, region, lang, default_index, speeddial_index)
        self.output.write('};\n')

        if global_default_engine_index == len(search_engines_sorted):
            warning('no default search engine for global configuration')
        if global_speeddial_engine_index == len(search_engines_sorted):
            warning('no speed dial search engine for global configuration')

        self.__write_const_size_t(self.output, 'g_hardcoded_configurations_count', search_configs_count)           
        self.__write_const_size_t(self.output, 'g_global_default_search_index', global_default_engine_index)
        self.__write_const_size_t(self.output, 'g_global_speeddial_search_index', global_speeddial_engine_index)

        self.output.write('\n\n/* uncompressed g_hardcoded_engines:\n\n')
        self.output.write(search_engines_ini.getvalue())
        self.output.write('*/\n')


    def CompareWithFile(self, path):
        """ Returns True if contents of output and file at the path are the same, False otherwise. """
        if os.path.exists(path):
            current_size = os.path.getsize(path)
            # don't bother reading the file if it is much bigger than generated output
            # (not checking if sizes are exactly the same, because eolns may be represented differently)
            if current_size > self.output.len * 2:
                return False
            f = open(path, 'r')
            return self.output.getvalue() == f.read()
        return False

    def WriteToFile(self, path):
        try:
            f = open(path, 'w')
            f.truncate(0)
            f.write(self.output.getvalue())
        except IOError:
            error('IOError while writing to %s' % path)

    @staticmethod
    def __write_search_engine(output, engine, index):
        output.write('[Search Engine ')
        output.write(str(index))
        output.write(']\n')
        for name in g_search_options_list:
            if engine.HasOption(name):
                output.write(name)
                output.write('=')
                output.write(engine.GetValue(name))
                output.write('\n')

    @staticmethod
    def __write_search_configuration(output, region, language, default_index, speeddial_index):
        output.write('  { \"')
        output.write(region)
        output.write('\", \"')
        output.write(language)
        output.write('\", ')
        output.write(str(default_index))
        output.write(', ')
        output.write(str(speeddial_index))
        output.write('},\n')

    @staticmethod
    def __write_const_size_t(output, name, value):
        output.write('\nconst size_t ')
        output.write(name)
        output.write(' = ')
        output.write(str(value))
        output.write(';\n')

    @staticmethod
    def __write_compressed(output, string):
        compressed = zlib.compress(string, 9)
        column = 0
        for i in range(2, len(compressed)): # skip CMF and FLAGS - DecompressZlibStream assumes windowBits=-15
            if column == 0:
                output.write('  ')
            elif column == 20:
                output.write('\n  ')
                column = 0
            column += 1
            output.write(hex(ord(compressed[i])))
            output.write(', ')


class SearchIniParser:
    """
    Parser for search.ini files.
    """
    def __init__(self):
        self.search_engines = {} # hash -> SearchEngine
        self.search_configs = {} # region+language -> SearchConfiguration
        self.number_of_files = 0 # number of visited search.ini files

    def GetFilesCount(self):
        return self.number_of_files

    def GetEnginesCount(self):
        return len(self.search_engines)

    def GetSearchEngines(self):
        return self.search_engines.values()

    def GetSearchConfigurations(self):
        return self.search_configs.values()

    @staticmethod
    def __add_if_new(engines_map, new_engine):
        if new_engine == None:
            return None
        engine_hash = new_engine.GetHash()
        if not engines_map.has_key(engine_hash):
            engines_map[engine_hash] = new_engine
        return engine_hash

    def WalkLocales(self, locales_path):
        """
        Visit and parse all search.ini files in locales directory.
        """
        generator = os.walk(locales_path)
        try:
            generator.next()
        except StopIteration:
            return
        for root,dirs,names in generator:
            dirs[:] = []
            if 'search.ini' in names:
                lang = os.path.split(root)[1]
                self.ProcessSearchIni(None, lang, os.path.join(root, 'search.ini'))

    def WalkRegions(self, region_path):
        """
        Visist and parse all search.ini files in region directory.
        """
        # normalize, becuase it will be compared with result of os.path.split(root)
        region_path = os.path.normpath(region_path)
        generator = os.walk(region_path)
        try:
            generator.next()
        except StopIteration:
            return
        for root,dirs,names in generator:
            if 'search.ini' in names:
                split = os.path.split(root)
                if split[0] == region_path:
                    # first level below region_path -> only region
                    region = split[1]
                    lang = None
                else:
                    # second level below region_path -> region + language
                    region = os.path.split(split[0])[1]
                    lang = split[1]
                    dirs[:] = []
                self.ProcessSearchIni(region, lang, os.path.join(root, 'search.ini'))

    def ProcessSearchIni(self, region, lang, path):
        """
        Add default and speeddial search from search.ini file.
        """
        self.number_of_files += 1
        (default_search, speeddial_search) = SearchIniParser.__parse(path)
        default_search_hash = SearchIniParser.__add_if_new(self.search_engines, default_search)
        speeddial_search_hash = SearchIniParser.__add_if_new(self.search_engines, speeddial_search)

        region_lang = str(region) + str(lang)
        if not self.search_configs.has_key(region_lang):
            # only add SearchConfiguration if both searches were found
            if default_search_hash != None and speeddial_search_hash != None:
                search = SearchConfiguration(region, lang, default_search_hash, speeddial_search_hash)
                self.search_configs[region_lang] = search

    class FileReader:
        def __init__(self, path):
            self.lineno = 0
            relpath_start = path.find('adjunct')
            if relpath_start >= 0:
                self.name = path[relpath_start:]
            else:
                self.name = path
            try:
                self.file = open(path, 'r')
            except IOError:
                error('can\'t open %s' % self.name)

        def ReadLine(self):
            if self.file == None:
                return ''
            try:
                line = self.file.readline()
                self.lineno += 1
            except IOError:
                error('IOError while reading from %s' % self.name)
            if line == '':
                self.file.close()
                self.file = None
            return line

        def GetLineNumber(self):
            return self.lineno

        def GetName(self):
            return self.name

    @staticmethod
    def __parse(path):
        """ Parses single search.ini file. Returns tuple that describes default search (first element)
            and default speed dial search (second element). """

        reader = SearchIniParser.FileReader(path)
        line = ''
        while line != 'Opera Preferences version 2.0':
            line = reader.ReadLine()
            if line == '':
                return (None, None)
            line = line.strip()

        current_section_name = None
        current_search_engine = None # SearchEngine for current section (if search engine section)
        search_engines = {}          # maps GUIDs to SearchEngines
        default_search_guid = None
        speeddial_search_guid = None

        while True:
            line = reader.ReadLine()
            if line == '':
                break
            line = line.strip()
            if line == '' or line[0] == ';':
                continue
            if line[0] == '[' and line[-1] == ']':
                current_section_name = line[1:-1].strip()
                if current_search_engine != None: # close previous section
                    if current_search_engine.HasOption('UNIQUEID'):
                        search_engines[current_search_engine.GetValue('UNIQUEID')] = current_search_engine
                    else:
                        warning('UNIQUEID missing (%s, line %d)' % (reader.GetName(), reader.GetLineNumber() - 1))
                    current_search_engine = None
                if current_section_name.startswith('Search Engine'):
                    current_search_engine = SearchEngine()
            else:
                eq_index = line.find('=')
                if eq_index > 0:
                    name = line[:eq_index].strip()
                    if name != '':
                        value = line[eq_index+1:].strip()
                        if current_section_name == 'Options':
                            if name == 'Default Search' and value != '':
                                default_search_guid = value
                            elif name == 'Speed Dial Search' and value != '':
                                speeddial_search_guid = value
                        elif current_search_engine != None:
                            if not name in g_search_options_set:
                                warning('unknown key \'%s\' (%s, line %d)' % (name, reader.GetName(), reader.GetLineNumber()))
                            current_search_engine.AddOption(name, value)

        # close last section
        if current_search_engine != None:
            if current_search_engine.HasOption('UNIQUEID'):
                search_engines[current_search_engine.GetValue('UNIQUEID')] = current_search_engine
            else:
                warning('UNIQUEID missing (%s, line %d)' % (relpath, lineno))

        default_search = None
        speeddial_search = None
        if default_search_guid != None and search_engines.has_key(default_search_guid):
            default_search = search_engines[default_search_guid]
        if speeddial_search_guid != None and search_engines.has_key(speeddial_search_guid):
            speeddial_search = search_engines[speeddial_search_guid]
        return (default_search, speeddial_search)

if __name__ == '__main__':
    resources = os.path.normpath(os.path.join(sys.path[0], '..', '..', 'resources'));
    locale = os.path.join(resources, 'locale')
    region = os.path.join(resources, 'region')
    default_search_ini = os.path.join(resources, 'defaults', 'search.ini')

    if len(sys.argv) > 1 and sys.argv[1] == '-q':
        g_quiet = True
        sys.argv[1:2] = []

    parser = SearchIniParser()
    info('scanning %s' % locale)
    parser.WalkLocales(locale)
    info('scanning %s' % region)
    parser.WalkRegions(region)
    info('scanning %s' % default_search_ini)
    parser.ProcessSearchIni(None, None, default_search_ini)
    info('%d search engines from %d files' % (parser.GetEnginesCount(), parser.GetFilesCount()))

    if len(sys.argv) > 1:
        output_path = sys.argv[1]
        output_dir = os.path.dirname(output_path)
        if not os.path.exists(output_dir):
            os.makedirs(output_dir)
    else:
        output_path = os.path.join(sys.path[0], 'hardcoded_searches.inl')
    info('output in %s' % output_path)
    output = OutputGenerator()
    output.Generate(parser.GetSearchEngines(), parser.GetSearchConfigurations())
    if output.CompareWithFile(output_path) == False:
        output.WriteToFile(output_path)
        info('output updated\n')
    else:
        info('output not changed\n')
