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

#include "control/CoreThermicSystemCommandRequest.h"
#include "control/CoreResponse.h"
#include "hvac/ThermicSystemCommandArg.h"

namespace deltadoreX2d
{

CoreThermicSystemCommandRequest::CoreThermicSystemCommandRequest()
{
	//
}

CoreThermicSystemCommandRequest::~CoreThermicSystemCommandRequest()
{
	//
}

const DataWay& CoreThermicSystemCommandRequest::getDataWay() const
{
	return DataWay::UPLOAD;
}

Family CoreThermicSystemCommandRequest::getFamily() const
{
	return HVAC;
}

void CoreThermicSystemCommandRequest::addNode(const Node& node, const NodeArg& arg)
{
	if (!arg.instanceOf(ThermicSystemCommandArg_t))
	{
		throw X2dException("Invalid argument => ThermicSystemCommandRequest::addNode(const Node& node, const NodeArg& arg)");
	}
	CoreRmRequest::addNode(node, arg);
}

void CoreThermicSystemCommandRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
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
	frame[25] = (byte)0x40;

	for (int i = 0; i < 16; i++)
	{
		if (m_nodes[i])
		{
			ThermicSystemCommandArg* arg = (ThermicSystemCommandArg*)m_nodes[i];
			frame[28 + 2*i] = (byte)(arg->getFanMode().toInt() << 3);
			frame[28 + 2*i] += (byte)arg->getSystemMode().toInt();
			if (arg->isDehumidifying()) { frame[28 + 2*i] |= 0x40; }
			if (arg->isFreeCooling()) { frame[28 + 2*i] |= 0x80; }
			frame[29 + 2*i] = (byte)arg->getReheatingMode().toInt();
		}
	}

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicSystemCommandRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
	return new CoreResponse(ResponseStatus::OK);
}

bool CoreThermicSystemCommandRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicSystemCommandRequest_t) { return true; }
	return false;
}

Request* CoreThermicSystemCommandRequest::clone() const
{
	return new CoreThermicSystemCommandRequest(*this);
}

void* CoreThermicSystemCommandRequest::derived()
{
	return (ThermicSystemCommandRequest*)this;
}

CoreRequest* CoreThermicSystemCommandRequest::core()
{
	return this;
}
}
