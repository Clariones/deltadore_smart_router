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

#include "control/CoreAlarmPeripheralDeletionMessage.h"

namespace deltadoreX2d
{

CoreAlarmPeripheralDeletionMessage::CoreAlarmPeripheralDeletionMessage()
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
}

CoreAlarmPeripheralDeletionMessage::CoreAlarmPeripheralDeletionMessage(const std::vector<byte>& frame) : CoreAlarmMessage(frame)
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
	m_productId = (frame[16] & 0xFF) << 16;
	m_productId += (frame[15] & 0xFF) << 8;
	m_productId += frame[12] & 0xFF;
}

CoreAlarmPeripheralDeletionMessage::~CoreAlarmPeripheralDeletionMessage()
{
	//
}

Family CoreAlarmPeripheralDeletionMessage::getFamily() const
{
	return SECURITY;
}

void CoreAlarmPeripheralDeletionMessage::setEnrollmentRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setEnrollmentRequest(bool value)");
}

void CoreAlarmPeripheralDeletionMessage::setAnswerRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setAnswerRequest(bool value)");
}

void CoreAlarmPeripheralDeletionMessage::setTestMode(bool value) {
    throw X2dException("Unsupported operation => Message::setTestMode(bool value)");
}

int CoreAlarmPeripheralDeletionMessage::getProductId() const
{
	return m_productId;
}

void CoreAlarmPeripheralDeletionMessage::setProductId(int id)
{
	m_productId = id;
}

const AlarmProductType CoreAlarmPeripheralDeletionMessage::getProductType() const
{
	return AlarmProductType((m_productId >> 16)& 0x3F);
}

void CoreAlarmPeripheralDeletionMessage::serialize(std::vector<byte>& frame) const
{
	frame.assign(17, 0);

	frame[12] = (byte)(m_productId & 0xFF);
	frame[13] = (byte)0x02;
	frame[14] = (byte)0x08;
	frame[15] = (byte)((m_productId >> 8) & 0xFF);
	frame[16] = (byte)((m_productId >> 16) & 0xFF);

	CoreAlarmMessage::serialize(frame);
}

bool CoreAlarmPeripheralDeletionMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmPeripheralDeletionMessage_t) { return true; }
	return false;
}

Message* CoreAlarmPeripheralDeletionMessage::clone() const
{
	return new CoreAlarmPeripheralDeletionMessage(*this);
}

void* CoreAlarmPeripheralDeletionMessage::derived()
{
	return (AlarmPeripheralDeletionMessage*)this;
}

CoreMessage* CoreAlarmPeripheralDeletionMessage::core()
{
	return this;
}
}
