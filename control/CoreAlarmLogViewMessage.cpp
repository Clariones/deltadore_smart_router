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

#include "control/CoreAlarmLogViewMessage.h"

namespace deltadoreX2d
{

CoreAlarmLogViewMessage::CoreAlarmLogViewMessage() :
	m_logType(AlarmLogType::UNACKNOWLEDGED),
	m_eventIndex(0),
	m_event(AlarmEvent::NONE),
	m_productId(0),
	m_label(AlarmProductLabel::OTHER),
	m_labelNumber(0)
{
    //
}

CoreAlarmLogViewMessage::CoreAlarmLogViewMessage(const std::vector<byte>& frame) :
	CoreAlarmMessage(frame),
	m_logType((frame[13] >> 4) & 0x03),
	m_event(AlarmEvent::NONE),
	m_productId(0),
	m_label(AlarmProductLabel::OTHER),
	m_labelNumber(0)
{
    m_eventIndex = (frame[13] << 2) & 0x0300;
    m_eventIndex += frame[12] & 0xFF;

    if (m_isAnswerRequest)
    {
        m_destinationAddress = (frame[17] & 0xFF) << 16;
        m_destinationAddress += (frame[16] & 0xFF) << 8;
        m_destinationAddress += frame[15] & 0xFF;
		return;
    }
    if (m_sourceType < 3 && m_eventIndex == 0xFF) { return; }
	if (m_eventIndex == 0x03FF) { return; }
	if (m_logType != AlarmLogType::ENTRANCE)
	{
        int year = (frame[14] & 0x01) << 4;
        year += (frame[15] & 0xF0) >> 4;
        year += 2000;
        int month = frame[15] & 0x0F;
        int day = (frame[16] & 0xF8) >> 3;
        int hour = (frame[16] & 0x07) << 2;
        hour += (frame[17] & 0xC0) >> 6;
        int minute = frame[17] & 0x3F;

        Calendar calendar = Calendar();
        calendar.set(Calendar::YEAR, year);
        calendar.set(Calendar::MONTH, month - 1);
        calendar.set(Calendar::DAY_OF_MONTH, day);
        calendar.set(Calendar::HOUR_OF_DAY, hour);
        calendar.set(Calendar::MINUTE, minute);
        calendar.set(Calendar::SECOND, 0);
        calendar.set(Calendar::MILLISECOND, 0);
        m_eventDate = calendar.getTime();
		m_event = AlarmEvent((frame[15] & 0xFF) >> 1);
	}

    m_productId = (frame[20] & 0xFF) << 16;
    m_productId += (frame[19] & 0xFF) << 8;
    m_productId += frame[18] & 0xFF;
    m_label = AlarmProductLabel(frame[22] & 0xFF);
	m_labelNumber = ((frame[22] >> 5) & 0x07);
}

CoreAlarmLogViewMessage::~CoreAlarmLogViewMessage()
{
    //
}

Family CoreAlarmLogViewMessage::getFamily() const
{
    return SECURITY;
}

void CoreAlarmLogViewMessage::setEnrollmentRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setEnrollmentRequest(bool value)");
}

void CoreAlarmLogViewMessage::setTestMode(bool value)
{
    throw X2dException("Unsupported operation => Message::setTestMode(bool value)");
}

void CoreAlarmLogViewMessage::setDestinationAddress(int address)
{
    m_destinationAddress = address;
}

const AlarmLogType& CoreAlarmLogViewMessage::getLogType() const
{
    return m_logType;
}

void CoreAlarmLogViewMessage::setLogType(const AlarmLogType& type)
{
    m_logType = type;
}

int CoreAlarmLogViewMessage::getEventIndex() const
{
    return m_eventIndex;
}

void CoreAlarmLogViewMessage::setEventIndex(int index)
{
    m_eventIndex = index;
}

bool CoreAlarmLogViewMessage::isEndOfLog() const
{
    if (m_sourceType < 3)
    {
		return m_eventIndex == 0xFF;
	}

	return m_eventIndex == 0x03FF;
}

void CoreAlarmLogViewMessage::setEndOfLog()
{
	m_eventIndex = 0x03FF;
}

const Date& CoreAlarmLogViewMessage::getEventDate() const
{
    return m_eventDate;
}

void CoreAlarmLogViewMessage::setEventDate(const Date& date)
{
    m_eventDate = date;
}

const AlarmEvent& CoreAlarmLogViewMessage::getEventType() const
{
    return m_event;
}

void CoreAlarmLogViewMessage::setEventType(const AlarmEvent& event)
{
    m_event = event;
}

int CoreAlarmLogViewMessage::getProductId() const
{
    return m_productId;
}

void CoreAlarmLogViewMessage::setProductId(int id)
{
    m_productId = id;
}

const AlarmProductType CoreAlarmLogViewMessage::getProductType() const
{
    return AlarmProductType((m_productId >> 16) & 0x3F);
}

const AlarmProductLabel& CoreAlarmLogViewMessage::getProductLabel() const
{
    return m_label;
}

void CoreAlarmLogViewMessage::setProductLabel(const AlarmProductLabel& label)
{
    m_label = label;
}

int CoreAlarmLogViewMessage::getProductLabelNumber() const
{
    return m_labelNumber;
}

void CoreAlarmLogViewMessage::setProductLabelNumber(int number)
{
	m_labelNumber = number;
}

void CoreAlarmLogViewMessage::serialize(std::vector<byte>& frame) const
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
        frame[15] = (byte)(m_event.toInt() << 1);

        Calendar calendar = Calendar();
        calendar.setTime(m_eventDate);
        int year = calendar.get(Calendar::YEAR);
        int month = calendar.get(Calendar::MONTH) + 1;
        int day = calendar.get(Calendar::DAY_OF_MONTH);
        int hour = calendar.get(Calendar::HOUR_OF_DAY);
        int minute = calendar.get(Calendar::MINUTE);
		frame[15] |= (byte)((year >> 4) & 0x01);
		frame[16] = (byte)((year << 4) & 0xF0);
		frame[16] |= (byte)(month & 0x0F);
		frame[17] = (byte)((day << 3) & 0xF8);
		frame[17] |= (byte)((hour >> 2) & 0x07);
		frame[18] = (byte)((hour << 6) & 0xC0);
		frame[18] |= (byte)(minute & 0x3F);
			
		frame[19] = (byte)(m_productId & 0xFF);
		frame[20] = (byte)((m_productId >> 8) & 0xFF);
		frame[21] = (byte)((m_productId >> 16) & 0xFF);
		frame[22] = (byte)m_label.toInt();
		frame[22] |= (byte)(m_labelNumber << 5);
    }
	frame[12] = (byte)(m_eventIndex & 0xFF);
	frame[13] = (byte)0x06;
	frame[13] |= (byte)((m_eventIndex >> 2) & 0xC0);
	frame[13] |= (byte)(m_logType.toInt() << 4);

    CoreAlarmMessage::serialize(frame);
}

bool CoreAlarmLogViewMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmLogViewMessage_t) { return true; }
	return false;
}

Message* CoreAlarmLogViewMessage::clone() const
{
	return new CoreAlarmLogViewMessage(*this);
}

void* CoreAlarmLogViewMessage::derived()
{
	return (AlarmLogViewMessage*)this;
}

CoreMessage* CoreAlarmLogViewMessage::core()
{
	return this;
}
}
