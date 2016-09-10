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

#include "control/CoreThermicSetDelayTimeRequest.h"
#include "hvac/ThermicDelayTimeArg.h"
#include "control/CoreResponse.h"

namespace deltadoreX2d
{

CoreThermicSetDelayTimeRequest::CoreThermicSetDelayTimeRequest()
{
	//
}

CoreThermicSetDelayTimeRequest::~CoreThermicSetDelayTimeRequest()
{
	//
}

Family CoreThermicSetDelayTimeRequest::getFamily() const
{
	return HVAC;
}

const DataWay& CoreThermicSetDelayTimeRequest::getDataWay() const
{
	return DataWay::UPLOAD;
}

void CoreThermicSetDelayTimeRequest::addNode(const Node& node, const NodeArg& arg)
{
	if (!arg.instanceOf(ThermicDelayTimeArg_t))
	{
		throw X2dException("Invalid argument => ThermicSetDelayTimeRequest::addNode(const Node& node, const NodeArg& arg)");
	}
    CoreRmRequest::addNode(node, arg);
}

void CoreThermicSetDelayTimeRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
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
	frame[24] = (byte)0x16;
	frame[25] = (byte)0x60;

	for (int i = 0; i < 16; i++)
	{
		if (m_nodes[i])
		{
			ThermicDelayTimeArg* arg = (ThermicDelayTimeArg*)m_nodes[i];
			int value = arg->getDelayTime().toInt();

			frame[29 + 2*i] = (byte)((value >> 8) & 0xFF);
			frame[28 + 2*i] = (byte)(value & 0xFF);
		}
	}

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicSetDelayTimeRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
	return new CoreResponse(ResponseStatus::OK);
}

bool CoreThermicSetDelayTimeRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicSetDelayTimeRequest_t) { return true; }
	return false;
}

Request* CoreThermicSetDelayTimeRequest::clone() const
{
	return new CoreThermicSetDelayTimeRequest(*this);
}

void* CoreThermicSetDelayTimeRequest::derived()
{
	return (ThermicSetDelayTimeRequest*)this;
}

CoreRequest* CoreThermicSetDelayTimeRequest::core()
{
	return this;
}
}
