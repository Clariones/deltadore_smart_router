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
** mleforestier        | 041811           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreDiagnosticOverheatingResponse.h"

namespace deltadoreX2d
{

CoreDiagnosticOverheatingResponse::CoreDiagnosticOverheatingResponse(int temperature) :
	CoreResponse(ResponseStatus::OK),
	m_temperature(temperature)
{
	//
}

CoreDiagnosticOverheatingResponse::~CoreDiagnosticOverheatingResponse()
{
	//
}

int CoreDiagnosticOverheatingResponse::getTemperature() const
{
	return m_temperature;
}

bool CoreDiagnosticOverheatingResponse::instanceOf(ResponseClass type) const
{
	if (type == DiagnosticOverheatingResponse_t) { return true; }
	return false;
}

Response* CoreDiagnosticOverheatingResponse::clone() const
{
	return new CoreDiagnosticOverheatingResponse(*this);
}

void* CoreDiagnosticOverheatingResponse::derived()
{
	return (DiagnosticOverheatingResponse*)this;
}
}
