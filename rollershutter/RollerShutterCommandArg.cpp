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

#include "rollershutter/RollerShutterCommandArg.h"

namespace deltadoreX2d
{

RollerShutterCommandArg::RollerShutterCommandArg(int value)
{
	m_value = value;
	if (value == 0) { m_name = "DOWN"; }
	else if (value == 100) { m_name = "UP"; }
	else if (value == 101) { m_name = "STOP"; }
	else if (value == 102) { m_name = "UP_SLOW"; }
	else if (value == 103) { m_name = "DOWN_SLOW"; }
	else if (value == 104) { m_name = "GO_FAVORITE_1"; }
	else if (value == 105) { m_name = "CHECK_MASTER_IDENTITY"; }
	else if (value == 106) { m_name = "ALARM_PAIRING"; }
	else if (value == 107) { m_name = "GO_FAVORITE_2"; }
	else if (value == 108) { m_name = "TOGGLE"; }
	else if (value == 109) { m_name = "STAND_OUT"; }
	else if (value == 110) { m_name = "NA"; }
	else if (value > 0 && value < 100) { m_name = value + "%"; }
	else { throw X2dException("Invalid argument => RollerShutterCommandArg::RollerShutterCommandArg(int value)"); }
}

RollerShutterCommandArg::~RollerShutterCommandArg()
{
    //
}

const RollerShutterCommandArg RollerShutterCommandArg::DOWN =RollerShutterCommandArg(0);
const RollerShutterCommandArg RollerShutterCommandArg::UP = RollerShutterCommandArg(100);
const RollerShutterCommandArg RollerShutterCommandArg::STOP = RollerShutterCommandArg(101);
const RollerShutterCommandArg RollerShutterCommandArg::UP_SLOW = RollerShutterCommandArg(102);
const RollerShutterCommandArg RollerShutterCommandArg::DOWN_SLOW = RollerShutterCommandArg(103);
const RollerShutterCommandArg RollerShutterCommandArg::GO_FAVORITE_1 = RollerShutterCommandArg(104);
const RollerShutterCommandArg RollerShutterCommandArg::CHECK_MASTER_IDENTITY = RollerShutterCommandArg(105);
const RollerShutterCommandArg RollerShutterCommandArg::ALARM_PAIRING = RollerShutterCommandArg(106);
const RollerShutterCommandArg RollerShutterCommandArg::GO_FAVORITE_2 = RollerShutterCommandArg(107);
const RollerShutterCommandArg RollerShutterCommandArg::TOGGLE = RollerShutterCommandArg(108);
const RollerShutterCommandArg RollerShutterCommandArg::STAND_OUT = RollerShutterCommandArg(109);
const RollerShutterCommandArg RollerShutterCommandArg::NA = RollerShutterCommandArg(110);

RollerShutterCommandArg RollerShutterCommandArg::valueOf(int value)
{
    return RollerShutterCommandArg(value);
}

RollerShutterCommandArg RollerShutterCommandArg::percent(int value)
{
    if (value >= 0 && value <= 100)
    {
        return RollerShutterCommandArg(value);
    }
	throw X2dException("Invalid argument => RollerShutterCommandArg::percent(int value)");
}

int RollerShutterCommandArg::toInt() const
{
    return m_value;
}

const std::string& RollerShutterCommandArg::toString() const
{
	return m_name;
}

bool RollerShutterCommandArg::instanceOf(ArgClass type) const
{
	if (type == RollerShutterCommandArg_t) { return true; }
	return false;
}

NodeArg* RollerShutterCommandArg::clone() const
{
	return new RollerShutterCommandArg(*this);
}

void* RollerShutterCommandArg::derived()
{
	return this;
}

bool RollerShutterCommandArg::operator==(const RollerShutterCommandArg &other) const {
	return (m_value == other.toInt());
}

bool RollerShutterCommandArg::operator!=(const RollerShutterCommandArg &other) const {
	return !(*this == other);
}
}
