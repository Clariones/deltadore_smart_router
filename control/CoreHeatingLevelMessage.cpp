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

#include "control/CoreHeatingLevelMessage.h"

namespace deltadoreX2d
{

CoreHeatingLevelMessage::CoreHeatingLevelMessage() : m_level(HeatingSetting::COMFORT)
{
    //
}

CoreHeatingLevelMessage::CoreHeatingLevelMessage(const std::vector<byte>& frame) :
	CoreDomesticMessage(frame),
	m_level(frame[16] & 0x0F)
{
    if ((frame[16] & 0x80) == 0x80)
    {
        m_isManual = true;
    }
    if ((frame[16] & 0x40) == 0x40)
    {
        int minCount = (frame[17] & 0xFF) << 8;
        minCount += frame[18] & 0xFF;
        m_duration = minCount;
    }
}

CoreHeatingLevelMessage::~CoreHeatingLevelMessage()
{
    //
}

Family CoreHeatingLevelMessage::getFamily() const
{
    return HVAC;
}

const HeatingSetting &CoreHeatingLevelMessage::getLevel() const
{
    return m_level;
}

void CoreHeatingLevelMessage::setLevel(const HeatingSetting& level)
{
    m_level = level;
}

int CoreHeatingLevelMessage::getDuration() const
{
    return m_duration;
}

void CoreHeatingLevelMessage::setDuration(int duration)
{
    m_duration = duration;
}

bool CoreHeatingLevelMessage::isManual() const
{
    return m_isManual;
}

void CoreHeatingLevelMessage::setManual(bool value)
{
    m_isManual = value;
}

void CoreHeatingLevelMessage::serialize(std::vector<byte>& frame) const
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
    frame[16] |= (byte)m_level.toInt();
    if (m_isManual) { frame[16] |= 0x80; }

    CoreDomesticMessage::serialize(frame);
}

bool CoreHeatingLevelMessage::instanceOf(MessageClass type) const
{
	if (type == HeatingLevelMessage_t) { return true; }
	return false;
}

Message* CoreHeatingLevelMessage::clone() const
{
	return new CoreHeatingLevelMessage(*this);
}

void* CoreHeatingLevelMessage::derived()
{
	return (HeatingLevelMessage*)this;
}

CoreMessage* CoreHeatingLevelMessage::core()
{
	return this;
}
}
