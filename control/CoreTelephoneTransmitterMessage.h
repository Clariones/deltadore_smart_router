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

#ifndef CORETELEPHONETRANSMITTERMESSAGE_H
#define CORETELEPHONETRANSMITTERMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "security/TelephoneTransmitterMessage.h"

namespace deltadoreX2d
{

class CoreTelephoneTransmitterMessage : public CoreAlarmMessage, public virtual TelephoneTransmitterMessage
{
    public :
        CoreTelephoneTransmitterMessage();
        CoreTelephoneTransmitterMessage(const std::vector<byte>& frame);
        ~CoreTelephoneTransmitterMessage();

        Family getFamily() const;
		void setPriority(const MessagePriority& priority);
		void setDestinationAddress(int address);

        const TelephoneTransmitterStatus& getStatus() const;
        void setStatus(const TelephoneTransmitterStatus& status);
        bool isTelemonitoringFaulty() const;
        void setTelemonitoringFaulty(bool value);
        bool isTelephoneLineFaulty() const;
        void setTelephoneLineFaulty(bool value);
        bool isDoubtRemovalCurrent() const;
        void setDoubtRemovalCurrent(bool value);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        TelephoneTransmitterStatus m_status;
        bool m_isTelemonitoringFaulty;
        bool m_isTelephoneLineFaulty;
        bool m_isDoubtRemovalCurrent;
};
}

#endif /* CORETELEPHONETRANSMITTERMESSAGE_H */
