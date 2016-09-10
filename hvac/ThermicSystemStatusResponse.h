/**
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
** mleforestier        | 052511           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef THERMICSYSTEMSTATUSRESPONSE_H
#define THERMICSYSTEMSTATUSRESPONSE_H

#include "control/Response.h"
#include "hvac/ThermicSystemOutput.h"
#include "hvac/ThermicFanSpeed.h"
#include "hvac/ThermicPipeworkSupply.h"

namespace deltadoreX2d
{

class ThermicSystemStatusResponse : public virtual Response
{
	public :
		virtual ~ThermicSystemStatusResponse(){};

		virtual const ThermicSystemOutput& getOutput() const=0;
		virtual const ThermicFanSpeed& getFanSpeed() const=0;
		virtual const ThermicPipeworkSupply& getPipeworkSupply() const=0;
};
}

#endif // THERMICSYSTEMSTATUSRESPONSE_H
