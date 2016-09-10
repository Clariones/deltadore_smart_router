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

#include "control/CoreThermicRegulationCommandRequest.h"
#include "hvac/ThermicRegulationCommandArg.h"
#include "control/CoreResponse.h"

namespace deltadoreX2d
{

CoreThermicRegulationCommandRequest::CoreThermicRegulationCommandRequest()
{
	//
}

CoreThermicRegulationCommandRequest::~CoreThermicRegulationCommandRequest()
{
	//
}

const DataWay& CoreThermicRegulationCommandRequest::getDataWay() const
{
	return DataWay::UPLOAD;
}

Family CoreThermicRegulationCommandRequest::getFamily() const
{
	return HVAC;
}

void CoreThermicRegulationCommandRequest::addNode(const Node& node, const NodeArg& arg)
{
 	if (!arg.instanceOf(ThermicRegulationCommandArg_t))
	{
		throw X2dException("Invalid argument => ThermicRegulationCommandRequest::addNode(const Node& node, const NodeArg& arg)");
	}
    CoreRmRequest::addNode(node, arg);
}

void CoreThermicRegulationCommandRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
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
	frame[25] = (byte)0x30;

	for (int i = 0; i < 16; i++)
	{
		if (m_nodes[i])
		{
			ThermicRegulationCommandArg* arg = (ThermicRegulationCommandArg*)m_nodes[i];
			frame[28 + 2*i] = (byte)arg->getLevel().toInt();
			frame[29 + 2*i] = (byte)arg->getMode().toInt();

			if (arg->isLevelTemporary())
			{
				frame[29 + 2*i] |= 0x08;
			}
		}
	}

	CoreRmRequest::serialize(frame);
}

Response* CoreThermicRegulationCommandRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
	return new CoreResponse(ResponseStatus::OK);
}

bool CoreThermicRegulationCommandRequest::instanceOf(RequestClass type) const
{
	if (type == ThermicRegulationCommandRequest_t) { return true; }
	return false;
}

Request* CoreThermicRegulationCommandRequest::clone() const
{
	return new CoreThermicRegulationCommandRequest(*this);
}

void* CoreThermicRegulationCommandRequest::derived()
{
	return (ThermicRegulationCommandRequest*)this;
}

CoreRequest* CoreThermicRegulationCommandRequest::core()
{
	return this;
}
}
