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

#include "control/CoreAlarmEventMessage.h"

namespace deltadoreX2d
{

CoreAlarmEventMessage::CoreAlarmEventMessage() :
	m_status(AlarmStatus::QUIET),
	m_mode(AlarmFunctioningMode::MAINTENANCE_MODE),
	m_isTechnicalAlarmCurrent(false),
	m_event(AlarmEvent::NEW_PERIPHERAL),
	m_productId(0)
{
	m_messagePriority = MessagePriority::PRIORITIZED;
}

CoreAlarmEventMessage::CoreAlarmEventMessage(const std::vector<byte>& frame) :
	CoreAlarmMessage(frame),
	m_status(frame[12] & 0x03),
	m_mode((frame[12] & 0x3C) >> 2),
	m_isTechnicalAlarmCurrent((frame[12] & 0x40) == 0x40),
	m_event(frame[15] & 0x7F),
	m_productId(0)
{
	m_messagePriority = MessagePriority::PRIORITIZED;

	if (frame.size() == 27)
    {
        m_productId = (frame[20] & 0xFF) << 16;
        m_productId += (frame[19] & 0xFF) << 8;
        m_productId += frame[18] & 0xFF;
    }
}

CoreAlarmEventMessage::~CoreAlarmEventMessage()
{
    //
}

Family CoreAlarmEventMessage::getFamily() const
{
    return SECURITY;
}

bool CoreAlarmEventMessage::isEnrollmentRequest() const
{
    return false;
}

void CoreAlarmEventMessage::setEnrollmentRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setEnrollmentRequest(bool value)");
}

void CoreAlarmEventMessage::setAnswerRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setAnswerRequest(bool value)");
}

bool CoreAlarmEventMessage::isTestMode() const
{
    return false;
}

void CoreAlarmEventMessage::setTestMode(bool value)
{
    throw X2dException("Unsupported operation => Message::setTestMode(bool value)");
}

bool CoreAlarmEventMessage::isBatteryFaulty() const
{
    return false;
}

void CoreAlarmEventMessage::setBatteryFaulty(bool value)
{
    throw X2dException("Unsupported operation => Message::setBatteryFaulty(bool value)");
}

bool CoreAlarmEventMessage::isSelfProtectionFaulty() const
{
    return false;
}

void CoreAlarmEventMessage::setSelfProtectionFaulty(bool value)
{
    throw X2dException("Unsupported operation => Message::setSelfProtectionFaulty(bool value)");
}

bool CoreAlarmEventMessage::isInternalFaulty() const
{
    return false;
}

void CoreAlarmEventMessage::setInternalFaulty(bool value)
{
    throw X2dException("Unsupported operation => Message::setInternalFaulty(bool value)");
}

const AlarmStatus& CoreAlarmEventMessage::getAlarmStatus() const
{
    return m_status;
}

void CoreAlarmEventMessage::setAlarmStatus(const AlarmStatus& status)
{
    m_status = status;
}

const AlarmFunctioningMode& CoreAlarmEventMessage::getFunctioningMode() const
{
    return m_mode;
}

void CoreAlarmEventMessage::setFunctioningMode(const AlarmFunctioningMode& mode)
{
    m_mode = mode;
}

bool CoreAlarmEventMessage::isTechnicalAlarmCurrent() const
{
    return m_isTechnicalAlarmCurrent;
}

void CoreAlarmEventMessage::setTechnicalAlarmCurrent(bool value)
{
    m_isTechnicalAlarmCurrent = value;
}

const AlarmEvent& CoreAlarmEventMessage::getEvent() const
{
    return m_event;
}

void CoreAlarmEventMessage::setEvent(const AlarmEvent& event)
{
    m_event = event;
}

int CoreAlarmEventMessage::getProductId() const
{
    return m_productId;
}

void CoreAlarmEventMessage::setProductId(int id)
{
    m_productId = id;
}

void CoreAlarmEventMessage::serialize(std::vector<byte>& frame) const
{
    if (m_productId)
    {
		frame.assign(21, 0);
        frame[18] = (byte)(m_productId & 0xFF);
        frame[19] = (byte)((m_productId >> 8) & 0xFF);
        frame[20] = (byte)((m_productId >> 16) & 0xFF);
    }
    else
    {
		frame.assign(18, 0);
    }
    frame[12] = (byte)m_status.toInt();
    frame[12] |= (byte)((m_mode.toInt() << 2) & 0x3C);
    if (m_isTechnicalAlarmCurrent) { frame[12] |= (byte)0x40; }
    frame[13] = (byte)0xF1;
    frame[14] = (byte)0x08;
    frame[15] = (byte)m_event.toInt();

    CoreAlarmMessage::serialize(frame);
}

bool CoreAlarmEventMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmEventMessage_t) { return true; }
	return false;
}

Message* CoreAlarmEventMessage::clone() const
{
	return new CoreAlarmEventMessage(*this);
}

void* CoreAlarmEventMessage::derived()
{
	return (AlarmEventMessage*)this;
}

CoreMessage* CoreAlarmEventMessage::core()
{
	return this;
}
}
