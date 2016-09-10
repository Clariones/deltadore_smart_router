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

#ifndef TELEPHONETRANSMITTERMESSAGE_H
#define TELEPHONETRANSMITTERMESSAGE_H

#include "control/AlarmMessage.h"
#include "security/TelephoneTransmitterStatus.h"

namespace deltadoreX2d
{

class TelephoneTransmitterMessage : public virtual AlarmMessage
{
    public :
        virtual ~TelephoneTransmitterMessage(){};

        virtual const TelephoneTransmitterStatus& getStatus() const=0;
        virtual void setStatus(const TelephoneTransmitterStatus& status)=0;
        virtual bool isTelemonitoringFaulty() const=0;
        virtual void setTelemonitoringFaulty(bool value)=0;
        virtual bool isTelephoneLineFaulty() const=0;
        virtual void setTelephoneLineFaulty(bool value)=0;
        virtual bool isDoubtRemovalCurrent() const=0;
        virtual void setDoubtRemovalCurrent(bool value)=0;
};
}

#endif /* TELEPHONETRANSMITTERMESSAGE_H */
