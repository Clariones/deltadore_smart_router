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

#include "control/CoreEnergyConsumptionResponse.h"

namespace deltadoreX2d
{

CoreEnergyConsumptionResponse::CoreEnergyConsumptionResponse(long value) :
	CoreResponse(ResponseStatus::OK),
	m_value(value)
{
    //
}

CoreEnergyConsumptionResponse::~CoreEnergyConsumptionResponse()
{
    //
}

long CoreEnergyConsumptionResponse::getValue() const
{
    return m_value;
}

bool CoreEnergyConsumptionResponse::instanceOf(ResponseClass type) const
{
	if (type == EnergyConsumptionResponse_t) { return true; }
	return false;
}

Response* CoreEnergyConsumptionResponse::clone() const
{
	return new CoreEnergyConsumptionResponse(*this);
}

void* CoreEnergyConsumptionResponse::derived()
{
	return (EnergyConsumptionResponse*)this;
}
}
