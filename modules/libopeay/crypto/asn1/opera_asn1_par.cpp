/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*-
**
** Copyright (C) 1995-2007 Opera Software AS.  All rights reserved.
**
** This file is part of the Opera web browser.  It may not be distributed
** under any circumstances.
*/

#include "core/pch.h"

#ifdef _SSL_USE_OPENSSL_
extern "C" {
#include "modules/libopeay/openssl/cryptlib.h"
#include "modules/libopeay/crypto/asn1/asn1_par.c"
}
#endif // _SSL_USE_OPENSSL_
