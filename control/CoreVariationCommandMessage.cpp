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

#include "control/CoreVariationCommandMessage.h"

namespace deltadoreX2d
{

CoreVariationCommandMessage::CoreVariationCommandMessage() : m_command(VariationCommand::STOP)
{
    //
}

CoreVariationCommandMessage::CoreVariationCommandMessage(const std::vector<byte>& frame) :
	CoreDomesticMessage(frame),
	m_command(frame[16] & 0xFF)
{
    //
}

CoreVariationCommandMessage::~CoreVariationCommandMessage()
{
    //
}

Family CoreVariationCommandMessage::getFamily() const
{
    return REMOTE;
}

const VariationCommand& CoreVariationCommandMessage::getCommand() const
{
    return m_command;
}

void CoreVariationCommandMessage::setCommand(const VariationCommand& command)
{
    m_command = command;
}

void CoreVariationCommandMessage::serialize(std::vector<byte>& frame) const
{
	frame.assign(17, 0);

    frame[15] = (byte)0x22;
    frame[16] = (byte)m_command.toInt();

    CoreDomesticMessage::serialize(frame);
}

bool CoreVariationCommandMessage::instanceOf(MessageClass type) const
{
	if (type == VariationCommandMessage_t) { return true; }
	return false;
}

Message* CoreVariationCommandMessage::clone() const
{
	return new CoreVariationCommandMessage(*this);
}

void* CoreVariationCommandMessage::derived()
{
	return (VariationCommandMessage*)this;
}

CoreMessage* CoreVariationCommandMessage::core()
{
	return this;
}
}
