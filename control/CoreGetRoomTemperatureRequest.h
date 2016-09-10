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
** mleforestier        | 052011           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef COREGETROOMTEMPERATUREREQUEST_H
#define COREGETROOMTEMPERATUREREQUEST_H

#include "control/CoreRmRequest.h"
#include "sensor/GetRoomTemperatureRequest.h"

namespace deltadoreX2d
{

class CoreGetRoomTemperatureRequest : public CoreRmRequest , public virtual GetRoomTemperatureRequest
{
    public :
        CoreGetRoomTemperatureRequest();
        ~CoreGetRoomTemperatureRequest();

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

#endif // COREGETROOMTEMPERATUREREQUEST_H
