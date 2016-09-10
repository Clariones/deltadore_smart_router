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

#ifndef THERMICHEATLEVEL_H
#define THERMICHEATLEVEL_H

#include "requirement.h"

namespace deltadoreX2d
{

class ThermicHeatLevel
{
	public :
		ThermicHeatLevel(int value);
		~ThermicHeatLevel();

		static const ThermicHeatLevel REDUCED;
		static const ThermicHeatLevel MODERATO;
		static const ThermicHeatLevel MEDIO;
		static const ThermicHeatLevel COMFORT;
		static const ThermicHeatLevel STOP;
		static const ThermicHeatLevel ANTI_FROST ;
		static const ThermicHeatLevel ON;
		static const ThermicHeatLevel OFF;
		static const ThermicHeatLevel NA ;
		static ThermicHeatLevel valueOf(int value);
		static ThermicHeatLevel setpoint(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const ThermicHeatLevel &other) const;
		bool operator!=(const ThermicHeatLevel &other) const;

	private :
		std::string m_name;
		int m_value;
};
}

#endif // THERMICHEATLEVEL_H
