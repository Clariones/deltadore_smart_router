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

#include "control/Codec.h"

#include "control/Checksum.h"
#include "control/CoreController.h"
#include "control/MessageReceivedEvent.h"
#include "control/AcknowledgmentEvent.h"

#include "control/CoreAlarmCentralUnitMessage.h"
#include "control/CoreAlarmCommandMessage.h"
#include "control/CoreAlarmCommandPanelMessage.h"
#include "control/CoreAlarmEventMessage.h"
#include "control/CoreAlarmLogViewMessage.h"
#include "control/CoreAlarmPeripheralDeletionMessage.h"
#include "control/CoreAlarmPeripheralLabelMessage.h"
#include "control/CoreAlarmTimeMessage.h"
#include "control/CoreBasicCommandMessage.h"
#include "control/CoreCompositeMeterReadingMessage.h"
#include "control/CoreCurrentTransformerDefinitionMessage.h"
#include "control/CoreDataTransferMessage.h"
#include "control/CoreDataTransferNotificationMessage.h"
#include "control/CoreDetectionMessage.h"
#include "control/CoreDistressMessage.h"
#include "control/CoreEnrollmentMessage.h"
#include "control/CoreFunctioningModeMessage.h"
#include "control/CoreHeatingLevelMessage.h"
#include "control/CoreMeterReadingMessage.h"
#include "control/CoreScenarioCommandMessage.h"
#include "control/CoreSirenMessage.h"
#include "control/CoreTelephoneTransmitterMessage.h"
#include "control/CoreTemperatureMessage.h"
#include "control/CoreVariationCommandMessage.h"
#include "control/CoreVariationMessage.h"



namespace deltadoreX2d
{

Codec::Codec(CoreController* controller)
{
    m_controller = controller;
}

Codec::~Codec()
{
    //
}

void Codec::decode(const std::vector<byte>& frame)
{
    if (!Checksum::check(frame))
    {
        m_controller->m_stat.incrementErrorCount();
        return;
    }

    m_controller->m_stat.incrementReceivedCount();
    m_controller->fireFrameReceived(FrameIoEvent(m_controller, frame)); //Fire event

    int ctrl = frame[1] & 0xFF;
    decode(frame, ctrl);
}

void Codec::decode(const std::vector<byte>& frame, int ctrl)
{
    if (ctrl == 0x01)
    { //Incoming
        CoreMessage* message = NULL;
        int productType = frame[11] & 0x3F;
        int messageType = frame[13] & 0x0F;

        if (messageType == 5)
        { //Domestic
            int variable = frame[15] & 0xFF;
            switch (variable)
            {
                case 0:
                    message = new CoreEnrollmentMessage(frame);
                    break;
                case 1:
                    message = new CoreHeatingLevelMessage(frame);
                    break;
                case 2:
                    message = new CoreFunctioningModeMessage(frame);
                    break;
                case 8:
                case 10:
                case 11:
                    message = new CoreTemperatureMessage(frame);
                    break;
                case 14:
                case 249:
					if (frame[16] == 6 || frame[16] == 10) {
						message = new CoreCompositeMeterReadingMessage(frame);
					}
					else { message = new CoreMeterReadingMessage(frame); }
					break;
                case 33:
                    message = new CoreBasicCommandMessage(frame);
                    break;
                case 34:
                    message = new CoreVariationCommandMessage(frame);
                    break;
                case 35:
                    message = new CoreScenarioCommandMessage(frame);
                    break;
                case 37:
                    message = new CoreVariationMessage(frame);
                    break;
                case 252:
                    message = new CoreCurrentTransformerDefinitionMessage(frame);
                    break;
            }
        } //Alarm
        else if (messageType == 0)
        {
            if (productType < 4)
            {
                message = new CoreAlarmCentralUnitMessage(frame);
            }
            else if (productType < 8)
            {
                message = new CoreTelephoneTransmitterMessage(frame);
            }
            else if (productType < 12)
            {
                message = new CoreSirenMessage(frame);
            }
            else if (productType < 20)
            {
                message = new CoreAlarmCommandPanelMessage(frame);
            }
            else
            {
                message = new CoreDetectionMessage(frame);
            }
        }
        else if (messageType == 1)
        {
            if (productType < 4)
            {
                message = new CoreAlarmEventMessage(frame);
            }
            else if (productType < 32)
            {
                message = new CoreAlarmCommandMessage(frame);
            }
            else
            {
                message = new CoreDetectionMessage(frame);
            }
        }
        else if (messageType == 4)
        {
            message = new CoreDistressMessage(frame);
        }
        else if (messageType == 6)
        {
            message = new CoreAlarmLogViewMessage(frame);
        }
        else if (messageType == 7)
        {
			message = new CoreDataTransferMessage(frame);
		}
		else if (messageType == 8)
		{
			message = new CoreAlarmTimeMessage(frame);
		}
		else if (messageType == 9)
		{
			message = new CoreDataTransferNotificationMessage(frame);
		}
        if (message != NULL)
        { //Fire event
            m_controller->fireMessageReceived(MessageReceivedEvent(m_controller, message, message->m_frequency));
        }
    }
    else if (ctrl == 0x02)
    { //Controller partial answer
        m_controller->fireAcknowledgment(AcknowledgmentEvent(m_controller, Acknowledgment::PRE_ACK));
    }
    else if (ctrl == 0x06)
    { //Controller answer
        m_controller->fireAcknowledgment(AcknowledgmentEvent(m_controller, Acknowledgment::ACK));
    }
    else if (ctrl == 0x07)
    { //Controller partial answer
        m_controller->fireAcknowledgment(AcknowledgmentEvent(m_controller, Acknowledgment::PRE_ACK));
    }
    else if (ctrl == 0x08)
    { //Controller answer
        m_controller->fireAcknowledgment(AcknowledgmentEvent(m_controller, Acknowledgment::ACK));
    }
    else if (ctrl >= 0x10)
    { //Controller error
        m_controller->fireAcknowledgment(AcknowledgmentEvent(m_controller, Acknowledgment::NACK));
    }
}
}
