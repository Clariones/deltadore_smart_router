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

#ifndef ALARMPRODUCTYPE_H
#define ALARMPRODUCTYPE_H

#include "requirement.h"

namespace deltadoreX2d
{

class AlarmProductType
{
    public :
        AlarmProductType(int value);
        ~AlarmProductType();

        static const AlarmProductType CENTRAL_UNIT;
        static const AlarmProductType CENTRAL_UNIT_WITH_TRANSMITTER;
        static const AlarmProductType TRANSMITTER ;
        static const AlarmProductType SIREN;
        static const AlarmProductType INTERNAL_SIREN;
        static const AlarmProductType EXTERNAL_SIREN;
        static const AlarmProductType COMMAND_PANEL;
        static const AlarmProductType CLRX_COMMAND_PANEL ;
        static const AlarmProductType CLIX_COMMAND_PANEL;
        static const AlarmProductType SIMPLE_COMMAND ;
        static const AlarmProductType SIMPLE_2KEYS_COMMAND;
        static const AlarmProductType SIMPLE_4KEYS_COMMAND;
        static const AlarmProductType SIMPLE_COMMAND_PANEL;
        static const AlarmProductType DISTRESS_MEDALLION;
        static const AlarmProductType VOLUMETRIC_SENSOR;
        static const AlarmProductType INFRARED_VOLUMETRIC_SENSOR;
        static const AlarmProductType PRESSURE_VOLUMETRIC_SENSOR ;
        static const AlarmProductType DUAL_VOLUMETRIC_SENSOR;
        static const AlarmProductType PERIMETRIC_SENSOR;
        static const AlarmProductType CONTACT_PERIMETRIC_SENSOR;
        static const AlarmProductType GLASS_BREAKAGE_PERIMETRIC_SENSOR ;
        static const AlarmProductType SOUND_PERIMETRIC_SENSOR;
        static const AlarmProductType ROLLER_SHUTTER_PERIMETRIC_SENSOR ;
        static const AlarmProductType TECHNICAL_SENSOR;
        static const AlarmProductType WATER_TECHNICAL_SENSOR;
        static const AlarmProductType GAS_TECHNICAL_SENSOR ;
        static const AlarmProductType FIRE_TECHNICAL_SENSOR;
        static const AlarmProductType SMOKE_TECHNICAL_SENSOR;
        static const AlarmProductType FROST_TECHNICAL_SENSOR;
        static const AlarmProductType POWER_OUTAGE_TECHNICAL_SENSOR;
        static const AlarmProductType PHONE_OUTAGE_TECHNICAL_SENSOR;
        static const AlarmProductType FREEZER_OUTAGE_TECHNICAL_SENSOR;
        static AlarmProductType valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const AlarmProductType &other) const;
		bool operator!=(const AlarmProductType &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* ALARMPRODUCTYPE_H */
