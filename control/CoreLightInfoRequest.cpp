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

#include "control/CoreLightInfoRequest.h"
#include "control/CoreLightInfoResponse.h"
#include "light/LightActuatorType.h"

namespace deltadoreX2d
{

CoreLightInfoRequest::CoreLightInfoRequest()
{
    //
}

CoreLightInfoRequest::~CoreLightInfoRequest()
{
    //
}

Family CoreLightInfoRequest::getFamily() const
{
    return LIGHT;
}

const DataWay& CoreLightInfoRequest::getDataWay() const
{
    return DataWay::DOWNLOAD;
}

void CoreLightInfoRequest::addNode(const Node& node, const NodeArg& arg)
{
    CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreLightInfoRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

    frame[8] = (byte)0x08;
    frame[24] = (byte)0x12;

    CoreRmRequest::serialize(frame);
}

Response* CoreLightInfoRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
    int lng = frame[8] & 0xFF;

    int channelCount = frame[20 + lng + 2*indice] & 0x0F;
    int type = (frame[20 + lng + 2*indice] & 0x70) >> 4;
    LightActuatorType actuatorType = LightActuatorType(type);
    bool isMulticolor = (frame[20 + lng + 2*indice] & 0x80) == 0x80;

    return new CoreLightInfoResponse(channelCount, actuatorType, isMulticolor);
}

bool CoreLightInfoRequest::instanceOf(RequestClass type) const
{
	if (type == LightInfoRequest_t) { return true; }
	return false;
}

Request* CoreLightInfoRequest::clone() const
{
	return new CoreLightInfoRequest(*this);
}

void* CoreLightInfoRequest::derived()
{
	return (LightInfoRequest*)this;
}

CoreRequest* CoreLightInfoRequest::core()
{
	return this;
}
}
