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

#include "sensor/DetectorType.h"

namespace deltadoreX2d
{

DetectorType::DetectorType(int value)
{
	m_value = value;
	if (value == 32) { m_name = "VOLUMETRIC_SENSOR"; }
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
	else { throw X2dException("Invalid argument => DetectorType::DetectorType(int value)"); }
}

DetectorType::~DetectorType()
{
    //
}

const DetectorType DetectorType::VOLUMETRIC_SENSOR = DetectorType(32);
const DetectorType DetectorType::INFRARED_VOLUMETRIC_SENSOR = DetectorType(33);
const DetectorType DetectorType::PRESSURE_VOLUMETRIC_SENSOR = DetectorType(34);
const DetectorType DetectorType::DUAL_VOLUMETRIC_SENSOR = DetectorType(35);
const DetectorType DetectorType::PERIMETRIC_SENSOR = DetectorType(40);
const DetectorType DetectorType::CONTACT_PERIMETRIC_SENSOR = DetectorType(41);
const DetectorType DetectorType::GLASS_BREAKAGE_PERIMETRIC_SENSOR = DetectorType(42);
const DetectorType DetectorType::SOUND_PERIMETRIC_SENSOR =DetectorType(43);
const DetectorType DetectorType::ROLLER_SHUTTER_PERIMETRIC_SENSOR = DetectorType(44);
const DetectorType DetectorType::TECHNICAL_SENSOR = DetectorType(48);
const DetectorType DetectorType::WATER_TECHNICAL_SENSOR = DetectorType(49);
const DetectorType DetectorType::GAS_TECHNICAL_SENSOR = DetectorType(50);
const DetectorType DetectorType::FIRE_TECHNICAL_SENSOR = DetectorType(51);
const DetectorType DetectorType::SMOKE_TECHNICAL_SENSOR = DetectorType(52);
const DetectorType DetectorType::FROST_TECHNICAL_SENSOR = DetectorType(53);
const DetectorType DetectorType::POWER_OUTAGE_TECHNICAL_SENSOR = DetectorType(54);
const DetectorType DetectorType::PHONE_OUTAGE_TECHNICAL_SENSOR = DetectorType(55);
const DetectorType DetectorType::FREEZER_OUTAGE_TECHNICAL_SENSOR = DetectorType(56);

DetectorType DetectorType::valueOf(int value)
{
    return DetectorType(value);
}

int DetectorType::toInt() const
{
    return m_value;
}

const std::string& DetectorType::toString() const
{
	return m_name;
}

bool DetectorType::operator==(const DetectorType &other) const {
	return (m_value == other.toInt());
}

bool DetectorType::operator!=(const DetectorType &other) const {
	return !(*this == other);
}
}
