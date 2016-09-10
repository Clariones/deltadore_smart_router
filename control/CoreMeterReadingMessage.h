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

#ifndef COREMETERREADINGMESSAGE_H
#define COREMETERREADINGMESSAGE_H

#include "control/CoreDomesticMessage.h"
#include "metering/MeterReadingMessage.h"

namespace deltadoreX2d
{

class CoreMeterReadingMessage : public CoreDomesticMessage, public virtual MeterReadingMessage
{
    public :
        CoreMeterReadingMessage();
        CoreMeterReadingMessage(const std::vector<byte>& frame);
        ~CoreMeterReadingMessage();


        Family getFamily() const;

        const ElectricityTariffOption getTariffOption() const;
        void setTariffOption(const ElectricityTariffOption& option);
        const ElectricityTariff& getCurrentTariff() const;
        void setCurrentTariff(const ElectricityTariff& tariff);
        const RegisterSelection& getSelection() const;
        void setSelection(const RegisterSelection& selection);
        const RegisterUnit& getUnit() const;
        void setUnit(const RegisterUnit& unit);
        long getRegister() const;
        void setRegister(long value);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        ElectricityTariff m_tariff;
        RegisterSelection m_selection;
        RegisterUnit m_unit;
        long m_register;
};
}

#endif /* COREMETERREADINGMESSAGE_H */
