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

#include "control/CoreRollerShutterInfoResponse.h"

namespace deltadoreX2d
{

CoreRollerShutterInfoResponse::CoreRollerShutterInfoResponse(int channelCount, const RollerShutterActuatorType& actuatorType) :
	CoreResponse(ResponseStatus::OK),
	m_channelCount(channelCount),
	m_actuatorType(actuatorType)
{
    //
}

CoreRollerShutterInfoResponse::~CoreRollerShutterInfoResponse()
{
    //
}

int CoreRollerShutterInfoResponse::getChannelCount() const
{
    return m_channelCount;
}

const RollerShutterActuatorType& CoreRollerShutterInfoResponse::getActuatorType() const
{
    return m_actuatorType;
}

bool CoreRollerShutterInfoResponse::instanceOf(ResponseClass type) const
{
	if (type == RollerShutterInfoResponse_t) { return true; }
	return false;
}

Response* CoreRollerShutterInfoResponse::clone() const
{
	return new CoreRollerShutterInfoResponse(*this);
}

void* CoreRollerShutterInfoResponse::derived()
{
	return (RollerShutterInfoResponse*)this;
}
}
