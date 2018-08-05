/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*-
**
** Copyright (C) 1995-2006 Opera Software AS.  All rights reserved.
**
** This file is part of the Opera web browser.  It may not be distributed
** under any circumstances.
*/

#ifndef CSS_TYPES_H
#define CSS_TYPES_H

typedef OP_STATUS CSS_PARSE_STATUS;

class CSSParseStatus : public OpStatus
{
public:
	enum
	{
		SYNTAX_ERROR = USER_ERROR+1,
		HIERARCHY_ERROR = USER_ERROR+2,
		NAMESPACE_ERROR = USER_ERROR+3
	};
};

enum CSSPseudoClassType
{
	CSS_PSEUDO_CLASS_UNKNOWN		= 0x0000,
	CSS_PSEUDO_CLASS_LINK			= 0x0001,
	CSS_PSEUDO_CLASS_VISITED		= 0x0002,
	CSS_PSEUDO_CLASS_ACTIVE			= 0x0004,
	CSS_PSEUDO_CLASS_HOVER			= 0x0008,
	CSS_PSEUDO_CLASS_FIRST_LINE		= 0x0010,
	CSS_PSEUDO_CLASS_FIRST_LETTER	= 0x0020,
	CSS_PSEUDO_CLASS_AFTER			= 0x0040,
	CSS_PSEUDO_CLASS_BEFORE			= 0x0080,
	CSS_PSEUDO_CLASS_FOCUS			= 0x0100,
	CSS_PSEUDO_CLASS__O_PREFOCUS	= 0x0200,
	CSS_PSEUDO_CLASS_SELECTION		= 0x0400,
	CSS_PSEUDO_CLASS_DEFAULT		= 0x0001000,
	CSS_PSEUDO_CLASS_INVALID		= 0x0002000,
	CSS_PSEUDO_CLASS_VALID			= 0x0004000,
	CSS_PSEUDO_CLASS_IN_RANGE		= 0x0008000,
	CSS_PSEUDO_CLASS_OUT_OF_RANGE	= 0x0010000,
	CSS_PSEUDO_CLASS_REQUIRED		= 0x0020000,
	CSS_PSEUDO_CLASS_OPTIONAL		= 0x0040000,
	CSS_PSEUDO_CLASS_READ_ONLY		= 0x0080000,
	CSS_PSEUDO_CLASS_READ_WRITE		= 0x0100000,
	// These below are in the CSS3 selector specification but we group
	// them with the other anyway.
	CSS_PSEUDO_CLASS_ENABLED		= 0x0200000,
	CSS_PSEUDO_CLASS_DISABLED		= 0x0400000,
	CSS_PSEUDO_CLASS_CHECKED		= 0x0800000,
	CSS_PSEUDO_CLASS_INDETERMINATE	= 0x1000000,
	CSS_PSEUDO_CLASS_PAST			= 0x2000000,
	CSS_PSEUDO_CLASS_FUTURE			= 0x4000000
};

#define IsPseudoElement(p) (p == PSEUDO_CLASS_FIRST_LINE || p == PSEUDO_CLASS_FIRST_LETTER || p == PSEUDO_CLASS_AFTER || p == PSEUDO_CLASS_BEFORE || p == PSEUDO_CLASS_SELECTION || p == PSEUDO_CLASS_CUE)

#define CSS_PSEUDO_CLASS_GROUP_ELEMENTS (CSS_PSEUDO_CLASS_FIRST_LINE | CSS_PSEUDO_CLASS_FIRST_LETTER | CSS_PSEUDO_CLASS_AFTER | CSS_PSEUDO_CLASS_BEFORE | CSS_PSEUDO_CLASS_SELECTION)
#define CSS_PSEUDO_CLASS_GROUP_MOUSE (CSS_PSEUDO_CLASS_ACTIVE | CSS_PSEUDO_CLASS_HOVER | CSS_PSEUDO_CLASS_FOCUS)
#define CSS_PSEUDO_CLASS_GROUP_FORM (CSS_PSEUDO_CLASS_DEFAULT | CSS_PSEUDO_CLASS_INVALID | CSS_PSEUDO_CLASS_VALID | CSS_PSEUDO_CLASS_IN_RANGE | CSS_PSEUDO_CLASS_OUT_OF_RANGE | CSS_PSEUDO_CLASS_REQUIRED | CSS_PSEUDO_CLASS_OPTIONAL | CSS_PSEUDO_CLASS_READ_ONLY | CSS_PSEUDO_CLASS_READ_WRITE | CSS_PSEUDO_CLASS_ENABLED | CSS_PSEUDO_CLASS_DISABLED | CSS_PSEUDO_CLASS_CHECKED)
#define CSS_PSEUDO_CLASS_GROUP_BEFORE_AFTER (CSS_PSEUDO_CLASS_BEFORE | CSS_PSEUDO_CLASS_AFTER)

