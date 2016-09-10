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

#ifndef THERMICACTUATORTYPE_H
#define THERMICACTUATORTYPE_H

#include "requirement.h"

namespace deltadoreX2d
{

class ThermicActuatorType
{
	public :
		ThermicActuatorType(int value);
		~ThermicActuatorType();

		static const ThermicActuatorType SETPOINT;
		static const ThermicActuatorType HEAT_SETPOINT;
		static const ThermicActuatorType COOL_SETPOINT ;
		static const ThermicActuatorType HEAT_COOL_SETPOINT ;
		static const ThermicActuatorType LEVEL;
		static const ThermicActuatorType HEAT_LEVEL ;
		static const ThermicActuatorType COOL_LEVEL;
		static const ThermicActuatorType HEAT_COOL_LEVEL;
		static const ThermicActuatorType SWITCH ;
		static const ThermicActuatorType HEAT_SWITCH ;
		static const ThermicActuatorType COOL_SWITCH;
		static const ThermicActuatorType HEAT_COOL_SWITCH;
		static ThermicActuatorType valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const ThermicActuatorType &other) const;
		bool operator!=(const ThermicActuatorType &other) const;

	private :
		std::string m_name;
		int m_value;
};
}

#endif // THERMICACTUATORTYPE_H
