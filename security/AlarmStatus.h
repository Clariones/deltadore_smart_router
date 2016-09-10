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

#ifndef ALARMSTATUS_H
#define ALARMSTATUS_H

#include "requirement.h"

namespace deltadoreX2d
{

class AlarmStatus
{
    public :
        AlarmStatus(int value);
        ~AlarmStatus();

        static const AlarmStatus QUIET;
        static const AlarmStatus DELAYED;
        static const AlarmStatus TRIGGERED;
        static const AlarmStatus DISCRETE;
        static AlarmStatus valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const AlarmStatus &other) const;
		bool operator!=(const AlarmStatus &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* ALARMSTATUS_H */
