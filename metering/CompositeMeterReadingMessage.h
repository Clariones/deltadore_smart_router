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

#ifndef COMPOSITEMETEREADINGMESSAGE_H
#define COMPOSITEMETEREADINGMESSAGE_H

#include "control/Message.h"
#include "metering/ElectricityTariffOption.h"
#include "metering/ElectricityTariff.h"
#include "metering/CompositeRegisterSelection.h"
#include "metering/RegisterUnit.h"

namespace deltadoreX2d
{

class CompositeMeterReadingMessage : public virtual Message
{
    public :
        virtual ~CompositeMeterReadingMessage(){};

        virtual const ElectricityTariffOption getTariffOption() const=0;
        virtual void setTariffOption(const ElectricityTariffOption& option)=0;
        virtual const ElectricityTariff& getCurrentTariff() const=0;
        virtual void setCurrentTariff(const ElectricityTariff& tariff)=0;
		virtual const CompositeRegisterSelection& getSelection() const=0;
		virtual void setSelection(const CompositeRegisterSelection& selection)=0;
        virtual const RegisterUnit& getUnit() const=0;
        virtual void setUnit(const RegisterUnit& unit)=0;
		virtual long getRegister1() const=0;
		virtual void setRegister1(long value)=0;
		virtual long getRegister2() const=0;
		virtual void setRegister2(long value)=0;
		virtual long getRegister3() const=0;
		virtual void setRegister3(long value)=0;
};
}

#endif /* COMPOSITEMETEREADINGMESSAGE_H */
