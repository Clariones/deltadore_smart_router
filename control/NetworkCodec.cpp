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

#include "control/NetworkCodec.h"
#include "control/CoreController.h"
#include "control/NodeDiscoveredEvent.h"

namespace deltadoreX2d
{

NetworkCodec::NetworkCodec(CoreController* controller) : Codec(controller)
{
    m_network = NULL;
}

NetworkCodec::~NetworkCodec()
{
	//
}

void NetworkCodec::decode(const std::vector<byte>& frame, int ctrl)
{
    if (ctrl == 0x02)
    { //Controller partial answer
        setTopology(frame);
    }
    else if (ctrl == 0x06)
    { //Controller answer
        int frameType = frame[2] & 0xFF;
        int frameSubtype = frame[3] & 0xFF;

        if (frameType == 128)
        { //service
            if (frameSubtype == 10)
            {
                setAllTopology(frame);
            }
        }
        else
        { //protocol
            setTopology(frame);
        }
    }
    Codec::decode(frame, ctrl);
}

void NetworkCodec::getAllTopology()
{
	std::vector<byte> frame = std::vector<byte>();

    byte byteArray[8] = { 0x0A, 0x00,(byte)0x80, 0x0A, 0x00, 0x00, 0x00, 0x00 };
	frame.assign(byteArray, byteArray + 8);

    m_controller->writeOutput(frame);
}

void NetworkCodec::startNodeDiscovery(bool automatic, int retries)
{
	int netId = m_network->getIdentifier();
	std::vector<byte> frame = std::vector<byte>();

    if (automatic)
    {
        byte byteArray[28] =
		{
			0x1E, 0x00,
            0x02, 0x00, (byte)netId, (byte)(retries & 0xFF), 0x00, 0x00,
            0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
            0x00, 0x00, 0x00,
            0x00, 0x00, 0x1F, (byte)0xFF, 0x00, 0x00, 0x00, 0x00, 0x00
		};
		frame.assign(byteArray, byteArray + 28);
    }
    else
    {
        byte byteArray[28] =
		{
			0x1E, 0x00,
            0x01, 0x02, (byte)netId, (byte)(retries & 0xFF), 0x00, 0x00,
            0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
            0x00, 0x00, 0x00,
            0x00, 0x00, 0x1F, (byte)0xFF, 0x00, 0x00, 0x00, 0x00, (byte)0xE0
        };
		frame.assign(byteArray, byteArray + 28);
    }
    m_controller->writeOutput(frame);
}

void NetworkCodec::scan()
{
    int netId = m_network->getIdentifier();
	std::vector<byte> frame = std::vector<byte>();
    byte byteArray[28] =
	{
		0x1E, 0x00,
        0x01, 0x02, (byte)netId, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x1F, (byte)0xFF, 0x00, 0x00, 0x00, 0x00, (byte)0xE2
    };
	frame.assign(byteArray, byteArray + 28);
    m_controller->writeOutput(frame);
}

void NetworkCodec::addCurrentNode()
{
    int netId = m_network->getIdentifier();
	std::vector<byte> frame = std::vector<byte>();
    byte byteArray[28] =
	{
		0x1E, 0x00,
        0x01, 0x02, (byte)netId, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x1F, (byte)0xFF, 0x00, 0x00, 0x00, 0x00, (byte)0xE4
    };
	frame.assign(byteArray, byteArray + 28);
    m_controller->writeOutput(frame);
}

void NetworkCodec::scanNode(const Node& node)
{
    int netId = m_network->getIdentifier();
	std::vector<byte> frame = std::vector<byte>();
    byte byteArray[26] =
	{
		0x1C, 0x00,
        0x01, 0x03, (byte)netId, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, (byte)node.toInt(), 0x00, (byte)0xE0, (byte)0xFF
    };
	frame.assign(byteArray, byteArray + 26);
    m_controller->writeOutput(frame);
}

void NetworkCodec::deleteNode(const Node& node, bool forced)
{
    int netId = m_network->getIdentifier();
    int action = forced ? 0xE5 : 0xE1;

	std::vector<byte> frame = std::vector<byte>();
    byte byteArray[26] =
	{
		0x1C, 0x00,
        0x01, 0x03, (byte)netId, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, (byte)node.toInt(), 0x00, (byte)action, (byte)0xFF
    };
	frame.assign(byteArray, byteArray + 26);
    m_controller->writeOutput(frame);
}

void NetworkCodec::deleteAllNodes()
{
    int netId = m_network->getIdentifier();
	std::vector<byte> frame = std::vector<byte>();
    byte byteArray[28] =
	{
		0x1E, 0x00,
        0x01, 0x01, (byte)netId, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, (byte)0xFF, (byte)0xFF, 0x00, (byte)0xE0, 0x00, 0x00, 0x00
    };
	frame.assign(byteArray, byteArray + 28);
    m_controller->writeOutput(frame);
}

void NetworkCodec::deleteReachableNodes()
{
    int netId = m_network->getIdentifier();
	std::vector<byte> frame = std::vector<byte>();
    byte byteArray[28] =
	{
		0x1E, 0x00,
        0x01, 0x01, (byte)netId, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, (byte)0xFF, (byte)0xFF, 0x00, (byte)0xE1, 0x00, 0x00, 0x00
    };
	frame.assign(byteArray, byteArray + 28);
    m_controller->writeOutput(frame);
}

void NetworkCodec::deleteUnreachableNodes()
{
    int netId = m_network->getIdentifier();
	std::vector<byte> frame = std::vector<byte>();
    byte byteArray[28] =
	{
		0x1E, 0x00,
        0x01, 0x01, (byte)netId, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00, (byte)(0x80 + netId), 0x05, (byte)0x98, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, (byte)0xFF, (byte)0xFF, 0x00, (byte)0xE2, 0x00, 0x00, 0x00
    };
	frame.assign(byteArray, byteArray + 28);
    m_controller->writeOutput(frame);
}

void NetworkCodec::setAllTopology(const std::vector<byte>& frame)
{
	int lng = frame[8] & 0xFF;
	unsigned int netCount = lng / 2;

	if (m_controller->m_networks.size() == 0)
	{
        for (unsigned int i = 0; i < netCount; i++)
    	{
			m_controller->m_networks.push_back(CoreNetwork(i, m_controller));
    	}
    }

	if (m_controller->m_networks.size() < netCount)
	{
		netCount = m_controller->m_networks.size();
	}

    for (unsigned int j = 0; j < netCount; j++)
    {
        int topo = (frame[10 + 2*j] & 0xFF) << 8;
        topo += frame[9 + 2*j] & 0xFF;

        int size = 0;
        for (int i = 0; i < 16; i++)
        {
            if (((topo >> i) & 1) == 1)
            {
                size++;
            }
        }

        std::vector<Node> newTopo;

        for (int i = 0; i < 16; i++)
		{
            if (((topo >> i) & 1) == 1)
            {
                newTopo.push_back(Node(i));
            }
        }
   	   	m_controller->m_networks[j].m_topology = newTopo;
    }
}

void NetworkCodec::setTopology(const std::vector<byte>& frame)
{
    int lng = frame[8] & 0xFF;
    int topo = (frame[10 + lng] & 0xFF) << 8;
    topo += frame[9 + lng] & 0xFF;

    int size = 0;
    for (int i = 0; i < 16; i++)
    {
        if (((topo >> i) & 1) == 1)
        {
            size++;
        }
    }

    std::vector<Node> newTopo;
    for (int i = 0; i < 16; i++)
    {
        if (((topo >> i) & 1) == 1)
        {
            newTopo.push_back(Node(i));
        }
    }

    const std::vector<Node>& oldTopo = m_network->getTopology();
    m_network->m_topology = newTopo;

    if (oldTopo.size() < newTopo.size())
    { //Nodes added
        unsigned int j = 0;
        for (unsigned int i = 0; i < newTopo.size(); i++)
        {
            if (j >= oldTopo.size())
            {
                m_controller->fireNodeDiscovered(NodeDiscoveredEvent(m_controller, m_network, newTopo[i]));
            }
            else if (newTopo[i] != oldTopo[j])
            {
                m_controller->fireNodeDiscovered(NodeDiscoveredEvent(m_controller, m_network, newTopo[i]));
            }
            else
            {
                j++;
            }
        }
    }
}

void NetworkCodec::setNetwork(CoreNetwork* network)
{
	m_network = network;
}
}
