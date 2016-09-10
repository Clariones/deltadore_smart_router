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

#include "security/AlarmCommand.h"

namespace deltadoreX2d
{

AlarmCommand::AlarmCommand(int value)
{
	m_value = value;
	if (value == 0) { m_name = "DISARM"; }
	else if (value == 1) { m_name = "FULL_ARM"; }
	else if (value == 2) { m_name = "PARTIAL_ARM1"; }
	else if (value == 3) { m_name = "PARTIAL_ARM2"; }
	else if (value == 4) { m_name = "PARTIAL_ARM3"; }
	else if (value == 5) { m_name = "PARTIAL_ARM4"; }
	else if (value == 6) { m_name = "PARTIAL_ARM5"; }
	else if (value == 7) { m_name = "PARTIAL_ARM6"; }
	else if (value == 8) { m_name = "PARTIAL_ARM7"; }
	else if (value == 9) { m_name = "PARTIAL_ARM8"; }
	else if (value == 10) { m_name = "PERIMETRIC_ARM"; }
	else if (value == 11) { m_name = "DISCRETE_ALARM"; }
	else if (value == 12) { m_name = "MAINTENANCE_MODE"; }
	else if (value == 14) { m_name = "INHIBIT_FAULT"; }
	else if (value == 15) { m_name = "ACKNOWLEDGE_FAULTS"; }
	else if (value == 16) { m_name = "DELETE_LOG"; }
	else if (value == 17) { m_name = "SELF_TEST"; }
	else if (value == 18) { m_name = "ENABLE_AUTOMATIC_PROGRAM"; }
	else if (value == 19) { m_name = "DISABLE_AUTOMATIC_PROGRAM"; }
	else if (value == 28) { m_name = "AUTO_ARM"; }
	else if (value == 32) { m_name = "PHONE_SETTINGS"; }
	else if (value == 33) { m_name = "INVALID_CODE"; }
	else if (value == 34) { m_name = "VIEW_LOG"; }
	else if (value == 37) { m_name = "ENABLE_PREALARM"; }
	else if (value == 38) { m_name = "DISABLE_PREALARM"; }
	else if (value == 40) { m_name = "PREALARM_MENU"; }
	else if (value == 42) { m_name = "PREALARM_DELETION_MENU"; }
	else { throw X2dException("Invalid argument => AlarmCommand::AlarmCommand(int value)"); }
}

AlarmCommand::~AlarmCommand()
{
    //
}

const AlarmCommand AlarmCommand::DISARM =  AlarmCommand(0);
const AlarmCommand AlarmCommand::FULL_ARM =  AlarmCommand(1);
const AlarmCommand AlarmCommand::PARTIAL_ARM1 =  AlarmCommand(2);
const AlarmCommand AlarmCommand::PARTIAL_ARM2 =  AlarmCommand(3);
const AlarmCommand AlarmCommand::PARTIAL_ARM3 =  AlarmCommand(4);
const AlarmCommand AlarmCommand::PARTIAL_ARM4 =  AlarmCommand(5);
const AlarmCommand AlarmCommand::PARTIAL_ARM5 =  AlarmCommand(6);
const AlarmCommand AlarmCommand::PARTIAL_ARM6 =  AlarmCommand(7);
const AlarmCommand AlarmCommand::PARTIAL_ARM7 =  AlarmCommand(8);
const AlarmCommand AlarmCommand::PARTIAL_ARM8 =  AlarmCommand(9);
const AlarmCommand AlarmCommand::PERIMETRIC_ARM =  AlarmCommand(10);
const AlarmCommand AlarmCommand::DISCRETE_ALARM =  AlarmCommand(11);
const AlarmCommand AlarmCommand::MAINTENANCE_MODE =  AlarmCommand(12);
const AlarmCommand AlarmCommand::INHIBIT_FAULT = AlarmCommand(14);
const AlarmCommand AlarmCommand::ACKNOWLEDGE_FAULTS = AlarmCommand(15);
const AlarmCommand AlarmCommand::DELETE_LOG = AlarmCommand(16);
const AlarmCommand AlarmCommand::SELF_TEST = AlarmCommand(17);
const AlarmCommand AlarmCommand::ENABLE_AUTOMATIC_PROGRAM = AlarmCommand(18);
const AlarmCommand AlarmCommand::DISABLE_AUTOMATIC_PROGRAM = AlarmCommand(19);
const AlarmCommand AlarmCommand::AUTO_ARM = AlarmCommand(28);
const AlarmCommand AlarmCommand::PHONE_SETTINGS = AlarmCommand(32);
const AlarmCommand AlarmCommand::INVALID_CODE = AlarmCommand(33);
const AlarmCommand AlarmCommand::VIEW_LOG = AlarmCommand(34);
const AlarmCommand AlarmCommand::ENABLE_PREALARM = AlarmCommand(37);
const AlarmCommand AlarmCommand::DISABLE_PREALARM = AlarmCommand(38);
const AlarmCommand AlarmCommand::PREALARM_MENU = AlarmCommand(40);
const AlarmCommand AlarmCommand::PREALARM_DELETION_MENU = AlarmCommand(42);

AlarmCommand AlarmCommand::valueOf(int value)
{
	return AlarmCommand(value);
}

int AlarmCommand::toInt() const
{
    return m_value;
}

const std::string& AlarmCommand::toString() const
{
	return m_name;
}

bool AlarmCommand::operator==(const AlarmCommand &other) const {
	return (m_value == other.toInt());
}

bool AlarmCommand::operator!=(const AlarmCommand &other) const {
	return !(*this == other);
}
}
