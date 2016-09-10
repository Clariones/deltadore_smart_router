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

#include "rollershutter/RollerShutterSettingArg.h"

namespace deltadoreX2d
{

RollerShutterSettingArg::RollerShutterSettingArg(int value)
{
	m_value = value;
	if (value == 0) { m_name = "SET_FAVORITE_1"; }
	else if (value == 1) { m_name = "SET_UPPER_END"; }
	else if (value == 2) { m_name = "SET_LOWER_END"; }
	else if (value == 3) { m_name = "REVERSE_ROTATION"; }
	else if (value == 4) { m_name = "SET_OBSTACLE_LIMIT"; }
	else if (value == 5) { m_name = "TOGGLE_OBSTACLE"; }
	else if (value == 6) { m_name = "RESTORE_END_LIMITS"; }
	else if (value == 7) { m_name = "CLEAR_END_LIMITS_AND_ADDITIONAL_NET"; }
	else if (value == 8) { m_name = "CLEAR_END_LIMITS"; }
	else if (value == 9) { m_name = "TOGGLE_SOFT_APPROACH"; }
	else if (value == 10) { m_name = "ENABLE_ALL_REPETITIONS"; }
	else if (value == 11) { m_name = "DISABLE_ALL_REPETITIONS"; }
	else if (value == 12) { m_name = "ENABLE_UP_REPETITIONS"; }
	else if (value == 13) { m_name = "DISABLE_UP_REPETITIONS"; }
	else if (value == 14) { m_name = "ENABLE_DOWN_REPETITIONS"; }
	else if (value == 15) { m_name = "DISABLE_DOWN_REPETITIONS"; }
	else if (value == 16) { m_name = "ENABLE_GO_FAVORITE_REPETITIONS"; }
	else if (value == 17) { m_name = "DISABLE_GO_FAVORITE_REPETITIONS"; }
	else if (value == 18) { m_name = "TOGGLE_UP_REPETITIONS"; }
	else if (value == 19) { m_name = "TOGGLE_DOWN_REPETITIONS"; }
	else if (value == 20) { m_name = "TOGGLE_GO_FAVORITE_REPETITIONS"; }
	else if (value == 21) { m_name = "CHANGE_SECURITY_BEHAVIOUR"; }
	else if (value == 22) { m_name = "SET_FAVORITE_2"; }
	else { throw X2dException("Invalid argument => RollerShutterSettingArg::RollerShutterSettingArg(int value)"); }
}

RollerShutterSettingArg::~RollerShutterSettingArg()
{
    //
}

const RollerShutterSettingArg RollerShutterSettingArg::SET_FAVORITE_1 = RollerShutterSettingArg(0);
const RollerShutterSettingArg RollerShutterSettingArg::SET_UPPER_END = RollerShutterSettingArg(1);
const RollerShutterSettingArg RollerShutterSettingArg::SET_LOWER_END = RollerShutterSettingArg(2);
const RollerShutterSettingArg RollerShutterSettingArg::REVERSE_ROTATION = RollerShutterSettingArg(3);
const RollerShutterSettingArg RollerShutterSettingArg::SET_OBSTACLE_LIMIT = RollerShutterSettingArg(4);
const RollerShutterSettingArg RollerShutterSettingArg::TOGGLE_OBSTACLE = RollerShutterSettingArg(5);
const RollerShutterSettingArg RollerShutterSettingArg::RESTORE_END_LIMITS = RollerShutterSettingArg(6);
const RollerShutterSettingArg RollerShutterSettingArg::CLEAR_END_LIMITS_AND_ADDITIONAL_NET = RollerShutterSettingArg(7);
const RollerShutterSettingArg RollerShutterSettingArg::CLEAR_END_LIMITS = RollerShutterSettingArg(8);
const RollerShutterSettingArg RollerShutterSettingArg::TOGGLE_SOFT_APPROACH = RollerShutterSettingArg(9);
const RollerShutterSettingArg RollerShutterSettingArg::ENABLE_ALL_REPETITIONS = RollerShutterSettingArg(10);
const RollerShutterSettingArg RollerShutterSettingArg::DISABLE_ALL_REPETITIONS = RollerShutterSettingArg(11);
const RollerShutterSettingArg RollerShutterSettingArg::ENABLE_UP_REPETITIONS = RollerShutterSettingArg(12);
const RollerShutterSettingArg RollerShutterSettingArg::DISABLE_UP_REPETITIONS = RollerShutterSettingArg(13);
const RollerShutterSettingArg RollerShutterSettingArg::ENABLE_DOWN_REPETITIONS = RollerShutterSettingArg(14);
const RollerShutterSettingArg RollerShutterSettingArg::DISABLE_DOWN_REPETITIONS = RollerShutterSettingArg(15);
const RollerShutterSettingArg RollerShutterSettingArg::ENABLE_GO_FAVORITE_REPETITIONS = RollerShutterSettingArg(16);
const RollerShutterSettingArg RollerShutterSettingArg::DISABLE_GO_FAVORITE_REPETITIONS = RollerShutterSettingArg(17);
const RollerShutterSettingArg RollerShutterSettingArg::TOGGLE_UP_REPETITIONS = RollerShutterSettingArg(18);
const RollerShutterSettingArg RollerShutterSettingArg::TOGGLE_DOWN_REPETITIONS = RollerShutterSettingArg(19);
const RollerShutterSettingArg RollerShutterSettingArg::TOGGLE_GO_FAVORITE_REPETITIONS = RollerShutterSettingArg(20);
const RollerShutterSettingArg RollerShutterSettingArg::CHANGE_SECURITY_BEHAVIOUR = RollerShutterSettingArg(21);
const RollerShutterSettingArg RollerShutterSettingArg::SET_FAVORITE_2 = RollerShutterSettingArg(22);

RollerShutterSettingArg RollerShutterSettingArg::valueOf(int value)
{
    return RollerShutterSettingArg(value);
}

int RollerShutterSettingArg::toInt() const
{
    return m_value;
}

const std::string& RollerShutterSettingArg::toString() const
{
	return m_name;
}

bool RollerShutterSettingArg::instanceOf(ArgClass type) const
{
	if (type == RollerShutterSettingArg_t) { return true; }
	return false;
}

NodeArg* RollerShutterSettingArg::clone() const
{
	return new RollerShutterSettingArg(*this);
}

void* RollerShutterSettingArg::derived()
{
	return this;
}

bool RollerShutterSettingArg::operator==(const RollerShutterSettingArg &other) const {
	return (m_value == other.toInt());
}

bool RollerShutterSettingArg::operator!=(const RollerShutterSettingArg &other) const {
	return !(*this == other);
}
}
