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

#include "control/CoreFunctioningModeMessage.h"

namespace deltadoreX2d
{

CoreFunctioningModeMessage::CoreFunctioningModeMessage() : m_mode(HeatingSetting::AUTO)
{
    //
}

CoreFunctioningModeMessage::CoreFunctioningModeMessage(const std::vector<byte>& frame) :
	CoreDomesticMessage(frame),
	m_mode(frame[16] & 0x0F)
{
    if ((frame[16] & 0x80) == 0x80)
    {
        m_isManual = true;
    }
    if ((frame[16] & 0x40) == 0x40)
    {
        int dayCount = (frame[18] & 0xFF) << 8;
        dayCount += frame[17] & 0xFF;
        m_duration = dayCount;
    }
}

CoreFunctioningModeMessage::~CoreFunctioningModeMessage()
{
    //
}

Family CoreFunctioningModeMessage::getFamily() const
{
    return HVAC;
}

const HeatingSetting& CoreFunctioningModeMessage::getMode() const
{
    return m_mode;
}

void CoreFunctioningModeMessage::setMode(const HeatingSetting& mode)
{
    m_mode = mode;
}

int CoreFunctioningModeMessage::getDuration() const
{
    return m_duration;
}

void CoreFunctioningModeMessage::setDuration(int duration)
{
    m_duration = duration;
}

bool CoreFunctioningModeMessage::isManual() const
{
    return m_isManual;
}

void CoreFunctioningModeMessage::setManual(bool value)
{
    m_isManual = value;
}

void CoreFunctioningModeMessage::serialize(std::vector<byte>& frame) const
{
    if (m_duration == 0)
    {
		frame.assign(17, 0);
    }
    else
    {
		frame.assign(19, 0);
        frame[16] |= 0x40;
        frame[17] = (byte)(m_duration & 0xFF);
        frame[18] = (byte)((m_duration >>8) & 0xFF);
    }

    frame[15] = (byte)0x02;
    frame[16] |= (byte)m_mode.toInt();
    if (m_isManual) { frame[16] |= 0x80; }

    CoreDomesticMessage::serialize(frame);
}

bool CoreFunctioningModeMessage::instanceOf(MessageClass type) const
{
	if (type == FunctioningModeMessage_t) { return true; }
	return false;
}

Message* CoreFunctioningModeMessage::clone() const
{
	return new CoreFunctioningModeMessage(*this);
}

void* CoreFunctioningModeMessage::derived()
{
	return (FunctioningModeMessage*)this;
}

CoreMessage* CoreFunctioningModeMessage::core()
{
	return this;
}
}
