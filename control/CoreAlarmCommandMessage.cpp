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

#include "control/CoreAlarmCommandMessage.h"

namespace deltadoreX2d
{

CoreAlarmCommandMessage::CoreAlarmCommandMessage() : m_command(AlarmCommand::FULL_ARM)
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
}

CoreAlarmCommandMessage::CoreAlarmCommandMessage(const std::vector<byte>& frame) :
	CoreAlarmMessage(frame),
	m_command(frame[12] & 0xFF)
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
}

CoreAlarmCommandMessage::~CoreAlarmCommandMessage()
{
    //
}

Family CoreAlarmCommandMessage::getFamily() const
{
    return SECURITY;
}

void CoreAlarmCommandMessage::setAnswerRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setAnswerRequest(bool value)");
}

const AlarmCommand& CoreAlarmCommandMessage::getCommand() const
{
    return m_command;
}

void CoreAlarmCommandMessage::setCommand(const AlarmCommand& command)
{
    m_command = command;
}

void CoreAlarmCommandMessage::serialize(std::vector<byte>& frame) const
{
    if (m_isTestMode)
    {
		frame.assign(16, 0);
    }
    else
    {
		frame.assign(15, 0);
    }

    frame[12] = (byte)m_command.toInt();
    frame[13] = (byte)0x01;
    frame[14] = (byte)0x08;

    if (m_command == AlarmCommand::MAINTENANCE_MODE)
    {
		frame[13] |= 0x80;
    }

	CoreAlarmMessage::serialize(frame);
}

bool CoreAlarmCommandMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmCommandMessage_t) { return true; }
	return false;
}

Message* CoreAlarmCommandMessage::clone() const
{
	return new CoreAlarmCommandMessage(*this);
}

void* CoreAlarmCommandMessage::derived()
{
	return (AlarmCommandMessage*)this;
}

CoreMessage* CoreAlarmCommandMessage::core()
{
	return this;
}
}
