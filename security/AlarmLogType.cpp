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

#include "security/AlarmLogType.h"

namespace deltadoreX2d
{

AlarmLogType::AlarmLogType(int value)
{
	m_value = value;
	if (value == 0) { m_name = "ENTRANCE"; }
	else if (value == 1) { m_name = "UNACKNOWLEDGED"; }
	else if (value == 2) { m_name = "ARM_DISARM"; }
	else if (value == 3) { m_name = "ALL"; }
	else { throw X2dException("Invalid argument => AlarmLogType::AlarmLogType(int value)"); }
}

AlarmLogType::~AlarmLogType()
{
    //
}

const AlarmLogType AlarmLogType::ENTRANCE =AlarmLogType(0);
const AlarmLogType AlarmLogType::UNACKNOWLEDGED = AlarmLogType(1);
const AlarmLogType AlarmLogType::ARM_DISARM = AlarmLogType(2);
const AlarmLogType AlarmLogType::ALL = AlarmLogType(3);

AlarmLogType AlarmLogType::valueOf(int value)
{
    return AlarmLogType(value);
}

int AlarmLogType::toInt() const
{
    return m_value;
}

const std::string& AlarmLogType::toString() const
{
	return m_name;
}

bool AlarmLogType::operator==(const AlarmLogType &other) const {
	return (m_value == other.toInt());
}

bool AlarmLogType::operator!=(const AlarmLogType &other) const {
	return !(*this == other);
}
}
