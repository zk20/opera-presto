#!/usr/bin/perl -w
# -*- Mode: perl; tab-width: 4; indent-tabs-mode: t; -*-
#
# File name:          entitites.pl
# Contents:           Extracts the list of HTML entitites and creates
#                     code needed for Opera.
#
# Copyright � 2006 Opera Software ASA. All rights reserved.
# This file is part of the Opera web browser.  It may not be distributed
# under any circumstances.
#
# Peter Karlsson <peter@opera.com>

require v5.6.0;

# Opera-added aliases
%aliases = (
	# Some of the most common ones are recognized also when written
	# in uppercase (street HTML).
	# IE supports seven uppercase HTML entities:
	# copy, reg, trade, quot, amp, lt and gt.
	'LT'	=> 'lt',
	'GT'	=> 'gt',
	'AMP'	=> 'amp',
	'QUOT'	=> 'quot',
	'COPY'	=> 'copy',
	'REG'	=> 'reg',		# Bug 120319
	'TRADE'	=> 'trade',		# Bug 219945
);

# Opera-added specials
%specials = (
	'apos'	=> ord("'"),	# XML specification
);

# Read entities.txt (extracted from the HTML 4.01 specification document)
my %entity;
open ENTS, '<', 'entities.txt'
	or die "Cannot read entitites.txt: $!\n";
while (<ENTS>)
{
	if (/ENTITY\s+(\S+)\s+CDATA "&#([0-9]+);"/)
	{
		$entity{$1} = $2;
	}
}

# Add aliases
foreach my $alias (keys %aliases)
{
	die "Unknown entity $aliases{$alias}"
		unless defined $entity{$aliases{$alias}};
	$entity{$alias} = $entity{$aliases{$alias}};
}

# Add specials
foreach my $new (keys %specials)
{
	$entity{$new} = $specials{$new};
}

# Spew out C++ code
open C, '>', '../data/entities.inl' or die "Cannot write entities.inl: $!";
open L, '>', '../data/entities_len.h' or die "Cannot write entities_len.h: $!";

# Order by length, find the longest
my @names = sort lengthsort keys %entity;
my $max_length = length($names[$#names]);

# Sizes
print L "#ifndef ENTITIES_LEN_H\n";
print L "#define ENTITIES_LEN_H\n\n";
print L "/** Number of supported entities. */\n";
print L "#define AMP_ESC_SIZE\t\t", $#names + 1, "\n";
print L "/** Length of the longest entity name. */\n";
print L "#define AMP_ESC_MAX_SIZE\t$max_length\n";
print L "\n";
print L "\n#endif // ENTITIES_LEN_H\n";

close L;

print C "/** \@file entities.inl\n";
print C "  * This file is auto-generated by modules/logdoc/scripts/entities.pl.\n";
print C "  * DO NOT EDIT THIS FILE MANUALLY.\n";
print C "  */\n\n";

# Size index into table
print C "/** Mapping from string length to first entry in the mapping table. */\n";
print C "static const int AMP_ESC_idx[] =\n";
print C "{\n";

my $first = 0;
for my $length (0..$max_length)
{
	while (length($names[$first]) < $length)
	{
		++ $first;
	}
	print C "\t$first,\t// start idx size $length\n";
}

print C "\t", $#names + 1, "\t// sentinel (index outside range)\n";
print C "};\n\n";

# Entity list
# FIXME: BREW
print C "/** List of entities, sorted by length and then by name. */\n";
print C "CONST_ARRAY(AMP_ESC, char*)\n";
foreach my $name (@names)
{
	print C qq'\tCONST_ENTRY("', $name, '")';
	print C ',' unless $name eq $names[$#names];
	print C "\n";
}
print C "CONST_END(AMP_ESC)\n\n";

# Entity valies
print C "/** Unicode codepoints for entities, matching the ordering of AMP_ESC. */\n";
print C "static const uni_char AMP_ESC_char[] =\n";
print C "{\n";
foreach my $name2 (@names)
{
	print C "\t", $entity{$name2};
	print C ',' unless $name2 eq $names[$#names];
	print C "\n";
}
print C "};\n\n";
close C;

# Spew out selftest code
open S, '>', '../selftest/entities.ot' or die "Cannot write entities.ot: $!";

print S "/** \@file entities.ot\n";
print S "  * This file is auto-generated by modules/logdoc/scripts/entities.pl.\n";
print S "  * DO NOT EDIT THIS FILE MANUALLY.\n";
print S "  */\n\n";

print S "group \"logdoc.logdoc_util.replaceescapes.entities\";\n";
print S "require initialization;\n";
print S "include \"modules/logdoc/logdoc_util.h\";\n\n";

# Write all entities, sorted by number
print S "table entities(const uni_char *, uni_char)\n";
print S "{\n";
foreach my $name (sort { $entity{$a} <=> $entity{$b} or $a cmp $b } @names)
{
	print S "\t{ UNI_L(\"${name}\"), $entity{$name} },\n";
}
print S "}\n\n";

# Write test code
print S "test(\"Testing standard entities\")\n";
print S "{\n";
print S "\titerate (entity, expected) from entities\n";
print S "\t{\n";
print S "\t\tuni_char buf[1024]; /* ARRAY OK 2005-06-24 peter */\n";
print S "\t\tuni_sprintf(buf, UNI_L(\"&%s;\"), entity);\n";
print S "\t\tReplaceEscapes(buf, TRUE, FALSE, FALSE);\n";
print S "\t\tverify(buf[0] == expected);\n";
print S "\t\tverify(buf[1] == 0);\n";
print S "\t}\n";
print S "}\n";
close S;

print "Done.\n";
exit 0;

sub lengthsort
{
	my $ldiff = length($a) <=> length($b);
	return $ldiff ? $ldiff : $a cmp $b;
}
