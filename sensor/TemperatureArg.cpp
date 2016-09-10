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

#include "sensor/TemperatureArg.h"

namespace deltadoreX2d
{

TemperatureArg::TemperatureArg(const Temperature& temperature) : m_temperature(temperature)
{
	//
}

TemperatureArg::~TemperatureArg()
{
	//
}

const Temperature& TemperatureArg::getTemperature() const
{
	return m_temperature;
}

bool TemperatureArg::instanceOf(ArgClass type) const
{
	if (type == TemperatureArg_t) { return true; }
	return false;
}

NodeArg* TemperatureArg::clone() const
{
	return new TemperatureArg(*this);
}

void* TemperatureArg::derived()
{
	return this;
}
}
