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
** mleforestier        | 042611           | First version
** ylebret             | 280212           | refactoring
*/

#include "hvac/ThermicHeatLevel.h"

namespace deltadoreX2d
{

ThermicHeatLevel::ThermicHeatLevel(int value)
{
	m_value = value;
	if (value == 241) { m_name = "REDUCED"; }
	else if (value == 242) { m_name = "MODERATO"; }
	else if (value == 243) { m_name = "MEDIO"; }
	else if (value == 244) { m_name = "COMFORT"; }
	else if (value == 245) { m_name = "STOP"; }
	else if (value == 246) { m_name = "ANTI_FROST"; }
	else if (value == 247) { m_name = "ON"; }
	else if (value == 248) { m_name = "OFF"; }
	else if (value == 255) { m_name = "NA"; }
	else if (value >= 0 && value <= 240) { m_name = value/2 + "." + value%2*5 + std::string("°C"); }
	else { throw X2dException("Invalid argument => ThermicHeatLevel::ThermicHeatLevel(int value)"); }
}

ThermicHeatLevel::~ThermicHeatLevel()
{
	//
}

const ThermicHeatLevel ThermicHeatLevel::REDUCED =ThermicHeatLevel(241);
const ThermicHeatLevel ThermicHeatLevel::MODERATO = ThermicHeatLevel(242);
const ThermicHeatLevel ThermicHeatLevel::MEDIO = ThermicHeatLevel(243);
const ThermicHeatLevel ThermicHeatLevel::COMFORT = ThermicHeatLevel(244);
const ThermicHeatLevel ThermicHeatLevel::STOP = ThermicHeatLevel(245);
const ThermicHeatLevel ThermicHeatLevel::ANTI_FROST = ThermicHeatLevel(246);
const ThermicHeatLevel ThermicHeatLevel::ON = ThermicHeatLevel(247);
const ThermicHeatLevel ThermicHeatLevel::OFF = ThermicHeatLevel(248);
const ThermicHeatLevel ThermicHeatLevel::NA = ThermicHeatLevel(255);

ThermicHeatLevel ThermicHeatLevel::valueOf(int value)
{
	return ThermicHeatLevel(value);
}

ThermicHeatLevel ThermicHeatLevel::setpoint(int value)
{
	if (value >= 0 && value <= 240)
	{
		return ThermicHeatLevel(value);
	}
	throw X2dException("Invalid argument => ThermicHeatLevel::setpoint(int value)");
}

int ThermicHeatLevel::toInt() const
{
	return m_value;
}

const std::string& ThermicHeatLevel::toString() const
{
	return m_name;
}

bool ThermicHeatLevel::operator==(const ThermicHeatLevel &other) const {
	return (m_value == other.toInt());
}

bool ThermicHeatLevel::operator!=(const ThermicHeatLevel &other) const {
	return !(*this == other);
}
}
