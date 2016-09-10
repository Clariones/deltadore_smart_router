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

#include "control/CoreCurrentTransformerDefinitionMessage.h"

namespace deltadoreX2d
{

CoreCurrentTransformerDefinitionMessage::CoreCurrentTransformerDefinitionMessage() :
	m_currentTransformer1(RegisterSelection::CURRENT_TRANSFORMER1),
	m_currentTransformer2(RegisterSelection::CURRENT_TRANSFORMER2),
	m_currentTransformer3(RegisterSelection::CURRENT_TRANSFORMER3)
{
    //
}

CoreCurrentTransformerDefinitionMessage::CoreCurrentTransformerDefinitionMessage(const std::vector<byte>& frame) :
	CoreDomesticMessage(frame),
	m_currentTransformer1(RegisterSelection::CURRENT_TRANSFORMER1),
	m_currentTransformer2(RegisterSelection::CURRENT_TRANSFORMER2),
	m_currentTransformer3(RegisterSelection::CURRENT_TRANSFORMER3)
{
    if (CoreDomesticMessage::isAnswerRequest())
    {
        m_currentTransformer1 = RegisterSelection(frame[16] & 0xFF);
        m_currentTransformer2 = RegisterSelection(frame[17] & 0xFF);
        m_currentTransformer3 = RegisterSelection(frame[18] & 0xFF);
    }
}

CoreCurrentTransformerDefinitionMessage::~CoreCurrentTransformerDefinitionMessage()
{
    //
}

Family CoreCurrentTransformerDefinitionMessage::getFamily() const
{
    return METERING;
}

const RegisterSelection& CoreCurrentTransformerDefinitionMessage::getCurrentTransformer1Definition() const
{
    return m_currentTransformer1;
}

void CoreCurrentTransformerDefinitionMessage::setCurrentTransformer1Definition(const RegisterSelection& selection)
{
    m_currentTransformer1 = selection;
}

const RegisterSelection& CoreCurrentTransformerDefinitionMessage::getCurrentTransformer2Definition() const
{
    return m_currentTransformer2;
}

void CoreCurrentTransformerDefinitionMessage::setCurrentTransformer2Definition(const RegisterSelection& selection)
{
    m_currentTransformer2 = selection;
}

const RegisterSelection& CoreCurrentTransformerDefinitionMessage::getCurrentTransformer3Definition() const
{
    return m_currentTransformer3;
}

void CoreCurrentTransformerDefinitionMessage::setCurrentTransformer3Definition(const RegisterSelection& selection)
{
    m_currentTransformer3 = selection;
}

void CoreCurrentTransformerDefinitionMessage::serialize(std::vector<byte>& frame) const
{
	if (m_isAnswerRequest)
    {
		frame.assign(16, 0);
    }
    else
    {
		frame.assign(19, 0);

        frame[16] = (byte)m_currentTransformer1.toInt();
        frame[17] = (byte)m_currentTransformer2.toInt();
        frame[18] = (byte)m_currentTransformer3.toInt();
    }
    frame[15] = (byte)0xFC;

    CoreDomesticMessage::serialize(frame);
}

bool CoreCurrentTransformerDefinitionMessage::instanceOf(MessageClass type) const
{
	if (type == CurrentTransformerDefinitionMessage_t) { return true; }
	return false;
}

Message* CoreCurrentTransformerDefinitionMessage::clone() const
{
	return new CoreCurrentTransformerDefinitionMessage(*this);
}

void* CoreCurrentTransformerDefinitionMessage::derived()
{
	return (CurrentTransformerDefinitionMessage*)this;
}

CoreMessage* CoreCurrentTransformerDefinitionMessage::core()
{
	return this;
}
}
