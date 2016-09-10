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

#ifndef ALARMEVENTMESSAGE_H
#define ALARMEVENTMESSAGE_H

#include "control/AlarmMessage.h"
#include "security/AlarmEvent.h"
#include "security/AlarmStatus.h"
#include "security/AlarmFunctioningMode.h"

namespace deltadoreX2d
{

class AlarmEventMessage : public virtual AlarmMessage
{
    public :
        virtual ~AlarmEventMessage(){};

		virtual const AlarmStatus& getAlarmStatus() const=0;
		virtual void setAlarmStatus(const AlarmStatus& status)=0;
		virtual const AlarmFunctioningMode& getFunctioningMode() const=0;
		virtual void setFunctioningMode(const AlarmFunctioningMode& mode)=0;
		virtual bool isTechnicalAlarmCurrent() const=0;
		virtual void setTechnicalAlarmCurrent(bool value)=0;
        virtual const AlarmEvent& getEvent() const=0;
        virtual void setEvent(const AlarmEvent& event)=0;
		virtual int getProductId() const=0;
		virtual void setProductId(int id)=0;
};
}

#endif /* ALARMEVENTMESSAGE_H */
