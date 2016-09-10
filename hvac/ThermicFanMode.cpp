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
** mleforestier        | 052311           | First version
** ylebret             | 280212           | refactoring
*/

#include "hvac/ThermicFanMode.h"

namespace deltadoreX2d
{

ThermicFanMode::ThermicFanMode(int value)
{
	m_value = value;
	if (value == 0) { m_name = "STOP"; }
	else if (value == 1) { m_name = "AUTO"; }
	else if (value == 2) { m_name = "LOW"; }
	else if (value == 3) { m_name = "MEDIUM"; }
	else if (value == 4) { m_name = "HIGH"; }
	else if (value == 7) { m_name = "NA"; }
	else { throw X2dException("Invalid argument => ThermicFanMode::ThermicFanMode(int value)"); }
}

ThermicFanMode::~ThermicFanMode()
{
	//
}

const ThermicFanMode ThermicFanMode::STOP = ThermicFanMode(0);
const ThermicFanMode ThermicFanMode::AUTO = ThermicFanMode(1);
const ThermicFanMode ThermicFanMode::LOW = ThermicFanMode(2);
const ThermicFanMode ThermicFanMode::MEDIUM = ThermicFanMode(3);
const ThermicFanMode ThermicFanMode::HIGH = ThermicFanMode(4);
const ThermicFanMode ThermicFanMode::NA = ThermicFanMode(7);

ThermicFanMode ThermicFanMode::valueOf(int value)
{
	return ThermicFanMode(value);
}

int ThermicFanMode::toInt() const
{
	return m_value;
}

const std::string& ThermicFanMode::toString() const
{
	return m_name;
}

bool ThermicFanMode::operator==(const ThermicFanMode &other) const {
	return (m_value == other.toInt());
}

bool ThermicFanMode::operator!=(const ThermicFanMode &other) const {
	return !(*this == other);
}
}
