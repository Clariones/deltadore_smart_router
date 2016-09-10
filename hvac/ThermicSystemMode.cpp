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

#include "hvac/ThermicSystemMode.h"

namespace deltadoreX2d
{

ThermicSystemMode::ThermicSystemMode(int value)
{
	m_value = value;
	if (value == 0) { m_name = "STOP"; }
	else if (value == 1) { m_name = "HEAT"; }
	else if (value == 2) { m_name = "COOL"; }
	else if (value == 3) { m_name = "AUTO"; }
	else if (value == 7) { m_name = "NA"; }
	else { throw X2dException("Invalid argument => ThermicSystemMode::ThermicSystemMode(int value)"); }
}

ThermicSystemMode::~ThermicSystemMode()
{
	//
}

const ThermicSystemMode ThermicSystemMode::STOP = ThermicSystemMode(0);
const ThermicSystemMode ThermicSystemMode::HEAT = ThermicSystemMode(1);
const ThermicSystemMode ThermicSystemMode::COOL = ThermicSystemMode(2);
const ThermicSystemMode ThermicSystemMode::AUTO = ThermicSystemMode(3);
const ThermicSystemMode ThermicSystemMode::NA = ThermicSystemMode(7);

ThermicSystemMode ThermicSystemMode::valueOf(int value)
{
	return ThermicSystemMode(value);
}

int ThermicSystemMode::toInt() const
{
	return m_value;
}

const std::string& ThermicSystemMode::toString() const
{
	return m_name;
}

bool ThermicSystemMode::operator==(const ThermicSystemMode &other) const {
	return (m_value == other.toInt());
}

bool ThermicSystemMode::operator!=(const ThermicSystemMode &other) const {
	return !(*this == other);
}
}
