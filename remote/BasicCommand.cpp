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

#include "remote/BasicCommand.h"

namespace deltadoreX2d
{

BasicCommand::BasicCommand(int value)
{
	m_value = value;
	if (value == 0) { m_name = "OFF"; }
	else if (value == 1) { m_name = "ON"; }
	else if (value == 2) { m_name = "TOGGLE"; }
	else { throw X2dException("Invalid argument => BasicCommand::BasicCommand(int value)"); }
}

BasicCommand::~BasicCommand()
{
    //
}

const BasicCommand BasicCommand::OFF = BasicCommand(0);
const BasicCommand BasicCommand::ON = BasicCommand(1);
const BasicCommand BasicCommand::TOGGLE = BasicCommand(2);

BasicCommand BasicCommand::valueOf(int value)
{
    return BasicCommand(value);
}

int BasicCommand::toInt() const
{
    return m_value;
}

const std::string& BasicCommand::toString() const
{
	return m_name;
}

bool BasicCommand::operator==(const BasicCommand &other) const {
	return (m_value == other.toInt());
}

bool BasicCommand::operator!=(const BasicCommand &other) const {
	return !(*this == other);
}
}
