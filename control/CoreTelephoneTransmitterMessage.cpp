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

#include "control/CoreTelephoneTransmitterMessage.h"

namespace deltadoreX2d
{

CoreTelephoneTransmitterMessage::CoreTelephoneTransmitterMessage() : m_status(TelephoneTransmitterStatus::IDLE)
{
	m_messagePriority = MessagePriority::PRIORITIZED;
}

CoreTelephoneTransmitterMessage::CoreTelephoneTransmitterMessage(const std::vector<byte>& frame) :
	CoreAlarmMessage(frame),
	m_status(TelephoneTransmitterStatus::IDLE)
{
	m_messagePriority = MessagePriority::PRIORITIZED;

    if(m_isAnswerRequest)
    {
        m_destinationAddress = (frame[17] & 0xFF) << 16;
        m_destinationAddress += (frame[16] & 0xFF) << 8;
        m_destinationAddress += frame[15] & 0xFF;
    }
    else
    {
        m_status = TelephoneTransmitterStatus(frame[12] & 0x1F);
        m_isTelemonitoringFaulty = (frame[12] & 0x20) == 0x20;
        m_isTelephoneLineFaulty = (frame[12] & 0x40) == 0x40;
        m_isDoubtRemovalCurrent = (frame[12] & 0x80) == 0x80;
    }
}

CoreTelephoneTransmitterMessage::~CoreTelephoneTransmitterMessage()
{
    //
}

Family CoreTelephoneTransmitterMessage::getFamily() const
{
    return SECURITY;
}

void CoreTelephoneTransmitterMessage::setDestinationAddress(int address)
{
    m_destinationAddress = address;
}

void CoreTelephoneTransmitterMessage::setPriority(const MessagePriority& priority)
{
	m_messagePriority = priority;
}

const TelephoneTransmitterStatus& CoreTelephoneTransmitterMessage::getStatus() const
{
    return m_status;
}

void CoreTelephoneTransmitterMessage::setStatus(const TelephoneTransmitterStatus& status)
{
    m_status = status;
}

bool CoreTelephoneTransmitterMessage::isTelemonitoringFaulty() const
{
    return m_isTelemonitoringFaulty;
}

void CoreTelephoneTransmitterMessage::setTelemonitoringFaulty(bool value)
{
    m_isTelemonitoringFaulty = value;
}

bool CoreTelephoneTransmitterMessage::isTelephoneLineFaulty() const
{
    return m_isTelephoneLineFaulty;
}

void CoreTelephoneTransmitterMessage::setTelephoneLineFaulty(bool value)
{
    m_isTelephoneLineFaulty = value;
}

bool CoreTelephoneTransmitterMessage::isDoubtRemovalCurrent() const
{
    return m_isDoubtRemovalCurrent;
}

void CoreTelephoneTransmitterMessage::setDoubtRemovalCurrent(bool value)
{
    m_isDoubtRemovalCurrent = value;
}

void CoreTelephoneTransmitterMessage::serialize(std::vector<byte>& frame) const
{
    if (m_isAnswerRequest)
    {
		frame.assign(18, 0);
        frame[15] = (byte)(CoreAlarmMessage::m_destinationAddress & 0xFF);
        frame[16] = (byte)((CoreAlarmMessage::m_destinationAddress >> 8) & 0xFF);
        frame[17] = (byte)((CoreAlarmMessage::m_destinationAddress >> 16) & 0xFF);
    }
    else
    {
		frame.assign(16, 0);
        frame[12] = (byte)m_status.toInt();
        if (m_isTelemonitoringFaulty) { frame[12] |= 0x20; }
        if (m_isTelephoneLineFaulty) {  frame[12] |= 0x40; }
        if (m_isDoubtRemovalCurrent) { frame[12] |= 0x80; }
    }

    CoreAlarmMessage::serialize(frame);
}

bool CoreTelephoneTransmitterMessage::instanceOf(MessageClass type) const
{
	if (type == TelephoneTransmitterMessage_t) { return true; }
	return false;
}

Message* CoreTelephoneTransmitterMessage::clone() const
{
	return new CoreTelephoneTransmitterMessage(*this);
}

void* CoreTelephoneTransmitterMessage::derived()
{
	return (TelephoneTransmitterMessage*)this;
}

CoreMessage* CoreTelephoneTransmitterMessage::core()
{
	return this;
}
}
