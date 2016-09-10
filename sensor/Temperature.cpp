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

#include "sensor/Temperature.h"

namespace deltadoreX2d
{

Temperature::Temperature(int value)
{
	m_value = value;
	if (value == -32768) { m_name = "UNKNOWN"; }
	else if (value == 32767) { m_name = "SHORT_CIRCUIT"; }
	else if (value == -32767) { m_name = "OPEN_CIRCUIT"; }
	else if (value > -32767 && value < 32767)
	{
		int fractionalPart = (int)(value % 100);
		if (fractionalPart < 10)
		{
			m_name = value/100 + ".0" + fractionalPart + std::string("°C");
		}
		else
		{
			m_name = value/100 + "." + fractionalPart + std::string("°C");
		}
	}
	else { throw X2dException("Invalid argument => Temperature::Temperature(int value)"); }
}

Temperature::~Temperature()
{
	//
}

const Temperature Temperature::UNKNOWN = Temperature(-32768);
const Temperature Temperature::SHORT_CIRCUIT = Temperature(32767);
const Temperature Temperature::OPEN_CIRCUIT = Temperature(-32767);

Temperature Temperature::valueOf(int value)
{
	return Temperature(value);
}

Temperature Temperature::fromHundredthsOfADegree(int value)
{
	if (value > -32767 && value < 32767)
	{
		return Temperature(value);
	}
	throw X2dException("Invalid argument => Temperature::fromHundredthsOfADegree(int value)");
}

int Temperature::toInt() const
{
	return m_value;
}

const std::string& Temperature::toString() const
{
	return m_name;
}

bool Temperature::operator==(const Temperature &other) const {
	return (m_value == other.toInt());
}

bool Temperature::operator!=(const Temperature &other) const {
	return !(*this == other);
}
}
