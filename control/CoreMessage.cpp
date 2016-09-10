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

#include "control/CoreMessage.h"

namespace deltadoreX2d
{

CoreMessage::CoreMessage() : m_sourceAddress(0),
							m_destinationPort(128),
							m_sourceType(-1),
							m_isTestMode(false),
							m_isAnswerRequest(false),
							m_isBatteryFaulty(false),
							m_isSelfProtectionFaulty(false),
							m_isInternalFaulty(false),
							m_messagePriority(MessagePriority::NORMAL),
							m_frequency(RadioFrequency::AM)
{
	//
}

CoreMessage::CoreMessage(const std::vector<byte>& frame) : m_messagePriority(MessagePriority::NORMAL),
													m_frequency(frame[2] & 0xFF)
{
    m_destinationPort = frame[7] & 0xFF;
    m_sourceAddress = (frame[11] & 0xFF) << 16;
    m_sourceAddress += (frame[10] & 0xFF) << 8;
    m_sourceAddress += frame[9] & 0xFF;
    m_sourceType = frame[11] & 0x3F;
    m_isTestMode = (frame[13] & 0x80) == 0x80;
    m_isAnswerRequest = (frame[14] & 0x04) == 0x04;
    m_isBatteryFaulty = (frame[13] & 0x10) == 0x10;
    m_isSelfProtectionFaulty = (frame[13] & 0x20) == 0x20;
    m_isInternalFaulty = (frame[13] & 0x40) == 0x40;
}

CoreMessage::~CoreMessage()
{
    //
}

int CoreMessage::getSourceAddress() const
{
    return m_sourceAddress;
}

int CoreMessage::getDestinationPort() const
{
    return m_destinationPort;
}

int CoreMessage::getSourceType() const
{
    return m_sourceType;
}

void CoreMessage::setSourceType(int type)
{
    m_sourceType = type;
}

bool CoreMessage::isEnrollmentRequest() const
{
    return m_isTestMode;
}

void CoreMessage::setEnrollmentRequest(bool value)
{
    m_isTestMode = value;
}

bool CoreMessage::isAnswerRequest() const
{
    return m_isAnswerRequest;
}

void CoreMessage::setAnswerRequest(bool value)
{
    m_isAnswerRequest = value;
}

bool CoreMessage::isBatteryFaulty() const
{
    return m_isBatteryFaulty;
}

void CoreMessage::setBatteryFaulty(bool value)
{
    m_isBatteryFaulty = value;
}

bool CoreMessage::isSelfProtectionFaulty() const
{
    return m_isSelfProtectionFaulty;
}

void CoreMessage::setSelfProtectionFaulty(bool value)
{
    m_isSelfProtectionFaulty = value;
}

bool CoreMessage::isInternalFaulty() const
{
    return m_isInternalFaulty;
}

void CoreMessage::setInternalFaulty(bool value)
{
    m_isInternalFaulty = value;
}

const MessagePriority& CoreMessage::getPriority() const
{
	return m_messagePriority;
}

void CoreMessage::setPriority(const MessagePriority& priority)
{
	if (priority.toString().compare("SPECIAL") != 0)
	{
		throw X2dException("Unsupported operation => Message::setPriority(const MessagePriority& priority)");
	}
	m_messagePriority = priority;
}

void CoreMessage::serialize(std::vector<byte>& frame) const
{
	if (m_sourceType < 0)
	{
		throw X2dException("Unspecified source type");
	}

	frame[0] = (byte)(frame.size() + 2);

    if (m_frequency == RadioFrequency::FM)
    {
        frame[2] = 1;
    }
	if (m_messagePriority.toString().compare("SPECIAL") == 0 && m_isAnswerRequest)
	{
		frame[4] = 2;
		frame[5] = 3;
	}
	else
	{
		frame[4] = (byte)(m_messagePriority.toInt() & 0xFF);
		frame[5] = (byte)((m_messagePriority.toInt() >> 8) & 0xFF);
	}

	frame[8] = (byte)(frame.size() - 8);
    frame[11] = (byte)(m_sourceType & 0x3F);

    if(m_isTestMode) { frame[13] |= 0x80; }
    if (m_isAnswerRequest) { frame[14] |= 0x04; }
    if (m_isBatteryFaulty) { frame[13] |= 0x10; }
    if (m_isSelfProtectionFaulty) { frame[13] |= 0x20; }
    if (m_isInternalFaulty) { frame[13] |= 0x40; }
}
}
