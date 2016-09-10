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
** mleforestier        | 052511           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef THERMICREGULATIONCOMMANDARG_H
#define THERMICREGULATIONCOMMANDARG_H

#include "control/NodeArg.h"
#include "hvac/ThermicHeatLevel.h"
#include "hvac/ThermicRegulationMode.h"

namespace deltadoreX2d
{

class ThermicRegulationCommandArg : public NodeArg
{
	public :
		ThermicRegulationCommandArg(const ThermicHeatLevel& level,
									const ThermicRegulationMode& mode,
									bool isLevelTemporary);
		~ThermicRegulationCommandArg();

		const ThermicHeatLevel& getLevel() const;
		const ThermicRegulationMode& getMode() const;
		bool isLevelTemporary() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

	private :
		ThermicHeatLevel m_level;
		ThermicRegulationMode m_mode;
		bool m_isLevelTemporary;
};
}

#endif // THERMICREGULATIONCOMMANDARG_H
