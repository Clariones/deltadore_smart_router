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

#include "control/CoreSirenMessage.h"
#include "security/AlarmProductType.h"

namespace deltadoreX2d
{

CoreSirenMessage::CoreSirenMessage()
{
	m_messagePriority = MessagePriority::PRIORITIZED;
    m_temperature = -400;
}

CoreSirenMessage::CoreSirenMessage(const std::vector<byte>& frame) : CoreAlarmMessage(frame)
{
	m_messagePriority = MessagePriority::PRIORITIZED;

    if (m_isAnswerRequest)
    {
        m_destinationAddress = (frame[17] & 0xFF) << 16;
        m_destinationAddress += (frame[16] & 0xFF) << 8;
        m_destinationAddress += frame[15] & 0xFF;
        m_temperature = -400;
    }
    else
    {
        m_temperature = (frame[15] & 0xFF) * 1000 / 255 - 400;
    }
}

CoreSirenMessage::~CoreSirenMessage()
{
    //
}

Family CoreSirenMessage::getFamily() const
{
    return SECURITY;
}

void CoreSirenMessage::setDestinationAddress(int address)
{
    m_destinationAddress = address;
}

void CoreSirenMessage::setPriority(const MessagePriority& priority)
{
	m_messagePriority = priority;
}

int CoreSirenMessage::getTemperature() const
{
    return m_temperature;
}

void CoreSirenMessage::setTemperature(int value)
{
    m_temperature = value;
}

void CoreSirenMessage::serialize(std::vector<byte>& frame) const
{
    if (m_isAnswerRequest)
    {
		frame.assign(18, 0);
        frame[15] = (byte)(CoreAlarmMessage::m_destinationAddress & 0xFF);
        frame[16] = (byte)((CoreAlarmMessage::m_destinationAddress >> 8) & 0xFF);
        frame[17] = (byte)((CoreAlarmMessage::m_destinationAddress >> 16) & 0xFF);
    }
    else
    {
        if (m_isTestMode)
        {
			frame.assign(17, 0);
        }
        else
        {
			frame.assign(16, 0);
        }

        int value = (m_temperature + 400) * 255 / 100;
        int modulus = value % 10;
        if (modulus >= 5)
        {
            frame[15] = (byte)(value / 10 + 1);
        }
        else
        {
            frame[15] = (byte)(value / 10);
        }
    }

    CoreAlarmMessage::serialize(frame);
}

bool CoreSirenMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmCentralUnitMessage_t) { return true; }
	return false;
}

Message* CoreSirenMessage::clone() const
{
	return new CoreSirenMessage(*this);
}

void* CoreSirenMessage::derived()
{
	return (SirenMessage*)this;
}

CoreMessage* CoreSirenMessage::core()
{
	return this;
}
}
