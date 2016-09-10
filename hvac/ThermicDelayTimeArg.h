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

#ifndef THERMICDELAYTIMEARG_H
#define THERMICDELAYTIMEARG_H

#include "control/NodeArg.h"
#include "hvac/ThermicDelayTime.h"

namespace deltadoreX2d
{

class ThermicDelayTimeArg : public NodeArg
{
	public :
		ThermicDelayTimeArg(const ThermicDelayTime& delayTime);
		~ThermicDelayTimeArg();

		const ThermicDelayTime& getDelayTime() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

	private :
		ThermicDelayTime m_delayTime;
};
}

#endif // THERMICDELAYTIMEARG
