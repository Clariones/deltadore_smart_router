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

#include "sensor/TemperatureType.h"

namespace deltadoreX2d
{

TemperatureType::TemperatureType(int value)
{
	m_value = value;
	if (value == 8) { m_name = "PROBE"; }
	else if (value == 10) { m_name = "INTERNAL"; }
	else if (value == 11) { m_name = "EXTERNAL"; }
	else { throw X2dException("Invalid argument => TemperatureType::TemperatureType(int value)"); }
}

TemperatureType::~TemperatureType()
{
    //
}

const TemperatureType TemperatureType::PROBE =TemperatureType(8);
const TemperatureType TemperatureType::INTERNAL = TemperatureType(10);
const TemperatureType TemperatureType::EXTERNAL = TemperatureType(11);

TemperatureType TemperatureType::valueOf(int value)
{
    return TemperatureType(value);
}

int TemperatureType::toInt() const
{
    return m_value;
}

const std::string& TemperatureType::toString() const
{
	return m_name;
}

bool TemperatureType::operator==(const TemperatureType &other) const {
	return (m_value == other.toInt());
}

bool TemperatureType::operator!=(const TemperatureType &other) const {
	return !(*this == other);
}
}
