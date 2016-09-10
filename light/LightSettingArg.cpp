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

#include "light/LightSettingArg.h"

namespace deltadoreX2d
{

LightSettingArg::LightSettingArg(int value)
{
	m_value = value;
	if (value == 0) { m_name = "SET_FAVORITE_1"; }
	else if (value == 1) { m_name = "SET_FAVORITE_2"; }
	else { throw X2dException("Invalid argument => LightSettingArg::LightSettingArg(int value)"); }
}

LightSettingArg::~LightSettingArg()
{
   //
}

const LightSettingArg LightSettingArg::SET_FAVORITE_1 = LightSettingArg(0);
const LightSettingArg LightSettingArg::SET_FAVORITE_2 = LightSettingArg(1);

LightSettingArg LightSettingArg::valueOf(int value)
{
    return LightSettingArg(value);
}

int LightSettingArg::toInt() const
{
    return m_value;
}

const std::string& LightSettingArg::toString() const
{
	return m_name;
}

bool LightSettingArg::instanceOf(ArgClass type) const
{
	if (type == LightSettingArg_t) { return true; }
	return false;
}

NodeArg* LightSettingArg::clone() const
{
	return new LightSettingArg(*this);
}

void* LightSettingArg::derived()
{
	return this;
}

bool LightSettingArg::operator==(const LightSettingArg &other) const {
	return (m_value == other.toInt());
}

bool LightSettingArg::operator!=(const LightSettingArg &other) const {
	return !(*this == other);
}
}
