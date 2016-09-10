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

#include "control/CoreThermicSystemStatusRequest.h"
#include "control/CoreThermicSystemStatusResponse.h"
#include "hvac/ThermicSystemOutput.h"
#include "hvac/ThermicFanSpeed.h"
#include "hvac/ThermicPipeworkSupply.h"

namespace deltadoreX2d
{

CoreThermicSystemStatusRequest::CoreThermicSystemStatusRequest()
{
	//
}

CoreThermicSystemStatusRequest::~CoreThermicSystemStatusRequest()
{
	//
}

const DataWay& CoreThermicSystemStatusRequest::getDataWay() const
{
	return DataWay::DOWNLOAD;
}

Family CoreThermicSystemStatusRequest::getFamily() const
{
	return HVAC;
}

void CoreThermicSystemStatusRequest::addNode(const Node& node, const NodeArg& arg)
{
	CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreThermicSystemStatusRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

	frame[8] = (byte)0x08;
	frame[24] = (byte)0x16;
	frame[25] = (byte)0x50;

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicSystemStatusRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
	int lng = frame[8] & 0xFF;

	ThermicSystemOutput output = ThermicSystemOutput(frame[20 + lng + 2*indice] & 0x07);
	ThermicFanSpeed fanSpeed = ThermicFanSpeed((frame[20 + lng + 2*indice] >> 3) & 0x07);
	ThermicPipeworkSupply pipeworkSupply = ThermicPipeworkSupply((frame[20 + lng + 2*indice] >> 6) & 0x03);

	return new CoreThermicSystemStatusResponse(output, fanSpeed, pipeworkSupply);
}

bool CoreThermicSystemStatusRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicSystemStatusRequest_t) { return true; }
	return false;
}

Request* CoreThermicSystemStatusRequest::clone() const
{
	return new CoreThermicSystemStatusRequest(*this);
}

void* CoreThermicSystemStatusRequest::derived()
{
	return (ThermicSystemStatusRequest*)this;
}

CoreRequest* CoreThermicSystemStatusRequest::core()
{
	return this;
}
}
