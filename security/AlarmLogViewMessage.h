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

#ifndef ALARMLOGVIEWMESSAGE_H
#define ALARMLOGVIEWMESSAGE_H

#include "control/AlarmMessage.h"
#include "security/AlarmLogType.h"
#include "security/AlarmEvent.h"
#include "security/AlarmProductType.h"
#include "security/AlarmProductLabel.h"

namespace deltadoreX2d
{

class AlarmLogViewMessage :public virtual AlarmMessage
{
    public :
        virtual ~AlarmLogViewMessage(){};

        virtual const AlarmLogType& getLogType() const=0;
        virtual void setLogType(const AlarmLogType& type)=0;
        virtual int getEventIndex() const=0;
        virtual void setEventIndex(int index)=0;
		virtual bool isEndOfLog() const=0;
		virtual void setEndOfLog()=0;
        virtual const Date& getEventDate() const=0;
        virtual void setEventDate(const Date& date)=0;
        virtual const AlarmEvent& getEventType() const=0;
        virtual void setEventType(const AlarmEvent& event)=0;
        virtual int getProductId() const=0;
        virtual void setProductId(int id)=0;
        virtual const AlarmProductType getProductType() const=0;
        virtual const AlarmProductLabel& getProductLabel() const=0;
        virtual void setProductLabel(const AlarmProductLabel& label)=0;
		virtual int getProductLabelNumber() const=0;
		virtual void setProductLabelNumber(int number)=0;
};
}

#endif /* ALARMLOGVIEWMESSAGE_H */
