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

#include "control/CoreDataTransferMessage.h"

namespace deltadoreX2d
{

CoreDataTransferMessage::CoreDataTransferMessage()
{
	//
}

CoreDataTransferMessage::CoreDataTransferMessage(const std::vector<byte>& frame) : CoreAlarmMessage(frame)
{
	m_index = frame[12] & 0xFF;
	if (m_isAnswerRequest)
	{
	    m_destinationAddress = (frame[17] & 0xFF) << 16;
		m_destinationAddress += (frame[16] & 0xFF) << 8;
		m_destinationAddress += frame[15] & 0xFF;
	}
	else if(m_index != 0xFF)
	{
		m_checksum = (frame[13] & 0x08) == 0x08;

		int dataLength = frame.size() - 19;
		m_data.assign(dataLength, 0);
		memcpy(&m_data[0], &frame[15], dataLength);
	}
}

CoreDataTransferMessage::~CoreDataTransferMessage()
{
	//
}

Family CoreDataTransferMessage::getFamily() const
{
	return SECURITY;
}

void CoreDataTransferMessage::setEnrollmentRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setEnrollmentRequest(bool value)");
}

void CoreDataTransferMessage::setTestMode(bool value)
{
    throw X2dException("Unsupported operation => Message::setTestMode(bool value)");
}

void CoreDataTransferMessage::setDestinationAddress(int address)
{
    m_destinationAddress = address;
}

int CoreDataTransferMessage::getDataPacketIndex() const
{
	return m_index;
}

void CoreDataTransferMessage::setDataPacketIndex(int index)
{
	m_index = index;
}

bool CoreDataTransferMessage::isChecksum() const
{
	return m_checksum;
}

void CoreDataTransferMessage::setChecksum()
{
	m_checksum = true;
}

bool CoreDataTransferMessage::isEndOfTransfer() const
{
	return m_index == (byte)0xFF;
}

void CoreDataTransferMessage::setEndOfTransfer()
{
	m_index = (byte)0xFF;
}

const std::vector<byte>& CoreDataTransferMessage::getDataPacket() const
{
	return m_data;
}

void CoreDataTransferMessage::setDataPacket(const std::vector<byte>& data)
{
	m_data = data;
}

void CoreDataTransferMessage::serialize(std::vector<byte>& frame) const
{
	if (m_isAnswerRequest)
	{
		frame.assign(18, 0);
    	frame[15] = (byte)(m_destinationAddress & 0xFF);
        frame[16] = (byte)((m_destinationAddress >> 8) & 0xFF);
        frame[17] = (byte)((m_destinationAddress >> 16) & 0xFF);
    }
    else if(m_index == 0xFF)
	{
		frame.assign(15, 0);
	}
	else
	{
		frame.assign(15 + m_data.size(), 0);
		if (m_checksum) { frame[13] = 0x08; }
		memcpy(&frame[15],&m_data[0],m_data.size());
	}

	frame[12] = (byte)m_index;
    frame[13] |= (byte)0x07;

	CoreAlarmMessage::serialize(frame);
}

bool CoreDataTransferMessage::instanceOf(MessageClass type) const
{
	if (type == DataTransferMessage_t) { return true; }
	return false;
}

Message* CoreDataTransferMessage::clone() const
{
	return new CoreDataTransferMessage(*this);
}

void* CoreDataTransferMessage::derived()
{
	return (DataTransferMessage*)this;
}

CoreMessage* CoreDataTransferMessage::core()
{
	return this;
}
}
