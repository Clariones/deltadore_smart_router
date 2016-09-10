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
** mleforestier        | 041811           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreThermicDelayTimeResponse.h"

namespace deltadoreX2d
{

CoreThermicDelayTimeResponse::CoreThermicDelayTimeResponse(const ThermicDelayTime& delayTime) :
	CoreResponse(ResponseStatus::OK),
	m_delayTime(delayTime)
{
	//
}

CoreThermicDelayTimeResponse::~CoreThermicDelayTimeResponse()
{
	//
}

const ThermicDelayTime& CoreThermicDelayTimeResponse::getDelayTime() const
{
	return m_delayTime;
}

bool CoreThermicDelayTimeResponse::instanceOf(ResponseClass type) const
{
	if (type == ThermicDelayTimeResponse_t) { return true; }
	return false;
}

Response* CoreThermicDelayTimeResponse::clone() const
{
	return new CoreThermicDelayTimeResponse(*this);
}

void* CoreThermicDelayTimeResponse::derived()
{
	return (ThermicDelayTimeResponse*)this;
}
}
