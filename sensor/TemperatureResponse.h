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

#ifndef TEMPERATURERESPONSE_H
#define TEMPERATURERESPONSE_H

#include "control/Response.h"
#include "sensor/Temperature.h"

namespace deltadoreX2d
{

class TemperatureResponse : public virtual Response
{
	public :
		virtual ~TemperatureResponse(){};

		virtual const Temperature& getTemperature() const=0;
};
}

#endif // TEMPERATURERESPONSE_H
