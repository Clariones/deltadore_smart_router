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
** ylebret             | 280212           | First version
*/

#include "control/MessagePriority.h"

namespace deltadoreX2d
{

MessagePriority::MessagePriority(int value)
{
	m_value = value;
	if (value == 770) { m_name = "NORMAL"; }
	else if (value == 771) { m_name = "IMPORTANT"; }
	else if (value == 773) { m_name = "PRIORITIZED"; }
	else if (value == 769) { m_name = "EXCLUSIVE"; }
	else { throw X2dException("Invalid argument => MessagePriority::MessagePriority(int value)"); }
}

MessagePriority::MessagePriority(int value1, int value2)
{
	m_value = (value2 << 8) + value1;
	m_name = "SPECIAL";
}

MessagePriority::~MessagePriority()
{
    //
}

const MessagePriority MessagePriority::NORMAL = MessagePriority(770);
const MessagePriority MessagePriority::IMPORTANT = MessagePriority(771);
const MessagePriority MessagePriority::PRIORITIZED = MessagePriority(773);
const MessagePriority MessagePriority::EXCLUSIVE = MessagePriority(769);

MessagePriority MessagePriority::valueOf(int value)
{
    return MessagePriority(value);
}

MessagePriority MessagePriority::valueOf(int value1, int value2)
{
    return MessagePriority(value1, value2);
}

int MessagePriority::toInt() const
{
    return m_value;
}

const std::string& MessagePriority::toString() const
{
    return m_name;
}

bool MessagePriority::operator==(const MessagePriority &other) const {
	return (m_value == other.toInt());
}

bool MessagePriority::operator!=(const MessagePriority &other) const {
	return !(*this == other);
}
}
