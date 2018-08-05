/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*-
**
** Copyright (C) 1995-2012 Opera Software AS.  All rights reserved.
**
** This file is part of the Opera web browser.  It may not be distributed
** under any circumstances.
*/

// Please don't modify this file.

// This file is automatically generated by modules/libopeay/create_wrappers.py

#include "core/pch.h"
#include "modules/libopeay/core_includes.h"

#if defined(_SSL_USE_OPENSSL_) || defined(USE_OPENSSL_CERTIFICATE_VERIFICATION) || defined(EXTERNAL_SSL_OPENSSL_IMPLEMENTATION)
# if !defined(_USE_SYSTEM_LIBCRYPTO_)
extern "C" {
#include "modules/libopeay/openssl/cryptlib.h"
#include "modules/libopeay/crypto/asn1/a_strnid.c"
}
# endif // !_USE_SYSTEM_LIBCRYPTO_
#endif // _SSL_USE_OPENSSL_ || defined(USE_OPENSSL_CERTIFICATE_VERIFICATION) || defined(EXTERNAL_SSL_OPENSSL_IMPLEMENTATION)
