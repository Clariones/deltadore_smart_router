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

#include "control/CoreLightGetColorRequest.h"
#include "control/CoreLightColorResponse.h"

namespace deltadoreX2d
{

CoreLightGetColorRequest::CoreLightGetColorRequest()
{
    //
}

CoreLightGetColorRequest::~CoreLightGetColorRequest()
{
    //
}

Family CoreLightGetColorRequest::getFamily() const
{
    return LIGHT;
}

const DataWay& CoreLightGetColorRequest::getDataWay() const
{
    return DataWay::DOWNLOAD;
}

void CoreLightGetColorRequest::addNode(const Node& node, const NodeArg& arg)
{
    CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreLightGetColorRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

    frame[8] = (byte)0x08;
    frame[24] = (byte)0x12;
    frame[25] = (byte)0x30;

    CoreRmRequest::serialize(frame);
}

Response* CoreLightGetColorRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
    int lng = frame[8] & 0xFF;

    int red565 = (frame[21 + lng + 2*indice] >> 3) & 0x1F;
    int green565 = (frame[21 + lng + 2*indice] & 0x07) << 3;
    green565 += (frame[20 + lng + 2*indice] >> 5) & 0x07;
    int blue565 = frame[20 + lng + 2*indice] & 0x1F;

    int red = (red565 << 3) & 0xF8;
    int green = (green565 << 2) & 0xFC;
    int blue = (blue565 << 3) & 0xF8;

    return new CoreLightColorResponse(red, green, blue);
}

bool CoreLightGetColorRequest::instanceOf(RequestClass type) const
{
	if (type == LightGetColorRequest_t) { return true; }
	return false;
}

Request* CoreLightGetColorRequest::clone() const
{
	return new CoreLightGetColorRequest(*this);
}

void* CoreLightGetColorRequest::derived()
{
	return (LightGetColorRequest*)this;
}

CoreRequest* CoreLightGetColorRequest::core()
{
	return this;
}
}
