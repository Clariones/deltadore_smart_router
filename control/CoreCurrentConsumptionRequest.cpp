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

#include "control/CoreCurrentConsumptionRequest.h"
#include "control/CoreCurrentConsumptionResponse.h"

namespace deltadoreX2d
{

CoreCurrentConsumptionRequest::CoreCurrentConsumptionRequest()
{
    //
}

CoreCurrentConsumptionRequest::~CoreCurrentConsumptionRequest()
{
    //
}

Family CoreCurrentConsumptionRequest::getFamily() const
{
    return METERING;
}

const DataWay& CoreCurrentConsumptionRequest::getDataWay() const
{
    return DataWay::DOWNLOAD;
}

void CoreCurrentConsumptionRequest::addNode(const Node& node, const NodeArg& arg)
{
    CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreCurrentConsumptionRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

    frame[8] = (byte)0x08;
    frame[24] = (byte)0x11;
    frame[25] = (byte)0x40;

    CoreRmRequest::serialize(frame);
}

Response* CoreCurrentConsumptionRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
    int lng = frame[8] & 0xFF;

    int registerValue = (frame[21 + lng + 2*indice] & 0xFF) << 8;
    registerValue += frame[20 + lng + 2*indice] & 0xFF;

    return new CoreCurrentConsumptionResponse(registerValue);
}

bool CoreCurrentConsumptionRequest::instanceOf(RequestClass type) const
{
	if (type == CurrentConsumptionRequest_t) { return true; }
	return false;
}

Request* CoreCurrentConsumptionRequest::clone() const
{
	return new CoreCurrentConsumptionRequest(*this);
}

void* CoreCurrentConsumptionRequest::derived()
{
	return (CurrentConsumptionRequest*)this;
}

CoreRequest* CoreCurrentConsumptionRequest::core()
{
	return this;
}
}
