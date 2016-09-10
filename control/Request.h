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

#ifndef REQUEST_H
#define REQUEST_H

#include "requirement.h"
#include "control/Network.h"
#include "control/Node.h"
#include "control/NodeArg.h"
#include "control/DataWay.h"

namespace deltadoreX2d
{

class CoreRequest;

typedef enum
{
    CommonSettingRequest_t = 0x00,
    CurrentConsumptionRequest_t,
    DiagnosticOverheatingRequest_t,
    EnergyConsumptionRequest_t,
    GetOutdoorTemperatureRequest_t,
    GetRoomTemperatureRequest_t,
    LightCommandRequest_t,
    LightGetColorRequest_t,
    LightInfoRequest_t,
    LightSetColorRequest_t,
    LightSettingRequest_t,
    LightStatusRequest_t,
    PowerConsumptionRequest_t,
    RollerShutterCommandRequest_t,
    RollerShutterInfoRequest_t,
    RollerShutterSettingRequest_t,
    RollerShutterStatusRequest_t,
    SetOutdoorTemperatureRequest_t,
    SetRoomTemperatureRequest_t,
    TemperatureInfoRequest_t,
    ThermicAntiFrostAdjustmentRequest_t,
    ThermicGetDelayTimeRequest_t,
    ThermicInfoRequest_t,
    ThermicRegulationCommandRequest_t,
    ThermicRegulationStatusRequest_t,
    ThermicSetDelayTimeRequest_t,
    ThermicSettingRequest_t,
    ThermicSystemCommandRequest_t,
    ThermicSystemStatusRequest_t
} RequestClass;

class Request
{
    public :
        virtual ~Request(){};

        virtual Network* getNetwork() const=0;
        virtual void setNetwork(Network* net)=0;
        virtual const std::vector<Node> nodes() const=0;
        virtual void addNode(const Node& node, const NodeArg& arg)=0;
        virtual void removeNode(const Node& node)=0;
        virtual const NodeArg& getNodeArg(const Node& node) const=0;
        virtual int getChannel() const=0;
        virtual void setChannel(int id)=0;
        virtual bool isMultiple() const=0;
        virtual const DataWay& getDataWay() const=0;
        virtual Family getFamily() const=0;
		virtual bool instanceOf(RequestClass type) const=0;
		virtual Request* clone() const=0;
		virtual void* derived()=0;
		virtual CoreRequest* core()=0;

		template<class T> T convert() { return (T)this->derived(); }
};
}

#endif // REQUEST_H
