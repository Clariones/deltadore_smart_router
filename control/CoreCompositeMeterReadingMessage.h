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

#ifndef CORECOMPOSITEMETERREADINGMESSAGE_H
#define CORECOMPOSITEMETERREADINGMESSAGE_H

#include "control/CoreDomesticMessage.h"
#include "metering/CompositeMeterReadingMessage.h"

namespace deltadoreX2d
{

class CoreCompositeMeterReadingMessage : public CoreDomesticMessage, public virtual CompositeMeterReadingMessage
{
    public :
        CoreCompositeMeterReadingMessage();
        CoreCompositeMeterReadingMessage(const std::vector<byte>& frame);
        ~CoreCompositeMeterReadingMessage();

        Family getFamily() const;

        const ElectricityTariffOption getTariffOption() const;
        void setTariffOption(const ElectricityTariffOption& option);
        const ElectricityTariff& getCurrentTariff() const;
        void setCurrentTariff(const ElectricityTariff& tariff);
		const CompositeRegisterSelection& getSelection() const;
		void setSelection(const CompositeRegisterSelection& selection);
        const RegisterUnit& getUnit() const;
        void setUnit(const RegisterUnit& unit);
		long getRegister1() const;
		void setRegister1(long value);
		long getRegister2() const;
		void setRegister2(long value);
		long getRegister3() const;
		void setRegister3(long value);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        ElectricityTariff m_tariff;
		CompositeRegisterSelection m_selection;
        RegisterUnit m_unit;
        long m_register1;
    	long m_register2;
    	long m_register3;
};
}

#endif // CORECOMPOSITEMETERREADINGMESSAGE_H
