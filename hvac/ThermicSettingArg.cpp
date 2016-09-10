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
** mleforestier        | 052311           | First version
** ylebret             | 280212           | refactoring
*/

#include "hvac/ThermicSettingArg.h"

namespace deltadoreX2d
{

ThermicSettingArg::ThermicSettingArg(int value)
{
	m_value = value;
	if (value == 0) { m_name = "ENABLE_ANTI_SEIZE"; }
	else if (value == 1) { m_name = "DISABLE_ANTI_SEIZE"; }
	else { throw X2dException("Invalid argument => ThermicSettingArg::ThermicSettingArg(int value)"); }
}

ThermicSettingArg::~ThermicSettingArg()
{
	//
}

const ThermicSettingArg ThermicSettingArg::ENABLE_ANTI_SEIZE = ThermicSettingArg(0);
const ThermicSettingArg ThermicSettingArg::DISABLE_ANTI_SEIZE = ThermicSettingArg(1);

ThermicSettingArg ThermicSettingArg::valueOf(int value)
{
	return ThermicSettingArg(value);
}

int ThermicSettingArg::toInt() const
{
	return m_value;
}

const std::string& ThermicSettingArg::toString() const
{
	return m_name;
}

bool ThermicSettingArg::instanceOf(ArgClass type) const
{
	if (type == ThermicSettingArg_t) { return true; }
	return false;
}

NodeArg* ThermicSettingArg::clone() const
{
	return new ThermicSettingArg(*this);
}

void* ThermicSettingArg::derived()
{
	return this;
}

bool ThermicSettingArg::operator==(const ThermicSettingArg &other) const {
	return (m_value == other.toInt());
}

bool ThermicSettingArg::operator!=(const ThermicSettingArg &other) const {
	return !(*this == other);
}
}
