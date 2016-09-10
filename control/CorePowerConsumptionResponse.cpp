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

#include "control/CorePowerConsumptionResponse.h"

namespace deltadoreX2d
{

CorePowerConsumptionResponse::CorePowerConsumptionResponse(int value) :
	CoreResponse(ResponseStatus::OK),
	m_value(value)
{
    //
}

CorePowerConsumptionResponse::~CorePowerConsumptionResponse()
{
    //
}

int CorePowerConsumptionResponse::getValue() const
{
    return m_value;
}

bool CorePowerConsumptionResponse::instanceOf(ResponseClass type) const
{
	if (type == PowerConsumptionResponse_t) { return true; }
	return false;
}

Response* CorePowerConsumptionResponse::clone() const
{
	return new CorePowerConsumptionResponse(*this);
}

void* CorePowerConsumptionResponse::derived()
{
	return (PowerConsumptionResponse*)this;
}
}
