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

#include "hvac/ThermicRegulationMode.h"

namespace deltadoreX2d
{

ThermicRegulationMode::ThermicRegulationMode(int value)
{
	m_value = value;
	if (value == 0) { m_name = "NORMAL"; }
	else if (value == 1) { m_name = "STOP"; }
	else if (value == 2) { m_name = "ABSENCE"; }
	else if (value == 7) { m_name = "NA"; }
	else { throw X2dException("Invalid argument => ThermicRegulationMode::ThermicRegulationMode(int value)"); }
}

ThermicRegulationMode::~ThermicRegulationMode()
{
	//
}

const ThermicRegulationMode ThermicRegulationMode::NORMAL = ThermicRegulationMode(0);
const ThermicRegulationMode ThermicRegulationMode::STOP = ThermicRegulationMode(1);
const ThermicRegulationMode ThermicRegulationMode::ABSENCE = ThermicRegulationMode(2);
const ThermicRegulationMode ThermicRegulationMode::NA = ThermicRegulationMode(7);

ThermicRegulationMode ThermicRegulationMode::valueOf(int value)
{
	return ThermicRegulationMode(value);
}

int ThermicRegulationMode::toInt() const
{
	return m_value;
}

const std::string& ThermicRegulationMode::toString() const
{
	return m_name;
}

bool ThermicRegulationMode::operator==(const ThermicRegulationMode &other) const {
	return (m_value == other.toInt());
}

bool ThermicRegulationMode::operator!=(const ThermicRegulationMode &other) const {
	return !(*this == other);
}
}
