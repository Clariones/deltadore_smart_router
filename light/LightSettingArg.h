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

#ifndef LIGHTSETTINGARG_H
#define LIGHTSETTINGARG_H

#include "requirement.h"
#include "control/NodeArg.h"

namespace deltadoreX2d
{

class LightSettingArg : public NodeArg
{
    public :
        LightSettingArg(int value);
        ~LightSettingArg();

        static const LightSettingArg SET_FAVORITE_1;
        static const LightSettingArg SET_FAVORITE_2;
        static LightSettingArg valueOf(int value);

        int toInt() const;
		const std::string& toString() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

		bool operator==(const LightSettingArg &other) const;
		bool operator!=(const LightSettingArg &other) const;

	private :
		std::string m_name;
		int m_value;
};
}

#endif /* LIGHTSETTINGARG_H */
