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

#include "control/CoreVariationMessage.h"

namespace deltadoreX2d
{

CoreVariationMessage::CoreVariationMessage()
{
    //
}

CoreVariationMessage::CoreVariationMessage(const std::vector<byte>& frame) : CoreDomesticMessage(frame)
{
    m_value = frame[16] & 0x7F;
}

CoreVariationMessage::~CoreVariationMessage()
{
    //
}

Family CoreVariationMessage::getFamily() const
{
    return REMOTE;
}

int CoreVariationMessage::getValue() const
{
    return m_value;
}

void CoreVariationMessage::setValue(int value)
{
    m_value = value;
}

void CoreVariationMessage::serialize(std::vector<byte>& frame) const
{
	frame.assign(17, 0);

    frame[15] = (byte)0x25;
    frame[16] = (byte)(m_value & 0x7F);

    CoreDomesticMessage::serialize(frame);
}

bool CoreVariationMessage::instanceOf(MessageClass type) const
{
	if (type == VariationMessage_t) { return true; }
	return false;
}

Message* CoreVariationMessage::clone() const
{
	return new CoreVariationMessage(*this);
}

void* CoreVariationMessage::derived()
{
	return (VariationMessage*)this;
}

CoreMessage* CoreVariationMessage::core()
{
	return this;
}
}
