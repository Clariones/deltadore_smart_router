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

#include "hvac/ThermicFanSpeed.h"

namespace deltadoreX2d
{

ThermicFanSpeed::ThermicFanSpeed(int value)
{
	m_value = value;
	if (value == 0) { m_name = "STOP"; }
	else if (value == 1) { m_name = "AUTO"; }
	else if (value == 2) { m_name = "LOW"; }
	else if (value == 3) { m_name = "MEDIUM"; }
	else if (value == 4) { m_name = "HIGH"; }
	else if (value == 7) { m_name = "NA"; }
	else { throw X2dException("Invalid argument => ThermicFanSpeed::ThermicFanSpeed(int value)"); }
}

ThermicFanSpeed::~ThermicFanSpeed()
{
	//
}

const ThermicFanSpeed ThermicFanSpeed::STOP = ThermicFanSpeed(0);
const ThermicFanSpeed ThermicFanSpeed::AUTO = ThermicFanSpeed(1);
const ThermicFanSpeed ThermicFanSpeed::LOW = ThermicFanSpeed(2);
const ThermicFanSpeed ThermicFanSpeed::MEDIUM = ThermicFanSpeed(3);
const ThermicFanSpeed ThermicFanSpeed::HIGH = ThermicFanSpeed(4);
const ThermicFanSpeed ThermicFanSpeed::NA = ThermicFanSpeed(7);

ThermicFanSpeed ThermicFanSpeed::valueOf(int value)
{
	return ThermicFanSpeed(value);
}

int ThermicFanSpeed::toInt() const
{
	return m_value;
}

const std::string& ThermicFanSpeed::toString() const
{
	return m_name;
}

bool ThermicFanSpeed::operator==(const ThermicFanSpeed &other) const {
	return (m_value == other.toInt());
}

bool ThermicFanSpeed::operator!=(const ThermicFanSpeed &other) const {
	return !(*this == other);
}
}
