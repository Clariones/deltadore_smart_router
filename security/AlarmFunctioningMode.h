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
** mleforestier        | 092410           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef ALARMFUNCTIONINGMODE_H
#define ALARMFUNCTIONINGMODE_H

#include "requirement.h"

namespace deltadoreX2d
{

class AlarmFunctioningMode
{
    public :
        AlarmFunctioningMode(int value);
        ~AlarmFunctioningMode();

        static const AlarmFunctioningMode DISARMED;
        static const AlarmFunctioningMode FULLY_ARMED;
        static const AlarmFunctioningMode PARTIALLY_ARMED1;
        static const AlarmFunctioningMode PARTIALLY_ARMED2;
        static const AlarmFunctioningMode PARTIALLY_ARMED3;
        static const AlarmFunctioningMode PARTIALLY_ARMED4;
        static const AlarmFunctioningMode PARTIALLY_ARMED5;
        static const AlarmFunctioningMode PARTIALLY_ARMED6;
        static const AlarmFunctioningMode PARTIALLY_ARMED7;
        static const AlarmFunctioningMode PARTIALLY_ARMED8;
        static const AlarmFunctioningMode PERIMETER_ARMED;
        static const AlarmFunctioningMode TEST_MODE;
        static const AlarmFunctioningMode MAINTENANCE_MODE;
        static AlarmFunctioningMode valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const AlarmFunctioningMode &other) const;
		bool operator!=(const AlarmFunctioningMode &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* ALARMFUNCTIONINGMODE_H */
