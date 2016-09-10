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

#include "security/AlarmEvent.h"

namespace deltadoreX2d
{

AlarmEvent::AlarmEvent(int value)
{
	m_value = value;
	if (value == 0) { m_name = "NONE"; }
	else if (value == 1) { m_name = "INTRUSION"; }
	else if (value == 2) { m_name = "SELF_PROTECTION_FAULT"; }
	else if (value == 3) { m_name = "DISTRESS"; }
	else if (value == 4) { m_name = "OPEN_ENTRANCE"; }
	else if (value == 5) { m_name = "CLOSED_ENTRANCE"; }
	else if (value == 6) { m_name = "DISCRETE_ALARM"; }
	else if (value == 8) { m_name = "TECHNICAL_ALARM"; }
	else if (value == 9) { m_name = "MONITORING_FAULT"; }
	else if (value == 10) { m_name = "BATTERY_FAULT"; }
	else if (value == 11) { m_name = "RADIO_FAULT"; }
	else if (value == 12) { m_name = "PHONE_LINE_FAULT"; }
	else if (value == 13) { m_name = "END_MONITORING_FAULT"; }
	else if (value == 14) { m_name = "TELEMONITORING_FAULT"; }
	else if (value == 15) { m_name = "FIRE_ALARM"; }
	else if (value == 16) { m_name = "DISARM"; }
	else if (value == 17) { m_name = "FULL_ARM"; }
	else if (value == 18) { m_name = "PARTIAL_ARM1"; }
	else if (value == 19) { m_name = "PARTIAL_ARM2"; }
	else if (value == 20) { m_name = "PARTIAL_ARM3"; }
	else if (value == 21) { m_name = "PARTIAL_ARM4"; }
	else if (value == 22) { m_name = "PARTIAL_ARM5"; }
	else if (value == 23) { m_name = "PARTIAL_ARM6"; }
	else if (value == 24) { m_name = "PARTIAL_ARM7"; }
	else if (value == 25) { m_name = "PARTIAL_ARM8"; }
	else if (value == 26) { m_name = "PERIMETRIC_ARM"; }
	else if (value == 27) { m_name = "TEST_MODE"; }
	else if (value == 28) { m_name = "MAINTENANCE_MODE"; }
	else if (value == 32) { m_name = "FAULTS_ACKNOWLEDGMENT"; }
	else if (value == 33) { m_name = "LOG_CLEARANCE"; }
	else if (value == 34) { m_name = "NEW_PERIPHERAL"; }
	else if (value == 35) { m_name = "PERIPHERAL_DELETION"; }
	else if (value == 36) { m_name = "PERIPHERAL_EXCLUSION"; }
	else if (value == 37) { m_name = "PERIPHERAL_INSERTION"; }
	else if (value == 38) { m_name = "SELF_TEST_REQUEST"; }
	else if (value == 39) { m_name = "DOOR_CHIME"; }
	else if (value == 40) { m_name = "ENROLLMENT_DENY"; }
	else if (value == 41) { m_name = "EXISTING_PERIPHERAL"; }
	else if (value == 42) { m_name = "SETTING_PARTIAL_DETECTOR"; }
	else if (value == 43) { m_name = "COMMAND_PERIPHERALS_DELETION"; }
	else if (value == 44) { m_name = "ALL_PERIPHERALS_DELETION"; }
	else if (value == 45) { m_name = "ALL_PERIPHERALS_DELETION_EXCEPT_SIREN"; }
	else if (value == 46) { m_name = "SETTING_TIME"; }
	else if (value == 49) { m_name = "AUTO_ARM_FAULT"; }
	else if (value == 50) { m_name = "END_ALARM"; }
	else if (value == 51) { m_name = "AUTO_ARM_REQUEST"; }
	else if (value == 52) { m_name = "SETTING_LABEL"; }
	else if (value == 55) { m_name = "AUTOMATISM_COMMAND"; }
	else if (value == 56) { m_name = "HEATING_COMMAND"; }
	else if (value == 57) { m_name = "OUTGOING_CONNECTION_FAILURE"; }
	else if (value == 58) { m_name = "INCOMING_VOICE_CALL"; }
	else if (value == 59) { m_name = "INCOMING_DIGITAL_CALL"; }
	else if (value == 60) { m_name = "SETTING_PHONE"; }
	else if (value == 61) { m_name = "WRONG_ACCESS_CODE"; }
	else if (value == 62) { m_name = "LOG_VIEWING"; }
	else if (value == 68) { m_name = "OUTGOING_VOICE_CALL"; }
	else if (value == 69) { m_name = "OUTGOING_DIGITAL_CALL"; }
	else if (value == 110) { m_name = "END_INTRUSION"; }
	else if (value == 111) { m_name = "END_SELF_PROTECTION_FAULT"; }
	else if (value == 112) { m_name = "END_DISTRESS"; }
	else if (value == 113) { m_name = "END_DISCRETE_ALARM"; }
	else if (value == 114) { m_name = "END_TECHNICAL_ALARM"; }
	else if (value == 115) { m_name = "END_BATTERY_FAULT"; }
	else if (value == 116) { m_name = "END_RADIO_FAULT"; }
	else if (value == 117) { m_name = "END_PHONE_LINE_FAULT"; }
	else if (value == 118) { m_name = "END_TELEMONITORING_FAULT"; }
	else if (value == 119) { m_name = "END_FIRE_ALARM"; }
	else { throw X2dException("Invalid argument => AlarmEvent::AlarmEvent(int value)"); }
}

AlarmEvent::~AlarmEvent()
{
    //
}

const AlarmEvent AlarmEvent::NONE =  AlarmEvent(0);
const AlarmEvent AlarmEvent::INTRUSION =  AlarmEvent(1);
const AlarmEvent AlarmEvent::SELF_PROTECTION_FAULT =  AlarmEvent(2);
const AlarmEvent AlarmEvent::DISTRESS =  AlarmEvent(3);
const AlarmEvent AlarmEvent::OPEN_ENTRANCE =  AlarmEvent(4);
const AlarmEvent AlarmEvent::CLOSED_ENTRANCE =  AlarmEvent(5);
const AlarmEvent AlarmEvent::DISCRETE_ALARM =  AlarmEvent(6);
const AlarmEvent AlarmEvent::TECHNICAL_ALARM =  AlarmEvent(8);
const AlarmEvent AlarmEvent::MONITORING_FAULT =  AlarmEvent(9);
const AlarmEvent AlarmEvent::BATTERY_FAULT =  AlarmEvent(10);
const AlarmEvent AlarmEvent::RADIO_FAULT =  AlarmEvent(11);
const AlarmEvent AlarmEvent::PHONE_LINE_FAULT =  AlarmEvent(12);
const AlarmEvent AlarmEvent::END_MONITORING_FAULT =  AlarmEvent(13);
const AlarmEvent AlarmEvent::TELEMONITORING_FAULT =  AlarmEvent(14);
const AlarmEvent AlarmEvent::FIRE_ALARM =  AlarmEvent(15);
const AlarmEvent AlarmEvent::DISARM =  AlarmEvent(16);
const AlarmEvent AlarmEvent::FULL_ARM =  AlarmEvent(17);
const AlarmEvent AlarmEvent::PARTIAL_ARM1 =  AlarmEvent(18);
const AlarmEvent AlarmEvent::PARTIAL_ARM2 =  AlarmEvent(19);
const AlarmEvent AlarmEvent::PARTIAL_ARM3 =  AlarmEvent(20);
const AlarmEvent AlarmEvent::PARTIAL_ARM4 =  AlarmEvent(21);
const AlarmEvent AlarmEvent::PARTIAL_ARM5 =  AlarmEvent(22);
const AlarmEvent AlarmEvent::PARTIAL_ARM6 =  AlarmEvent(23);
const AlarmEvent AlarmEvent::PARTIAL_ARM7 =  AlarmEvent(24);
const AlarmEvent AlarmEvent::PARTIAL_ARM8 =  AlarmEvent(25);
const AlarmEvent AlarmEvent::PERIMETRIC_ARM =  AlarmEvent(26);
const AlarmEvent AlarmEvent::TEST_MODE =  AlarmEvent(27);
const AlarmEvent AlarmEvent::MAINTENANCE_MODE =  AlarmEvent(28);
const AlarmEvent AlarmEvent::FAULTS_ACKNOWLEDGMENT =  AlarmEvent(32);
const AlarmEvent AlarmEvent::LOG_CLEARANCE =  AlarmEvent(33);
const AlarmEvent AlarmEvent::NEW_PERIPHERAL =  AlarmEvent(34);
const AlarmEvent AlarmEvent::PERIPHERAL_DELETION =  AlarmEvent(35);
const AlarmEvent AlarmEvent::PERIPHERAL_EXCLUSION =  AlarmEvent(36);
const AlarmEvent AlarmEvent::PERIPHERAL_INSERTION =  AlarmEvent(37);
const AlarmEvent AlarmEvent::SELF_TEST_REQUEST =  AlarmEvent(38);
const AlarmEvent AlarmEvent::DOOR_CHIME =  AlarmEvent(39);
const AlarmEvent AlarmEvent::ENROLLMENT_DENY =  AlarmEvent(40);
const AlarmEvent AlarmEvent::EXISTING_PERIPHERAL =  AlarmEvent(41);
const AlarmEvent AlarmEvent::SETTING_PARTIAL_DETECTOR =  AlarmEvent(42);
const AlarmEvent AlarmEvent::COMMAND_PERIPHERALS_DELETION =  AlarmEvent(43);
const AlarmEvent AlarmEvent::ALL_PERIPHERALS_DELETION =  AlarmEvent(44);
const AlarmEvent AlarmEvent::ALL_PERIPHERALS_DELETION_EXCEPT_SIREN =  AlarmEvent(45);
const AlarmEvent AlarmEvent::SETTING_TIME =  AlarmEvent(46);
const AlarmEvent AlarmEvent::AUTO_ARM_FAULT = AlarmEvent(49);
const AlarmEvent AlarmEvent::END_ALARM = AlarmEvent(50);
const AlarmEvent AlarmEvent::AUTO_ARM_REQUEST = AlarmEvent(51);
const AlarmEvent AlarmEvent::SETTING_LABEL =  AlarmEvent(52);
const AlarmEvent AlarmEvent::AUTOMATISM_COMMAND =  AlarmEvent(55);
const AlarmEvent AlarmEvent::HEATING_COMMAND =  AlarmEvent(56);
const AlarmEvent AlarmEvent::OUTGOING_CONNECTION_FAILURE =  AlarmEvent(57);
const AlarmEvent AlarmEvent::INCOMING_VOICE_CALL =  AlarmEvent(58);
const AlarmEvent AlarmEvent::INCOMING_DIGITAL_CALL =  AlarmEvent(59);
const AlarmEvent AlarmEvent::SETTING_PHONE =  AlarmEvent(60);
const AlarmEvent AlarmEvent::WRONG_ACCESS_CODE =  AlarmEvent(61);
const AlarmEvent AlarmEvent::LOG_VIEWING =  AlarmEvent(62);
const AlarmEvent AlarmEvent::OUTGOING_VOICE_CALL =  AlarmEvent(68);
const AlarmEvent AlarmEvent::OUTGOING_DIGITAL_CALL =  AlarmEvent(69);
const AlarmEvent AlarmEvent::END_INTRUSION =  AlarmEvent(110);
const AlarmEvent AlarmEvent::END_SELF_PROTECTION_FAULT =  AlarmEvent(111);
const AlarmEvent AlarmEvent::END_DISTRESS =  AlarmEvent(112);
const AlarmEvent AlarmEvent::END_DISCRETE_ALARM =  AlarmEvent(113);
const AlarmEvent AlarmEvent::END_TECHNICAL_ALARM =  AlarmEvent(114);
const AlarmEvent AlarmEvent::END_BATTERY_FAULT =  AlarmEvent(115);
const AlarmEvent AlarmEvent::END_RADIO_FAULT =  AlarmEvent(116);
const AlarmEvent AlarmEvent::END_PHONE_LINE_FAULT =  AlarmEvent(117);
const AlarmEvent AlarmEvent::END_TELEMONITORING_FAULT =  AlarmEvent(118);
const AlarmEvent AlarmEvent::END_FIRE_ALARM =  AlarmEvent(119);

AlarmEvent AlarmEvent::valueOf(int value)
{
    return AlarmEvent(value);
}

int AlarmEvent::toInt() const
{
    return m_value;
}

const std::string& AlarmEvent::toString() const
{
	return m_name;
}

bool AlarmEvent::operator==(const AlarmEvent &other) const {
	return (m_value == other.toInt());
}

bool AlarmEvent::operator!=(const AlarmEvent &other) const {
	return !(*this == other);
}
}
