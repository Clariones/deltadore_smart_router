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
** mleforestier        | 042611           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreThermicInfoResponse.h"
#include "control/ResponseStatus.h"

namespace deltadoreX2d
{

CoreThermicInfoResponse::CoreThermicInfoResponse(int channelCount, const ThermicActuatorType& actuatorType) :
	CoreResponse(ResponseStatus::OK),
	m_channelCount(channelCount),
	m_actuatorType(actuatorType)
{
	//
}

CoreThermicInfoResponse::~CoreThermicInfoResponse()
{
	//
}

int CoreThermicInfoResponse::getChannelCount() const
{
	return m_channelCount;
}

const ThermicActuatorType& CoreThermicInfoResponse::getActuatorType() const
{
	return m_actuatorType;
}

bool CoreThermicInfoResponse::instanceOf(ResponseClass type) const
{
	if (type == ThermicInfoResponse_t) { return true; }
	return false;
}

Response* CoreThermicInfoResponse::clone() const
{
	return new CoreThermicInfoResponse(*this);
}

void* CoreThermicInfoResponse::derived()
{
	return (ThermicInfoResponse*)this;
}
}
