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

#ifndef COREDETECTIONMESSAGE_H
#define COREDETECTIONMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "sensor/DetectionMessage.h"

namespace deltadoreX2d
{

class CoreDetectionMessage : public CoreAlarmMessage, public virtual DetectionMessage
{
    public :
        CoreDetectionMessage();
        CoreDetectionMessage(const std::vector<byte>& frame);
        ~CoreDetectionMessage();

        Family getFamily() const;
        bool isInternalFaulty() const;
        void setInternalFaulty(bool value);
		void setPriority(const MessagePriority& priority);

        const DetectorType getDetectorType() const;
        void setDetectorType(const DetectorType& type);
        bool isTriggered() const;
        void setTriggered(bool value);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();
};
}

#endif /* COREDETECTIONMESSAGE_H */
