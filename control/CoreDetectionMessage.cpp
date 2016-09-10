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

#include "control/CoreDetectionMessage.h"

namespace deltadoreX2d
{

CoreDetectionMessage::CoreDetectionMessage()
{
	m_messagePriority = MessagePriority::PRIORITIZED;
	m_sourceType = DetectorType::TECHNICAL_SENSOR.toInt();
}

CoreDetectionMessage::CoreDetectionMessage(const std::vector<byte>& frame) : CoreAlarmMessage(frame)
{
	m_messagePriority = MessagePriority::PRIORITIZED;
}

CoreDetectionMessage::~CoreDetectionMessage()
{
    //
}

Family CoreDetectionMessage::getFamily() const
{
    return SENSOR;
}

bool CoreDetectionMessage::isInternalFaulty() const
{
    return false;
}

void CoreDetectionMessage::setInternalFaulty(bool value)
{
    throw X2dException("Unsupported operation => Message::setInternalFaulty(bool value)");
}

void CoreDetectionMessage::setPriority(const MessagePriority& priority)
{
	if (priority == MessagePriority::IMPORTANT) { m_messagePriority = priority; }
	else if (priority == MessagePriority::PRIORITIZED) { m_messagePriority = priority; }
	else if (priority == MessagePriority::EXCLUSIVE) { m_messagePriority = priority; }
	else { CoreMessage::setPriority(priority); }
}

const DetectorType CoreDetectionMessage::getDetectorType() const
{
    return DetectorType(m_sourceType);
}

void CoreDetectionMessage::setDetectorType(const DetectorType& type)
{
	m_sourceType = type.toInt();
}

bool CoreDetectionMessage::isTriggered() const
{
    return m_isInternalFaulty;
}

void CoreDetectionMessage::setTriggered(bool value)
{
    m_isInternalFaulty = value;
}

void CoreDetectionMessage::serialize(std::vector<byte>& frame) const
{
	if (m_isTestMode)
    {
		frame.assign(16, 0);
	}
	else
	{
		frame.assign(15, 0);
    }
	if (m_messagePriority.toInt() > 1)
    {
        frame[13] = (byte)0x01;
    }

    CoreAlarmMessage::serialize(frame);
}

bool CoreDetectionMessage::instanceOf(MessageClass type) const
{
	if (type == DetectionMessage_t) { return true; }
	return false;
}

Message* CoreDetectionMessage::clone() const
{
	return new CoreDetectionMessage(*this);
}

void* CoreDetectionMessage::derived()
{
	return (DetectionMessage*)this;
}

CoreMessage* CoreDetectionMessage::core()
{
	return this;
}
}
