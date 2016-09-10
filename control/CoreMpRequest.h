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

#ifndef COREMPREQUEST_H
#define COREMPREQUEST_H

#include "control/CoreRequest.h"

namespace deltadoreX2d
{

class CoreMpRequest: public CoreRequest
{
    public :
        CoreMpRequest();
        ~CoreMpRequest();

        bool isMultiple() const;
        void addNode(const Node& node, const NodeArg& arg);
		void serialize(std::vector<byte>& frame) const;
        EndTransactionEvent getEndTransactionEvent(MeshController* controller, const std::vector< std::vector<byte> >& frames);
};
}

#endif // COREMPREQUEST_H
