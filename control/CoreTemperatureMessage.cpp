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

#include "control/CoreTemperatureMessage.h"

namespace deltadoreX2d
{

CoreTemperatureMessage::CoreTemperatureMessage() : m_type(TemperatureType::INTERNAL)
{
}

CoreTemperatureMessage::CoreTemperatureMessage(const std::vector<byte>& frame) :
	CoreDomesticMessage(frame),
	m_type(frame[15] & 0xFF)
{
    if(m_type == TemperatureType::PROBE)
    {
        int value = (frame[18] & 0xFF) << 8;
        value += frame[17] & 0xFF;
        value = (int)(short)value;
        int modulus = value % 10;
        if (modulus >= 5)
        {
            m_temperature = value / 10 + 1;
        }
        else if (modulus <= -5)
        {
            m_temperature = value / 10 - 1;
        }
        else
        {
            m_temperature = value / 10;
        }
    }
    else
    {
        int value = (frame[17] & 0xFF) << 8;
        value += frame[16] & 0xFF;
        value = (int)(short)value;
        value = value * 100 / 512;
        int modulus = value % 10;
        if (modulus >= 5)
        {
            m_temperature = value / 10 + 1;
        }
        else if (modulus <= -5)
        {
            m_temperature = value / 10 - 1;
        }
        else
        {
            m_temperature = value / 10;
        }
    }
}

CoreTemperatureMessage::~CoreTemperatureMessage()
{
    //
}

Family CoreTemperatureMessage::getFamily() const
{
    return SENSOR;
}

const TemperatureType& CoreTemperatureMessage::getType() const
{
    return m_type;
}

void CoreTemperatureMessage::setType(const TemperatureType& type)
{
    m_type = type;
}

int CoreTemperatureMessage::getTemperature() const
{
    return m_temperature;
}

void CoreTemperatureMessage::setTemperature(int value)
{
    m_temperature = value;
}

void CoreTemperatureMessage::serialize(std::vector<byte>& frame) const
{
    int value;

    if(m_type == TemperatureType::PROBE)
    {
		frame.assign(19, 0);

        value = m_temperature * 10;
        frame[17] = (byte)(value & 0xFF);
        frame[18] = (byte)((value >> 8) & 0xFF);
    }
    else
    {
		frame.assign(18, 0);

        value = m_temperature * 512 / 10;
        frame[16] = (byte)(value & 0xFF);
        frame[17] = (byte)((value >> 8) & 0xFF);
    }
    frame[15] = (byte)m_type.toInt();

    CoreDomesticMessage::serialize(frame);
}

bool CoreTemperatureMessage::instanceOf(MessageClass type) const
{
	if (type == TemperatureMessage_t) { return true; }
	return false;
}

Message* CoreTemperatureMessage::clone() const
{
	return new CoreTemperatureMessage(*this);
}

void* CoreTemperatureMessage::derived()
{
	return (TemperatureMessage*)this;
}

CoreMessage* CoreTemperatureMessage::core()
{
	return this;
}
}
