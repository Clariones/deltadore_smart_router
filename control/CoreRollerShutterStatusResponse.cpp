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

#include "control/CoreRollerShutterStatusResponse.h"

namespace deltadoreX2d
{

CoreRollerShutterStatusResponse::CoreRollerShutterStatusResponse(int position,
																bool isRaisingFaulty,
																bool isLoweringFaulty,
																bool isObstacleFaulty,
																bool isOverheatingFaulty,
																bool isFavoritePosition,
																bool isIntrusionDetected) :
	CoreResponse(ResponseStatus::OK),
	m_position(position),
	m_isRaisingFaulty(isRaisingFaulty),
	m_isLoweringFaulty(isLoweringFaulty),
	m_isObstacleFaulty(isObstacleFaulty),
	m_isOverheatingFaulty(isOverheatingFaulty),
	m_isFavoritePosition(isFavoritePosition),
	m_isIntrusionDetected(isIntrusionDetected)
{
    //
}

CoreRollerShutterStatusResponse::~CoreRollerShutterStatusResponse()
{
    //
}

int CoreRollerShutterStatusResponse::getPosition() const
{
    return m_position;
}

bool CoreRollerShutterStatusResponse::isRaisingFaulty() const
{
    return m_isRaisingFaulty;
}

bool CoreRollerShutterStatusResponse::isLoweringFaulty() const
{
    return m_isLoweringFaulty;
}

bool CoreRollerShutterStatusResponse::isObstacleFaulty() const
{
    return m_isObstacleFaulty;
}

bool CoreRollerShutterStatusResponse::isOverheatingFaulty() const
{
    return m_isOverheatingFaulty;
}

bool CoreRollerShutterStatusResponse::isFavoritePosition() const
{
    return m_isFavoritePosition;
}

bool CoreRollerShutterStatusResponse::isIntrusionDetected() const
{
    return m_isIntrusionDetected;
}

bool CoreRollerShutterStatusResponse::instanceOf(ResponseClass type) const
{
	if (type == RollerShutterStatusResponse_t) { return true; }
	return false;
}

Response* CoreRollerShutterStatusResponse::clone() const
{
	return new CoreRollerShutterStatusResponse(*this);
}

void* CoreRollerShutterStatusResponse::derived()
{
	return (RollerShutterStatusResponse*)this;
}
}
