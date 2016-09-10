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

#ifndef MESHCONTROLLER_H
#define MESHCONTROLLER_H

#include "control/Controller.h"
#include "control/Network.h"
#include "control/Request.h"
#include "control/NodeDiscoveredListener.h"
#include "control/EndTransactionListener.h"

namespace deltadoreX2d
{

class MeshController : public virtual Controller
{
    public :
        virtual ~MeshController(){};

		virtual void initNetworks()=0;
		virtual void initNetworks(int count)=0;
		virtual int getNetworkCount()=0;
        virtual Network* getNetwork(int id)=0;
        virtual Request* createRequest(RequestClass type)=0;
        virtual void beginTransaction(Request* request)=0;
        virtual void addEndTransactionListener(EndTransactionListener* listener)=0;
        virtual void removeEndTransactionListener(EndTransactionListener* listener)=0;
        virtual void addNodeDiscoveredListener(NodeDiscoveredListener* listener)=0;
        virtual void removeNodeDiscoveredListener(NodeDiscoveredListener* listener)=0;
};
}

#endif /* MESHCONTROLLER_H */
