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

#include "control/CoreAlarmCommandPanelMessage.h"

namespace deltadoreX2d
{

CoreAlarmCommandPanelMessage::CoreAlarmCommandPanelMessage()
{
	m_messagePriority = MessagePriority::IMPORTANT;
}

CoreAlarmCommandPanelMessage::CoreAlarmCommandPanelMessage(const std::vector<byte>& frame) : CoreAlarmMessage(frame)
{
	m_messagePriority = MessagePriority::IMPORTANT;
}

CoreAlarmCommandPanelMessage::~CoreAlarmCommandPanelMessage()
{
    //
}

Family CoreAlarmCommandPanelMessage::getFamily() const
{
    return SECURITY;
}

void CoreAlarmCommandPanelMessage::setAnswerRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setAnswerRequest(bool value)");
}

void CoreAlarmCommandPanelMessage::setPriority(const MessagePriority& priority)
{
	if (priority == MessagePriority::NORMAL) { m_messagePriority = priority; }
	else if (priority == MessagePriority::IMPORTANT) { m_messagePriority = priority; }
	else if (priority == MessagePriority::PRIORITIZED) { m_messagePriority = priority; }
	else { CoreMessage::setPriority(priority); }
}

void CoreAlarmCommandPanelMessage::serialize(std::vector<byte>& frame) const
{
    if (m_isTestMode)
    {
		frame.assign(16, 0);
    }
    else
    {
		frame.assign(15, 0);
    }

    CoreAlarmMessage::serialize(frame);
}

bool CoreAlarmCommandPanelMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmCommandPanelMessage_t) { return true; }
	return false;
}

Message* CoreAlarmCommandPanelMessage::clone() const
{
	return new CoreAlarmCommandPanelMessage(*this);
}

void* CoreAlarmCommandPanelMessage::derived()
{
	return (AlarmCommandPanelMessage*)this;
}

CoreMessage* CoreAlarmCommandPanelMessage::core()
{
	return this;
}
}
