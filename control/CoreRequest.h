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

#ifndef COREREQUEST_H
#define COREREQUEST_H

#include "control/Request.h"
#include "control/Response.h"
#include "control/EndTransactionEvent.h"
#include "control/MeshController.h"

namespace deltadoreX2d
{

class CoreRequest : public virtual Request
{
    public :
        CoreRequest();
		CoreRequest(const CoreRequest& from);
        virtual ~CoreRequest();

        Network* getNetwork() const;
        void setNetwork(Network* net);
        const std::vector<Node> nodes() const;
        void addNode(const Node& node, const NodeArg& arg);
        void removeNode(const Node& node);
        const NodeArg& getNodeArg(const Node& node) const;
        int getChannel() const;
        void setChannel(int id);

        Response* getResponse(const Node& node) const;
        const std::vector<Node> getUnreachableNodes(int nack16) const;
		virtual void serialize(std::vector<byte>& frame) const;
		virtual void serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const=0;
        virtual Response* createData(const std::vector< std::vector<byte> >& frames, int indice) const=0;
        virtual EndTransactionEvent getEndTransactionEvent(MeshController* controller, const std::vector< std::vector<byte> >& frames)=0;

        Network* m_network;
        const NodeArg* m_nodes[16];
        Response* m_responses[16];
        int m_channelId;
};
}

#endif // COREREQUEST_H
