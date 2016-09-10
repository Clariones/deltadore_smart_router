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

#ifndef ELECTRICITYTARIFF_H
#define ELECTRICITYTARIFF_H

#include "requirement.h"

namespace deltadoreX2d
{

class ElectricityTariff
{
    public :
        ElectricityTariff(int value);
        ~ElectricityTariff();

        static const ElectricityTariff UNKNOWN;
        static const ElectricityTariff BASE;
        static const ElectricityTariff EJP_OFF_PEAK_DAY;
        static const ElectricityTariff EJP_PEAK_DAY;
        static const ElectricityTariff EJP_CUMULATIVE;
        static const ElectricityTariff DOUBLE_OFF_PEAK_HOUR;
        static const ElectricityTariff DOUBLE_PEAK_HOUR;
        static const ElectricityTariff DOUBLE_CUMULATIVE;
        static const ElectricityTariff TEMPO_BLUE_DAY_OFF_PEAK_HOUR;
        static const ElectricityTariff TEMPO_BLUE_DAY_PEAK_HOUR;
        static const ElectricityTariff TEMPO_WHITE_DAY_OFF_PEAK_HOUR;
        static const ElectricityTariff TEMPO_WHITE_DAY_PEAK_HOUR;
        static const ElectricityTariff TEMPO_RED_DAY_OFF_PEAK_HOUR;
        static const ElectricityTariff TEMPO_RED_DAY_PEAK_HOUR;
        static const ElectricityTariff TEMPO_CUMULATIVE;
        static ElectricityTariff valueOf(int value);

        int toInt() const;
		const std::string& toString() const;

		bool operator==(const ElectricityTariff &other) const;
		bool operator!=(const ElectricityTariff &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* ELECTRICITYTARIFF_H */
