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
** mleforestier        | 052311           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef THERMICANTIFROSTADJUSTEMENTARG_H
#define THERMICANTIFROSTADJUSTEMENTARG_H

#include "control/NodeArg.h"

namespace deltadoreX2d
{

class ThermicAntiFrostAdjustmentArg : public NodeArg
{
	public :
		ThermicAntiFrostAdjustmentArg(int setpoint);
		~ThermicAntiFrostAdjustmentArg();

		int getSetpoint() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

	private :
		int mSetpoint;
};
}

#endif // THERMICANTIFROSTADJUSTEMENTARG_H
