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
** mleforestier        | 042611           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef HEATINGSETTING_H
#define HEATINGSETTING_H

#include "requirement.h"

namespace deltadoreX2d
{

class HeatingSetting
{
	public :
		HeatingSetting(int value);
		~HeatingSetting();

		static const HeatingSetting REDUCED;
		static const HeatingSetting MODERATO ;
		static const HeatingSetting MEDIO ;
		static const HeatingSetting COMFORT;
		static const HeatingSetting STOP;
		static const HeatingSetting ANTI_FROST;
		static const HeatingSetting SPECIAL;
		static const HeatingSetting AUTO;
		static const HeatingSetting CENTRALIZED;
		static HeatingSetting valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const HeatingSetting &other) const;
		bool operator!=(const HeatingSetting &other) const;

	private :
		std::string m_name;
		int m_value;
};
}

#endif // HEATINGSETTING_H
