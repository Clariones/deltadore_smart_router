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

#include "control/CoreAlarmCentralUnitMessage.h"

namespace deltadoreX2d
{

CoreAlarmCentralUnitMessage::CoreAlarmCentralUnitMessage() :
	m_status(AlarmStatus::QUIET),
	m_mode(AlarmFunctioningMode::MAINTENANCE_MODE),
	m_isTechnicalAlarmCurrent(false),
	m_isIntrusionEventCurrent(false),
	m_isSelfProtectionEventCurrent(false),
	m_isBatteryEventCurrent(false),
	m_isOpenEntranceEventCurrent(false),
	m_isPowerOutageEventCurrent(false),
	m_isTechnicalEventCurrent(false),
	m_partialCount(1),
	m_centralUnitType(AlarmCentralUnitType::DIY),
	m_temperature(-400)
{
	m_messagePriority = MessagePriority::IMPORTANT;
}

CoreAlarmCentralUnitMessage::CoreAlarmCentralUnitMessage(const std::vector<byte>& frame) :
	CoreAlarmMessage(frame),
	m_status(AlarmStatus::QUIET),
	m_mode(AlarmFunctioningMode::MAINTENANCE_MODE),
	m_isTechnicalAlarmCurrent(false),
	m_isIntrusionEventCurrent(false),
	m_isSelfProtectionEventCurrent(false),
	m_isBatteryEventCurrent(false),
	m_isOpenEntranceEventCurrent(false),
	m_isPowerOutageEventCurrent(false),
	m_isTechnicalEventCurrent(false),
	m_partialCount(1),
	m_centralUnitType(AlarmCentralUnitType::DIY)
{
	m_messagePriority = MessagePriority::IMPORTANT;

    if (m_isAnswerRequest)
    {
        m_destinationAddress = (frame[17] & 0xFF) << 16;
        m_destinationAddress += (frame[16] & 0xFF) << 8;
        m_destinationAddress += frame[15] & 0xFF;
    }
    else
    {
        m_status = AlarmStatus(frame[12] & 0x03);
        m_mode = AlarmFunctioningMode((frame[12] & 0x3C) >> 2);
        m_isTechnicalEventCurrent = (frame[12] & 0x40) == 0x40;
        m_isIntrusionEventCurrent = (frame[16] & 0x01) == 0x01;
        m_isSelfProtectionEventCurrent = (frame[16] & 0x02) == 0x02;
        m_isBatteryEventCurrent = (frame[16] & 0x04) == 0x04;
        m_isMonitoringEventCurrent = (frame[16] & 0x08) == 0x08;
        m_isOpenEntranceEventCurrent = (frame[16] & 0x10) == 0x10;
        m_isPowerOutageEventCurrent = (frame[16] & 0x40) == 0x40;
        m_isTechnicalEventCurrent = (frame[16] & 0x80) == 0x80;
        m_partialCount = (frame[17] & 0x07) +1;
		m_centralUnitType = (frame[17] & 0x08) == 0x08 ? AlarmCentralUnitType::DIY : AlarmCentralUnitType::PRO;
        m_temperature = (frame[18] & 0xFF) * 1000 / 255 - 400;
    }
}

CoreAlarmCentralUnitMessage::~CoreAlarmCentralUnitMessage()
{
    //
}

Family CoreAlarmCentralUnitMessage::getFamily() const
{
    return SECURITY;
}

void CoreAlarmCentralUnitMessage::setDestinationAddress(int address)
{
    m_destinationAddress = address;
}

void CoreAlarmCentralUnitMessage::setPriority(const MessagePriority& priority)
{
	if (priority == MessagePriority::NORMAL) { m_messagePriority = priority; }
	else if (priority == MessagePriority::IMPORTANT) { m_messagePriority = priority; }
	else if (priority == MessagePriority::EXCLUSIVE) { m_messagePriority = priority; }
	else { CoreMessage::setPriority(priority); }
}

const AlarmStatus& CoreAlarmCentralUnitMessage::getAlarmStatus() const
{
    return m_status;
}

void CoreAlarmCentralUnitMessage::setAlarmStatus(const AlarmStatus& status)
{
    m_status = status;
}

const AlarmFunctioningMode& CoreAlarmCentralUnitMessage::getFunctioningMode() const
{
    return m_mode;
}

void CoreAlarmCentralUnitMessage::setFunctioningMode(const AlarmFunctioningMode& mode)
{
    m_mode = mode;
}

bool CoreAlarmCentralUnitMessage::isTechnicalAlarmCurrent() const
{
    return m_isTechnicalAlarmCurrent;
}

void CoreAlarmCentralUnitMessage::setTechnicalAlarmCurrent(bool value)
{
    m_isTechnicalAlarmCurrent = value;
}

bool CoreAlarmCentralUnitMessage::isIntrusionEventCurrent() const
{
    return m_isIntrusionEventCurrent;
}

void CoreAlarmCentralUnitMessage::setIntrusionEventCurrent(bool value)
{
    m_isIntrusionEventCurrent = value;
}

bool CoreAlarmCentralUnitMessage::isSelfProtectionEventCurrent() const
{
    return m_isSelfProtectionEventCurrent;
}

void CoreAlarmCentralUnitMessage::setSelfProtectionEventCurrent(bool value)
{
    m_isSelfProtectionEventCurrent = value;
}

bool CoreAlarmCentralUnitMessage::isBatteryEventCurrent() const
{
    return m_isBatteryEventCurrent;
}

void CoreAlarmCentralUnitMessage::setBatteryEventCurrent(bool value)
{
    m_isBatteryEventCurrent = value;
}

bool CoreAlarmCentralUnitMessage::isMonitoringEventCurrent() const
{
    return m_isMonitoringEventCurrent;
}

void CoreAlarmCentralUnitMessage::setMonitoringEventCurrent(bool value)
{
    m_isMonitoringEventCurrent = value;
}

bool CoreAlarmCentralUnitMessage::isOpenEntranceEventCurrent() const
{
    return m_isOpenEntranceEventCurrent;
}

void CoreAlarmCentralUnitMessage::setOpenEntranceEventCurrent(bool value)
{
    m_isOpenEntranceEventCurrent = value;
}

bool CoreAlarmCentralUnitMessage::isPowerOutageEventCurrent() const
{
    return m_isPowerOutageEventCurrent;
}

void CoreAlarmCentralUnitMessage::setPowerOutageEventCurrent(bool value)
{
    m_isPowerOutageEventCurrent = value;
}

bool CoreAlarmCentralUnitMessage::isTechnicalEventCurrent() const
{
    return m_isTechnicalEventCurrent;
}

void CoreAlarmCentralUnitMessage::setTechnicalEventCurrent(bool value)
{
    m_isTechnicalEventCurrent = value;
}

const AlarmCentralUnitType& CoreAlarmCentralUnitMessage::getCentralUnitType() const
{
	return m_centralUnitType;
}

void CoreAlarmCentralUnitMessage::setCentralUnitType(const AlarmCentralUnitType& type)
{
	m_centralUnitType = type;
}

int CoreAlarmCentralUnitMessage::getPartialCount() const
{
	return m_partialCount;
}

void CoreAlarmCentralUnitMessage::setPartialCount(int count)
{
	m_partialCount = count;
}

int CoreAlarmCentralUnitMessage::getTemperature() const
{
    return m_temperature;
}

void CoreAlarmCentralUnitMessage::setTemperature(int value)
{
    m_temperature = value;
}

void CoreAlarmCentralUnitMessage::serialize(std::vector<byte>& frame) const
{
    if (m_isAnswerRequest)
    {
		frame.assign(18, 0);
        frame[15] = (byte)(m_destinationAddress & 0xFF);
        frame[16] = (byte)((m_destinationAddress >> 8) & 0xFF);
        frame[17] = (byte)((m_destinationAddress >> 16) & 0xFF);
    }
    else
    {
		frame.assign(23, 0);
        frame[12] = (byte)m_status.toInt();
        frame[12] |= (byte)((m_mode.toInt() << 2) & 0x3C);
        if (m_isTechnicalAlarmCurrent) { frame[12] |= (byte)0x40; }
        if (m_isTechnicalEventCurrent) { frame[16] |= (byte)0x80; }
        if (m_isIntrusionEventCurrent) { frame[16] |= 0x01; }
        if (m_isSelfProtectionEventCurrent) { frame[16] |= 0x02; }
        if (m_isBatteryEventCurrent) { frame[16] |= 0x04; }
        if (m_isMonitoringEventCurrent) { frame[16] |= 0x08; }
        if (m_isOpenEntranceEventCurrent) { frame[16] |= 0x10; }
        if (m_isPowerOutageEventCurrent) { frame[16] |= 0x40; }
        frame[17] = (byte)(m_partialCount +1);
		if (m_centralUnitType == AlarmCentralUnitType::DIY) { frame[17] |= 0x08; }

        int value = (m_temperature + 400) * 255 / 100;
        int modulus = value % 10;
        if (modulus >= 5)
        {
            frame[18] = (byte)(value / 10 + 1);
        }
        else
        {
            frame[18] = (byte)(value / 10);
        }
    }

    CoreAlarmMessage::serialize(frame);
}

bool CoreAlarmCentralUnitMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmCentralUnitMessage_t) { return true; }
	return false;
}

Message* CoreAlarmCentralUnitMessage::clone() const
{
	return new CoreAlarmCentralUnitMessage(*this);
}

void* CoreAlarmCentralUnitMessage::derived()
{
	return (AlarmCentralUnitMessage*)this;
}

CoreMessage* CoreAlarmCentralUnitMessage::core()
{
	return this;
}
}
