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

#include "light/LightActuatorType.h"

namespace deltadoreX2d
{

LightActuatorType::LightActuatorType(int value)
{
	m_value = value;
	if (value == 0) { m_name = "BINARY_STATE"; }
	else if (value == 1) { m_name = "STATEFULL"; }
	else if (value == 2) { m_name = "STATELESS"; }
	else { throw X2dException("Invalid argument => LightActuatorType::LightActuatorType(int value)"); }
}

LightActuatorType::~LightActuatorType()
{
    //
}

const LightActuatorType LightActuatorType::BINARY_STATE = LightActuatorType(0);
const LightActuatorType LightActuatorType::STATEFULL = LightActuatorType(1);
const LightActuatorType LightActuatorType::STATELESS = LightActuatorType(2);

LightActuatorType LightActuatorType::valueOf(int value)
{
    return LightActuatorType(value);
}

int LightActuatorType::toInt() const
{
    return m_value;
}

const std::string& LightActuatorType::toString() const
{
	return m_name;
}

bool LightActuatorType::operator==(const LightActuatorType &other) const {
	return (m_value == other.toInt());
}

bool LightActuatorType::operator!=(const LightActuatorType &other) const {
	return !(*this == other);
}
}
