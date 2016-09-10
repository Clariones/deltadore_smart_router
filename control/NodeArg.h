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

#ifndef NODEARG_H
#define NODEARG_H

#include "requirement.h"

namespace deltadoreX2d
{

typedef enum
{
    CommonSettingArg_t = 0x00,
    LightColorArg_t,
    LightCommandArg_t,
    LightSettingArg_t,
    RollerShutterCommandArg_t,
    RollerShutterSettingArg_t,
    TemperatureArg_t,
    ThermicAntiFrostAdjustmentArg_t,
    ThermicDelayTimeArg_t,
    ThermicRegulationCommandArg_t,
    ThermicSettingArg_t,
    ThermicSystemCommandArg_t
} ArgClass;

class NodeArg
{
    public :
		NodeArg();
		NodeArg(bool none);
        virtual ~NodeArg();

		static const NodeArg NONE;

		virtual bool instanceOf(ArgClass type) const;
		virtual NodeArg* clone() const;
		virtual void* derived();
		
		bool operator==(const NodeArg &other) const;
		bool operator!=(const NodeArg &other) const;

		template<class T> T convert() { return (T)this->derived(); }

	private:
		bool m_none;
};
}

#endif // NODEARG_H
