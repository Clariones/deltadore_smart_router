/*
** Copyright (C) 2010 Eff'Innov Technologies.  All rights reserved.
** May not be redistributed without prior written permission.
**
** Based on Java version by DeltaDore, subject to DeltaDore copyrights
**
** Note: Eff'Innov Technologies disclaims responsibility for any malfunction
** or error that may arise from any change to the current file, provided that such
** change have not been submitted to and formerly approved by Eff'Innov Technologies,
** prior to the occurence of such malfunction or error
**
** Author: Mickael Leforestier (mickael.leforestier@effinnov.com)
**
** History log:
** ------------------------------------------------------------------------------
** Author              | Date             | Changes
** ------------------------------------------------------------------------------
** mleforestier        | 092410           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreEnrollmentMessage.h"

namespace deltadoreX2d
{

CoreEnrollmentMessage::CoreEnrollmentMessage()
{
    m_isTestMode = true;
}

CoreEnrollmentMessage::CoreEnrollmentMessage(const std::vector<byte>& frame) : CoreDomesticMessage(frame)
{
    //
}

CoreEnrollmentMessage::~CoreEnrollmentMessage()
{
    //
}

Family CoreEnrollmentMessage::getFamily() const
{
    return ENROLLEMENT;
}

bool CoreEnrollmentMessage::isEnrollmentRequest() const
{
    return true;
}

void CoreEnrollmentMessage::setEnrollmentRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setEnrollmentRequest(bool value)");
}

void CoreEnrollmentMessage::serialize(std::vector<byte>& frame) const
{
	frame.assign(16, 0);

    CoreDomesticMessage::serialize(frame);
}

bool CoreEnrollmentMessage::instanceOf(MessageClass type) const
{
	if (type == EnrollmentMessage_t) { return true; }
	return false;
}

Message* CoreEnrollmentMessage::clone() const
{
	return new CoreEnrollmentMessage(*this);
}

void* CoreEnrollmentMessage::derived()
{
	return (EnrollmentMessage*)this;
}

CoreMessage* CoreEnrollmentMessage::core()
{
	return this;
}
}
