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

#include "control/CoreDistressMessage.h"

namespace deltadoreX2d
{

CoreDistressMessage::CoreDistressMessage()
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
}

CoreDistressMessage::CoreDistressMessage(const std::vector<byte>& frame) : CoreAlarmMessage(frame)
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
}

CoreDistressMessage::~CoreDistressMessage()
{
    //
}

Family CoreDistressMessage::getFamily() const
{
    return SECURITY;
}

void CoreDistressMessage::setAnswerRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setAnswerRequest(bool value)");
}

void CoreDistressMessage::serialize(std::vector<byte>& frame) const
{
    if (m_isTestMode)
    {
		frame.assign(16, 0);
    }
    else
    {
		frame.assign(15, 0);
    }

    frame[12] = (byte)0x01;
    frame[13] = (byte)0x04;
    frame[14] = (byte)0x08;

    CoreAlarmMessage::serialize(frame);
}

bool CoreDistressMessage::instanceOf(MessageClass type) const
{
	if (type == DistressMessage_t) { return true; }
	return false;
}

Message* CoreDistressMessage::clone() const
{
	return new CoreDistressMessage(*this);
}

void* CoreDistressMessage::derived()
{
	return (DistressMessage*)this;
}

CoreMessage* CoreDistressMessage::core()
{
	return this;
}
}
