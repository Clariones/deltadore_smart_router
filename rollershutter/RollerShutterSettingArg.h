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

#ifndef ROLLERSHUTTERSETTINGARG_H
#define ROLLERSHUTTERSETTINGARG_H

#include "requirement.h"
#include "control/NodeArg.h"

namespace deltadoreX2d
{

class RollerShutterSettingArg : public NodeArg
{
    public :
        RollerShutterSettingArg(int value);
        ~RollerShutterSettingArg();

        static const RollerShutterSettingArg SET_FAVORITE_1;
        static const RollerShutterSettingArg SET_UPPER_END;
        static const RollerShutterSettingArg SET_LOWER_END;
		static const RollerShutterSettingArg REVERSE_ROTATION;
        static const RollerShutterSettingArg SET_OBSTACLE_LIMIT;
        static const RollerShutterSettingArg TOGGLE_OBSTACLE;
        static const RollerShutterSettingArg RESTORE_END_LIMITS;
        static const RollerShutterSettingArg CLEAR_END_LIMITS_AND_ADDITIONAL_NET;
        static const RollerShutterSettingArg CLEAR_END_LIMITS;
        static const RollerShutterSettingArg TOGGLE_SOFT_APPROACH;
        static const RollerShutterSettingArg ENABLE_ALL_REPETITIONS;
        static const RollerShutterSettingArg DISABLE_ALL_REPETITIONS;
        static const RollerShutterSettingArg ENABLE_UP_REPETITIONS;
        static const RollerShutterSettingArg DISABLE_UP_REPETITIONS;
        static const RollerShutterSettingArg ENABLE_DOWN_REPETITIONS;
        static const RollerShutterSettingArg DISABLE_DOWN_REPETITIONS;
        static const RollerShutterSettingArg ENABLE_GO_FAVORITE_REPETITIONS;
        static const RollerShutterSettingArg DISABLE_GO_FAVORITE_REPETITIONS;
        static const RollerShutterSettingArg TOGGLE_UP_REPETITIONS;
        static const RollerShutterSettingArg TOGGLE_DOWN_REPETITIONS;
        static const RollerShutterSettingArg TOGGLE_GO_FAVORITE_REPETITIONS;
        static const RollerShutterSettingArg CHANGE_SECURITY_BEHAVIOUR;
        static const RollerShutterSettingArg SET_FAVORITE_2;
        static RollerShutterSettingArg valueOf(int value);

		int toInt() const;
		const std::string& toString() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

		bool operator==(const RollerShutterSettingArg &other) const;
		bool operator!=(const RollerShutterSettingArg &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* ROLLERSHUTTERSETTINGARG_H */
