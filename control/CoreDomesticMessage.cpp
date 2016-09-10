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

#include "control/CoreDomesticMessage.h"

namespace deltadoreX2d
{

CoreDomesticMessage::CoreDomesticMessage() : m_sourcePort(0)
{
	m_messagePriority = MessagePriority::EXCLUSIVE;
    m_sourceType = 62; // OEM by default
}

CoreDomesticMessage::CoreDomesticMessage(const std::vector<byte>& frame) : CoreMessage(frame)
{
    m_sourcePort = frame[12] & 0x0F;
}

CoreDomesticMessage::~CoreDomesticMessage()
{
    //
}

int CoreDomesticMessage::getSourcePort() const
{
    return m_sourcePort;
}

void CoreDomesticMessage::setSourcePort(int port)
{
    m_sourcePort = port;
}

void CoreDomesticMessage::serialize(std::vector<byte>& frame) const
{
    frame[12] |= (byte)(m_sourcePort & 0x0F);
    frame[13] = (byte)0x05;
    frame[14] = (byte)0x98;

    CoreMessage::serialize(frame);
}
}
