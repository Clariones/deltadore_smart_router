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

#ifndef ENDTRANSACTIONEVENT_H
#define ENDTRANSACTIONEVENT_H

#include "control/Request.h"
#include "control/Response.h"
#include "control/Node.h"

namespace deltadoreX2d
{

class MeshController;

class EndTransactionEvent
{
    public :
        EndTransactionEvent(MeshController* source, Request* request, const std::vector<Node>& unreachableNodes);
        ~EndTransactionEvent();

        MeshController* getSource() const;
        const Request* getRequest() const;
        const Response* getResponse(const Node& node) const;
        const std::vector<Node>& getUnreachableNodes() const;

    private:
        MeshController* m_source;
        Request* m_request;
        std::vector<Node> m_unreachableNodes;
};
}

#endif /* ENDTRANSACTIONEVENT_H */
