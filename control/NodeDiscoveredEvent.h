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

#ifndef NODEDISCOVEREVENT_H
#define NODEDISCOVEREVENT_H

#include "requirement.h"
#include "control/Network.h"
#include "control/Node.h"

namespace deltadoreX2d
{

class MeshController;

class NodeDiscoveredEvent
{
    public :
        NodeDiscoveredEvent(MeshController* source, Network* network, const Node& node);
		~NodeDiscoveredEvent();

        MeshController* getSource() const;
        Network* getNetwork() const;
        const Node& getNode() const;

    private :
        MeshController* m_source;
        Network* m_net;
        Node m_node;
};
}

#endif /* NODEDISCOVEREVENT_H */
