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

#include "control/MessageReceivedEvent.h"

namespace deltadoreX2d
{

MessageReceivedEvent::MessageReceivedEvent(DirectController* source, Message* message, const RadioFrequency& frequency) :
	m_frequency(frequency)
{
    m_source = source;
    m_message = message;
}

MessageReceivedEvent::~MessageReceivedEvent()
{
    //
}

DirectController* MessageReceivedEvent::getSource() const
{
    return m_source;
}

const Message* MessageReceivedEvent::getMessage() const
{
    return m_message;
}

const RadioFrequency& MessageReceivedEvent::getRadioFrequency() const
{
    return m_frequency;
}
}
