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
** mleforestier        | 052311           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreTemperatureInfoRequest.h"
#include "control/CoreTemperatureInfoResponse.h"
#include "sensor/Temperature.h"

namespace deltadoreX2d
{

CoreTemperatureInfoRequest::CoreTemperatureInfoRequest()
{
	//
}

CoreTemperatureInfoRequest::~CoreTemperatureInfoRequest()
{
	//
}

const DataWay& CoreTemperatureInfoRequest::getDataWay() const
{
	return DataWay::DOWNLOAD;
}

Family CoreTemperatureInfoRequest::getFamily() const
{
	return SENSOR;
}

void CoreTemperatureInfoRequest::addNode(const Node& node, const NodeArg& arg)
{
	CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreTemperatureInfoRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

	frame[8] = (byte)0x08;
	frame[24] = (byte)0x15;

	CoreRmRequest::serialize(frame);
}

Response* CoreTemperatureInfoRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
	int lng = frame[8] & 0xFF;

	int channelCount = frame[20 + lng + 2*indice] & 0x0F;

	return new CoreTemperatureInfoResponse(channelCount);
}

bool CoreTemperatureInfoRequest::instanceOf(RequestClass type) const
{
	if (type == TemperatureInfoRequest_t) { return true; }
	return false;
}

Request* CoreTemperatureInfoRequest::clone() const
{
	return new CoreTemperatureInfoRequest(*this);
}

void* CoreTemperatureInfoRequest::derived()
{
	return (TemperatureInfoRequest*)this;
}

CoreRequest* CoreTemperatureInfoRequest::core()
{
	return this;
}
}