#ifdef MEDIA_HTML_SUPPORT
# define CSS_PSEUDO_CLASS_GROUP_CUE_TIMING (CSS_PSEUDO_CLASS_PAST | CSS_PSEUDO_CLASS_FUTURE)
#endif // MEDIA_HTML_SUPPORT

#define CSS_PSEUDO_NEEDS_CONTENT(x) ((x & CSS_PSEUDO_CLASS_GROUP_BEFORE_AFTER) != 0)

/** Constants controlling the behaviour of CSS::FormatDeclaration(). See that function for details. */
enum CSS_SerializationFormat
{
	CSS_FORMAT_CSSOM_STYLE,
	CSS_FORMAT_COMPUTED_STYLE,
	CSS_FORMAT_CURRENT_STYLE
};


// these constants are used for reverse mapping colors to keywords
// the 5 most significant bits cannot be used because they are used
// in the BgColor-construct in htm_css.h. Furthermore the next 3 bits
// are used for special color values if they are not 0x1. If they are
enum CSSColorKeyword
{
	CSS_COLOR_KEYWORD_TYPE_index	= 0x007fffff,
	CSS_COLOR_KEYWORD_TYPE_named	= 0x80000000,
	CSS_COLOR_KEYWORD_TYPE_x_color	= 0x80000000,
	CSS_COLOR_KEYWORD_TYPE_ui_color	= 0xc0000000,
	CSS_COLOR_current_color			= 0x81000000,
	CSS_COLOR_inherit				= 0x82000000,
	CSS_COLOR_transparent			= 0x83000000,
	CSS_COLOR_invert				= 0x84000000
};

#define COLOR_is_indexed(v) ((COLORREF) v & 0x80000000 && !(v & 0x0f000000))
#define COLOR_is_rgba(v) (!(COLORREF(v) & 0x80000000))
#define COLOR_is_non_color_keyword(v) ((COLORREF) v & 0x80000000 && v & 0x0f000000)

#define CSS_GENERIC_FONT_FAMILY			0x8000 // flag to indicate that a font family is generic
#define CSS_GENERIC_FONT_FAMILY_mask	0x7fff

// *** MOVE ALL BELOW TO LAYOUT MODULE ***
enum
{
	FONT_STYLE_INHERIT	= 0,
	FONT_STYLE_NORMAL	= 1,
	FONT_STYLE_ITALIC	= 2,
	FONT_STYLE_OBLIQUE	= 3
};

enum
{
	TEXT_DECORATION_NONE		= 0x00,
	TEXT_DECORATION_UNDERLINE	= 0x01,
	TEXT_DECORATION_LINETHROUGH	= 0x02,
	TEXT_DECORATION_OVERLINE	= 0x04,
	TEXT_DECORATION_BLINK		= 0x08
};

// THIS ENUM SHOULD BE MOVED TO cssprop_storage.h!
enum
{
	CSS_TEXT_DECORATION_none          = 0x0000,
	CSS_TEXT_DECORATION_underline     = 0x0010,
	CSS_TEXT_DECORATION_overline      = 0x0020,
	CSS_TEXT_DECORATION_line_through  = 0x0040,
	CSS_TEXT_DECORATION_blink         = 0x0080
};

/** In CSS we use a fixed ratio between CSS pixels and CSS inches.
	Note that a CSS inch does not necessarily have the same length as a physical inch. */
#define CSS_PX_PER_INCH 96

#endif // CSS_TYPES_H
