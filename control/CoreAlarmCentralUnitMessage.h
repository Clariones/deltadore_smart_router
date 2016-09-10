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

#ifndef COREALARMCENTRALUNITMESSAGE_H
#define COREALARMCENTRALUNITMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "security/AlarmCentralUnitMessage.h"
#include "security/AlarmStatus.h"
#include "security/AlarmFunctioningMode.h"
#include "security/AlarmProductType.h"
#include "security/AlarmCentralUnitType.h"

namespace deltadoreX2d
{

class CoreAlarmCentralUnitMessage : public CoreAlarmMessage, public virtual AlarmCentralUnitMessage
{
    public :
        CoreAlarmCentralUnitMessage();
        CoreAlarmCentralUnitMessage(const std::vector<byte>& frame);
        ~CoreAlarmCentralUnitMessage();

        Family getFamily() const;
		void setDestinationAddress(int address);
		void setPriority(const MessagePriority& priority);

        const AlarmStatus& getAlarmStatus() const;
        void setAlarmStatus(const AlarmStatus& status);
        const AlarmFunctioningMode& getFunctioningMode() const;
        void setFunctioningMode(const AlarmFunctioningMode& mode);
        bool isTechnicalAlarmCurrent() const;
        void setTechnicalAlarmCurrent(bool value);
        bool isIntrusionEventCurrent() const;
        void setIntrusionEventCurrent(bool value);
        bool isSelfProtectionEventCurrent() const;
        void setSelfProtectionEventCurrent(bool value);
        bool isBatteryEventCurrent() const;
        void setBatteryEventCurrent(bool value);
        bool isMonitoringEventCurrent() const;
        void setMonitoringEventCurrent(bool value);
        bool isOpenEntranceEventCurrent() const;
        void setOpenEntranceEventCurrent(bool value);
        bool isPowerOutageEventCurrent() const;
        void setPowerOutageEventCurrent(bool value);
        bool isTechnicalEventCurrent() const;
        void setTechnicalEventCurrent(bool value);
		int getPartialCount() const;
		void setPartialCount(int count);
		const AlarmCentralUnitType& getCentralUnitType() const;
		void setCentralUnitType(const AlarmCentralUnitType& type);
        int getTemperature() const;
        void setTemperature(int value);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        AlarmStatus m_status;
        AlarmFunctioningMode m_mode;
        bool m_isTechnicalAlarmCurrent;
        bool m_isIntrusionEventCurrent;
        bool m_isSelfProtectionEventCurrent;
        bool m_isBatteryEventCurrent;
        bool m_isMonitoringEventCurrent;
        bool m_isOpenEntranceEventCurrent;
        bool m_isPowerOutageEventCurrent;
        bool m_isTechnicalEventCurrent;
        int m_partialCount;
		AlarmCentralUnitType m_centralUnitType;
        int m_temperature;
};
}

#endif /* COREALARMCENTRALUNITMESSAGE_H */
