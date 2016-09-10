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

#ifndef CORENETWORK_H
#define CORENETWORK_H

#include "control/Network.h"

namespace deltadoreX2d
{

class CoreController;

class CoreNetwork : public virtual Network
{
    public :
        CoreNetwork(int id, CoreController* controller);
        ~CoreNetwork();

        int getIdentifier();
        MeshController* getController();
        const std::vector<Node> getTopology();
        void startNodeDiscovery(bool automatic);
        void startNodeDiscovery(bool automatic, int retries);
        void scan();
        void addCurrentNode();
        void scanNode(const Node& node);
        void deleteNode(const Node& node, bool forced);
        void deleteAllNodes();
        void deleteReachableNodes();
        void deleteUnreachableNodes();
        CoreNetwork* derived();

        int m_id;
        CoreController* m_controller;
		std::vector<Node> m_topology;
};
}

#endif // CORENETWORK_H
