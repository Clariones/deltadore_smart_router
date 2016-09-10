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

#include "hvac/ThermicAntiFrostAdjustmentArg.h"

namespace deltadoreX2d
{

ThermicAntiFrostAdjustmentArg::ThermicAntiFrostAdjustmentArg(int setpoint) : mSetpoint(setpoint)
{
	//
}

ThermicAntiFrostAdjustmentArg::~ThermicAntiFrostAdjustmentArg()
{
	//
}

int ThermicAntiFrostAdjustmentArg::getSetpoint() const
{
	return mSetpoint;
}

bool ThermicAntiFrostAdjustmentArg::instanceOf(ArgClass type) const
{
	if (type == ThermicAntiFrostAdjustmentArg_t) { return true; }
	return false;
}

NodeArg* ThermicAntiFrostAdjustmentArg::clone() const
{
	return new ThermicAntiFrostAdjustmentArg(*this);
}

void* ThermicAntiFrostAdjustmentArg::derived()
{
	return this;
}
}
