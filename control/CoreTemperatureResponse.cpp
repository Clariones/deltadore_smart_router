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
** mleforestier        | 052310           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreTemperatureResponse.h"

namespace deltadoreX2d
{

CoreTemperatureResponse::CoreTemperatureResponse(const Temperature& temperature) :
	CoreResponse(ResponseStatus::OK),
	m_temperature(temperature)
{
	//
}

CoreTemperatureResponse::~CoreTemperatureResponse()
{
	//
}

const Temperature& CoreTemperatureResponse::getTemperature() const
{
	return m_temperature;
}

bool CoreTemperatureResponse::instanceOf(ResponseClass type) const
{
	if (type == TemperatureResponse_t) { return true; }
	return false;
}

Response* CoreTemperatureResponse::clone() const
{
	return new CoreTemperatureResponse(*this);
}

void* CoreTemperatureResponse::derived()
{
	return (TemperatureResponse*)this;
}
}
