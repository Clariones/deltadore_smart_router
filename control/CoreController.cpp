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

#include "control/CoreController.h"
#include "control/Checksum.h"
#include "control/PrintableHex.h"
#include "control/DirectCodec.h"
#include "control/MeshCodec.h"
#include <errno.h>

#include "control/CoreMessage.h"
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

#include "control/CoreRequest.h"
#include "control/CoreCommonSettingRequest.h"
#include "control/CoreCurrentConsumptionRequest.h"
#include "control/CoreDiagnosticOverheatingRequest.h"
#include "control/CoreEnergyConsumptionRequest.h"
#include "control/CoreGetOutdoorTemperatureRequest.h"
#include "control/CoreGetRoomTemperatureRequest.h"
#include "control/CoreLightCommandRequest.h"
#include "control/CoreLightGetColorRequest.h"
#include "control/CoreLightInfoRequest.h"
#include "control/CoreLightSetColorRequest.h"
#include "control/CoreLightSettingRequest.h"
#include "control/CoreLightStatusRequest.h"
#include "control/CorePowerConsumptionRequest.h"
#include "control/CoreRollerShutterCommandRequest.h"
#include "control/CoreRollerShutterInfoRequest.h"
#include "control/CoreRollerShutterSettingRequest.h"
#include "control/CoreRollerShutterStatusRequest.h"
#include "control/CoreSetOutdoorTemperatureRequest.h"
#include "control/CoreSetRoomTemperatureRequest.h"
#include "control/CoreTemperatureInfoRequest.h"
#include "control/CoreThermicAntiFrostAdjustmentRequest.h"
#include "control/CoreThermicGetDelayTimeRequest.h"
#include "control/CoreThermicInfoRequest.h"
#include "control/CoreThermicRegulationCommandRequest.h"
#include "control/CoreThermicRegulationStatusRequest.h"
#include "control/CoreThermicSetDelayTimeRequest.h"
#include "control/CoreThermicSettingRequest.h"
#include "control/CoreThermicSystemCommandRequest.h"
#include "control/CoreThermicSystemStatusRequest.h"

#include "driver/Utils.h"

