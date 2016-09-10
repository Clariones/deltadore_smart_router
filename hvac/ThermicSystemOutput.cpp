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
** mleforestier        | 052511           | First version
** ylebret             | 280212           | refactoring
*/

#include "hvac/ThermicSystemOutput.h"

namespace deltadoreX2d
{

ThermicSystemOutput::ThermicSystemOutput(int value)
{
	m_value = value;
	if (value == 0) { m_name = "NONE"; }
	else if (value == 1) { m_name = "HEAT"; }
	else if (value == 2) { m_name = "COOL"; }
	else if (value == 7) { m_name = "NA"; }
	else { throw X2dException("Invalid argument => ThermicSystemOutput::ThermicSystemOutput(int value)"); }
}

ThermicSystemOutput::~ThermicSystemOutput()
{
	//
}

const ThermicSystemOutput ThermicSystemOutput::NONE = ThermicSystemOutput(0);
const ThermicSystemOutput ThermicSystemOutput::HEAT = ThermicSystemOutput(1);
const ThermicSystemOutput ThermicSystemOutput::COOL = ThermicSystemOutput(2);
const ThermicSystemOutput ThermicSystemOutput::NA = ThermicSystemOutput(7);

ThermicSystemOutput ThermicSystemOutput::valueOf(int value)
{
	return ThermicSystemOutput(value);
}

int ThermicSystemOutput::toInt() const
{
	return m_value;
}

const std::string& ThermicSystemOutput::toString() const
{
	return m_name;
}

bool ThermicSystemOutput::operator==(const ThermicSystemOutput &other) const {
	return (m_value == other.toInt());
}

bool ThermicSystemOutput::operator!=(const ThermicSystemOutput &other) const {
	return !(*this == other);
}
}
