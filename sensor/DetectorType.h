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

#ifndef DETECTORTYPE_H
#define DETECTORTYPE_H

#include "requirement.h"

namespace deltadoreX2d
{

class DetectorType
{
    public :
        DetectorType(int value);
        ~DetectorType();

        static const DetectorType VOLUMETRIC_SENSOR;
        static const DetectorType INFRARED_VOLUMETRIC_SENSOR;
        static const DetectorType PRESSURE_VOLUMETRIC_SENSOR ;
        static const DetectorType DUAL_VOLUMETRIC_SENSOR;
        static const DetectorType PERIMETRIC_SENSOR;
        static const DetectorType CONTACT_PERIMETRIC_SENSOR;
        static const DetectorType GLASS_BREAKAGE_PERIMETRIC_SENSOR;
        static const DetectorType SOUND_PERIMETRIC_SENSOR;
        static const DetectorType ROLLER_SHUTTER_PERIMETRIC_SENSOR;
        static const DetectorType TECHNICAL_SENSOR;
        static const DetectorType WATER_TECHNICAL_SENSOR;
        static const DetectorType GAS_TECHNICAL_SENSOR;
        static const DetectorType FIRE_TECHNICAL_SENSOR;
        static const DetectorType SMOKE_TECHNICAL_SENSOR;
        static const DetectorType FROST_TECHNICAL_SENSOR;
        static const DetectorType POWER_OUTAGE_TECHNICAL_SENSOR ;
        static const DetectorType PHONE_OUTAGE_TECHNICAL_SENSOR;
        static const DetectorType FREEZER_OUTAGE_TECHNICAL_SENSOR;
        static DetectorType valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const DetectorType &other) const;
		bool operator!=(const DetectorType &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* DETECTORTYPE_H */
