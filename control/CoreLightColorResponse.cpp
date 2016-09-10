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

#include "control/CoreLightColorResponse.h"

namespace deltadoreX2d
{

CoreLightColorResponse::CoreLightColorResponse(int red, int green, int blue) :
	CoreResponse(ResponseStatus::OK),
	m_red(red),
	m_green(green),
	m_blue(blue)
{
	//
}

CoreLightColorResponse::~CoreLightColorResponse()
{
    //
}

int CoreLightColorResponse::getRedValue() const
{
    return m_red;
}

int CoreLightColorResponse::getGreenValue() const
{
    return m_green;
}

int CoreLightColorResponse::getBlueValue() const
{
    return m_blue;
}

bool CoreLightColorResponse::instanceOf(ResponseClass type) const
{
	if (type == LightColorResponse_t) { return true; }
	return false;
}

Response* CoreLightColorResponse::clone() const
{
	return new CoreLightColorResponse(*this);
}

void* CoreLightColorResponse::derived()
{
	return (LightColorResponse*)this;
}
}
