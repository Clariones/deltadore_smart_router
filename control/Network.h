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

#ifndef NETWORK_H
#define NETWORK_H

#include "control/Node.h"

namespace deltadoreX2d
{

class MeshController;
class CoreNetwork;

class Network
{
    public :
        virtual ~Network(){};

        virtual int getIdentifier()=0;
        virtual MeshController* getController()=0;
        virtual const std::vector<Node> getTopology()=0;
        virtual void startNodeDiscovery(bool automatic)=0;
		virtual void startNodeDiscovery(bool automatic, int retries)=0;
		virtual void scan()=0;
        virtual void addCurrentNode()=0;
        virtual void scanNode(const Node& node)=0;
        virtual void deleteNode(const Node& node, bool forced)=0;
        virtual void deleteAllNodes()=0;
        virtual void deleteReachableNodes()=0;
        virtual void deleteUnreachableNodes()=0;
		virtual CoreNetwork* derived()=0;
};
}

#endif /* NETWORK_H */
