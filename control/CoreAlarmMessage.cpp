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

#include "control/CoreAlarmMessage.h"

namespace deltadoreX2d
{

CoreAlarmMessage::CoreAlarmMessage() : m_destinationAddress(0)
{
    //
}

CoreAlarmMessage::CoreAlarmMessage(const std::vector<byte>& frame) : CoreMessage(frame), m_destinationAddress(0)
{
    //
}

CoreAlarmMessage::~CoreAlarmMessage()
{
    //
}

bool CoreAlarmMessage::isTestMode() const
{
	return m_isTestMode;
}

void CoreAlarmMessage::setTestMode(bool value)
{
	m_isTestMode = value;
}

int CoreAlarmMessage::getDestinationAddress() const
{
	return m_destinationAddress;
}

void CoreAlarmMessage::setDestinationAddress(int address)
{
    throw X2dException("Unsupported operation => Message::setDestinationAddress(int address)");
}

int CoreAlarmMessage::getSourcePort() const
{
    return 0;
}

void CoreAlarmMessage::setSourcePort(int port)
{
    throw X2dException("Unsupported operation => Message::setSourcePort(int port)");
}

void CoreAlarmMessage::serialize(std::vector<byte>& frame) const
{
    frame[3] = (byte)0x01;
    frame[14] |= (byte)0x80;

    CoreMessage::serialize(frame);
}
}
