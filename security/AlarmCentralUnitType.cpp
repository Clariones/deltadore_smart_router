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

#include "security/AlarmCentralUnitType.h"

namespace deltadoreX2d
{

AlarmCentralUnitType::AlarmCentralUnitType(int value)
{
	m_value = value;
	if (value == 0) { m_name = "PRO"; }
	else if (value == 1) { m_name = "DIY"; }
	else { throw X2dException("Invalid argument => AlarmCentralUnitType::AlarmCentralUnitType(int value)"); }
}

AlarmCentralUnitType::~AlarmCentralUnitType()
{
	//
}

const AlarmCentralUnitType AlarmCentralUnitType::PRO  = AlarmCentralUnitType(0);
const AlarmCentralUnitType AlarmCentralUnitType::DIY  = AlarmCentralUnitType(1);

AlarmCentralUnitType AlarmCentralUnitType::valueOf(int value)
{
	return AlarmCentralUnitType(value);
}

int AlarmCentralUnitType::toInt() const
{
	return m_value;
}

const std::string& AlarmCentralUnitType::toString() const {
	return m_name;
}

bool AlarmCentralUnitType::operator==(const AlarmCentralUnitType &other) const {
	return (m_value == other.toInt());
}

bool AlarmCentralUnitType::operator!=(const AlarmCentralUnitType &other) const {
	return !(*this == other);
}
}