namespace deltadoreX2d
{

CoreController::CoreController()
{
    m_inputStream = NULL;
    m_outputStream = NULL;
    m_codec = new Codec(this);
	m_jobCancel = false;
	m_jobRunning = false;
}

CoreController::~CoreController()
{
    delete(m_codec);
}

int CoreController::getReceivedCount()
{
    return m_stat.getReceivedCount();
}

int CoreController::getSentCount()
{
    return m_stat.getSentCount();
}

int CoreController::getErrorCount()
{
    return m_stat.getErrorCount();
}

int CoreController::getTimeoutCount()
{
    return m_stat.getTimeoutCount();
}

void CoreController::clearStatistics()
{
    m_stat.clear();
}

void CoreController::addFrameReceivedListener(FrameReceivedListener* listener)
{
	m_lock.lock();
	m_frameReceivedListeners.push_back(listener);
	m_lock.unlock();
}

void CoreController::removeFrameReceivedListener(FrameReceivedListener* listener)
{
	m_lock.lock();
	m_frameReceivedListeners.remove(listener);
	m_lock.unlock();
}

void CoreController::fireFrameReceived(const FrameIoEvent& evt)
{
	std::list<FrameReceivedListener*>::iterator it;
	for (it = m_frameReceivedListeners.begin(); it != m_frameReceivedListeners.end(); ++it)
	{
		(*it)->frameReceived(evt);
	}
}

void CoreController::addFrameSentListener(FrameSentListener* listener)
{
	m_lock.lock();
	m_frameSentListeners.push_back(listener);
	m_lock.unlock();
}

void CoreController::removeFrameSentListener(FrameSentListener* listener)
{
	m_lock.lock();
    m_frameSentListeners.remove(listener);
	m_lock.unlock();
}

void CoreController::fireFrameSent(const FrameIoEvent& evt)
{
	std::list<FrameSentListener*>::iterator it;
	for (it = m_frameSentListeners.begin(); it != m_frameSentListeners.end(); ++it)
	{
		(*it)->frameSent(evt);
	}
}

void CoreController::addAcknowledgmentListener(AcknowledgmentListener* listener)
{
	m_lock.lock();
	m_acknowledgmentListeners.push_back(listener);
	m_lock.unlock();
}

void CoreController::removeAcknowledgmentListener(AcknowledgmentListener* listener)
{
	m_lock.lock();
    m_acknowledgmentListeners.remove(listener);
	m_lock.unlock();
}

void CoreController::fireAcknowledgment(const AcknowledgmentEvent& evt)
{
	std::list<AcknowledgmentListener*>::iterator it;
	for (it = m_acknowledgmentListeners.begin(); it != m_acknowledgmentListeners.end(); ++it)
	{
		(*it)->acknowledgment(evt);
	}
}

void CoreController::addMessageReceivedListener(MessageReceivedListener* listener)
{
	m_lock.lock();
	m_messageReceivedListeners.push_back(listener);
	m_lock.unlock();
}

void CoreController::removeMessageReceivedListener(MessageReceivedListener* listener)
{
	m_lock.lock();
    m_messageReceivedListeners.remove(listener);
	m_lock.unlock();
}

void CoreController::fireMessageReceived(const MessageReceivedEvent& evt)
{
	std::list<MessageReceivedListener*>::iterator it;
	for (it = m_messageReceivedListeners.begin(); it != m_messageReceivedListeners.end(); ++it)
	{
		(*it)->messageReceived(evt);
	}
}

void CoreController::addEndTransactionListener(EndTransactionListener* listener)
{
	m_lock.lock();
	m_endTransactionListeners.push_back(listener);
	m_lock.unlock();
}

void CoreController::removeEndTransactionListener(EndTransactionListener* listener)
{
	m_lock.lock();
    m_endTransactionListeners.remove(listener);
	m_lock.unlock();
}

void CoreController::fireEndTransaction(const EndTransactionEvent& evt)
{
	std::list<EndTransactionListener*>::iterator it;
	for (it = m_endTransactionListeners.begin(); it != m_endTransactionListeners.end(); ++it)
	{
		(*it)->endTransaction(evt);
	}
}

void CoreController::addNodeDiscoveredListener(NodeDiscoveredListener* listener)
{
	m_lock.lock();
	m_nodeDiscoveredListeners.push_back(listener);
	m_lock.unlock();
}

void CoreController::removeNodeDiscoveredListener(NodeDiscoveredListener* listener)
{
	m_lock.lock();
    m_nodeDiscoveredListeners.remove(listener);
	m_lock.unlock();
}

void CoreController::fireNodeDiscovered(const NodeDiscoveredEvent& evt)
{
	std::list<NodeDiscoveredListener*>::iterator it;
	for (it = m_nodeDiscoveredListeners.begin(); it != m_nodeDiscoveredListeners.end(); ++it)
	{
		(*it)->nodeDiscovered(evt);
	}
}

void CoreController::open(InputStream* in, OutputStream* out)
{
	m_lock.lock();
	if (!m_jobRunning)
	{
        m_inputStream = in;
        m_outputStream = out;

		m_jobCancel = false;
		m_jobRunning = true;

		Runnable::start();
	}
	m_lock.unlock();
}

void CoreController::close()
{
	if (m_jobRunning)
	{
		m_jobCancel = true;
		m_inputStream->close(); // prevent blocking behavior if necessary
		m_outputStream->close(); // prevent blocking behavior if necessary
		Runnable::join();
	}
}

void CoreController::setEnrollmentListeningMode(bool enabled)
{
	m_lock.lock();

    DirectCodec* codec = new DirectCodec(this);
	delete(m_codec);
    m_codec = codec;
    codec->setEnrollmentListeningMode(enabled);

	m_lock.unlock();
}

void CoreController::setEnrollmentListeningMode(int port)
{
	m_lock.lock();

    DirectCodec* codec = new DirectCodec(this);
	delete(m_codec);
    m_codec = codec;
    codec->setEnrollmentListeningMode(port);

	m_lock.unlock();
}

void CoreController::clearEnrolledSources()
{
	m_lock.lock();

    DirectCodec* codec = new DirectCodec(this);
	delete(m_codec);
    m_codec = codec;
    codec->clearEnrolledSources();

	m_lock.unlock();
}

Message* CoreController::createMessage(MessageClass type)
{
    if (type == AlarmCentralUnitMessage_t)
    {
		return new CoreAlarmCentralUnitMessage();
	}
	else if (type == AlarmCommandMessage_t)
    {
        return new CoreAlarmCommandMessage();
    }
    else if(type == AlarmCommandPanelMessage_t)
    {
        return new CoreAlarmCommandPanelMessage();
    }
    else if(type == AlarmEventMessage_t)
    {
        return new CoreAlarmEventMessage();
    }
    else if(type == AlarmLogViewMessage_t)
    {
        return new CoreAlarmLogViewMessage();
    }
    else if (type == AlarmPeripheralDeletionMessage_t)
    {
		return new CoreAlarmPeripheralDeletionMessage();
	}
	else if (type == AlarmPeripheralLabelMessage_t)
	{
        return new CoreAlarmPeripheralLabelMessage();
    }
    else if (type == BasicCommandMessage_t)
    {
        return new CoreBasicCommandMessage();
    }
    else if (type == CompositeMeterReadingMessage_t)
    {
        return new CoreCompositeMeterReadingMessage();
    }
    else if (type == CurrentTransformerDefinitionMessage_t)
    {
        return new CoreCurrentTransformerDefinitionMessage();
    }
    else if (type == DataTransferMessage_t)
    {
		return new CoreDataTransferMessage();
	}
	else if (type == DataTransferNotificationMessage_t)
	{
		return new CoreDataTransferNotificationMessage();
	}
    else if (type == DetectionMessage_t)
    {
        return new CoreDetectionMessage();
    }
    else if (type == DistressMessage_t)
    {
        return new CoreDistressMessage();
    }
    else if (type == EnrollmentMessage_t)
    {
        return new CoreEnrollmentMessage();
    }
    else if (type == FunctioningModeMessage_t)
    {
        return new CoreFunctioningModeMessage();
    }
    else if (type == HeatingLevelMessage_t)
    {
        return new CoreHeatingLevelMessage();
    }
    else if (type == MeterReadingMessage_t)
    {
        return new CoreMeterReadingMessage();
    }
    else if (type == ScenarioCommandMessage_t)
    {
        return new CoreScenarioCommandMessage();
    }
    else if (type == SirenMessage_t)
    {
        return new CoreSirenMessage();
    }
    else if(type == TelephoneTransmitterMessage_t)
    {
        return new CoreTelephoneTransmitterMessage();
    }
    else if (type == TemperatureMessage_t)
    {
        return new CoreTemperatureMessage();
    }
    else if (type == VariationCommandMessage_t)
    {
        return new CoreVariationCommandMessage();
    }
    else if (type == VariationMessage_t)
    {
        return new CoreVariationMessage();
    }

    throw X2dException("Invalid argument => DirectController::createMessage(MessageClass type) const");
}

Request* CoreController::createRequest(RequestClass type)
{
    if (type == CommonSettingRequest_t)
    {
		return new CoreCommonSettingRequest();
	}
	else if (type == DiagnosticOverheatingRequest_t)
	{
		return new CoreDiagnosticOverheatingRequest();
	}
	else if(type == CurrentConsumptionRequest_t)
    {
        return new CoreCurrentConsumptionRequest();
    }
    else if(type == EnergyConsumptionRequest_t)
    {
        return new CoreEnergyConsumptionRequest();
    }
    else if (type == GetOutdoorTemperatureRequest_t)
    {
		return new CoreGetOutdoorTemperatureRequest();
	}
	else if (type == GetRoomTemperatureRequest_t)
	{
		return new CoreGetRoomTemperatureRequest();
	}
    else if (type == LightCommandRequest_t)
    {
        return new CoreLightCommandRequest();
    }
    else if (type == LightGetColorRequest_t)
    {
        return new CoreLightGetColorRequest();
    }
    else if (type == LightInfoRequest_t)
    {
        return new CoreLightInfoRequest();
    }
    else if (type == LightSetColorRequest_t)
    {
        return new CoreLightSetColorRequest();
    }
    else if (type == LightSettingRequest_t)
    {
        return new CoreLightSettingRequest();
    }
    else if (type == LightStatusRequest_t)
    {
        return new CoreLightStatusRequest();
    }
    else if(type == PowerConsumptionRequest_t)
    {
        return new CorePowerConsumptionRequest();
    }
    else if (type == RollerShutterCommandRequest_t)
    {
        return new CoreRollerShutterCommandRequest();
    }
    else if(type == RollerShutterInfoRequest_t)
    {
        return new CoreRollerShutterInfoRequest();
    }
    else if (type == RollerShutterSettingRequest_t)
    {
        return new CoreRollerShutterSettingRequest();
    }
    else if(type == RollerShutterStatusRequest_t)
    {
        return new CoreRollerShutterStatusRequest();
    }
    else if (type == SetOutdoorTemperatureRequest_t)
    {
		return new CoreSetOutdoorTemperatureRequest();
	}
	else if (type == SetRoomTemperatureRequest_t)
	{
		return new CoreSetRoomTemperatureRequest();
	}
	else if (type == TemperatureInfoRequest_t)
	{
		return new CoreTemperatureInfoRequest();
	}
	else if (type == ThermicAntiFrostAdjustmentRequest_t)
	{
		return new CoreThermicAntiFrostAdjustmentRequest();
	}
    else if (type == ThermicGetDelayTimeRequest_t)
    {
		return new CoreThermicGetDelayTimeRequest();
	}
	else if (type == ThermicRegulationCommandRequest_t)
	{
        return new CoreThermicRegulationCommandRequest();
    }
    else if (type == ThermicRegulationStatusRequest_t)
    {
        return new CoreThermicRegulationStatusRequest();
    }
    else if (type == ThermicSystemCommandRequest_t)
    {
        return new CoreThermicSystemCommandRequest();
    }
    else if (type == ThermicSystemStatusRequest_t)
    {
        return new CoreThermicSystemStatusRequest();
    }
	else if (type == ThermicInfoRequest_t)
	{
		return new CoreThermicInfoRequest();
	}
	else if (type == ThermicSetDelayTimeRequest_t)
	{
		return new CoreThermicSetDelayTimeRequest();
	}
	else if (type == ThermicSettingRequest_t)
	{
		return new CoreThermicSettingRequest();
	}

    throw X2dException("Invalid argument => MeshController::createRequest(RequestClass type) const");
}

void CoreController::initNetworks()
{
	initNetworks(-1); // auto
}

void CoreController::initNetworks(int count)
{
	m_lock.lock();

	m_networks.clear();
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
    	{
        	m_networks.push_back(CoreNetwork(i, this));
    	}
	}
    NetworkCodec* codec = new NetworkCodec(this);
	delete(m_codec);
    m_codec = codec;
	codec->getAllTopology();

