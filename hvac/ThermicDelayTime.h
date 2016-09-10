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
** mleforestier        | 042611           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef THERMICDELAYTIME_H
#define THERMICDELAYTIME_H

#include "requirement.h"

namespace deltadoreX2d
{

class ThermicDelayTime
{
	public :
		ThermicDelayTime(int value);
		~ThermicDelayTime();

		static const ThermicDelayTime STOP;
		static const ThermicDelayTime INFINITE;
		static ThermicDelayTime valueOf(int value);
		static ThermicDelayTime fromSeconds(int value) ;

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const ThermicDelayTime &other) const;
		bool operator!=(const ThermicDelayTime &other) const;

	private :
		std::string m_name;
		int m_value;
};
}

#endif // THERMICDELAYTIME_H
