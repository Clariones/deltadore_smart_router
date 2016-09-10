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

#include "security/AlarmProductType.h"

namespace deltadoreX2d
{

AlarmProductType::AlarmProductType(int value)
{
	m_value = value;
	if (value == 0) { m_name = "CENTRAL_UNIT"; }
	else if (value == 1) { m_name = "CENTRAL_UNIT_WITH_TRANSMITTER"; }
	else if (value == 4) { m_name = "TRANSMITTER"; }
	else if (value == 8) { m_name = "SIREN"; }
	else if (value == 9) { m_name = "INTERNAL_SIREN"; }
	else if (value == 10) { m_name = "EXTERNAL_SIREN"; }
	else if (value == 12) { m_name = "COMMAND_PANEL"; }
	else if (value == 13) { m_name = "CLRX_COMMAND_PANEL"; }
	else if (value == 16) { m_name = "CLIX_COMMAND_PANEL"; }
	else if (value == 20) { m_name = "SIMPLE_COMMAND"; }
	else if (value == 21) { m_name = "SIMPLE_2KEYS_COMMAND"; }
	else if (value == 22) { m_name = "SIMPLE_4KEYS_COMMAND"; }
	else if (value == 23) { m_name = "SIMPLE_COMMAND_PANEL"; }
	else if (value == 28) { m_name = "DISTRESS_MEDALLION"; }
	else if (value == 32) { m_name = "VOLUMETRIC_SENSOR"; }
	else if (value == 33) { m_name = "INFRARED_VOLUMETRIC_SENSOR"; }
	else if (value == 34) { m_name = "PRESSURE_VOLUMETRIC_SENSOR"; }
	else if (value == 35) { m_name = "DUAL_VOLUMETRIC_SENSOR"; }
	else if (value == 40) { m_name = "PERIMETRIC_SENSOR"; }
	else if (value == 41) { m_name = "CONTACT_PERIMETRIC_SENSOR"; }
	else if (value == 42) { m_name = "GLASS_BREAKAGE_PERIMETRIC_SENSOR"; }
	else if (value == 43) { m_name = "SOUND_PERIMETRIC_SENSOR"; }
	else if (value == 44) { m_name = "ROLLER_SHUTTER_PERIMETRIC_SENSOR"; }
	else if (value == 48) { m_name = "TECHNICAL_SENSOR"; }
	else if (value == 49) { m_name = "WATER_TECHNICAL_SENSOR"; }
	else if (value == 50) { m_name = "GAS_TECHNICAL_SENSOR"; }
	else if (value == 51) { m_name = "FIRE_TECHNICAL_SENSOR"; }
	else if (value == 52) { m_name = "SMOKE_TECHNICAL_SENSOR"; }
	else if (value == 53) { m_name = "FROST_TECHNICAL_SENSOR"; }
	else if (value == 54) { m_name = "POWER_OUTAGE_TECHNICAL_SENSOR"; }
	else if (value == 55) { m_name = "PHONE_OUTAGE_TECHNICAL_SENSOR"; }
	else if (value == 56) { m_name = "FREEZER_OUTAGE_TECHNICAL_SENSOR"; }
	else { 	m_name = "UNKNOWN"; }
}

AlarmProductType::~AlarmProductType()
{
    //
}

const AlarmProductType AlarmProductType::CENTRAL_UNIT = AlarmProductType(0);
const AlarmProductType AlarmProductType::CENTRAL_UNIT_WITH_TRANSMITTER = AlarmProductType(1);
const AlarmProductType AlarmProductType::TRANSMITTER = AlarmProductType(4);
const AlarmProductType AlarmProductType::SIREN = AlarmProductType(8);
const AlarmProductType AlarmProductType::INTERNAL_SIREN = AlarmProductType(9);
const AlarmProductType AlarmProductType::EXTERNAL_SIREN = AlarmProductType(10);
const AlarmProductType AlarmProductType::COMMAND_PANEL = AlarmProductType(12);
const AlarmProductType AlarmProductType::CLRX_COMMAND_PANEL = AlarmProductType(13);
const AlarmProductType AlarmProductType::CLIX_COMMAND_PANEL = AlarmProductType(16);
const AlarmProductType AlarmProductType::SIMPLE_COMMAND = AlarmProductType(20);
const AlarmProductType AlarmProductType::SIMPLE_2KEYS_COMMAND = AlarmProductType(21);
const AlarmProductType AlarmProductType::SIMPLE_4KEYS_COMMAND = AlarmProductType(22);
const AlarmProductType AlarmProductType::SIMPLE_COMMAND_PANEL = AlarmProductType(23);
const AlarmProductType AlarmProductType::DISTRESS_MEDALLION = AlarmProductType(28);
const AlarmProductType AlarmProductType::VOLUMETRIC_SENSOR = AlarmProductType(32);
const AlarmProductType AlarmProductType::INFRARED_VOLUMETRIC_SENSOR = AlarmProductType(33);
const AlarmProductType AlarmProductType::PRESSURE_VOLUMETRIC_SENSOR = AlarmProductType(34);
const AlarmProductType AlarmProductType::DUAL_VOLUMETRIC_SENSOR = AlarmProductType(35);
const AlarmProductType AlarmProductType::PERIMETRIC_SENSOR = AlarmProductType(40);
const AlarmProductType AlarmProductType::CONTACT_PERIMETRIC_SENSOR = AlarmProductType(41);
const AlarmProductType AlarmProductType::GLASS_BREAKAGE_PERIMETRIC_SENSOR = AlarmProductType(42);
const AlarmProductType AlarmProductType::SOUND_PERIMETRIC_SENSOR = AlarmProductType(43);
const AlarmProductType AlarmProductType::ROLLER_SHUTTER_PERIMETRIC_SENSOR = AlarmProductType(44);
const AlarmProductType AlarmProductType::TECHNICAL_SENSOR = AlarmProductType(48);
const AlarmProductType AlarmProductType::WATER_TECHNICAL_SENSOR = AlarmProductType(49);
const AlarmProductType AlarmProductType::GAS_TECHNICAL_SENSOR = AlarmProductType(50);
const AlarmProductType AlarmProductType::FIRE_TECHNICAL_SENSOR = AlarmProductType(51);
const AlarmProductType AlarmProductType::SMOKE_TECHNICAL_SENSOR = AlarmProductType(52);
const AlarmProductType AlarmProductType::FROST_TECHNICAL_SENSOR = AlarmProductType(53);
const AlarmProductType AlarmProductType::POWER_OUTAGE_TECHNICAL_SENSOR = AlarmProductType(54);
const AlarmProductType AlarmProductType::PHONE_OUTAGE_TECHNICAL_SENSOR = AlarmProductType(55);
const AlarmProductType AlarmProductType::FREEZER_OUTAGE_TECHNICAL_SENSOR = AlarmProductType(56);

AlarmProductType AlarmProductType::valueOf(int value)
{
    return AlarmProductType(value);
}

int AlarmProductType::toInt() const
{
    return m_value;
}

const std::string& AlarmProductType::toString() const
{
	return m_name;
}

bool AlarmProductType::operator==(const AlarmProductType &other) const {
	return (m_value == other.toInt());
}

bool AlarmProductType::operator!=(const AlarmProductType &other) const {
	return !(*this == other);
}
}
