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

#include "control/CoreRmRequest.h"
#include "control/CoreResponse.h"

namespace deltadoreX2d
{

CoreRmRequest::CoreRmRequest()
{
    //
}

CoreRmRequest::~CoreRmRequest()
{
    //
}

bool CoreRmRequest::isMultiple() const
{
	return true;
}

void CoreRmRequest::serialize(std::vector<byte>& frame) const
{
    frame[3] = (byte)0x01;
    int destination = 0;

    for (int indice = 0; indice < 16; indice++)
    {
        if (m_nodes[indice])
        {
            destination |= 1 << indice;
        }
    }

    int lng = frame[8] & 0xFF;
    frame[13 + lng] = (byte)(destination & 0xFF);
    frame[14 + lng] = (byte)((destination >> 8) & 0xFF);
    frame[17 + lng] |= (byte)(m_channelId & 0x0F);

    CoreRequest::serialize(frame);
}

EndTransactionEvent CoreRmRequest::getEndTransactionEvent(MeshController* controller, const std::vector< std::vector<byte> >& frames)
{
    int topo = 0xFFFF;
    int ack16 = 0xFFFF;
    int dest16 = 0xFFFF;
    int use16 = 0xFFFF;

    for (unsigned int i = 0; i < frames.size(); i++)
    {
        std::vector<byte> frame = (std::vector<byte>)frames[i];
        int lng = frame[8] & 0xFF;

        int frameTopo = (frame[10 + lng] & 0xFF) << 8;
        frameTopo += frame[9 + lng] & 0xFF;
        topo &= frameTopo;

        int frameAck16 = (frame[12 + lng] & 0xFF) << 8;
        frameAck16 += frame[11 + lng] & 0xFF;
        ack16 &= frameAck16;

        int frameDest16 = (frame[14 + lng] & 0xFF) << 8;
        frameDest16 += frame[13 +  lng] & 0xFF;
        dest16 &= frameDest16;

        int frameUse16 = (frame[19 + lng] & 0xFF) << 8;
        frameUse16 += frame[18 + lng] & 0xFF;
        use16 &= frameUse16;
    }

    int nack16 = topo ^ ack16;
    std::vector<Node> unreachableNodes = getUnreachableNodes(nack16);

    for (int i = 0; i < 16; i++)
    {
        if (((dest16 >> i) & 1) == 1)
        {
            if (((topo >> i) & 1) == 0)
            {
                m_responses[i] = new CoreResponse(ResponseStatus::UNEXISTING_NODE);
            }
            else if (((ack16 >> i) & 1) == 0)
            {
                m_responses[i] = new CoreResponse(ResponseStatus::UNREACHABLE_NODE);
            }
            else if (((use16 >> i) & 1) == 0)
            {
                m_responses[i] = new CoreResponse(ResponseStatus::NOT_CAPABLE_NODE);
            }
            else
            {
                m_responses[i] = createData(frames ,i);
            }
        }
    }

	return EndTransactionEvent(controller, (Request*)this, unreachableNodes);
}
}
