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
** mleforestier        | 052511           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreThermicRegulationStatusRequest.h"
#include "control/CoreThermicRegulationStatusResponse.h"

namespace deltadoreX2d
{

CoreThermicRegulationStatusRequest::CoreThermicRegulationStatusRequest()
{
	//
}

CoreThermicRegulationStatusRequest::~CoreThermicRegulationStatusRequest()
{
	//
}

const DataWay& CoreThermicRegulationStatusRequest::getDataWay() const
{
	return DataWay::DOWNLOAD;
}

Family CoreThermicRegulationStatusRequest::getFamily() const
{
	return HVAC;
}

void CoreThermicRegulationStatusRequest::addNode(const Node& node, const NodeArg& arg)
{
	CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreThermicRegulationStatusRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
	byte info;
    if (!receivedFrames)
	{
		info = (byte)0x10;
	}
	else if (receivedFrames->size() == 1)
	{
		info = (byte)0x20;
		bool abort = true;
		std::vector<byte> receivedFrame = (*receivedFrames)[0];
		int lng = receivedFrame[8] & 0xFF;

		for (unsigned int i = 0; i < 16; i++)
		{
			if ((21 + lng + 2*i) >= (receivedFrame.size() - 2)) { break; }
			if ((receivedFrame[21 + lng + 2*i] & 0x80) == 0x80)
			{
				abort = false;
				break;
			}
		}
		if (abort) { return; }
	}
	else { return; }

	frame.assign(28, 0);

	frame[8] = (byte)0x08;
	frame[24] = (byte)0x16;
	frame[25] = info;

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicRegulationStatusRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
	int lng = frame[8] & 0xFF;

	ThermicHeatLevel level = ThermicHeatLevel(frame[20 + lng + 2*indice] & 0xFF);
	ThermicRegulationMode mode = ThermicRegulationMode(frame[21 + lng + 2*indice] & 0x07);
	bool isLevelTemporary = (frame[21 + lng + 2*indice] & 0x08) == 0x08;
	bool isProductionCurrent = (frame[21 + lng + 2*indice] & 0x10) == 0x10;

	bool isLoadSheddingCurrent = false;
	bool isEntranceOpened = false;
	bool isPresenceDetected =false;
	bool isTemperatureSensorRadioFault = false;
	bool isTemperatureSensorShortCircuit = false;
	bool isTemperatureSensorOpenCircuit =false;
	bool isProductionFault = false;

	if(frames.size() > 1)
	{
	    frame = frames[1];

		isLoadSheddingCurrent = (frame[20 + lng + 2*indice] & 0x01) == 0x01;
		isEntranceOpened = (frame[20 + lng + 2*indice] & 0x02) == 0x02;
		isPresenceDetected= (frame[20 + lng + 2*indice] & 0x04) == 0x04;
		isTemperatureSensorRadioFault= (frame[21 + lng + 2*indice] & 0x01) == 0x01;
		isTemperatureSensorShortCircuit= (frame[21 + lng + 2*indice] & 0x02) == 0x02;
		isTemperatureSensorOpenCircuit =(frame[21 + lng + 2*indice] & 0x04) == 0x04;
		isProductionFault =(frame[21 + lng + 2*indice] & 0x08) == 0x08;
	}

	return new CoreThermicRegulationStatusResponse(level,
												mode,
												isLevelTemporary,
												isProductionCurrent,
												isLoadSheddingCurrent,
												isEntranceOpened,
												isPresenceDetected,
												isTemperatureSensorRadioFault,
												isTemperatureSensorShortCircuit,
												isTemperatureSensorOpenCircuit,
												isProductionFault);
}

bool CoreThermicRegulationStatusRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicRegulationStatusRequest_t) { return true; }
	return false;
}

Request* CoreThermicRegulationStatusRequest::clone() const
{
	return new CoreThermicRegulationStatusRequest(*this);
}

void* CoreThermicRegulationStatusRequest::derived()
{
	return (ThermicRegulationStatusRequest*)this;
}

CoreRequest* CoreThermicRegulationStatusRequest::core()
{
	return this;
}
}
