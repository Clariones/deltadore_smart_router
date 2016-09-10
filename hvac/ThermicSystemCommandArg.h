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

#ifndef THERMICSYSTEMCOMMANDARG_H
#define THERMICSYSTEMCOMMANDARG_H

#include "control/NodeArg.h"
#include "hvac/ThermicSystemMode.h"
#include "hvac/ThermicFanMode.h"
#include "hvac/ThermicReheatingMode.h"

namespace deltadoreX2d
{

class ThermicSystemCommandArg : public NodeArg
{
	public :
		ThermicSystemCommandArg(const ThermicSystemMode& systemMode,
								const ThermicFanMode& fanMode,
								const ThermicReheatingMode& reheatingMode,
								bool isDehumidifying,
								bool isFreeCooling);
		~ThermicSystemCommandArg();

		const ThermicSystemMode& getSystemMode() const;
		const ThermicFanMode& getFanMode() const;
		const ThermicReheatingMode& getReheatingMode() const;
		bool isDehumidifying() const;
		bool isFreeCooling() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

	private :
		ThermicSystemMode m_systemMode;
		ThermicFanMode m_fanMode;
		ThermicReheatingMode m_reheatingMode;
		bool m_isDehumidifying;
		bool m_isFreeCooling;
};
}

#endif // THERMICSYSTEMCOMMANDARG_H
