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

#include "control/CoreLightCommandRequest.h"
#include "control/CoreResponse.h"
#include "light/LightCommandArg.h"

namespace deltadoreX2d
{

CoreLightCommandRequest::CoreLightCommandRequest()
{
    //
}

CoreLightCommandRequest::~CoreLightCommandRequest()
{
    //
}

Family CoreLightCommandRequest::getFamily() const
{
    return LIGHT;
}

const DataWay& CoreLightCommandRequest::getDataWay() const
{
    return DataWay::UPLOAD;
}

void CoreLightCommandRequest::addNode(const Node& node, const NodeArg& arg)
{
	if (!arg.instanceOf(LightCommandArg_t))
	{
		throw X2dException("Invalid argument => LightCommandRequest::addNode(const Node& node, const NodeArg& arg)");
	}
    CoreRmRequest::addNode(node, arg);
}

void CoreLightCommandRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
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
    frame[25] = (byte)0x20;

    for (int i = 0; i < 16; i++)
    {
        if (m_nodes[i])
        {
            LightCommandArg* arg = (LightCommandArg*)m_nodes[i];
			frame[28 + 2*i] = (byte)arg->toInt();
        }
    }

    CoreRmRequest::serialize(frame);
}

Response* CoreLightCommandRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    return new CoreResponse(ResponseStatus::OK);
}

bool CoreLightCommandRequest::instanceOf(RequestClass type) const
{
	if (type == LightCommandRequest_t) { return true; }
	return false;
}

Request* CoreLightCommandRequest::clone() const
{
	return new CoreLightCommandRequest(*this);
}

void* CoreLightCommandRequest::derived()
{
	return (LightCommandRequest*)this;
}

CoreRequest* CoreLightCommandRequest::core()
{
	return this;
}
}
