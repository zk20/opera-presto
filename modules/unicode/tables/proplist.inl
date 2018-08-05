/** @file proplist.inl
 * This file is auto-generated by modules/unicode/scripts/make_proplist.py.
 * DO NOT EDIT THIS FILE MANUALLY.
 */

#ifdef USE_UNICODE_INC_DATA
enum UnicodeProperties {PROP_White_Space,PROP_Join_Control,PROP_Other_Default_Ignorable_Code_Point,PROP_Variation_Selector,PROP_NumberOfProperties};

static const UnicodePoint table_White_Space[] = {
	0x0009, 0x000e, 0x0020, 0x0021, 0x0085, 0x0086, 0x00a0, 0x00a1,
	0x1680, 0x1681, 0x180e, 0x180f, 0x2000, 0x200b, 0x2028, 0x2029,
	0x2029, 0x202a, 0x202f, 0x2030, 0x205f, 0x2060, 0x3000, 0x3001,
	0xffffff,
};

static const UnicodePoint table_Join_Control[] = {
	0x200c, 0x200e, 0xffffff,
};

static const UnicodePoint table_Other_Default_Ignorable_Code_Point[] = {
	0x034f, 0x0350, 0x115f, 0x1161, 0x17b4, 0x17b6, 0x2065, 0x206a,
	0x3164, 0x3165, 0xffa0, 0xffa1, 0xfff0, 0xfff9, 0xe0000, 0xe0001,
	0xe0002, 0xe0020, 0xe0080, 0xe0100, 0xe01f0, 0xe1000, 0xffffff,
};

static const UnicodePoint table_Variation_Selector[] = {
	0x180b, 0x180e, 0xfe00, 0xfe10, 0xe0100, 0xe01f0, 0xffffff,
};

inline BOOL FindTableForProperty(UnicodeProperties p, const UnicodePoint **table, int *size)
{
	switch (p)
	{
		case PROP_White_Space:
			*table = table_White_Space, *size = ARRAY_SIZE(table_White_Space);
			return TRUE;
		case PROP_Join_Control:
			*table = table_Join_Control, *size = ARRAY_SIZE(table_Join_Control);
			return TRUE;
		case PROP_Other_Default_Ignorable_Code_Point:
			*table = table_Other_Default_Ignorable_Code_Point, *size = ARRAY_SIZE(table_Other_Default_Ignorable_Code_Point);
			return TRUE;
		case PROP_Variation_Selector:
			*table = table_Variation_Selector, *size = ARRAY_SIZE(table_Variation_Selector);
			return TRUE;
		default:
			return FALSE;
	}
}
#endif // USE_UNICODE_INC_DATA
