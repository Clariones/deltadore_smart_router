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

#include "control/MeshCodec.h"
#include "control/CoreController.h"

namespace deltadoreX2d
{

MeshCodec::MeshCodec(CoreController* controller) :
	NetworkCodec(controller)
{
    m_request = NULL;
}

MeshCodec::~MeshCodec()
{
    if (m_request) { delete m_request; }
}

void MeshCodec::decode(const std::vector<byte>& frame, int ctrl)
{
    if (ctrl == 0x06)
    { //Controller answer
        m_receivedFrames.push_back(frame);

        std::vector<byte> frameToSend;
		m_request->serialize(frameToSend, &m_receivedFrames);

		if(frameToSend.size() != 0)
        {
            m_controller->fireAcknowledgment(AcknowledgmentEvent(m_controller, Acknowledgment::PRE_ACK));
            m_controller->writeOutput(frameToSend);
            return;
        }
        else
        {
            EndTransactionEvent evt = m_request->getEndTransactionEvent(m_controller, m_receivedFrames);
            m_controller->fireEndTransaction(evt);
        }
    }

    NetworkCodec::decode(frame, ctrl);
}

void MeshCodec::beginTransaction()
{
    std::vector<byte> frame;
	m_request->serialize(frame, NULL);
    m_controller->writeOutput(frame);
}

void MeshCodec::adoptRequest(Request* request)
{
	m_request = request->clone()->core();
}
}