	m_lock.unlock();
}

int CoreController::getNetworkCount()
{
	m_lock.lock();
    int size = m_networks.size();
	m_lock.unlock();
	return size;
}

Network* CoreController::getNetwork(int id)
{
	m_lock.lock();
    Network* net = &m_networks[id];
	m_lock.unlock();
	return net;
}

void CoreController::sendMessage(Message* message, const RadioFrequency& frequency)
{
	m_lock.lock();

    DirectCodec* codec = new DirectCodec(this);
	delete(m_codec);
    m_codec = codec;
	codec->sendMessage(message, frequency);

	m_lock.unlock();
}

void CoreController::beginTransaction(Request* request)
{
	m_lock.lock();

	MeshCodec* codec = new MeshCodec(this);
	codec->adoptRequest(request);
	codec->setNetwork(&m_networks[request->getNetwork()->getIdentifier()]);
	delete(m_codec);
    m_codec = codec;
	codec->beginTransaction();

	m_lock.unlock();
}

void CoreController::sendFrame(std::vector<byte>& frame)
{
	m_lock.lock();

	Codec* codec = new Codec(this);
	delete(m_codec);
    m_codec = codec;
    writeOutput(frame);

	m_lock.unlock();
}

void CoreController::sendFrame(const std::string& hexString)
{
	std::vector<byte> frame = PrintableHex::getBytes(hexString);
	sendFrame(frame);
}

