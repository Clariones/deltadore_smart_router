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

#include "security/AlarmStatus.h"

namespace deltadoreX2d
{

AlarmStatus::AlarmStatus(int value)
{
	m_value = value;
	if (value == 0) { m_name = "QUIET"; }
	else if (value == 1) { m_name = "DELAYED"; }
	else if (value == 2) { m_name = "TRIGGERED"; }
	else if (value == 3) { m_name = "DISCRETE"; }
	else { throw X2dException("Invalid argument => AlarmStatus::AlarmStatus(int value)"); }
}

AlarmStatus::~AlarmStatus()
{
    //
}

const AlarmStatus AlarmStatus::QUIET = AlarmStatus(0);
const AlarmStatus AlarmStatus::DELAYED = AlarmStatus(1);
const AlarmStatus AlarmStatus::TRIGGERED = AlarmStatus(2);
const AlarmStatus AlarmStatus::DISCRETE = AlarmStatus(3);

AlarmStatus AlarmStatus::valueOf(int value)
{
	return AlarmStatus(value);
}

int AlarmStatus::toInt() const
{
    return m_value;
}

const std::string& AlarmStatus::toString() const
{
	return m_name;
}

bool AlarmStatus::operator==(const AlarmStatus &other) const {
	return (m_value == other.toInt());
}

bool AlarmStatus::operator!=(const AlarmStatus &other) const {
	return !(*this == other);
}
}
