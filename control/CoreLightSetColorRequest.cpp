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

#include "control/CoreLightSetColorRequest.h"
#include "control/CoreResponse.h"
#include "light/LightColorArg.h"

namespace deltadoreX2d
{

CoreLightSetColorRequest::CoreLightSetColorRequest()
{
    //
}

CoreLightSetColorRequest::~CoreLightSetColorRequest()
{
    //
}

Family CoreLightSetColorRequest::getFamily() const
{
    return LIGHT;
}

const DataWay& CoreLightSetColorRequest::getDataWay() const
{
    return DataWay::UPLOAD;
}

void CoreLightSetColorRequest::addNode(const Node& node, const NodeArg& arg)
{
	if (!arg.instanceOf(LightColorArg_t))
	{
		throw X2dException("Invalid argument => LightSetColorRequest::addNode(const Node& node, const NodeArg& arg)");
	}
    CoreRmRequest::addNode(node, arg);
}

void CoreLightSetColorRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	int size;
	for (size = 16; size > 0; size--)
	{
		if (m_nodes[size-1]) { break; }
	}

	frame.assign(28 + 2*size, 0);

    frame[8] = (byte)0x08;
    frame[23] = (byte)0x08;
    frame[24] = (byte)0x12;
    frame[25] = (byte)0x30;

    for (int i = 0; i < 16; i++)
    {
        if (m_nodes[i])
        {
            LightColorArg* colorArg = (LightColorArg*)m_nodes[i];
            int red565 = colorArg->getRedValue() >> 3;
            int green565 = colorArg->getGreenValue() >> 2;
            int blue565 = colorArg->getBlueValue() >> 3;
            frame[28 + 2*i] = (byte)((green565 << 5) & 0xE0);
            frame[28 + 2*i] |= (byte)blue565;
            frame[29 + 2*i] = (byte)((red565 << 3) & 0xF8);
            frame[29 + 2*i] |= (byte)(green565 >> 3);
        }
    }

    CoreRmRequest::serialize(frame);
}

Response* CoreLightSetColorRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    return new CoreResponse(ResponseStatus::OK);
}

bool CoreLightSetColorRequest::instanceOf(RequestClass type) const
{
	if (type == LightSetColorRequest_t) { return true; }
	return false;
}

Request* CoreLightSetColorRequest::clone() const
{
	return new CoreLightSetColorRequest(*this);
}

void* CoreLightSetColorRequest::derived()
{
	return (LightSetColorRequest*)this;
}

CoreRequest* CoreLightSetColorRequest::core()
{
	return this;
}
}
