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

#include "control/CoreBasicCommandMessage.h"

namespace deltadoreX2d
{

CoreBasicCommandMessage::CoreBasicCommandMessage() : m_command(BasicCommand::TOGGLE)
{
    //
}

CoreBasicCommandMessage::CoreBasicCommandMessage(const std::vector<byte>& frame) :
	CoreDomesticMessage(frame),
	m_command(frame[16] & 0xFF)
{
    //
}

CoreBasicCommandMessage::~CoreBasicCommandMessage()
{
    //
}

Family CoreBasicCommandMessage::getFamily() const
{
    return REMOTE;
}

const BasicCommand& CoreBasicCommandMessage::getCommand() const
{
    return m_command;
}

void CoreBasicCommandMessage::setCommand(const BasicCommand& command)
{
    m_command = command;
}

void CoreBasicCommandMessage::serialize(std::vector<byte>& frame) const
{
	frame.assign(17, 0);

    frame[15] = (byte)0x21;
    frame[16] = (byte)m_command.toInt();

    CoreDomesticMessage::serialize(frame);
}

bool CoreBasicCommandMessage::instanceOf(MessageClass type) const
{
	if (type == BasicCommandMessage_t) { return true; }
	return false;
}

Message* CoreBasicCommandMessage::clone() const
{
	return new CoreBasicCommandMessage(*this);
}

void* CoreBasicCommandMessage::derived()
{
	return (BasicCommandMessage*)this;
}

CoreMessage* CoreBasicCommandMessage::core()
{
	return this;
}
}
