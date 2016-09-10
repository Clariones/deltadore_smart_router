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

#include "security/AlarmFunctioningMode.h"

namespace deltadoreX2d
{

AlarmFunctioningMode::AlarmFunctioningMode(int value)
{
	m_value = value;
	if (value == 0) { m_name = "DISARMED"; }
	else if (value == 1) { m_name = "FULLY_ARMED"; }
	else if (value == 2) { m_name = "PARTIALLY_ARMED1"; }
	else if (value == 3) { m_name = "PARTIALLY_ARMED2"; }
	else if (value == 4) { m_name = "PARTIALLY_ARMED3"; }
	else if (value == 5) { m_name = "PARTIALLY_ARMED4"; }
	else if (value == 6) { m_name = "PARTIALLY_ARMED5"; }
	else if (value == 7) { m_name = "PARTIALLY_ARMED6"; }
	else if (value == 8) { m_name = "PARTIALLY_ARMED7"; }
	else if (value == 9) { m_name = "PARTIALLY_ARMED8"; }
	else if (value == 10) { m_name = "PERIMETER_ARMED"; }
	else if (value == 11) { m_name = "TEST_MODE"; }
	else if (value == 12) { m_name = "MAINTENANCE_MODE"; }
	else { throw X2dException("Invalid argument => AlarmFunctioningMode::AlarmFunctioningMode(int value)"); }
}

AlarmFunctioningMode::~AlarmFunctioningMode()
{
    //
}

const AlarmFunctioningMode AlarmFunctioningMode::DISARMED =AlarmFunctioningMode(0);
const AlarmFunctioningMode AlarmFunctioningMode::FULLY_ARMED =AlarmFunctioningMode(1);
const AlarmFunctioningMode AlarmFunctioningMode::PARTIALLY_ARMED1 =AlarmFunctioningMode(2);
const AlarmFunctioningMode AlarmFunctioningMode::PARTIALLY_ARMED2 =AlarmFunctioningMode(3);
const AlarmFunctioningMode AlarmFunctioningMode::PARTIALLY_ARMED3 =AlarmFunctioningMode(4);
const AlarmFunctioningMode AlarmFunctioningMode::PARTIALLY_ARMED4 =AlarmFunctioningMode(5);
const AlarmFunctioningMode AlarmFunctioningMode::PARTIALLY_ARMED5 =AlarmFunctioningMode(6);
const AlarmFunctioningMode AlarmFunctioningMode::PARTIALLY_ARMED6 =AlarmFunctioningMode(7);
const AlarmFunctioningMode AlarmFunctioningMode::PARTIALLY_ARMED7 =AlarmFunctioningMode(8);
const AlarmFunctioningMode AlarmFunctioningMode::PARTIALLY_ARMED8 =AlarmFunctioningMode(9);
const AlarmFunctioningMode AlarmFunctioningMode::PERIMETER_ARMED =AlarmFunctioningMode(10);
const AlarmFunctioningMode AlarmFunctioningMode::TEST_MODE =AlarmFunctioningMode(11);
const AlarmFunctioningMode AlarmFunctioningMode::MAINTENANCE_MODE =AlarmFunctioningMode(12);

AlarmFunctioningMode AlarmFunctioningMode::valueOf(int value)
{
    return AlarmFunctioningMode(value);
}

int AlarmFunctioningMode::toInt() const
{
    return m_value;
}

const std::string& AlarmFunctioningMode::toString() const
{
	return m_name;
}

bool AlarmFunctioningMode::operator==(const AlarmFunctioningMode &other) const {
	return (m_value == other.toInt());
}

bool AlarmFunctioningMode::operator!=(const AlarmFunctioningMode &other) const {
	return !(*this == other);
}
}
