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
** mleforestier        | 041211           | First version
** ylebret             | 280212           | refactoring
*/

#include "common/CommonSettingArg.h"

namespace deltadoreX2d
{

CommonSettingArg::CommonSettingArg(int value)
{
	m_value = value;
	if (value == 0) { m_name = "DELETE_ALL_NET"; }
	else if (value == 1) { m_name = "AUTHORIZE_DELETION"; }
	else if (value == 2) { m_name = "DELETE_ADDITIONAL_NET"; }
	else if (value == 3) { m_name = "RESTORE_FACTORY_SETTINGS"; }
	else if (value == 4) { m_name = "REBOOT"; }
	else { throw X2dException("Invalid argument => CommonSettingArg::CommonSettingArg(int value)"); }
}

CommonSettingArg::~CommonSettingArg()
{
    //
}

const CommonSettingArg CommonSettingArg::DELETE_ALL_NET = CommonSettingArg(0);
const CommonSettingArg CommonSettingArg::AUTHORIZE_DELETION = CommonSettingArg(1);
const CommonSettingArg CommonSettingArg::DELETE_ADDITIONAL_NET = CommonSettingArg(2);
const CommonSettingArg CommonSettingArg::RESTORE_FACTORY_SETTINGS = CommonSettingArg(3);
const CommonSettingArg CommonSettingArg::REBOOT = CommonSettingArg(4);

CommonSettingArg CommonSettingArg::valueOf(int value)
{
    return CommonSettingArg(value);
}

int CommonSettingArg::toInt() const
{
    return m_value;
}

const std::string& CommonSettingArg::toString() const
{
	return m_name;
}

bool CommonSettingArg::instanceOf(ArgClass type) const
{
	if (type == CommonSettingArg_t) { return true; }
	return false;
}

NodeArg* CommonSettingArg::clone() const
{
	return new CommonSettingArg(*this);
}

void* CommonSettingArg::derived()
{
	return this;
}

bool CommonSettingArg::operator==(const CommonSettingArg &other) const {
	return (m_value == other.toInt());
}

bool CommonSettingArg::operator!=(const CommonSettingArg &other) const {
	return !(*this == other);
}
}
