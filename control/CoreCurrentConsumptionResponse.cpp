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
** mleforestier        | 060311           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreCurrentConsumptionResponse.h"

namespace deltadoreX2d
{

CoreCurrentConsumptionResponse::CoreCurrentConsumptionResponse(int value) :
	CoreResponse(ResponseStatus::OK),
	m_value(value)
{
    //
}

CoreCurrentConsumptionResponse::~CoreCurrentConsumptionResponse()
{
    //
}

int CoreCurrentConsumptionResponse::getValue() const
{
    return m_value;
}

bool CoreCurrentConsumptionResponse::instanceOf(ResponseClass type) const
{
	if (type == CurrentConsumptionResponse_t) { return true; }
	return false;
}

Response* CoreCurrentConsumptionResponse::clone() const
{
	return new CoreCurrentConsumptionResponse(*this);
}

void* CoreCurrentConsumptionResponse::derived()
{
	return (CurrentConsumptionResponse*)this;
}
}
