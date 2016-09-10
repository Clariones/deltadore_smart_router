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

#include "control/CoreMpRequest.h"
#include "control/CoreResponse.h"

namespace deltadoreX2d
{

CoreMpRequest::CoreMpRequest()
{
    //
}

CoreMpRequest::~CoreMpRequest()
{
    //
}

bool CoreMpRequest::isMultiple() const
{
    return false;
}

void CoreMpRequest::addNode(const Node& node, const NodeArg& arg)
{
    for(int i = 0 ; i < 16; i++)
    {
        m_nodes[i] = NULL;
    }
    CoreRequest::addNode(node, arg);
}

void CoreMpRequest::serialize(std::vector<byte>& frame) const
{
    frame[3] = (byte)0x03;

    int indice;
    for (indice = 0; indice < 16; indice++)
    {
        if (m_nodes[indice] != NULL)
        {
            break;
        }
    }
    int lng = frame[8] & 0xFF;
    frame[14 + lng] = (byte)(indice & 0xFF);

    CoreRequest::serialize(frame);
}

EndTransactionEvent CoreMpRequest::getEndTransactionEvent(MeshController* controller, const std::vector< std::vector<byte> >& frames)
{
    int topo = 0xFF;
    int ack16 = 0xFF;
    bool use = true;

    for (unsigned int i = 0; i < frames.size(); i++)
    {
		std::vector<byte> frame = frames[i];
        int lng = frame[8] & 0xFF;

        int frameTopo = (frame[10 + lng] & 0xFF) << 8;
        frameTopo += frame[9 + lng] & 0xFF;
        topo &= frameTopo;

        int frameAck16 = (frame[12 + lng] & 0xFF) << 8;
        frameAck16 += frame[11 + lng] & 0xFF;
        ack16 &= frameAck16;

        int frameUse = frame[14 + lng] & 0x10;
        if (frameUse == 0)
        {
            use = false;
        }
    }

    int nack16 = topo ^ ack16;
    std::vector<Node> unreachableNodes = getUnreachableNodes(nack16);

    int indice;
    for (indice = 0; indice < 16; indice++)
    {
        if (m_nodes[indice] != NULL)
        {
            break;
        }
    }
    if (((topo >> indice) & 1) == 0)
    {
        m_responses[indice] = new CoreResponse(ResponseStatus::UNEXISTING_NODE);
    }
    else if (((ack16 >> indice) & 1) == 0)
    {
        m_responses[indice] = new CoreResponse(ResponseStatus::UNREACHABLE_NODE);
    }
    else if (!use)
    {
        m_responses[indice] = new CoreResponse(ResponseStatus::NOT_CAPABLE_NODE);
    }
    else
    {
        m_responses[indice] = createData(frames,indice);
    }

    return EndTransactionEvent(controller, (Request*)this, unreachableNodes);
}
}
