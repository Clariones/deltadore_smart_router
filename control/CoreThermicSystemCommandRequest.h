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
** mleforestier        | 052511           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef CORETHERMICSYSTEMCOMMANDREQUEST_H
#define CORETHERMICSYSTEMCOMMANDREQUEST_H

#include "control/CoreRmRequest.h"
#include "hvac/ThermicSystemCommandRequest.h"

namespace deltadoreX2d
{

class CoreThermicSystemCommandRequest : public CoreRmRequest , public virtual ThermicSystemCommandRequest
{
    public :
        CoreThermicSystemCommandRequest();
        ~CoreThermicSystemCommandRequest();

        const DataWay& getDataWay() const;
        Family getFamily() const;
		void addNode(const Node& node, const NodeArg& arg);
		void serialize(std::vector<byte>& frame, const std::vector< std::vector<byte> >* receivedFrames) const;
        Response* createData(const std::vector< std::vector<byte> >& frames, int indice) const;
		bool instanceOf(RequestClass type) const;
		Request* clone() const;
		void* derived();
		CoreRequest* core();
};
}

#endif // CORETHERMICSYSTEMCOMMANDREQUEST_H
