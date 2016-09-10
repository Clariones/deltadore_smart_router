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

#ifndef CORETEMPERATUREMESSAGE_H
#define CORETEMPERATUREMESSAGE_H

#include "control/CoreDomesticMessage.h"
#include "sensor/TemperatureMessage.h"

namespace deltadoreX2d
{

class CoreTemperatureMessage : public CoreDomesticMessage, public virtual TemperatureMessage
{
    public :
        CoreTemperatureMessage();
        CoreTemperatureMessage(const std::vector<byte>& frame);
        ~CoreTemperatureMessage();

        Family getFamily() const;

        const TemperatureType& getType() const;
        void setType(const TemperatureType& type);
        virtual int getTemperature() const;
        void setTemperature(int value);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        TemperatureType m_type;
        int m_temperature;
};
}

#endif /* CORETEMPERATUREMESSAGE_H */
