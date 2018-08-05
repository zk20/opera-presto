/* v3_enum.c */
/* Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL
 * project 1999.
 */
/* ====================================================================
 * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    licensing@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

#ifndef OPERA_SMALL_VERSION
#include <stdio.h>
#endif /* !OPERA_SMALL_VERSION */
#include <openssl/cryptlib.h>
#include <openssl/x509v3.h>
#include "modules/libopeay/libopeay_arrays.h"

OPENSSL_PREFIX_CONST_ARRAY(static, ENUMERATED_NAMES, crl_reasons, libopeay)
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_UNSPECIFIED, "Unspecified", "unspecified")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_KEY_COMPROMISE, "Key Compromise", "keyCompromise")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_CA_COMPROMISE, "CA Compromise", "CACompromise")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_AFFILIATION_CHANGED, "Affiliation Changed", "affiliationChanged")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_SUPERSEDED, "Superseded", "superseded")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_CESSATION_OF_OPERATION, "Cessation Of Operation", "cessationOfOperation")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_CERTIFICATE_HOLD, "Certificate Hold", "certificateHold")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_REMOVE_FROM_CRL, "Remove From CRL", "removeFromCRL")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_PRIVILEGE_WITHDRAWN, "Privilege Withdrawn", "privilegeWithdrawn")
	CONST_BIT_STRING_BITNAME_ENTRY(CRL_REASON_AA_COMPROMISE,	 "AA Compromise", "AACompromise")
	CONST_BIT_STRING_BITNAME_ENTRY(-1, NULL, NULL)
CONST_END(crl_reasons)

CONST_X509V3_EXT_METHOD_item(v3_crl_reason, 
NID_crl_reason, 0, ASN1_ITEM_ref(ASN1_ENUMERATED),
0,0,0,0,
OPERA_I2S_DECLARE((X509V3_EXT_I2S)i2s_ASN1_ENUMERATED_TABLE),
0,
0,0,0,0,
OPENSSL_GLOBAL_ARRAY_NAME(crl_reasons))


#ifndef OPERA_SMALL_VERSION
char *i2s_ASN1_ENUMERATED_TABLE(X509V3_EXT_METHOD *method,
	     ASN1_ENUMERATED *e)
{
	const ENUMERATED_NAMES *enam;
	long strval;
	strval = ASN1_ENUMERATED_get(e);
	for(enam = (const ENUMERATED_NAMES *) method->usr_data; enam->lname; enam++) {
		if(strval == enam->bitnum) return BUF_strdup(enam->lname);
	}
	return i2s_ASN1_ENUMERATED(method, e);
}
#endif
