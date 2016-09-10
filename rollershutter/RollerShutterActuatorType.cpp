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

#include "rollershutter/RollerShutterActuatorType.h"

namespace deltadoreX2d
{

RollerShutterActuatorType::RollerShutterActuatorType(int value)
{
	m_value = value;
	if (value == 0) { m_name = "TERNARY_STATE"; }
	else if (value == 1) { m_name = "STATEFULL"; }
	else if (value == 2) { m_name = "STATELESS"; }
	else { throw X2dException("Invalid argument => RollerShutterActuatorType::RollerShutterActuatorType(int value)"); }
}

RollerShutterActuatorType::~RollerShutterActuatorType()
{
    //
}

const RollerShutterActuatorType RollerShutterActuatorType::TERNARY_STATE = RollerShutterActuatorType(0);
const RollerShutterActuatorType RollerShutterActuatorType::STATEFULL = RollerShutterActuatorType(1);
const RollerShutterActuatorType RollerShutterActuatorType::STATELESS = RollerShutterActuatorType(2);

RollerShutterActuatorType RollerShutterActuatorType::valueOf(int value)
{
    return RollerShutterActuatorType(value);
}

int RollerShutterActuatorType::toInt() const
{
    return m_value;
}

const std::string& RollerShutterActuatorType::toString() const
{
	return m_name;
}

bool RollerShutterActuatorType::operator==(const RollerShutterActuatorType &other) const {
	return (m_value == other.toInt());
}

bool RollerShutterActuatorType::operator!=(const RollerShutterActuatorType &other) const {
	return !(*this == other);
}
}
