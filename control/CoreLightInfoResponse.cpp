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

#include "control/CoreLightInfoResponse.h"

namespace deltadoreX2d
{

CoreLightInfoResponse::CoreLightInfoResponse(int channelCount, const LightActuatorType& actuatorType, bool isMulticolor) :
	CoreResponse(ResponseStatus::OK),
	m_channelCount(channelCount),
	m_actuatorType(actuatorType),
	m_isMulticolor(isMulticolor)
{
    //
}

CoreLightInfoResponse::~CoreLightInfoResponse()
{
    //
}

int CoreLightInfoResponse::getChannelCount() const
{
    return m_channelCount;
}

const LightActuatorType& CoreLightInfoResponse::getActuatorType() const
{
    return m_actuatorType;
}

bool CoreLightInfoResponse::isMulticolor() const
{
    return m_isMulticolor;
}

bool CoreLightInfoResponse::instanceOf(ResponseClass type) const
{
	if (type == LightInfoResponse_t) { return true; }
	return false;
}

Response* CoreLightInfoResponse::clone() const
{
	return new CoreLightInfoResponse(*this);
}

void* CoreLightInfoResponse::derived()
{
	return (LightInfoResponse*)this;
}
}
