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

#ifndef THERMICSYSTEMMODE_H
#define THERMICSYSTEMMODE_H

#include "requirement.h"

namespace deltadoreX2d
{

class ThermicSystemMode
{
	public :
		ThermicSystemMode(int value);
		~ThermicSystemMode();

		static const ThermicSystemMode STOP;
		static const ThermicSystemMode HEAT;
		static const ThermicSystemMode COOL;
		static const ThermicSystemMode AUTO;
		static const ThermicSystemMode NA;
		static ThermicSystemMode valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const ThermicSystemMode &other) const;
		bool operator!=(const ThermicSystemMode &other) const;

	private :
		std::string m_name;
		int m_value;
};
}

#endif // THERMICSYSTEMMODE_H
