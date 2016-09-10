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

#ifndef THERMICFANSPEED_H
#define THERMICFANSPEED_H

#include "requirement.h"

namespace deltadoreX2d
{

class ThermicFanSpeed
{
	public :
		ThermicFanSpeed(int value);
		~ThermicFanSpeed();

		static const ThermicFanSpeed STOP;
		static const ThermicFanSpeed AUTO;
		static const ThermicFanSpeed LOW;
		static const ThermicFanSpeed MEDIUM ;
		static const ThermicFanSpeed HIGH;
		static const ThermicFanSpeed NA ;
		static ThermicFanSpeed valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const ThermicFanSpeed &other) const;
		bool operator!=(const ThermicFanSpeed &other) const;

	private :
		std::string m_name;
		int m_value;
};
}

#endif // THERMICFANSPEED_H
