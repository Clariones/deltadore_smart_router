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

#include "control/CoreThermicAntiFrostAdjustmentRequest.h"
#include "control/CoreResponse.h"
#include "hvac/ThermicAntiFrostAdjustmentArg.h"

namespace deltadoreX2d
{

CoreThermicAntiFrostAdjustmentRequest::CoreThermicAntiFrostAdjustmentRequest()
{
	//
}

CoreThermicAntiFrostAdjustmentRequest::~CoreThermicAntiFrostAdjustmentRequest()
{
	//
}

const DataWay& CoreThermicAntiFrostAdjustmentRequest::getDataWay() const
{
	return DataWay::UPLOAD;
}

Family CoreThermicAntiFrostAdjustmentRequest::getFamily() const
{
	return HVAC;
}

void CoreThermicAntiFrostAdjustmentRequest::addNode(const Node& node, const NodeArg& arg)
{
	if (!arg.instanceOf(ThermicAntiFrostAdjustmentArg_t))
	{
		throw X2dException("Invalid argument => ThermicAntiFrostAdjustmentRequest::addNode(const Node& node, const NodeArg& arg)");
	}
    CoreRmRequest::addNode(node, arg);
}

void CoreThermicAntiFrostAdjustmentRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
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
	frame[25] = (byte)0x80;

	for (int i = 0; i < 16; i++)
	{
		if (m_nodes[i])
		{
			ThermicAntiFrostAdjustmentArg* arg = (ThermicAntiFrostAdjustmentArg*)m_nodes[i];
			int value = arg->getSetpoint();
			frame[29 + 2*i] = (byte)((value >> 8) & 0xFF);
			frame[28 + 2*i] = (byte)(value & 0xFF);
		}
	}

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicAntiFrostAdjustmentRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
	return new CoreResponse(ResponseStatus::OK);
}

bool CoreThermicAntiFrostAdjustmentRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicAntiFrostAdjustmentRequest_t) { return true; }
	return false;
}

Request* CoreThermicAntiFrostAdjustmentRequest::clone() const
{
	return new CoreThermicAntiFrostAdjustmentRequest(*this);
}

void* CoreThermicAntiFrostAdjustmentRequest::derived()
{
	return (ThermicAntiFrostAdjustmentRequest*)this;
}

CoreRequest* CoreThermicAntiFrostAdjustmentRequest::core()
{
	return this;
}
}
