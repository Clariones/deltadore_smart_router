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

#include "control/CoreLightStatusRequest.h"
#include "control/CoreLightStatusResponse.h"

namespace deltadoreX2d
{

CoreLightStatusRequest::CoreLightStatusRequest()
{
    //
}

CoreLightStatusRequest::~CoreLightStatusRequest()
{
    //
}

Family CoreLightStatusRequest::getFamily() const
{
    return LIGHT;
}

const DataWay& CoreLightStatusRequest::getDataWay() const
{
    return DataWay::DOWNLOAD;
}

void CoreLightStatusRequest::addNode(const Node& node, const NodeArg& arg)
{
    CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreLightStatusRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

    frame[8] = (byte)0x08;
    frame[24] = (byte)0x12;
    frame[25] = (byte)0x10;

    CoreRmRequest::serialize(frame);
}

Response* CoreLightStatusRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
    int lng = frame[8] & 0xFF;

    int level = frame[20 + lng + 2*indice] & 0xFF;
    bool isOverloadFaulty = (frame[21 + lng + 2*indice] & 0x01) == 0x01;
    bool isCommandFaulty = (frame[21 + lng + 2*indice] & 0x02) == 0x02;
    bool isOverheatingFaulty = (frame[21 + lng + 2*indice] & 0x04) == 0x04;
    bool isFavoritePosition = (frame[21 + lng + 2*indice] & 0x08) == 0x08;
    bool isPresenceDetected = (frame[21 + lng + 2*indice] & 0x10) == 0x10;
    bool isTwilight = (frame[21 + lng + 2*indice] & 0x20) == 0x20;

    return new CoreLightStatusResponse(level,
										isOverloadFaulty,
										isCommandFaulty,
										isOverheatingFaulty,
										isFavoritePosition,
										isPresenceDetected,
										isTwilight);
}

bool CoreLightStatusRequest::instanceOf(RequestClass type) const
{
	if (type == LightStatusRequest_t) { return true; }
	return false;
}

Request* CoreLightStatusRequest::clone() const
{
	return new CoreLightStatusRequest(*this);
}

void* CoreLightStatusRequest::derived()
{
	return (LightStatusRequest*)this;
}

CoreRequest* CoreLightStatusRequest::core()
{
	return this;
}
}
