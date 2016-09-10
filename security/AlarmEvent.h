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

#ifndef ALARMEVENT_H
#define ALARMEVENT_H

#include "requirement.h"

namespace deltadoreX2d
{

class AlarmEvent
{
    public :
        AlarmEvent(int value);
        ~AlarmEvent();

        static const AlarmEvent NONE ;
        static const AlarmEvent INTRUSION ;
        static const AlarmEvent SELF_PROTECTION_FAULT ;
        static const AlarmEvent DISTRESS ;
        static const AlarmEvent OPEN_ENTRANCE;
        static const AlarmEvent CLOSED_ENTRANCE;
        static const AlarmEvent DISCRETE_ALARM;
        static const AlarmEvent TECHNICAL_ALARM;
        static const AlarmEvent MONITORING_FAULT;
        static const AlarmEvent BATTERY_FAULT;
        static const AlarmEvent RADIO_FAULT;
        static const AlarmEvent PHONE_LINE_FAULT;
        static const AlarmEvent END_MONITORING_FAULT;
        static const AlarmEvent TELEMONITORING_FAULT ;
        static const AlarmEvent FIRE_ALARM;
        static const AlarmEvent DISARM ;
        static const AlarmEvent FULL_ARM;
        static const AlarmEvent PARTIAL_ARM1 ;
        static const AlarmEvent PARTIAL_ARM2 ;
        static const AlarmEvent PARTIAL_ARM3 ;
        static const AlarmEvent PARTIAL_ARM4;
        static const AlarmEvent PARTIAL_ARM5 ;
        static const AlarmEvent PARTIAL_ARM6;
        static const AlarmEvent PARTIAL_ARM7 ;
        static const AlarmEvent PARTIAL_ARM8 ;
        static const AlarmEvent PERIMETRIC_ARM ;
        static const AlarmEvent TEST_MODE;
        static const AlarmEvent MAINTENANCE_MODE;
        static const AlarmEvent FAULTS_ACKNOWLEDGMENT;
        static const AlarmEvent LOG_CLEARANCE;
        static const AlarmEvent NEW_PERIPHERAL;
        static const AlarmEvent PERIPHERAL_DELETION;
        static const AlarmEvent PERIPHERAL_EXCLUSION ;
        static const AlarmEvent PERIPHERAL_INSERTION ;
        static const AlarmEvent SELF_TEST_REQUEST;
        static const AlarmEvent DOOR_CHIME;
        static const AlarmEvent ENROLLMENT_DENY;
        static const AlarmEvent EXISTING_PERIPHERAL;
        static const AlarmEvent SETTING_PARTIAL_DETECTOR;
        static const AlarmEvent COMMAND_PERIPHERALS_DELETION ;
        static const AlarmEvent ALL_PERIPHERALS_DELETION ;
        static const AlarmEvent ALL_PERIPHERALS_DELETION_EXCEPT_SIREN ;
        static const AlarmEvent SETTING_TIME;
		static const AlarmEvent AUTO_ARM_FAULT ;
		static const AlarmEvent END_ALARM ;
		static const AlarmEvent AUTO_ARM_REQUEST;
        static const AlarmEvent SETTING_LABEL;
        static const AlarmEvent AUTOMATISM_COMMAND;
        static const AlarmEvent HEATING_COMMAND;
        static const AlarmEvent OUTGOING_CONNECTION_FAILURE;
        static const AlarmEvent INCOMING_VOICE_CALL;
        static const AlarmEvent INCOMING_DIGITAL_CALL;
        static const AlarmEvent SETTING_PHONE;
        static const AlarmEvent WRONG_ACCESS_CODE;
        static const AlarmEvent LOG_VIEWING;
        static const AlarmEvent OUTGOING_VOICE_CALL;
        static const AlarmEvent OUTGOING_DIGITAL_CALL;
        static const AlarmEvent END_INTRUSION;
        static const AlarmEvent END_SELF_PROTECTION_FAULT;
        static const AlarmEvent END_DISTRESS;
        static const AlarmEvent END_DISCRETE_ALARM;
        static const AlarmEvent END_TECHNICAL_ALARM;
        static const AlarmEvent END_BATTERY_FAULT;
        static const AlarmEvent END_RADIO_FAULT;
        static const AlarmEvent END_PHONE_LINE_FAULT;
        static const AlarmEvent END_TELEMONITORING_FAULT;
        static const AlarmEvent END_FIRE_ALARM;
        static AlarmEvent valueOf(int value);

        int toInt() const;
		const std::string& toString() const;

		bool operator==(const AlarmEvent &other) const;
		bool operator!=(const AlarmEvent &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* ALARMEVENT_H */
