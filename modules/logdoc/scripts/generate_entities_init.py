#!/usr/bin/env python

import os
import cStringIO
import time
import zipfile

# The input to this script should be a text file with entity name as first
# string (including ending semicolon if it requires it), and one or two 
# unicode numbers in the U+number format.
# Anything from the first space after the numbers will be ignored.
# It should work to just copy the table from the HTML spec into a text file and
# run the script on that textfile.
# The init_file should be moved to directory specified as OPFILE_RESOURCES_FOLDER.

entities_file = os.path.join('..', 'data', 'html5_entities.txt')
c_file = os.path.join('..', 'src', 'html5', 'html5entity_nodes_init.inl')
init_file = os.path.join('..', 'data', 'html5_entity_init.dat')
nodes = []

# Stores index of all children of all nodes.  Used for indirect reference in C++
children = []

# List with all replacement chararcters
replacement_chars = []

# Hash with all replacement characters and their index in previous list 
# (to make sure we avoid duplicate entries in list)
replacement_chars_used = {}

def set_replacement_char(repl_char):
    """Adds a new character to the replacement_characters list (unless it's
       a duplicate), and returns its index"""
    if repl_char in replacement_chars_used:
        return replacement_chars_used[repl_char]

    idx = len(replacement_chars)
    replacement_chars_used[repl_char] = idx
    replacement_chars.append(repl_char)
    return idx

class Entity:
    def __init__(self, name, uni_char):
        self.name = name
        self.uni_char = uni_char

class Node:
    def __init__(self, char):
        self.char = char
        self.uni_char_index = -1   # index into replacement characters table
        self.children = {}
        self.children_index = -1   # index where this node's children can be found in the childrens list
        self.nodeid = len(nodes)
        nodes.append(self)

    def insert(self, name, final_uni_char):
        """Inserts the name into this node by storing the first character and
           creating a child node for the rest"""
        if not name:  # reached the end of the string, store the replacement character
            self.uni_char_index = set_replacement_char(final_uni_char)
        else:
            next = name[0]
            if self.children.has_key(next):
                n = self.children[next]
            else:
                n = Node(next)
                self.children[next] = n
            n.insert(name[1:], final_uni_char)

    def __str__(self):
        chlds = [str(n.nodeid) for n in self.children.values()]
        repl_char = None
        if self.uni_char_index != -1:
            repl_char = replacement_chars[self.uni_char_index]
        return '%d %s %s %s [%s]' % (self.nodeid, self.char,  repl_char, self.children_index, ', '.join(chlds))

    def count(self):
        return 1 + sum([c.count() for c in self.children.values()])

    def write_init_line(self, f):
        nchildren = len(self.children)
        id = self.nodeid

        if nchildren > 2:
            f.write('%c %d %d %d\n' % (
                    (self.char) or '*',
                    self.uni_char_index,
                    nchildren,
                    self.children_index))
        else:
            children = self.children.values()
            child2 = child1 = 0

            if nchildren > 0:
                child1 = children[0].nodeid
            if nchildren > 1:
                child2 = children[1].nodeid

            f.write('%c %d %d %d %d\n' % (
                    (self.char) or ' ',
                    self.uni_char_index,
                    nchildren,
                    child1,
                    child2))

def read_entities_file():
    entities = []

    for line in file(entities_file):
        if not line.strip():
            continue
        tokens = line.split()
        [name,code] = tokens[:2]
        code = code.replace('U+', '0x')
        if len(tokens) > 2 and tokens[2].startswith('U+'):
            code2 = tokens[2].replace('U+', '0x')
            assert(len(name) >= 4)  # we will need space to replace at least 4 characters
        else:
            code2 = 0
        entities.append(Entity(name, (code, code2)))

    return entities

def generate_children_table():
    """Generates a table with the index of all children.  In the C++ code
       this will be used as indirect reference into the nodes table."""
    table = []
    for node in nodes:
        if len(node.children) > 2:
            node.children_index = len(table)
            table.extend(child.nodeid for child in node.children.values())

    return table


def build_tree(entities):
    root = Node(None)
    replacement_chars = {}
    for ent in entities:
        root.insert(ent.name, ent.uni_char)

    return root

def write_c_code(filename):
    f = file(filename, 'w')

    f.write("// This file is autogenerated from the generate_entities_init.py script.  Don't edit manually!\n\n")
    f.write('#define NUM_ENTITY_NODES %d\n' % len(nodes))
    f.write('#define NUM_REPLACEMENT_CHARS %d\n\n' % len(replacement_chars))

    # Children table
    f.write('static const UINT16 entity_node_children[] =\n{')
    for i in range(0, len(children), 20):
        f.write('\n\t' + ', '.join(map(str, children[i:i+20])) + ',')
    f.write('\n};\n\n')

    # The replacement characters table
    f.write('REPLACEMENT_CHAR_TABLE_START()\n')
    for repl in replacement_chars:
        f.write('REPLACEMENT_CHAR_TABLE_ENTRY(%s, %s)\n' % repl)
    f.write('REPLACEMENT_CHAR_TABLE_END()\n\n')

    f.close()

def write_init_file(filename):
    data = cStringIO.StringIO()

    data.write("# File automatically generated, don't edit!\n")
    data.write('%d\n' % len(nodes))

    for n in nodes:
        n.write_init_line(data)

    info = zipfile.ZipInfo(os.path.basename(filename))
    info.date_time = time.localtime(time.time())[:6]
    info.compress_type = zipfile.ZIP_DEFLATED

    f = zipfile.ZipFile(filename, 'w')
    f.writestr(info, data.getvalue())
    f.close()

    data.close()

entities = read_entities_file()
build_tree(entities)
children = generate_children_table()
replacement_chars
write_c_code(c_file)
write_init_file(init_file)

print 'Number of entities:', len(replacement_chars)
print 'Number of nodes:', len(nodes)
