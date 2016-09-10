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

#ifndef CORETEMPERATURERESPONSE_H
#define CORETEMPERATURERESPONSE_H

#include "control/CoreResponse.h"
#include "sensor/TemperatureResponse.h"

namespace deltadoreX2d
{

class CoreTemperatureResponse : public CoreResponse, public virtual TemperatureResponse
{
    public :
        CoreTemperatureResponse(const Temperature& _temperature);
        ~CoreTemperatureResponse();

		const Temperature& getTemperature() const;
		bool instanceOf(ResponseClass type) const;
		Response* clone() const;
		void* derived();

    private :
        Temperature m_temperature;
};
}

#endif // CORETEMPERATURERESPONSE_H
