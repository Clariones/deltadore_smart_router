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

#ifndef LIGHTCOMMANDARG_H
#define LIGHTCOMMANDARG_H

#include "requirement.h"
#include "control/NodeArg.h"

namespace deltadoreX2d
{

class LightCommandArg : public NodeArg
{
    public :
        LightCommandArg(int value);
        ~LightCommandArg();

        static const LightCommandArg DOWN;
        static const LightCommandArg UP;
        static const LightCommandArg STOP;
        static const LightCommandArg UP_SLOW;
        static const LightCommandArg DOWN_SLOW;
        static const LightCommandArg GO_FAVORITE_1;
        static const LightCommandArg ALARM_PAIRING;
		static const LightCommandArg STAND_OUT;
		static const LightCommandArg GO_FAVORITE_2;
		static const LightCommandArg TOGGLE;
		static const LightCommandArg NA;
        static LightCommandArg valueOf(int value);
        static LightCommandArg percent(int value);

        int toInt() const;
		const std::string& toString() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

		bool operator==(const LightCommandArg &other) const;
		bool operator!=(const LightCommandArg &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* LIGHTCOMMANDARG_H */
