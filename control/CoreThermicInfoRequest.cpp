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
** mleforestier        | 042611           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreThermicInfoRequest.h"
#include "control/CoreThermicInfoResponse.h"

namespace deltadoreX2d
{

CoreThermicInfoRequest::CoreThermicInfoRequest()
{
	//
}

CoreThermicInfoRequest::~CoreThermicInfoRequest()
{
	//
}

Family CoreThermicInfoRequest::getFamily() const
{
	return HVAC;
}

const DataWay& CoreThermicInfoRequest::getDataWay() const
{
	return DataWay::DOWNLOAD;
}

void CoreThermicInfoRequest::addNode(const Node& node, const NodeArg& arg)
{
	CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreThermicInfoRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

	frame[8] = (byte)0x08;
	frame[24] = (byte)0x16;

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicInfoRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
	int lng = frame[8] & 0xFF;

	int channelCount = frame[20 + lng + 2*indice] & 0x0F;
	int type = frame[21 + lng + 2*indice] & 0x1F;

	return new CoreThermicInfoResponse(channelCount, ThermicActuatorType(type));
}

bool CoreThermicInfoRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicInfoRequest_t) { return true; }
	return false;
}

Request* CoreThermicInfoRequest::clone() const
{
	return new CoreThermicInfoRequest(*this);
}

void* CoreThermicInfoRequest::derived()
{
	return (ThermicInfoRequest*)this;
}

CoreRequest* CoreThermicInfoRequest::core()
{
	return this;
}
}
