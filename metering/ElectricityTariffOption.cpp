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

#include "metering/ElectricityTariffOption.h"

namespace deltadoreX2d
{

ElectricityTariffOption::ElectricityTariffOption(int value)
{
	m_value = value;
	if (value == 0) { m_name = "BASE"; }
	else if (value == 32) { m_name = "EJP"; }
	else if (value == 64) { m_name = "DOUBLE"; }
	else if (value == 96) { m_name = "TEMPO"; }
	else { throw X2dException("Invalid argument => ElectricityTariffOption::ElectricityTariffOption(int value)"); }
}

ElectricityTariffOption::~ElectricityTariffOption()
{
    //
}

const ElectricityTariffOption ElectricityTariffOption::BASE = ElectricityTariffOption(0);
const ElectricityTariffOption ElectricityTariffOption::EJP = ElectricityTariffOption(32);
const ElectricityTariffOption ElectricityTariffOption::DOUBLE = ElectricityTariffOption(64);
const ElectricityTariffOption ElectricityTariffOption::TEMPO = ElectricityTariffOption(96);

ElectricityTariffOption ElectricityTariffOption::valueOf(int value)
{
    return ElectricityTariffOption(value);
}

int ElectricityTariffOption::toInt() const
{
    return m_value;
}

const std::string& ElectricityTariffOption::toString() const
{
	return m_name;
}

bool ElectricityTariffOption::operator==(const ElectricityTariffOption &other) const {
	return (m_value == other.toInt());
}

bool ElectricityTariffOption::operator!=(const ElectricityTariffOption &other) const {
	return !(*this == other);
}
}
