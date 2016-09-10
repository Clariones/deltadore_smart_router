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

#include "control/CoreDataTransferNotificationMessage.h"

namespace deltadoreX2d
{

CoreDataTransferNotificationMessage::CoreDataTransferNotificationMessage()
{
	//
}

CoreDataTransferNotificationMessage::CoreDataTransferNotificationMessage(const std::vector<byte>& frame) : CoreAlarmMessage(frame)
{
	m_index = frame[12] & 0xFF;
	m_destinationAddress = (frame[17] & 0xFF) << 16;
	m_destinationAddress += (frame[16] & 0xFF) << 8;
	m_destinationAddress += frame[15] & 0xFF;
}

CoreDataTransferNotificationMessage::~CoreDataTransferNotificationMessage()
{
	//
}

Family CoreDataTransferNotificationMessage::getFamily() const
{
	return SECURITY;
}

void CoreDataTransferNotificationMessage::setEnrollmentRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setEnrollmentRequest(bool value)");
}

void CoreDataTransferNotificationMessage::setAnswerRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setAnswerRequest(bool value)");
}

void CoreDataTransferNotificationMessage::setTestMode(bool value)
{
    throw X2dException("Unsupported operation => Message::setTestMode(bool value)");
}

void CoreDataTransferNotificationMessage::setDestinationAddress(int address)
{
    m_destinationAddress = address;
}

int CoreDataTransferNotificationMessage::getDataPacketIndex() const
{
	return m_index;
}

void CoreDataTransferNotificationMessage::setDataPacketIndex(int index)
{
	m_index = index;
}

void CoreDataTransferNotificationMessage::serialize(std::vector<byte>& frame) const
{
	frame.assign(18, 0);

	frame[12] = (byte)m_index;
	frame[15] = (byte)(m_destinationAddress & 0xFF);
	frame[16] = (byte)((m_destinationAddress >> 8) & 0xFF);
	frame[17] = (byte)((m_destinationAddress >> 16) & 0xFF);

	CoreAlarmMessage::serialize(frame);
}

bool CoreDataTransferNotificationMessage::instanceOf(MessageClass type) const
{
	if (type == DataTransferNotificationMessage_t) { return true; }
	return false;
}

Message* CoreDataTransferNotificationMessage::clone() const
{
	return new CoreDataTransferNotificationMessage(*this);
}

void* CoreDataTransferNotificationMessage::derived()
{
	return (DataTransferNotificationMessage*)this;
}

CoreMessage* CoreDataTransferNotificationMessage::core()
{
	return this;
}
}
