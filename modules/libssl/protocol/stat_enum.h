/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
**
** Copyright (C) 2000-2008 Opera Software AS.  All rights reserved.
**
** This file is part of the Opera web browser.  It may not be distributed
** under any circumstances.
**
** Yngve Pettersen
**
*/

#ifndef SSLSTAT_ENUM_H
#define SSLSTAT_ENUM_H

#if defined _NATIVE_SSL_SUPPORT_

enum SSL_STATE { 
	SSL_NOT_CONNECTED,
	SSL_PREHANDSHAKE,
	SSL_WAITING_FOR_SESSION,
	SSL_SENT_CLIENT_HELLO,
	SSL_NEGOTIATING,
	SSL_CONNECTED,
	SSL_PRE_CLOSE_CONNECTION,
	SSL_CLOSE_CONNECTION,
	SSL_CLOSE_CONNECTION2,
	SSL_SENT_SERVER_HELLO,
	SSL_RECONNECTING,
	SSL_ANYSTATE,
	SSL_NOSTATE,
	SSL_RETRY,
	// Error handling states
	SSL_PREHANDSHAKE_WAITING,
	SSL_SENT_CLIENT_HELLO_WAITING,
	SSL_SERVER_HELLO_WAITING,
	SSL_Wait_ForAction_Start,
	SSL_Wait_ForUI_Start,
	SSL_WAIT_CERT_2,
	SSL_WAIT_PASSWORD,
	SSL_Wait_ForUI_End,
	SSL_WAIT_DownloadStart,
	SSL_WAIT_KeyExchange,
	SSL_WAIT_DownloadEnd,
	SSL_Wait_ForAction_End,
};

enum SSL_ACTIONS {
	SSL_IGNORE,
	SSL_HANDLE_ALERT,
	SSL_HANDLE_HANDSHAKE,
	SSL_CHANGE_CIPHER,
	SSL_HANDLE_APPLICATION,
	SSL_HANDLE_APPLICATION2,
	SSL_HANDLE_V2_RECORD,
	
	SSL_START_HANDSHAKE,
	SSL_HANDLE_SERVER_HELLO,
	SSL_HANDLE_CERTIFICATE,
	SSL_HANDLE_SERVER_KEYS,
	SSL_HANDLE_CERT_REQ,
	SSL_HANDLE_HELLO_DONE,
	SSL_HANDLE_FINISHED,
	SSL_ERROR_UNEXPECTED_MESSAGE,
	
	SSL_HANDLE_INTERNAL_ERRROR,
	SSL_HANDLE_ILLEGAL_PARAMETER,
	SSL_HANDLE_CLOSE,
	SSL_HANDLE_DECOMPRESSION_FAIL,
	SSL_HANDLE_BAD_MAC,
	SSL_HANDLE_HANDSHAKE_FAIL,
	SSL_HANDLE_AS_HANDSHAKE_FAIL,
	SSL_HANDLE_BAD_CERT,
	SSL_HANDLE_NO_CLIENT_CERT,
	SSL_ERROR_UNEXPECTED_ERROR,
	
	SSL_HANDLE_CLIENT_KEYS,
	SSL_HANDLE_CERT_VERIFY,
	SSL_HANDLE_CLIENT_HELLO,
	
	SSL_HANDLE_V2_ERROR,
	SSL_HANDLE_V2_SERVER_HELLO,
	SSL_HANDLE_V2_SERVER_VERIFY,
	SSL_HANDLE_V2_CERT_REQ,
	SSL_HANDLE_V2_FINISHED
};

struct SSL_statesdescription_record{
	SSL_STATE present_state;
	SSL_ContentType recordtype; 
	SSL_ACTIONS action;
	SSL_STATE default_nextstate;
};

struct SSL_statesdescription_handshake{
	SSL_STATE present_state;
	SSL_HandShakeType recordtype; 
	SSL_ACTIONS action;
	SSL_STATE default_nextstate;
};

struct SSL_statesdescription_alert{
	SSL_STATE present_state;
	SSL_AlertDescription alerttype; 
	SSL_ACTIONS action;
	SSL_STATE fatal_nextstate;
};

#endif
#endif // SSLSTAT_H
