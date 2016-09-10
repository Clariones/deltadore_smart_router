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

#include "control/EndTransactionEvent.h"
#include "control/CoreRequest.h"
#include "control/CoreResponse.h"

namespace deltadoreX2d
{

EndTransactionEvent::EndTransactionEvent(MeshController* source,
										Request* request,
										const std::vector<Node>& unreachableNodes) :
	m_unreachableNodes(unreachableNodes)
{
    m_source = source;
    m_request = request;
}

EndTransactionEvent::~EndTransactionEvent()
{
	//
}

MeshController* EndTransactionEvent::getSource() const
{
    return m_source;
}

const Request* EndTransactionEvent::getRequest() const
{
    return m_request;
}

const Response* EndTransactionEvent::getResponse(const Node& node) const
{
    return m_request->core()->getResponse(node);
}

const std::vector<Node>& EndTransactionEvent::getUnreachableNodes() const
{
    return m_unreachableNodes;
}
}
