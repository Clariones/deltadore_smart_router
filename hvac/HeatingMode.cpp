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

#include "hvac/HeatingMode.h"

namespace deltadoreX2d
{

HeatingMode::HeatingMode(int value)
{
	m_value = value;
	if (value == 0) { m_name = "REDUCED"; }
	else if (value == 1) { m_name = "MODERATO"; }
	else if (value == 2) { m_name = "MEDIO"; }
	else if (value == 3) { m_name = "COMFORT"; }
	else if (value == 4) { m_name = "STOP"; }
	else if (value == 5) { m_name = "ANTI_FROST"; }
	else if (value == 6) { m_name = "SPECIAL"; }
	else if (value == 7) { m_name = "AUTO"; }
	else if (value == 8) { m_name = "CENTRALIZED"; }
	else { throw X2dException("Invalid argument => HeatingMode::HeatingMode(int value)"); }
}

HeatingMode::~HeatingMode()
{
    //
}

const HeatingMode HeatingMode::REDUCED = HeatingMode(0);
const HeatingMode HeatingMode::MODERATO = HeatingMode(1);
const HeatingMode HeatingMode::MEDIO = HeatingMode(2);
const HeatingMode HeatingMode::COMFORT = HeatingMode(3);
const HeatingMode HeatingMode::STOP = HeatingMode(4);
const HeatingMode HeatingMode::ANTI_FROST = HeatingMode(5);
const HeatingMode HeatingMode::SPECIAL = HeatingMode(6);
const HeatingMode HeatingMode::AUTO = HeatingMode(7);
const HeatingMode HeatingMode::CENTRALIZED = HeatingMode(8);

HeatingMode HeatingMode::valueOf(int value)
{
    return HeatingMode(value);
}

int HeatingMode::toInt() const
{
    return m_value;
}

const std::string& HeatingMode::toString() const
{
	return m_name;
}

bool HeatingMode::operator==(const HeatingMode &other) const {
	return (m_value == other.toInt());
}

bool HeatingMode::operator!=(const HeatingMode &other) const {
	return !(*this == other);
}
}
