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

#ifndef TEMPERATUREARG_H
#define TEMPERATUREARG_H

#include "control/NodeArg.h"
#include "sensor/Temperature.h"

namespace deltadoreX2d
{

class TemperatureArg : public NodeArg
{
	public :
		TemperatureArg(const Temperature& temperature);
		~TemperatureArg();

		const Temperature& getTemperature() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

	private :
		Temperature m_temperature;
};
}

#endif // TEMPERATUREARG_H

