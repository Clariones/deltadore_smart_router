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

#include "control/CoreThermicGetDelayTimeRequest.h"
#include "control/CoreThermicDelayTimeResponse.h"

namespace deltadoreX2d
{

CoreThermicGetDelayTimeRequest::CoreThermicGetDelayTimeRequest()
{
	//
}

CoreThermicGetDelayTimeRequest::~CoreThermicGetDelayTimeRequest()
{
	//
}

const DataWay& CoreThermicGetDelayTimeRequest::getDataWay() const
{
	return DataWay::DOWNLOAD;
}

Family CoreThermicGetDelayTimeRequest::getFamily() const
{
	return HVAC;
}

void CoreThermicGetDelayTimeRequest::addNode(const Node& node, const NodeArg& arg)
{
	CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreThermicGetDelayTimeRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

	frame[8] = (byte)0x08;
	frame[24] = (byte)0x16;
	frame[25] = (byte)0x60;

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicGetDelayTimeRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
	int lng = frame[8] & 0xFF;

	int value = (frame[21 + lng + 2*indice] & 0xFF) << 8;
	value += frame[20 + lng + 2*indice] & 0xFF;

	return new CoreThermicDelayTimeResponse(ThermicDelayTime(value));
}

bool CoreThermicGetDelayTimeRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicGetDelayTimeRequest_t) { return true; }
	return false;
}

Request* CoreThermicGetDelayTimeRequest::clone() const
{
	return new CoreThermicGetDelayTimeRequest(*this);
}

void* CoreThermicGetDelayTimeRequest::derived()
{
	return (ThermicGetDelayTimeRequest*)this;
}

CoreRequest* CoreThermicGetDelayTimeRequest::core()
{
	return this;
}
}
