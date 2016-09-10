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

#ifndef CORETHERMICSYSTEMSTATUSRESPONSE_H
#define CORETHERMICSYSTEMSTATUSRESPONSE_H

#include "control/CoreResponse.h"
#include "hvac/ThermicSystemStatusResponse.h"

namespace deltadoreX2d
{

class CoreThermicSystemStatusResponse : public CoreResponse, public virtual ThermicSystemStatusResponse
{
    public :
        CoreThermicSystemStatusResponse(const ThermicSystemOutput& output,
										const ThermicFanSpeed& fanSpeed,
										const ThermicPipeworkSupply& pipeworkSupply);
        ~CoreThermicSystemStatusResponse();

		const ThermicFanSpeed& getFanSpeed() const;
		const ThermicSystemOutput& getOutput() const;
		const ThermicPipeworkSupply& getPipeworkSupply() const;
		bool instanceOf(ResponseClass type) const;
		Response* clone() const;
		void* derived();

    private :
        ThermicFanSpeed m_fanSpeed;
        ThermicSystemOutput m_output;
        ThermicPipeworkSupply m_pipeworkSupply;
};
}

#endif // CORETHERMICSYSTEMSTATUSRESPONSE_H
