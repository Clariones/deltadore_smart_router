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

#ifndef THERMICFANMODE_H
#define THERMICFANMODE_H

#include "requirement.h"

namespace deltadoreX2d
{

class ThermicFanMode
{
	public :
		ThermicFanMode(int value);
		~ThermicFanMode();

		static const ThermicFanMode STOP;
		static const ThermicFanMode AUTO;
		static const ThermicFanMode LOW;
		static const ThermicFanMode MEDIUM ;
		static const ThermicFanMode HIGH;
		static const ThermicFanMode NA ;
		static ThermicFanMode valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const ThermicFanMode &other) const;
		bool operator!=(const ThermicFanMode &other) const;

	private :
		std::string m_name;
		int m_value;
};
}

#endif // THERMICFANMODE_H
