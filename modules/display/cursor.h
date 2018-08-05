/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*-
**
** Copyright (C) 1995-2007 Opera Software AS.  All rights reserved.
**
** This file is part of the Opera web browser.  It may not be distributed
** under any circumstances.
*/

#ifndef OPERA_CURSOR_H	// {
#define OPERA_CURSOR_H

enum CursorType
{
	CURSOR_URI,
	CURSOR_CROSSHAIR,
	CURSOR_DEFAULT_ARROW,
	CURSOR_CUR_POINTER,
	CURSOR_MOVE,
	CURSOR_E_RESIZE,
	CURSOR_NE_RESIZE,
	CURSOR_NW_RESIZE,
	CURSOR_N_RESIZE,
	CURSOR_SE_RESIZE,
	CURSOR_SW_RESIZE,
	CURSOR_S_RESIZE,
	CURSOR_W_RESIZE,
	CURSOR_TEXT,
	CURSOR_WAIT,
	CURSOR_HELP,
	CURSOR_HOR_SPLITTER,
	CURSOR_VERT_SPLITTER,
	CURSOR_ARROW_WAIT,
	CURSOR_PROGRESS,
	CURSOR_AUTO,				// Used by layout engine only!
	CURSOR_MAGNIFYING_GLASS,	// For use in overview mode
	CURSOR_ZOOM_IN,				// Used in the image viewer
	CURSOR_ZOOM_OUT,			// Used in the image viewer
	CURSOR_CONTEXT_MENU,
	CURSOR_CELL,
	CURSOR_VERTICAL_TEXT,
	CURSOR_ALIAS,
	CURSOR_COPY,
	CURSOR_NO_DROP,
	CURSOR_DROP_COPY,
	CURSOR_DROP_MOVE,
	CURSOR_DROP_LINK,
	CURSOR_NOT_ALLOWED,
	CURSOR_EW_RESIZE,
	CURSOR_NS_RESIZE,
	CURSOR_NESW_RESIZE,
	CURSOR_NWSE_RESIZE,
	CURSOR_COL_RESIZE,
	CURSOR_ROW_RESIZE,
	CURSOR_ALL_SCROLL,
	CURSOR_NONE,

	CURSOR_NUM_CURSORS			// added 26/7-00 <JB>
};

#endif		// } OPERA_CURSOR_H
