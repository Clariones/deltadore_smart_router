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

#include "metering/ElectricityTariff.h"

namespace deltadoreX2d
{

ElectricityTariff::ElectricityTariff(int value)
{
	m_value = value;
	if (value == 0) { m_name = "BASE"; }
	else if (value == 32) { m_name = "EJP_OFF_PEAK_DAY"; }
	else if (value == 33) { m_name = "EJP_PEAK_DAY"; }
	else if (value == 47) { m_name = "EJP_CUMULATIVE"; }
	else if (value == 64) { m_name = "DOUBLE_OFF_PEAK_HOUR"; }
	else if (value == 65) { m_name = "DOUBLE_PEAK_HOUR"; }
	else if (value == 79) { m_name = "DOUBLE_CUMULATIVE"; }
	else if (value == 96) { m_name = "TEMPO_BLUE_DAY_OFF_PEAK_HOUR"; }
	else if (value == 97) { m_name = "TEMPO_BLUE_DAY_PEAK_HOUR"; }
	else if (value == 98) { m_name = "TEMPO_WHITE_DAY_OFF_PEAK_HOUR"; }
	else if (value == 99) { m_name = "TEMPO_WHITE_DAY_PEAK_HOUR"; }
	else if (value == 100) { m_name = "TEMPO_RED_DAY_OFF_PEAK_HOUR"; }
	else if (value == 101) { m_name = "TEMPO_RED_DAY_PEAK_HOUR"; }
	else if (value == 111) { m_name = "TEMPO_CUMULATIVE"; }
	else { throw X2dException("Invalid argument => ElectricityTariff::ElectricityTariff(int value)"); }
}

ElectricityTariff::~ElectricityTariff()
{
    //
}

const ElectricityTariff ElectricityTariff::BASE =  ElectricityTariff(0);
const ElectricityTariff ElectricityTariff::EJP_OFF_PEAK_DAY =  ElectricityTariff(32);
const ElectricityTariff ElectricityTariff::EJP_PEAK_DAY =  ElectricityTariff(33);
const ElectricityTariff ElectricityTariff::EJP_CUMULATIVE =  ElectricityTariff(47);
const ElectricityTariff ElectricityTariff::DOUBLE_OFF_PEAK_HOUR =  ElectricityTariff(64);
const ElectricityTariff ElectricityTariff::DOUBLE_PEAK_HOUR =  ElectricityTariff(65);
const ElectricityTariff ElectricityTariff::DOUBLE_CUMULATIVE =  ElectricityTariff(79);
const ElectricityTariff ElectricityTariff::TEMPO_BLUE_DAY_OFF_PEAK_HOUR =  ElectricityTariff(96);
const ElectricityTariff ElectricityTariff::TEMPO_BLUE_DAY_PEAK_HOUR =  ElectricityTariff(97);
const ElectricityTariff ElectricityTariff::TEMPO_WHITE_DAY_OFF_PEAK_HOUR =  ElectricityTariff(98);
const ElectricityTariff ElectricityTariff::TEMPO_WHITE_DAY_PEAK_HOUR =  ElectricityTariff(99);
const ElectricityTariff ElectricityTariff::TEMPO_RED_DAY_OFF_PEAK_HOUR =  ElectricityTariff(100);
const ElectricityTariff ElectricityTariff::TEMPO_RED_DAY_PEAK_HOUR =  ElectricityTariff(101);
const ElectricityTariff ElectricityTariff::TEMPO_CUMULATIVE =  ElectricityTariff(111);

ElectricityTariff ElectricityTariff::valueOf(int value)
{
    return ElectricityTariff(value);
}

int ElectricityTariff::toInt() const
{
    return m_value;
}

const std::string& ElectricityTariff::toString() const
{
	return m_name;
}

bool ElectricityTariff::operator==(const ElectricityTariff &other) const {
	return (m_value == other.toInt());
}

bool ElectricityTariff::operator!=(const ElectricityTariff &other) const {
	return !(*this == other);
}
}
