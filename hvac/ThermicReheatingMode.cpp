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

#include "hvac/ThermicReheatingMode.h"

namespace deltadoreX2d
{

ThermicReheatingMode::ThermicReheatingMode(int value)
{
	m_value = value;
	if (value == 0) { m_name = "VALVE_AND_ELECTRIC_BATTERY"; }
	else if (value == 1) { m_name = "VALVE"; }
	else if (value == 2) { m_name = "ELECTRIC_BATTERY"; }
	else if (value == 7) { m_name = "NA"; }
	else { 	throw X2dException("Invalid argument => ThermicReheatingMode::ThermicReheatingMode(int value)"); }
}

ThermicReheatingMode::~ThermicReheatingMode()
{
	//
}

const ThermicReheatingMode ThermicReheatingMode::VALVE_AND_ELECTRIC_BATTERY = ThermicReheatingMode(0);
const ThermicReheatingMode ThermicReheatingMode::VALVE = ThermicReheatingMode(1);
const ThermicReheatingMode ThermicReheatingMode::ELECTRIC_BATTERY = ThermicReheatingMode(2);
const ThermicReheatingMode ThermicReheatingMode::NA = ThermicReheatingMode(7);

ThermicReheatingMode ThermicReheatingMode::valueOf(int value)
{
	return ThermicReheatingMode(value);
}

int ThermicReheatingMode::toInt() const
{
	return m_value;
}

const std::string& ThermicReheatingMode::toString() const
{
	return m_name;
}

bool ThermicReheatingMode::operator==(const ThermicReheatingMode &other) const {
	return (m_value == other.toInt());
}

bool ThermicReheatingMode::operator!=(const ThermicReheatingMode &other) const {
	return !(*this == other);
}
}
