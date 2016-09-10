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
** mleforestier        | 052510           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreThermicSystemStatusResponse.h"

namespace deltadoreX2d
{

CoreThermicSystemStatusResponse::CoreThermicSystemStatusResponse(const ThermicSystemOutput& output,
																const ThermicFanSpeed& fanSpeed,
																const ThermicPipeworkSupply& pipeworkSupply) :
	CoreResponse(ResponseStatus::OK),
	m_output(output),
	m_fanSpeed(fanSpeed),
	m_pipeworkSupply(pipeworkSupply)
{
	//
}

CoreThermicSystemStatusResponse::~CoreThermicSystemStatusResponse()
{
	//
}


const ThermicSystemOutput& CoreThermicSystemStatusResponse::getOutput() const
{
	return m_output;
}

const ThermicFanSpeed& CoreThermicSystemStatusResponse::getFanSpeed() const
{
	return m_fanSpeed;
}

const ThermicPipeworkSupply& CoreThermicSystemStatusResponse::getPipeworkSupply() const
{
	return m_pipeworkSupply;
}

bool CoreThermicSystemStatusResponse::instanceOf(ResponseClass type) const
{
	if (type == ThermicSystemStatusResponse_t) { return true; }
	return false;
}

Response* CoreThermicSystemStatusResponse::clone() const
{
	return new CoreThermicSystemStatusResponse(*this);
}

void* CoreThermicSystemStatusResponse::derived()
{
	return (ThermicSystemStatusResponse*)this;
}
}
