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

#ifndef RESPONSE_H
#define RESPONSE_H

#include "control/ResponseStatus.h"

namespace deltadoreX2d
{

class CoreResponse;

typedef enum
{
	CurrentConsumptionResponse_t = 0X00,
	DiagnosticOverheatingResponse_t,
	EnergyConsumptionResponse_t,
	LightColorResponse_t,
	LightInfoResponse_t,
	LightStatusResponse_t,
	PowerConsumptionResponse_t,
	RollerShutterInfoResponse_t,
	RollerShutterStatusResponse_t,
	TemperatureInfoResponse_t,
	TemperatureResponse_t,
	ThermicDelayTimeResponse_t,
	ThermicInfoResponse_t,
	ThermicRegulationStatusResponse_t,
	ThermicSystemStatusResponse_t
} ResponseClass;

class Response
{
    public :
        virtual ~Response(){};

        virtual const ResponseStatus& getStatus() const=0;
		virtual bool instanceOf(ResponseClass type) const=0;
		virtual Response* clone() const=0;
		virtual void* derived()=0;

		template<class T> T convert() { return (T)this->derived(); }
};
}

#endif // RESPONSE_H
