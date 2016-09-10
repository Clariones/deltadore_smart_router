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

#ifndef MESSAGE_H
#define MESSAGE_H

#include "requirement.h"
#include "control/MessagePriority.h"

namespace deltadoreX2d
{

class CoreMessage;

typedef enum
{
    AlarmCentralUnitMessage_t = 0x00,
    AlarmCommandMessage_t,
    AlarmCommandPanelMessage_t,
    AlarmEventMessage_t,
    AlarmLogViewMessage_t,
    AlarmMessage_t,
    AlarmPeripheralDeletionMessage_t,
    AlarmPeripheralLabelMessage_t,
    AlarmTimeMessage_t,
    BasicCommandMessage_t,
    CompositeMeterReadingMessage_t,
    CurrentTransformerDefinitionMessage_t,
    DataTransferMessage_t,
    DataTransferNotificationMessage_t,
    DetectionMessage_t,
    DistressMessage_t,
    DomesticMessage_t,
    EnrollmentMessage_t,
    FunctioningModeMessage_t,
    HeatingLevelMessage_t,
    Message_t,
    MeterReadingMessage_t,
    ScenarioCommandMessage_t,
    SirenMessage_t,
    TelephoneTransmitterMessage_t,
    TemperatureMessage_t,
    VariationCommandMessage_t,
    VariationMessage_t
} MessageClass;

class Message
{
    public :
        virtual ~Message(){};

        virtual int getSourceAddress() const=0;
        virtual int getSourcePort() const=0;
        virtual void setSourcePort(int port)=0;
        virtual int getDestinationPort() const=0;
        virtual int getSourceType() const=0;
        virtual void setSourceType(int type)=0;
        virtual bool isEnrollmentRequest() const=0;
        virtual void setEnrollmentRequest(bool value)=0;
        virtual bool isAnswerRequest() const=0;
        virtual void setAnswerRequest(bool value)=0;
        virtual Family getFamily() const=0;
        virtual bool isBatteryFaulty() const=0;
        virtual void setBatteryFaulty(bool value)=0;
        virtual bool isSelfProtectionFaulty() const=0;
        virtual void setSelfProtectionFaulty(bool value)=0;
        virtual bool isInternalFaulty() const=0;
        virtual void setInternalFaulty(bool value)=0;
		virtual const MessagePriority& getPriority() const=0;
		virtual void setPriority(const MessagePriority& priority)=0;
		virtual bool instanceOf(MessageClass type) const=0;
		virtual Message* clone() const=0;
		virtual void* derived()=0;
		virtual CoreMessage* core()=0;

		template<class T> T convert() { return (T)this->derived(); }
};
}

#endif /* MESSAGE_H */
