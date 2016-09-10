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

#include "control/CoreScenarioCommandMessage.h"

namespace deltadoreX2d
{

CoreScenarioCommandMessage::CoreScenarioCommandMessage()
{
    //
}

CoreScenarioCommandMessage::CoreScenarioCommandMessage(const std::vector<byte>& frame) : CoreDomesticMessage(frame)
{
    //
}

CoreScenarioCommandMessage::~CoreScenarioCommandMessage()
{
    //
}

Family CoreScenarioCommandMessage::getFamily() const
{
    return REMOTE;
}

void CoreScenarioCommandMessage::serialize(std::vector<byte>& frame) const
{
	frame.assign(16, 0);

    frame[15] = (byte)0x23;

    CoreDomesticMessage::serialize(frame);
}

bool CoreScenarioCommandMessage::instanceOf(MessageClass type) const
{
	if (type == ScenarioCommandMessage_t) { return true; }
	return false;
}

Message* CoreScenarioCommandMessage::clone() const
{
	return new CoreScenarioCommandMessage(*this);
}

void* CoreScenarioCommandMessage::derived()
{
	return (ScenarioCommandMessage*)this;
}

CoreMessage* CoreScenarioCommandMessage::core()
{
	return this;
}
}
