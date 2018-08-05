#! /usr/bin/python
import sys
import re
import array

# IF YOU NEED TO CHECK ANY OTHER PROPERTIES THEN LISTED BELOW - DO NOT HESTITATE TO EDIT THIS VARIABLE
# If the number of needed properties will exceed 8, you should change the type of selftest array from "B" to "H" and update the selftest accordingly.
needed_properties = ["Other_Default_Ignorable_Code_Point", "White_Space", "Variation_Selector", "Join_Control"]

def error(message):
	print >>sys.stderr, message
	sys.exit(1)

pattern = re.compile('([\d\.A-Fa-f]+)[^;]*; ([^\s]*)[^#]*# (.*)')
properties = []
values = {}

# Let the selftest support BMP, SMP and SIP only. Each number in the table describes the full set of values of all properties for given codepoint. 
# Consecutive properties defined in UnicodeProperties enum are represented by consecutive bits.
selftest_table = [0]*0x30000;

# Open and parse the input data
try:
	file = open('../data/PropList.txt', 'r')
except:
	error("Error opening PropList.txt")

for line in file.readlines():
	m = pattern.match(line)
	if not m:
		continue

	# Get range, property and comment from the parsed line
	range_s, property, comment = m.group(1,2,3)

	if not property in needed_properties:
		continue

	if not property in properties:
		values[property] = []
		properties.append(property)

	range_splited = range_s.split("..")
	start, end = (int(range_splited[0], 16), int(range_splited[-1], 16))
	
	values[property].extend([start, end+1])	
	
	if (end+1<0x30000):
		for i in range(start, end+1):
			selftest_table[i] |= 1<<properties.index(property);

for p in properties:
	values[p].append(0xffffff)

# Write the selftest data
out = open("proplist.dat", "wb")
array.array("B", selftest_table).tofile(out)
out.close()

# Write the requested table
# Write enum and tables used by Unicode::CheckPropertyValue method
print "/** @file proplist.inl"
print " * This file is auto-generated by modules/unicode/scripts/make_proplist.py."
print " * DO NOT EDIT THIS FILE MANUALLY."
print " */\n"
print "#ifdef USE_UNICODE_INC_DATA"

print "enum UnicodeProperties {" + ",".join(["PROP_" + p for p in properties + ['NumberOfProperties']]) + "};\n"

for p in properties:
	print "static const UnicodePoint table_%s[] = {" % p
	row = values[p][0:8]
	while row:
		print "\t"+", ".join(["0x%.4x" % v for v in row])+","
		values[p] = values[p][8:]
		row = values[p][0:8]
	print "};\n"

print "inline BOOL FindTableForProperty(UnicodeProperties p, const UnicodePoint **table, int *size)"
print "{"
print "\tswitch (p)"
print "\t{"
for p in properties:
	print "\t\tcase PROP_"+p+":"
	print "\t\t\t*table = table_"+p+", *size = ARRAY_SIZE(table_"+p+");"
	print "\t\t\treturn TRUE;"
print "\t\tdefault:"
print "\t\t\treturn FALSE;"
print "\t}"
print "}"

print "#endif // USE_UNICODE_INC_DATA"
