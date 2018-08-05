/* -*- Mode: c++; tab-width: 4; c-basic-offset: 4 -*-
 *
 * Copyright (C) 1995-2010 Opera Software AS.  All rights reserved.
 *
 * This file is part of the Opera web browser.
 * It may not be distributed under any circumstances.
 *
 * @author Arjan van Leeuwen (arjanl)
 */

#ifndef MAILTO_H
#define MAILTO_H

/** @brief Generate and parse mailto: URLs as defined in RFC 2368
  */
class MailTo
{
public:
	/** Initialize object using a mailto: raw string
	 * @param url const char * mailto string
	 */
	OP_STATUS Init(const char * url);

	/** Initialize object specifying several attributes
	  * @param to To header for mail generated by mailto
	  * @param cc Cc header for mail generated by mailto
	  * @param bcc Bcc header for mail generated by mailto
	  * @param subject Subject header for mail generated by mailto
	  * @param body Body for mail generated by mailto
	  */
	OP_STATUS Init(const OpStringC& to, const OpStringC& cc, const OpStringC& bcc, const OpStringC& subject, const OpStringC& body);

	/** Getters: get data values for this mailto
	  * @return requested value
	  */
	const OpStringC8& GetRawMailTo() const { return m_raw_mailto; }

	// decoded values:
	const OpStringC& GetTo() const					{ return m_values[MAILTO_TO]; }
	const OpStringC& GetCc() const					{ return m_values[MAILTO_CC]; }
	const OpStringC& GetBcc() const					{ return m_values[MAILTO_BCC]; }
	const OpStringC& GetSubject() const				{ return m_values[MAILTO_SUBJECT]; }
	const OpStringC& GetBody() const				{ return m_values[MAILTO_BODY]; }

	// encoded values:
	OP_STATUS GetEncodedTo(OpString8& enc_v) const			{ RETURN_IF_ERROR(EncodeValue(m_values[MAILTO_TO],enc_v)); return OpStatus::OK;}
	OP_STATUS GetEncodedCc(OpString8& enc_v) const			{ RETURN_IF_ERROR(EncodeValue(m_values[MAILTO_CC],enc_v)); return OpStatus::OK;}
	OP_STATUS GetEncodedBcc(OpString8& enc_v) const		{ RETURN_IF_ERROR(EncodeValue(m_values[MAILTO_BCC],enc_v)); return OpStatus::OK;}
	OP_STATUS GetEncodedSubject(OpString8& enc_v) const	{ RETURN_IF_ERROR(EncodeValue(m_values[MAILTO_SUBJECT],enc_v)); return OpStatus::OK;}
	OP_STATUS GetEncodedBody(OpString8& enc_v) const		{ RETURN_IF_ERROR(EncodeValue(m_values[MAILTO_BODY],enc_v)); return OpStatus::OK;}

private:
	OP_STATUS RawToAttributes();
	OP_STATUS AttributesToRaw();
	OP_STATUS EncodeValue(const OpStringC& value, OpString8& encoded) const;
	OP_STATUS DecodeValue(const char* value, const char* value_end, OpString& decoded) const;

	enum Attribute
	{
		MAILTO_TO,
		MAILTO_CC,
		MAILTO_BCC,
		MAILTO_SUBJECT,
		MAILTO_BODY,
		MAILTO_ATTR_COUNT // don't remove, should be last
	};

	OpString	m_values[MAILTO_ATTR_COUNT];
	OpString8	m_raw_mailto;
};

#endif // MAILTO_H
