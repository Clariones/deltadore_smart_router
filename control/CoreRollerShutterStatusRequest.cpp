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

#include "control/CoreRollerShutterStatusRequest.h"
#include "control/CoreRollerShutterStatusResponse.h"

namespace deltadoreX2d
{

CoreRollerShutterStatusRequest::CoreRollerShutterStatusRequest()
{
    //
}

CoreRollerShutterStatusRequest::~CoreRollerShutterStatusRequest()
{
    //
}

Family CoreRollerShutterStatusRequest::getFamily() const
{
    return ROLLERSHUTTER;
}

const DataWay& CoreRollerShutterStatusRequest::getDataWay() const
{
    return DataWay::DOWNLOAD;
}

void CoreRollerShutterStatusRequest::addNode(const Node& node, const NodeArg& arg)
{
    CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreRollerShutterStatusRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

    frame[8] = (byte)0x08;
    frame[24] = (byte)0x10;
    frame[25] = (byte)0x10;

    CoreRmRequest::serialize(frame);
}

Response* CoreRollerShutterStatusRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
    int lng = frame[8] & 0xFF;

    int position = frame[20 + lng + 2*indice] & 0xFF;
    bool isRaisingFaulty = (frame[21 + lng + 2*indice] & 0x01) == 0x01;
    bool isLoweringFaulty = (frame[21 + lng + 2*indice] & 0x02) == 0x02;
    bool isObstacleFaulty = (frame[21 + lng + 2*indice] & 0x04) == 0x04;
    bool isOverheatingFaulty = (frame[21 + lng + 2*indice] & 0x08) == 0x08;
    bool isFavoritePosition = (frame[21 + lng + 2*indice] & 0x10) == 0x10;
    bool isIntrusionDetected = (frame[21 + lng + 2*indice] & 0x20) == 0x20;

    return new CoreRollerShutterStatusResponse(position,
												   isRaisingFaulty,
												   isLoweringFaulty,
												   isObstacleFaulty,
												   isOverheatingFaulty,
												   isFavoritePosition,
												   isIntrusionDetected);
}

bool CoreRollerShutterStatusRequest::instanceOf(RequestClass type) const
{
	if (type == RollerShutterStatusRequest_t) { return true; }
	return false;
}

Request* CoreRollerShutterStatusRequest::clone() const
{
	return new CoreRollerShutterStatusRequest(*this);
}

void* CoreRollerShutterStatusRequest::derived()
{
	return (RollerShutterStatusRequest*)this;
}

CoreRequest* CoreRollerShutterStatusRequest::core()
{
	return this;
}
}
