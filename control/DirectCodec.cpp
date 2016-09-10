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

#include "control/DirectCodec.h"
#include "control/CoreController.h"

namespace deltadoreX2d
{

DirectCodec::DirectCodec(CoreController* controller) : Codec(controller)
{
    //
}

DirectCodec::~DirectCodec()
{
    //
}

void DirectCodec::setEnrollmentListeningMode(bool enabled)
{
	std::vector<byte> frame = std::vector<byte>();

    if (enabled)
    {
		byte byteArray[8] = { 0x0A, 0x00, (byte)0x80, 0x01, 0x01, 0x00, 0x00, (byte)0x80 };
		frame.assign(byteArray, byteArray + 8);
    }
    else
    {
        byte byteArray[8] = { 0x0A, 0x00, (byte)0x80, 0x01, 0x00, 0x00, 0x00, 0x00 };
		frame.assign(byteArray, byteArray + 8);
    }
    m_controller->writeOutput(frame);
}

void DirectCodec::setEnrollmentListeningMode(int port)
{
	std::vector<byte> frame = std::vector<byte>();

    byte byteArray[8] = { 0x0A, 0x00, (byte)0x80, 0x01, 0x01, 0x00, 0x00, (byte)port };
	frame.assign(byteArray, byteArray + 8);

    m_controller->writeOutput(frame);
}

void DirectCodec::clearEnrolledSources()
{
	std::vector<byte> frame = std::vector<byte>();

    byte byteArray[8] = { 0x0A, 0x00, (byte)0x80, 0x01, 0x01, 0x00, 0x00, (byte)0xFF };
	frame.assign(byteArray, byteArray + 8);

    m_controller->writeOutput(frame);
}

void DirectCodec::sendMessage(Message* message, const RadioFrequency& frequency)
{
	message->convert<CoreMessage*>()->m_frequency = frequency;

	std::vector<byte> frame;
	message->core()->serialize(frame);
    m_controller->writeOutput(frame);
}
}
