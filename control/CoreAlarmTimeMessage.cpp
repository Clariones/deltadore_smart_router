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
** mleforestier        | 041311           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreAlarmTimeMessage.h"

namespace deltadoreX2d
{

CoreAlarmTimeMessage::CoreAlarmTimeMessage()
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
}

CoreAlarmTimeMessage::CoreAlarmTimeMessage(const std::vector<byte>& frame) : CoreAlarmMessage(frame)
{
	m_messagePriority = MessagePriority::EXCLUSIVE;

	int year = (frame[15] & 0x01) << 4;
	year += (frame[16] & 0xF0) >> 4;
	year += 2000;
	int month = frame[16] & 0x0F;
	int day = (frame[17] & 0xF8) >> 3;
	int hour = (frame[17] & 0x07) << 2;
	hour += (frame[18] & 0xC0) >> 6;
	int minute = frame[18] & 0x3F;

	Calendar calendar = Calendar();
	calendar.set(Calendar::YEAR, year);
	calendar.set(Calendar::MONTH, month - 1);
	calendar.set(Calendar::DAY_OF_MONTH, day);
	calendar.set(Calendar::HOUR_OF_DAY, hour);
	calendar.set(Calendar::MINUTE, minute);
	calendar.set(Calendar::SECOND, 0);
	calendar.set(Calendar::MILLISECOND, 0);
	m_date = calendar.getTime();
}

CoreAlarmTimeMessage::~CoreAlarmTimeMessage()
{
	//
}

Family CoreAlarmTimeMessage::getFamily() const
{
	return SECURITY;
}

void CoreAlarmTimeMessage::setEnrollmentRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setEnrollmentRequest(bool value)");
}

void CoreAlarmTimeMessage::setAnswerRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setAnswerRequest(bool value)");
}

void CoreAlarmTimeMessage::setTestMode(bool value)
{
    throw X2dException("Unsupported operation => Message::setTestMode(bool value)");
}

bool CoreAlarmTimeMessage::isBatteryFaulty() const
{
	return false;
}

void CoreAlarmTimeMessage::setBatteryFaulty(bool value)
{
    throw X2dException("Unsupported operation => Message::setBatteryFaulty(bool value)");
}

const Date& CoreAlarmTimeMessage::getDate() const
{
	return m_date;
}

void CoreAlarmTimeMessage::setDate(const Date& date)
{
	m_date = date;
}

bool CoreAlarmTimeMessage::isAccurate() const
{
	return !m_isBatteryFaulty;
}

void CoreAlarmTimeMessage::setAccurate(bool value)
{
	m_isBatteryFaulty = !value;
}

void CoreAlarmTimeMessage::serialize(std::vector<byte>& frame) const
{
	frame.assign(19, 0);

	frame[13] = (byte)0x08;

	Calendar calendar = Calendar();
	calendar.setTime(m_date);
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

	CoreAlarmMessage::serialize(frame);
}

bool CoreAlarmTimeMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmTimeMessage_t) { return true; }
	return false;
}

Message* CoreAlarmTimeMessage::clone() const
{
	return new CoreAlarmTimeMessage(*this);
}

void* CoreAlarmTimeMessage::derived()
{
	return (AlarmTimeMessage*)this;
}

CoreMessage* CoreAlarmTimeMessage::core()
{
	return this;
}
}
