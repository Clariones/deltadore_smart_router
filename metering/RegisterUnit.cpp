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

#include "metering/RegisterUnit.h"

namespace deltadoreX2d
{

RegisterUnit::RegisterUnit(int value)
{
	m_value = value;
	if (value == 0) { m_name = "KWH"; }
	else if (value == 1) { m_name = "EURO"; }
	else if (value == 2) { m_name = "WH"; }
	else { throw X2dException("Invalid argument => RegisterUnit::RegisterUnit(int value)"); }
}

RegisterUnit::~RegisterUnit()
{
    //
}

const RegisterUnit RegisterUnit::KWH = RegisterUnit(0);
const RegisterUnit RegisterUnit::EURO = RegisterUnit(1);
const RegisterUnit RegisterUnit::WH = RegisterUnit(2);

RegisterUnit RegisterUnit::valueOf(int value)
{
    return RegisterUnit(value);
}

int RegisterUnit::toInt() const
{
    return m_value;
}

const std::string& RegisterUnit::toString() const
{
	return m_name;
}

bool RegisterUnit::operator==(const RegisterUnit &other) const {
	return (m_value == other.toInt());
}

bool RegisterUnit::operator!=(const RegisterUnit &other) const {
	return !(*this == other);
}
}
