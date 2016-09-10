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

#ifndef ALARMCOMMAND_H
#define ALARMCOMMAND_H

#include "requirement.h"

namespace deltadoreX2d
{

class AlarmCommand
{
    public :
        AlarmCommand(int value);
        ~AlarmCommand();

        static const AlarmCommand DISARM;
        static const AlarmCommand FULL_ARM;
        static const AlarmCommand PARTIAL_ARM1;
        static const AlarmCommand PARTIAL_ARM2;
        static const AlarmCommand PARTIAL_ARM3;
        static const AlarmCommand PARTIAL_ARM4;
        static const AlarmCommand PARTIAL_ARM5;
        static const AlarmCommand PARTIAL_ARM6;
        static const AlarmCommand PARTIAL_ARM7;
        static const AlarmCommand PARTIAL_ARM8;
        static const AlarmCommand PERIMETRIC_ARM;
        static const AlarmCommand DISCRETE_ALARM;
        static const AlarmCommand MAINTENANCE_MODE;
		static const AlarmCommand INHIBIT_FAULT ;
		static const AlarmCommand ACKNOWLEDGE_FAULTS;
		static const AlarmCommand DELETE_LOG ;
		static const AlarmCommand SELF_TEST ;
		static const AlarmCommand ENABLE_AUTOMATIC_PROGRAM ;
		static const AlarmCommand DISABLE_AUTOMATIC_PROGRAM;
		static const AlarmCommand AUTO_ARM ;
		static const AlarmCommand PHONE_SETTINGS;
		static const AlarmCommand INVALID_CODE ;
		static const AlarmCommand VIEW_LOG;
		static const AlarmCommand ENABLE_PREALARM;
		static const AlarmCommand DISABLE_PREALARM ;
		static const AlarmCommand PREALARM_MENU ;
		static const AlarmCommand PREALARM_DELETION_MENU;
		static AlarmCommand valueOf(int value);

        int toInt() const;
		const std::string& toString() const;

		bool operator==(const AlarmCommand &other) const;
		bool operator!=(const AlarmCommand &other) const;

    private :
        std::string m_name;
        int m_value;
};
}

#endif /* ALARMCOMMAND_H */
