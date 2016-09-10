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

#include "control/CoreLightStatusResponse.h"

namespace deltadoreX2d
{

CoreLightStatusResponse::CoreLightStatusResponse(int level,
												bool isOverloadFaulty,
												bool isCommandFaulty,
												bool isOverheatingFaulty,
												bool isFavoritePosition,
												bool isPresenceDetected,
												bool isTwilight) :
	CoreResponse(ResponseStatus::OK),
	m_level(level),
	m_isOverloadFaulty(isOverloadFaulty),
	m_isOverheatingFaulty(isOverheatingFaulty),
	m_isFavoritePosition(isFavoritePosition),
	m_isPresenceDetected(isPresenceDetected),
	m_isTwilight(isTwilight)
{
    //
}

CoreLightStatusResponse::~CoreLightStatusResponse()
{
    //
}

int CoreLightStatusResponse::getLevel() const
{
    return m_level;
}

bool CoreLightStatusResponse::isOverloadFaulty() const
{
    return m_isOverloadFaulty;
}

bool CoreLightStatusResponse::isCommandFaulty() const
{
    return m_isCommandFaulty;
}

bool CoreLightStatusResponse::isOverheatingFaulty() const
{
    return m_isOverheatingFaulty;
}

bool CoreLightStatusResponse::isFavoritePosition() const
{
    return m_isFavoritePosition;
}

bool CoreLightStatusResponse::isPresenceDetected() const
{
    return m_isPresenceDetected;
}

bool CoreLightStatusResponse::isTwilight() const
{
    return m_isTwilight;
}

bool CoreLightStatusResponse::instanceOf(ResponseClass type) const
{
	if (type == LightStatusResponse_t) { return true; }
	return false;
}

Response* CoreLightStatusResponse::clone() const
{
	return new CoreLightStatusResponse(*this);
}

void* CoreLightStatusResponse::derived()
{
	return (LightStatusResponse*)this;
}
}
