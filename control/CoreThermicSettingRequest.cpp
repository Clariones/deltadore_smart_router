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

#include "control/CoreThermicSettingRequest.h"
#include "control/CoreResponse.h"
#include "hvac/ThermicSettingArg.h"

namespace deltadoreX2d
{

CoreThermicSettingRequest::CoreThermicSettingRequest()
{
	//
}

CoreThermicSettingRequest::~CoreThermicSettingRequest()
{
	//
}

const DataWay& CoreThermicSettingRequest::getDataWay() const
{
	return DataWay::UPLOAD;
}

Family CoreThermicSettingRequest::getFamily() const
{
	return HVAC;
}

void CoreThermicSettingRequest::addNode(const Node& node, const NodeArg& arg)
{
	if (!arg.instanceOf(ThermicSettingArg_t))
	{
		throw X2dException("Invalid argument => ThermicSettingRequest::addNode(const Node& node, const NodeArg& arg)");
	}
	CoreRmRequest::addNode(node, arg);
}

void CoreThermicSettingRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
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
	frame[25] = (byte)0x70;

	for (int i = 0; i < 16; i++)
	{
		if (m_nodes[i])
		{
			ThermicSettingArg* arg = (ThermicSettingArg*)m_nodes[i];
			frame[28 + 2*i] = (byte)arg->toInt();
		}
	}

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicSettingRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
	return new CoreResponse(ResponseStatus::OK);
}

bool CoreThermicSettingRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicSettingRequest_t) { return true; }
	return false;
}

Request* CoreThermicSettingRequest::clone() const
{
	return new CoreThermicSettingRequest(*this);
}

void* CoreThermicSettingRequest::derived()
{
	return (ThermicSettingRequest*)this;
}

CoreRequest* CoreThermicSettingRequest::core()
{
	return this;
}
}
