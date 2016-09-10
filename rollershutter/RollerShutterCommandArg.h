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

#ifndef ROLLERSHUTTERCOMMANDARG_H
#define ROLLERSHUTTERCOMMANDARG_H

#include "requirement.h"
#include "control/NodeArg.h"

namespace deltadoreX2d
{

class RollerShutterCommandArg : public NodeArg
{
    public :
        RollerShutterCommandArg(int value);
        ~RollerShutterCommandArg();

        static const RollerShutterCommandArg DOWN;
        static const RollerShutterCommandArg UP;
        static const RollerShutterCommandArg STOP;
        static const RollerShutterCommandArg UP_SLOW;
        static const RollerShutterCommandArg DOWN_SLOW;
        static const RollerShutterCommandArg GO_FAVORITE_1;
        static const RollerShutterCommandArg CHECK_MASTER_IDENTITY;
        static const RollerShutterCommandArg ALARM_PAIRING;
		static const RollerShutterCommandArg GO_FAVORITE_2;
		static const RollerShutterCommandArg TOGGLE;
		static const RollerShutterCommandArg STAND_OUT;
		static const RollerShutterCommandArg NA;
        static RollerShutterCommandArg valueOf(int value);
        static RollerShutterCommandArg percent(int value);

		int toInt() const;
		const std::string& toString() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

		bool operator==(const RollerShutterCommandArg &other) const;
		bool operator!=(const RollerShutterCommandArg &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* ROLLERSHUTTERCOMMANDARG_H */
