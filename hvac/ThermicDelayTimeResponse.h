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
** mleforestier        | 041811           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef THERMICDELAYTIMERESPONSE_H
#define THERMICDELAYTIMERESPONSE_H

#include "control/Response.h"
#include "hvac/ThermicDelayTime.h"

namespace deltadoreX2d
{

class ThermicDelayTimeResponse : public virtual Response
{
	public :
		virtual ~ThermicDelayTimeResponse(){};

		virtual const ThermicDelayTime& getDelayTime() const=0;
};
}

#endif // THERMICDELAYTIMERESPONSE_H
