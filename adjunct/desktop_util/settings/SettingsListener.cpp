/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*-
 *
 * Copyright (C) 1995-2009 Opera Software AS.  All rights reserved.
 *
 * This file is part of the Opera web browser.
 * It may not be distributed under any circumstances.
 */

#include "core/pch.h"

#include "adjunct/desktop_util/settings/SettingsListener.h"
#include "adjunct/quick/Application.h"

SettingsListener::~SettingsListener()
{
	if (g_application)
		g_application->RemoveSettingsListener(this);
}
