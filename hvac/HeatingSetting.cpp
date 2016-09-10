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

#include "hvac/HeatingSetting.h"

namespace deltadoreX2d
{

HeatingSetting::HeatingSetting(int value)
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
	else { throw X2dException("Invalid argument => HeatingSetting::HeatingSetting(int value)"); }
}

HeatingSetting::~HeatingSetting()
{
	//
}

const HeatingSetting HeatingSetting::REDUCED = HeatingSetting(0);
const HeatingSetting HeatingSetting::MODERATO = HeatingSetting(1);
const HeatingSetting HeatingSetting::MEDIO = HeatingSetting(2);
const HeatingSetting HeatingSetting::COMFORT = HeatingSetting(3);
const HeatingSetting HeatingSetting::STOP = HeatingSetting(4);
const HeatingSetting HeatingSetting::ANTI_FROST = HeatingSetting(5);
const HeatingSetting HeatingSetting::SPECIAL = HeatingSetting(6);
const HeatingSetting HeatingSetting::AUTO = HeatingSetting(7);
const HeatingSetting HeatingSetting::CENTRALIZED = HeatingSetting(8);

HeatingSetting HeatingSetting::valueOf(int value)
{
	return HeatingSetting(value);
}

int HeatingSetting::toInt() const
{
	return m_value;
}

const std::string& HeatingSetting::toString() const
{
	return m_name;
}

bool HeatingSetting::operator==(const HeatingSetting &other) const {
	return (m_value == other.toInt());
}

bool HeatingSetting::operator!=(const HeatingSetting &other) const {
	return !(*this == other);
}
}
