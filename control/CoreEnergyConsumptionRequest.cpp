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

#include "control/CoreEnergyConsumptionRequest.h"
#include "control/CoreEnergyConsumptionResponse.h"

namespace deltadoreX2d
{

CoreEnergyConsumptionRequest::CoreEnergyConsumptionRequest()
{
    //
}

CoreEnergyConsumptionRequest::~CoreEnergyConsumptionRequest()
{
    //
}

Family CoreEnergyConsumptionRequest::getFamily() const
{
    return METERING;
}

const DataWay& CoreEnergyConsumptionRequest::getDataWay() const
{
    return DataWay::DOWNLOAD;
}

void CoreEnergyConsumptionRequest::addNode(const Node& node, const NodeArg& arg)
{
    CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreEnergyConsumptionRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    byte info;

    if (!receivedFrames)
    {
        info = (byte)0x20;
    }
    else if(receivedFrames->size() == 1)
    {
        info = (byte)0x10;
    }
	else { return; }

	frame.assign(28, 0);

    frame[8] = (byte)0x08;
    frame[24] = (byte)0x11;
    frame[25] = info;

    CoreRmRequest::serialize(frame);
}

Response* CoreEnergyConsumptionRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
    int lng = frame[8] & 0xFF;

    long registerValue = (frame[21 + lng + 2*indice] & 0xFF) << 24;
    registerValue += (frame[20 + lng + 2*indice] & 0xFF) << 16;

    frame = frames[1];

    registerValue += (frame[21 + lng + 2*indice] & 0xFF) << 8;
    registerValue += frame[20 + lng + 2*indice] & 0xFF;

    return new CoreEnergyConsumptionResponse(registerValue);
}

bool CoreEnergyConsumptionRequest::instanceOf(RequestClass type) const
{
	if (type == EnergyConsumptionRequest_t) { return true; }
	return false;
}

Request* CoreEnergyConsumptionRequest::clone() const
{
	return new CoreEnergyConsumptionRequest(*this);
}

void* CoreEnergyConsumptionRequest::derived()
{
	return (EnergyConsumptionRequest*)this;
}

CoreRequest* CoreEnergyConsumptionRequest::core()
{
	return this;
}
}
