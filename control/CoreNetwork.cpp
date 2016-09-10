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

#include "control/CoreNetwork.h"
#include "control/CoreController.h"
#include "control/NetworkCodec.h"

namespace deltadoreX2d
{

CoreNetwork::CoreNetwork(int id, CoreController* controller)
{
    m_id = id;
    m_controller = controller;
}

CoreNetwork::~CoreNetwork()
{
    //
}

int CoreNetwork::getIdentifier()
{
    return m_id;
}

MeshController* CoreNetwork::getController()
{
    return m_controller;
}

const std::vector<Node> CoreNetwork::getTopology()
{
	m_controller->m_lock.lock();
    std::vector<Node> topo = m_topology;
	m_controller->m_lock.unlock();
	return topo;
}

void CoreNetwork::startNodeDiscovery(bool automatic)
{
    startNodeDiscovery(automatic, 0);
}

void CoreNetwork::startNodeDiscovery(bool automatic, int retries)
{
	m_controller->m_lock.lock();

	NetworkCodec* codec = new NetworkCodec(m_controller);
	codec->setNetwork(this);
	delete(m_controller->m_codec);
	m_controller->m_codec = codec;
	codec->startNodeDiscovery(automatic, retries);

	m_controller->m_lock.unlock();
}

void CoreNetwork::scan()
{
	m_controller->m_lock.lock();

	NetworkCodec* codec = new NetworkCodec(m_controller);
	codec->setNetwork(this);
	delete(m_controller->m_codec);
	m_controller->m_codec = codec;
    codec->scan();

	m_controller->m_lock.unlock();
}

void CoreNetwork::addCurrentNode()
{
	m_controller->m_lock.lock();

	NetworkCodec* codec = new NetworkCodec(m_controller);
	codec->setNetwork(this);
	delete(m_controller->m_codec);
	m_controller->m_codec = codec;
    codec->addCurrentNode();

	m_controller->m_lock.unlock();
}

void CoreNetwork::scanNode(const Node& node)
{
	m_controller->m_lock.lock();

	NetworkCodec* codec = new NetworkCodec(m_controller);
	codec->setNetwork(this);
	delete(m_controller->m_codec);
	m_controller->m_codec = codec;
    codec->scanNode(node);

	m_controller->m_lock.unlock();
}

void CoreNetwork::deleteNode(const Node& node, bool forced)
{
	m_controller->m_lock.lock();

	NetworkCodec* codec = new NetworkCodec(m_controller);
	codec->setNetwork(this);
	delete(m_controller->m_codec);
	m_controller->m_codec = codec;
    codec->deleteNode(node, forced);

	m_controller->m_lock.unlock();
}

void CoreNetwork::deleteAllNodes()
{
	m_controller->m_lock.lock();

	NetworkCodec* codec = new NetworkCodec(m_controller);
	codec->setNetwork(this);
	delete(m_controller->m_codec);
	m_controller->m_codec = codec;
    codec->deleteAllNodes();

	m_controller->m_lock.unlock();
}

void CoreNetwork::deleteReachableNodes()
{
	m_controller->m_lock.lock();

	NetworkCodec* codec = new NetworkCodec(m_controller);
	codec->setNetwork(this);
	delete(m_controller->m_codec);
	m_controller->m_codec = codec;
    codec->deleteReachableNodes();

	m_controller->m_lock.unlock();
}

void CoreNetwork::deleteUnreachableNodes()
{
	m_controller->m_lock.lock();

	NetworkCodec* codec = new NetworkCodec(m_controller);
	codec->setNetwork(this);
	delete(m_controller->m_codec);
	m_controller->m_codec = codec;
    codec->deleteUnreachableNodes();

	m_controller->m_lock.unlock();
}

CoreNetwork* CoreNetwork::derived()
{
    return this;
}
}
