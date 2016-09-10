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

#include "hvac/ThermicActuatorType.h"

namespace deltadoreX2d
{

ThermicActuatorType::ThermicActuatorType(int value)
{
	m_value = value;
	if (value == 0) { m_name = "SETPOINT"; }
	else if (value == 1) { m_name = "HEAT_SETPOINT"; }
	else if (value == 2) { m_name = "COOL_SETPOINT"; }
	else if (value == 3) { m_name = "HEAT_COOL_SETPOINT"; }
	else if (value == 4) { m_name = "LEVEL"; }
	else if (value == 5) { m_name = "HEAT_LEVEL"; }
	else if (value == 6) { m_name = "COOL_LEVEL"; }
	else if (value == 7) { m_name = "HEAT_COOL_LEVEL"; }
	else if (value == 8) { m_name = "SWITCH"; }
	else if (value == 9) { m_name = "HEAT_SWITCH"; }
	else if (value == 10) { m_name = "COOL_SWITCH"; }
	else if (value == 11) { m_name = "HEAT_COOL_SWITCH"; }
	else { throw X2dException("Invalid argument => ThermicActuatorType::ThermicActuatorType(int value)"); }
}

ThermicActuatorType::~ThermicActuatorType()
{
	//
}

const ThermicActuatorType ThermicActuatorType::SETPOINT = ThermicActuatorType(0);
const ThermicActuatorType ThermicActuatorType::HEAT_SETPOINT = ThermicActuatorType(1);
const ThermicActuatorType ThermicActuatorType::COOL_SETPOINT = ThermicActuatorType(2);
const ThermicActuatorType ThermicActuatorType::HEAT_COOL_SETPOINT =ThermicActuatorType(3);
const ThermicActuatorType ThermicActuatorType::LEVEL = ThermicActuatorType(4);
const ThermicActuatorType ThermicActuatorType::HEAT_LEVEL = ThermicActuatorType(5);
const ThermicActuatorType ThermicActuatorType::COOL_LEVEL = ThermicActuatorType(6);
const ThermicActuatorType ThermicActuatorType::HEAT_COOL_LEVEL = ThermicActuatorType(7);
const ThermicActuatorType ThermicActuatorType::SWITCH = ThermicActuatorType(8);
const ThermicActuatorType ThermicActuatorType::HEAT_SWITCH = ThermicActuatorType(9);
const ThermicActuatorType ThermicActuatorType::COOL_SWITCH = ThermicActuatorType(10);
const ThermicActuatorType ThermicActuatorType::HEAT_COOL_SWITCH = ThermicActuatorType(11);

ThermicActuatorType ThermicActuatorType::valueOf(int value)
{
	return ThermicActuatorType(value);
}

int ThermicActuatorType::toInt() const
{
	return m_value;
}

const std::string& ThermicActuatorType::toString() const
{
	return m_name;
}

bool ThermicActuatorType::operator==(const ThermicActuatorType &other) const {
	return (m_value == other.toInt());
}

bool ThermicActuatorType::operator!=(const ThermicActuatorType &other) const {
	return !(*this == other);
}
}
