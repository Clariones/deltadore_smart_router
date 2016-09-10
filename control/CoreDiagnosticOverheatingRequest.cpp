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
** mleforestier        | 041811           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreDiagnosticOverheatingRequest.h"
#include "control/CoreDiagnosticOverheatingResponse.h"

namespace deltadoreX2d
{

CoreDiagnosticOverheatingRequest::CoreDiagnosticOverheatingRequest()
{
	//
}

CoreDiagnosticOverheatingRequest::~CoreDiagnosticOverheatingRequest()
{
	//
}

Family CoreDiagnosticOverheatingRequest::getFamily() const
{
	return DIAGNOSTIC;
}

const DataWay& CoreDiagnosticOverheatingRequest::getDataWay() const
{
	return DataWay::DOWNLOAD;
}

void CoreDiagnosticOverheatingRequest::addNode(const Node& node, const NodeArg& arg)
{
	CoreRmRequest::addNode(node, NodeArg::NONE);
}

void CoreDiagnosticOverheatingRequest::serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const
{
    if (receivedFrames) { return; }

	frame.assign(28, 0);

	frame[8] = (byte)0x08;
	frame[24] = (byte)0x13;
	frame[25] = (byte)0x00;

	CoreRmRequest::serialize(frame);
}

Response* CoreDiagnosticOverheatingRequest::createData(const std::vector< std::vector<byte> >& frames, int indice) const
{
    std::vector<byte> frame = frames[0];
	int lng = frame[8] & 0xFF;

	int temperature = (frame[21 + lng + 2*indice] & 0xFF) << 8;
	temperature += frame[20 + lng + 2*indice] & 0xFF;

	return new CoreDiagnosticOverheatingResponse(temperature);
}

bool CoreDiagnosticOverheatingRequest::instanceOf(RequestClass type) const
{
	if (type == DiagnosticOverheatingRequest_t) { return true; }
	return false;
}

Request* CoreDiagnosticOverheatingRequest::clone() const
{
	return new CoreDiagnosticOverheatingRequest(*this);
}

void* CoreDiagnosticOverheatingRequest::derived()
{
	return (DiagnosticOverheatingRequest*)this;
}

CoreRequest* CoreDiagnosticOverheatingRequest::core()
{
	return this;
}
}
