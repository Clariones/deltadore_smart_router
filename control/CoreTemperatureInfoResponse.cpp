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

#include "control/CoreTemperatureInfoResponse.h"

namespace deltadoreX2d
{

CoreTemperatureInfoResponse::CoreTemperatureInfoResponse(int channelCount) :
	CoreResponse(ResponseStatus::OK),
	m_channelCount(channelCount)
{
	//
}

CoreTemperatureInfoResponse::~CoreTemperatureInfoResponse()
{
	//
}

int CoreTemperatureInfoResponse::getChannelCount() const
{
	return m_channelCount;
}

bool CoreTemperatureInfoResponse::instanceOf(ResponseClass type) const
{
	if (type == TemperatureInfoResponse_t) { return true; }
	return false;
}

Response* CoreTemperatureInfoResponse::clone() const
{
	return new CoreTemperatureInfoResponse(*this);
}

void* CoreTemperatureInfoResponse::derived()
{
	return (TemperatureInfoResponse*)this;
}
}
