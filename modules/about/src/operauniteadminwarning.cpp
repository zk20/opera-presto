/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*-
**
** Copyright (C) 2009 Opera Software ASA.  All rights reserved.
**
** This file is part of the Opera web browser.  It may not be distributed
** under any circumstances.
**
*/

#include "core/pch.h"

#ifdef WEBSERVER_SUPPORT
#include "modules/about/operauniteadminwarning.h"
#include "modules/locale/locale-enum.h"
#include "modules/locale/oplanguagemanager.h"
#include "modules/util/htmlify.h"
#include "modules/prefs/prefsmanager/collections/pc_files.h"

OP_STATUS OperaUniteAdminWarningURL::GenerateData()
{
	OP_ASSERT(m_unite_url.GetAttribute(URL::KIsUniteServiceAdminURL));
	/* Determine which strings to use */
	Str::LocaleString header_id = Str::NOT_A_STRING;
	Str::LocaleString locale_id = Str::NOT_A_STRING;

	if (m_is_blocked)
	{
		header_id = Str::S_UNITE_BLOCKED_HEADER;
		locale_id = Str::S_UNITE_BLOCKED_CONTENT;
	}
	else
	{
		header_id = Str::S_UNITE_ADMIN_HEADER;
		locale_id = Str::S_UNITE_ADMIN_CONTENT;
	}

	/* Generate header */
#ifdef _LOCALHOST_SUPPORT_
	RETURN_IF_ERROR(OpenDocument(header_id, PrefsCollectionFiles::StyleMessageFile));
#else
	RETURN_IF_ERROR(OpenDocument(header_id));
#endif

	RETURN_IF_ERROR(OpenBody(header_id));

	OpString locale_str;
	RETURN_IF_ERROR(g_languageManager->GetString(locale_id, locale_str));

	if (m_is_blocked)
	{
		RETURN_IF_ERROR(m_url.WriteDocumentData(URL::KNormal, UNI_L("<p>")));
		m_url.WriteDocumentDataUniSprintf(locale_str.CStr());
		RETURN_IF_ERROR(m_url.WriteDocumentData(URL::KNormal, UNI_L("</p>\n")));
	}
	else
	{
		/* If the users selects the no option that should take us to the unite 
		   service without admin rights.
		   This is the same url with the initial "admin." in the hostname removed */
		   
		uni_char *admin_string = HTMLify_string(m_unite_url.GetAttribute(URL::KUniName_With_Fragment_Username_Password_NOT_FOR_UI).CStr());
		if (!admin_string)
			return OpStatus::ERR_NO_MEMORY;

		OP_ASSERT(uni_strncmp(admin_string, UNI_L("http://admin."), 13) == 0);

		const uni_char* admin_end = uni_strchr(admin_string, '.');
		if (admin_end)
		{
			admin_end++;  // advance past dot

			OpString non_admin_string;
			OpString8 protocol;

			RETURN_IF_ERROR(m_unite_url.GetAttribute(URL::KProtocolName, protocol));
			RETURN_IF_ERROR(non_admin_string.Set(protocol));
			RETURN_IF_ERROR(non_admin_string.Append("://"));
			RETURN_IF_ERROR(non_admin_string.Append(admin_end));

			m_url.WriteDocumentDataUniSprintf(locale_str.CStr(), admin_string, non_admin_string.CStr());
		}

		OP_DELETEA(admin_string);
	}

	// More information
	RETURN_IF_ERROR(m_url.WriteDocumentData(URL::KNormal, UNI_L("<p>")));
	OpString help_str;
	RETURN_IF_ERROR(g_languageManager->GetString(Str::S_UNITE_ADMIN_HELP, help_str));
	RETURN_IF_ERROR(m_url.WriteDocumentData(URL::KNormal, help_str.CStr()));
	RETURN_IF_ERROR(m_url.WriteDocumentData(URL::KNormal, UNI_L("</p>\n")));

	/* Say that page is generated by Opera. */
	GeneratedByOpera();

	/* Done */
	return CloseDocument();
}
#endif // WEBSERVER_SUPPORT
