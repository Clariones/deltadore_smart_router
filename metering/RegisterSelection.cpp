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

#include "metering/RegisterSelection.h"

namespace deltadoreX2d
{

RegisterSelection::RegisterSelection(int value)
{
	m_value = value;
	if (value == 0) { m_name = "CURRENT_TRANSFORMER1"; }
	else if (value == 1) { m_name = "CURRENT_TRANSFORMER2"; }
	else if (value == 2) { m_name = "CURRENT_TRANSFORMER3"; }
	else if (value == 3) { m_name = "HEATING"; }
	else if (value == 4) { m_name = "HOT_WATER"; }
	else if (value == 5) { m_name = "TOTAL"; }
	else if (value == 7) { m_name = "COOLING"; }
	else if (value == 8) { m_name = "HEATING_AND_COOLING"; }
	else if (value == 9) { m_name = "ELECTRICITY_PRODUCTION"; }
	else { throw X2dException("Invalid argument => RegisterSelection::RegisterSelection(int value)"); }
}

RegisterSelection::~RegisterSelection()
{
    //
}

const RegisterSelection RegisterSelection::CURRENT_TRANSFORMER1 = RegisterSelection(0);
const RegisterSelection RegisterSelection::CURRENT_TRANSFORMER2 = RegisterSelection(1);
const RegisterSelection RegisterSelection::CURRENT_TRANSFORMER3 = RegisterSelection(2);
const RegisterSelection RegisterSelection::HEATING = RegisterSelection(3);
const RegisterSelection RegisterSelection::HOT_WATER = RegisterSelection(4);
const RegisterSelection RegisterSelection::TOTAL = RegisterSelection(5);
const RegisterSelection RegisterSelection::COOLING = RegisterSelection(7);
const RegisterSelection RegisterSelection::HEATING_AND_COOLING = RegisterSelection(8);
const RegisterSelection RegisterSelection::ELECTRICITY_PRODUCTION = RegisterSelection(9);

RegisterSelection RegisterSelection::valueOf(int value)
{
    return RegisterSelection(value);
}

int RegisterSelection::toInt() const
{
    return m_value;
}

const std::string& RegisterSelection::toString() const
{
	return m_name;
}

bool RegisterSelection::operator==(const RegisterSelection &other) const {
	return (m_value == other.toInt());
}

bool RegisterSelection::operator!=(const RegisterSelection &other) const {
	return !(*this == other);
}
}
