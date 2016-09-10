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

#ifndef COREALARMEVENTMESSAGE_H
#define COREALARMEVENTMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "security/AlarmEventMessage.h"

namespace deltadoreX2d
{

class CoreAlarmEventMessage : public CoreAlarmMessage, public virtual AlarmEventMessage
{
    public :
        CoreAlarmEventMessage();
        CoreAlarmEventMessage(const std::vector<byte>& frame);
        ~CoreAlarmEventMessage();

        Family getFamily() const;
        bool isEnrollmentRequest() const;
        void setEnrollmentRequest(bool value);
        void setAnswerRequest(bool value);
		bool isTestMode() const;
		void setTestMode(bool value);
        bool isBatteryFaulty() const;
        void setBatteryFaulty(bool value);
        bool isSelfProtectionFaulty() const;
        void setSelfProtectionFaulty(bool value);
        bool isInternalFaulty() const;
        void setInternalFaulty(bool value);

		const AlarmStatus& getAlarmStatus() const;
		void setAlarmStatus(const AlarmStatus& status);
		const AlarmFunctioningMode& getFunctioningMode() const;
		void setFunctioningMode(const AlarmFunctioningMode& mode);
		bool isTechnicalAlarmCurrent() const;
		void setTechnicalAlarmCurrent(bool value);
        const AlarmEvent& getEvent() const;
        void setEvent(const AlarmEvent& event);
		int getProductId() const;
		void setProductId(int id);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        AlarmStatus m_status;
        AlarmFunctioningMode m_mode;
        bool m_isTechnicalAlarmCurrent;
        AlarmEvent m_event;
        int m_productId;
};
}

#endif /* COREALARMEVENTMESSAGE_H */
