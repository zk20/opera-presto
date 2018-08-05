/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; c-file-style: "stroustrup" -*-
 *
 * Copyright (C) 1995-2011 Opera Software AS.  All rights reserved.
 *
 * This file is part of the Opera web browser.
 * It may not be distributed under any circumstances.
 */

#ifndef HTML5TREESTATE_H
#define HTML5TREESTATE_H

class HTML5TreeState
{
public:

	// These are used in LogdocModule to initialize the transition
	// table when we have no complex global support.
	static const unsigned	kNumberOfTransitionStates = 23;
	static const unsigned	kNumberOfTransitionSubStates = 6;

	enum State
	{
		IGNORE_SPACE,
		PROCESS_DOCTYPE,
		INSERT_COMMENT,
		NO_DOCTYPE,
		IGNORE_TOKEN_ERR,
		START_BEFORE_HTML,
		EARLY_END_TAG,
		IMPLICIT_HTML,
		START_BEFORE_HEAD,
		IMPLICIT_HEAD,
		WS_BEFORE_BODY,
		START_IN_HEAD,
		END_IN_HEAD,
		IMPLICIT_END_HEAD,
		START_IN_NOSCRIPT,
		END_IN_NOSCRIPT,
		WS_IN_NOSCRIPT,
		AS_IN_HEAD,
		AS_IN_HEAD_ERR,
		START_AFTER_HEAD,
		REMOVE_REOPENED_HEAD,
		END_AFTER_HEAD,
		IMPLICIT_BODY,
		TEXT_IN_BODY,
		START_IN_BODY,
		END_IN_BODY,
		EOF_IN_BODY,
		HANDLE_TEXT,
		EOF_IN_TEXT,
		END_TAG_IN_TEXT,
		START_IN_TABLE,
		END_IN_TABLE,
		TEXT_IN_TABLE,
		EOF_IN_TABLE,
		TERMINATE_TABLE,
		INSERT_TABLE_TEXT,
		START_IN_CAPTION,
		END_IN_CAPTION,
		TERMINATE_CAPTION,
		AS_IN_BODY,
		START_IN_COLGROUP,
		END_IN_COLGROUP,
		SPACE_IN_COLGROUP,
		EOF_IN_COLGROUP,
		TERMINATE_COLGROUP,
		AS_IN_TABLE,
		START_IN_TBODY,
		END_IN_TBODY,
		TERMINATE_TBODY,
		START_IN_ROW,
		END_IN_ROW,
		TERMINATE_ROW,
		START_IN_CELL,
		END_IN_CELL,
		IMPLICIT_CELL_END,
		START_IN_SELECT,
		END_IN_SELECT,
		EARLY_EOF,
		TERMINATE_SELECT,
		AS_IN_SELECT,
		START_IN_SELECT_TABLE,
		END_IN_SELECT_TABLE,
		START_IN_FOREIGN,
		END_IN_FOREIGN,
		TEXT_IN_FOREIGN,
		TERMINATE_FOREIGN,
		START_AFTER_BODY,
		END_AFTER_BODY,
		WS_AFTER_BODY,
		AFTER_BODY_ERR,
		START_IN_FRAMESET,
		END_IN_FRAMESET,
		WS_OUT_OF_BODY,
		EOF_IN_FRAMESET,
		START_AFTER_FRAMESET,
		END_AFTER_FRAMESET,
		START_AFTER_AFTER_BODY,
		AS_IN_BODY_ERR,
		START_AFTER_AFTER_FRAMSET,
		EOF_AFTER_AFTER,
		ABORT,
		STOP,
		ILLEGAL_STATE
	};
};

#endif // HTML5TREESTATE_H
