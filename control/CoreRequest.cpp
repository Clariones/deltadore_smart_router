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

#include "control/CoreRequest.h"
#include "control/CoreResponse.h"

namespace deltadoreX2d
{

CoreRequest::CoreRequest() : m_channelId(1)
{
    m_network = NULL;

    for(int i = 0 ; i < 16; i++)
    {
        m_nodes[i] = NULL;
        m_responses[i] = NULL;
    }
}

CoreRequest::CoreRequest(const CoreRequest& source)
{
	m_network = source.m_network;

    for(int i = 0 ; i < 16; i++)
    {
		if (source.m_nodes[i]) { m_nodes[i] = source.m_nodes[i]->clone(); }
		else { m_nodes[i] = NULL; }
		if (source.m_responses[i]) { m_responses[i] = source.m_responses[i]->clone(); }
		else { m_responses[i] = NULL; }
    }

	m_channelId = source.m_channelId;
}

CoreRequest::~CoreRequest()
{
    for(int i = 0; i < 16; i++)
    {
		if (m_nodes[i]) { delete m_nodes[i]; }
		if (m_responses[i]) { delete m_responses[i]; }
    }
}

Network* CoreRequest::getNetwork() const
{
    return m_network;
}

void CoreRequest::setNetwork(Network* net)
{
	m_network = net;
}

const std::vector<Node> CoreRequest::nodes() const
{
	std::vector<Node> nodes = std::vector<Node>(); 

	for(int i = 0; i < 16; i++)
    {
		if (m_nodes[i]) { nodes.push_back(Node(i)); }
    }
    return nodes;
}

void CoreRequest::addNode(const Node& node, const NodeArg& arg)
{
	m_nodes[node.toInt()] = arg.clone();
}

void CoreRequest::removeNode(const Node& node)
{
	delete m_nodes[node.toInt()];
    m_nodes[node.toInt()] = NULL;
}

const NodeArg& CoreRequest::getNodeArg(const Node& node) const
{
    return *(m_nodes[node.toInt()]);
}

int CoreRequest::getChannel() const
{
    return m_channelId;
}

void CoreRequest::setChannel(int id)
{
    m_channelId = id;
}

Response* CoreRequest::getResponse(const Node& node) const
{
    return m_responses[node.toInt()];
}

const std::vector<Node> CoreRequest::getUnreachableNodes(int nack16) const
{
	std::vector<Node> unreachableNodes = std::vector<Node>();

    for (int i = 0; i < 16; i++)
    {
        if (((nack16 >> i) & 1) == 1)
        {
            unreachableNodes.push_back(Node(i));
        }
    }
    return unreachableNodes;
}

void CoreRequest::serialize(std::vector<byte>& frame) const
{
	if (!m_network)
	{
		throw X2dException("Unspecified network");
	}
	frame[0] = (byte)(frame.size()+2);
    frame[2] = (byte)0x01;
	frame[4] = (byte)(m_network->getIdentifier());
    frame[12] = (byte)(0x80 + m_network->getIdentifier());
    frame[13] = (byte)0x05;
    frame[14] = (byte)0x98;
}
}