void CoreController::writeOutput(std::vector<byte>& frame)
{
    Checksum::add(frame);

    m_outputStream->write(&frame[0], frame.size());
    m_stat.incrementSentCount();
    fireFrameSent(FrameIoEvent(this, frame)); //Fire event
}

void CoreController::run()
{
    int idx=0;
    byte receivedByte = -1;
    byte buffer[100]; //Maximum packet size
	Date previousTime;

    while(!m_jobCancel)
    {
		int count = m_inputStream->read(&receivedByte, 1);
		if (count <= 0)
		{ //Timeout detection with non blocking behavior
			if (idx > 0)
			{ //Timeout
				m_stat.incrementTimeoutCount();
				printf("read timeout\n");
				idx = 0;
			}
			Runnable::sleep(); //Suspending thread if necessary
			continue;
		}

		Date receivedTime;
		int elapsedSeconds = receivedTime.getElapsedSecondsSince(previousTime);
		previousTime = receivedTime;
		if (elapsedSeconds > 1)
		{ //Timeout detection with blocking behavior
			if (idx > 0)
			{ //Timeout
				m_stat.incrementTimeoutCount();
				idx = 0;
			}
		}

		buffer[idx] = receivedByte;
		idx++;
        printf("buffer[0]=%02X, read %02X, size=%d\n", buffer[0], buffer[idx-1], idx);
		if (idx == buffer[0]) //Frame length
		{
            dumpHex("Received frame", buffer, idx);
			std::vector<byte> frame(buffer, buffer+idx);
			idx = 0;

			m_lock.lock();
			try { m_codec->decode(frame); }
			catch(...) { m_stat.incrementErrorCount(); }
			m_lock.unlock();
		}
		else if (idx > buffer[0])
		{
			m_stat.incrementErrorCount();
			idx = 0;
		}
    }

    m_jobRunning = false;
}

CoreController* CoreController::core()
{
	return this;
}
}
