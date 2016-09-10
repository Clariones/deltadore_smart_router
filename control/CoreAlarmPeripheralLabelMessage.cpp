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

#include "control/CoreAlarmPeripheralLabelMessage.h"

namespace deltadoreX2d
{

CoreAlarmPeripheralLabelMessage::CoreAlarmPeripheralLabelMessage() :
	m_label(AlarmProductLabel::OTHER)
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
}

CoreAlarmPeripheralLabelMessage::CoreAlarmPeripheralLabelMessage(const std::vector<byte>& frame) :
	CoreAlarmMessage(frame),
	m_label(AlarmProductLabel(frame[17] & 0x1F))
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
	m_productId = (frame[16] & 0xFF) << 16;
	m_productId += (frame[15] & 0xFF) << 8;
	m_productId += frame[12] & 0xFF;
	m_labelNumber = ((frame[17] >> 5) & 0x07);

	if (frame.size() > 20)
	{
		int length = frame.size() - 20;
		char* buffer = (char*)malloc(sizeof(char) * length +1);
		memcpy(buffer, &frame[0], length);
		buffer[length] = '\0';
		m_customLabel = std::string(buffer);
		free(buffer);
	}
}

CoreAlarmPeripheralLabelMessage::~CoreAlarmPeripheralLabelMessage()
{
	//
}

Family CoreAlarmPeripheralLabelMessage::getFamily() const
{
	return SECURITY;
}

void CoreAlarmPeripheralLabelMessage::setEnrollmentRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setEnrollmentRequest(bool value)");
}

void CoreAlarmPeripheralLabelMessage::setAnswerRequest(bool value)
{
    throw X2dException("Unsupported operation => Message::setAnswerRequest(bool value)");
}

void CoreAlarmPeripheralLabelMessage::setTestMode(bool value)
{
    throw X2dException("Unsupported operation => Message::setTestMode(bool value)");
}

int CoreAlarmPeripheralLabelMessage::getProductId() const
{
	return m_productId;
}

void CoreAlarmPeripheralLabelMessage::setProductId(int id)
{
	m_productId = id;
}

const AlarmProductType CoreAlarmPeripheralLabelMessage::getProductType() const
{
	return AlarmProductType((m_productId >> 16) & 0x3F);
}

const AlarmProductLabel& CoreAlarmPeripheralLabelMessage::getLabel() const
{
    return m_label;
}

void CoreAlarmPeripheralLabelMessage::setLabel(const AlarmProductLabel& label)
{
	m_label = label;
}

int CoreAlarmPeripheralLabelMessage::getLabelNumber() const
{
	return m_labelNumber;
}

void CoreAlarmPeripheralLabelMessage::setLabelNumber(int number)
{
	m_labelNumber = number;
}

const std::string& CoreAlarmPeripheralLabelMessage::getCustomLabel() const
{
	return m_customLabel;
}

void CoreAlarmPeripheralLabelMessage::setCustomLabel(const std::string& label)
{
	m_customLabel = label;
}

void CoreAlarmPeripheralLabelMessage::serialize(std::vector<byte>& frame) const
{
	if (!m_customLabel.empty())
	{
		frame.assign(18 + m_customLabel.length(), 0);
		memcpy(&frame.at(17), m_customLabel.c_str(), m_customLabel.length());
	}
	else
	{
		frame.assign(18, 0);
	}

	frame[12] = (byte)(m_productId & 0xFF);
	frame[13] = (byte)0x03;
	frame[15] = (byte)((m_productId >> 8) & 0xFF);
	frame[16] = (byte)((m_productId >> 16) & 0xFF);
	frame[17] = (byte)m_label.toInt();
	frame[17] |= (byte)(m_labelNumber << 5);

	CoreAlarmMessage::serialize(frame);
}

bool CoreAlarmPeripheralLabelMessage::instanceOf(MessageClass type) const
{
	if (type == AlarmPeripheralLabelMessage_t) { return true; }
	return false;
}

Message* CoreAlarmPeripheralLabelMessage::clone() const
{
	return new CoreAlarmPeripheralLabelMessage(*this);
}

void* CoreAlarmPeripheralLabelMessage::derived()
{
	return (AlarmPeripheralLabelMessage*)this;
}

CoreMessage* CoreAlarmPeripheralLabelMessage::core()
{
	return this;
}
}
