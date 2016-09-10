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

#include "control/CoreRollerShutterInfoRequest.h"
#include "control/CoreRollerShutterInfoResponse.h"
#include "rollershutter/RollerShutterActuatorType.h"

namespace deltadoreX2d
{

CoreRollerShutterInfoRequest::CoreRollerShutterInfoRequest()
{
    //
}

CoreRollerShutterInfoRequest::~CoreRollerShutterInfoRequest()
{
    //
}

Family CoreRollerShutterInfoRequest::getFamily() const
{
    return ROLLERSHUTTER;
}

const DataWay& CoreRollerShutterInfoRequest::getDataWay() const
{
    return DataWay::DOWNLOAD;
}

void CoreRollerShutterInfoRequest::addNode(const Node& node, const NodeArg& arg)
{
    CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreRollerShutterInfoRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

    frame[8] = (byte)0x08;
    frame[24] = (byte)0x10;

    CoreRmRequest::serialize(frame);
}

Response* CoreRollerShutterInfoRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
    int lng = frame[8] & 0xFF;

    int channelCount = frame[20 + lng + 2*indice] & 0x0F;
    int type = (frame[20 + lng + 2*indice] & 0x70) >> 4;
    RollerShutterActuatorType actuatorType = RollerShutterActuatorType(type);

    return new CoreRollerShutterInfoResponse(channelCount, actuatorType);
}

bool CoreRollerShutterInfoRequest::instanceOf(RequestClass type) const
{
	if (type == RollerShutterInfoRequest_t) { return true; }
	return false;
}

Request* CoreRollerShutterInfoRequest::clone() const
{
	return new CoreRollerShutterInfoRequest(*this);
}

void* CoreRollerShutterInfoRequest::derived()
{
	return (RollerShutterInfoRequest*)this;
}

CoreRequest* CoreRollerShutterInfoRequest::core()
{
	return this;
}
}
