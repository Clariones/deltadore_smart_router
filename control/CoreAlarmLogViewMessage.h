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

#ifndef COREALARMLOGVIEWMESSAGE_H
#define COREALARMLOGVIEWMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "security/AlarmLogViewMessage.h"

namespace deltadoreX2d
{

class CoreAlarmLogViewMessage : public CoreAlarmMessage, public virtual AlarmLogViewMessage
{
    public :
        CoreAlarmLogViewMessage();
        CoreAlarmLogViewMessage(const std::vector<byte>& frame);
        ~CoreAlarmLogViewMessage();

        Family getFamily() const;
        void setEnrollmentRequest(bool value);
		void setTestMode(bool value);
		void setDestinationAddress(int address);

        const AlarmLogType& getLogType() const;
        void setLogType(const AlarmLogType& type);
        int getEventIndex() const;
        void setEventIndex(int index);
		bool isEndOfLog() const;
		void setEndOfLog();
        const Date& getEventDate() const;
        void setEventDate(const Date& date);
        const AlarmEvent& getEventType() const;
        void setEventType(const AlarmEvent& event);
        int getProductId() const;
        void setProductId(int id);
        const AlarmProductType getProductType() const;
        const AlarmProductLabel& getProductLabel() const;
        void setProductLabel(const AlarmProductLabel& label);
		int getProductLabelNumber() const;
		void setProductLabelNumber(int number);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

	private:
        AlarmLogType m_logType;
        int m_eventIndex;
        Date m_eventDate;
        AlarmEvent m_event;
        int m_productId;
        AlarmProductLabel m_label;
        int m_labelNumber;
};

}

#endif /* COREALARMLOGVIEWMESSAGE_H */
