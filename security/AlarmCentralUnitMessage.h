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

#ifndef ALARMCENTRALUNITMESSAGE_H
#define ALARMCENTRALUNITMESSAGE_H

#include "control/AlarmMessage.h"
#include "security/AlarmStatus.h"
#include "security/AlarmFunctioningMode.h"
#include "security/AlarmCentralUnitType.h"

namespace deltadoreX2d
{

class AlarmCentralUnitMessage : public virtual AlarmMessage
{
    public :
        virtual ~AlarmCentralUnitMessage(){};

        virtual const AlarmStatus& getAlarmStatus() const=0;
        virtual void setAlarmStatus(const AlarmStatus& status)=0;
        virtual const AlarmFunctioningMode& getFunctioningMode() const=0;
        virtual void setFunctioningMode(const AlarmFunctioningMode& mode)=0;
        virtual bool isTechnicalAlarmCurrent() const=0;
        virtual void setTechnicalAlarmCurrent(bool value)=0;
        virtual bool isIntrusionEventCurrent() const=0;
        virtual void setIntrusionEventCurrent(bool value)=0;
        virtual bool isSelfProtectionEventCurrent() const=0;
        virtual void setSelfProtectionEventCurrent(bool value)=0;
        virtual bool isBatteryEventCurrent() const=0;
        virtual void setBatteryEventCurrent(bool value)=0;
        virtual bool isMonitoringEventCurrent() const=0;
        virtual void setMonitoringEventCurrent(bool value)=0;
        virtual bool isOpenEntranceEventCurrent() const=0;
        virtual void setOpenEntranceEventCurrent(bool value)=0;
        virtual bool isPowerOutageEventCurrent() const=0;
        virtual void setPowerOutageEventCurrent(bool value)=0;
        virtual bool isTechnicalEventCurrent() const=0;
        virtual void setTechnicalEventCurrent(bool value)=0;
		virtual int getPartialCount() const=0;
		virtual void setPartialCount(int count)=0;
		virtual const AlarmCentralUnitType& getCentralUnitType() const=0;
		virtual void setCentralUnitType(const AlarmCentralUnitType& type)=0;
        virtual int getTemperature() const=0;
        virtual void setTemperature(int value)=0;
};
}

#endif // ALARMCENTRALUNITMESSAGE_H

