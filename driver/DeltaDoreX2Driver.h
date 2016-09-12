#ifndef DELTADOREX2DRIVER_H
#define DELTADOREX2DRIVER_H

#include "requirement.h"
#include "driver/SerialPort.h"
#include "driver/cJSON.h"
#include "driver/DeltaDoreDeviceInfo.h"

#include "control/Node.h"
#include "control/Response.h"
#include "control/Request.h"
#include "rollershutter/RollerShutterStatusResponse.h"
#include "rollershutter/RollerShutterCommandArg.h"
#include "control/NodeDiscoveredEvent.h"
#include "control/Controller.h"
#include "control/Factory.h"
#include "control/MeshController.h"
#include "control/DirectController.h"
#include "control/Network.h"
#include "control/Node.h"

#include <semaphore.h>

#ifndef NULL
#define NULL (void*)0
#endif

#define MAX_NETWORK_NUM 12
#define MAX_NODE_NUM 16

using namespace deltadoreX2d;


class DeltaDoreX2Driver: public AcknowledgmentListener, public EndTransactionListener, public NodeDiscoveredListener
{
    public:
        DeltaDoreX2Driver();
        virtual ~DeltaDoreX2Driver();

    // callback functions
    public:
        virtual void acknowledgment(const AcknowledgmentEvent& evt);
        virtual void endTransaction(const EndTransactionEvent& evt);
        virtual void nodeDiscovered(const NodeDiscoveredEvent& evt);
    // command interfaces
    public:
        cJSON* getTopology();
        cJSON* queryRollerShutterStatus(int network, int node);
        cJSON* controlRollerShutter(int network, int node, const RollerShutterCommandArg& action);
        cJSON* openRollerShutter(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::UP);}
        cJSON* openRollerShutterSlowly(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::UP_SLOW);}
        cJSON* closeRollerShutter(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::DOWN);}
        cJSON* closeRollerShutterSlowly(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::DOWN_SLOW);}
        cJSON* stopRollerShutter(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::STOP);}

        cJSON* deleteNode(int network, int node);
        cJSON* registerNode(int network);

    public:
        void init(const char* devName);
        void waitAck();

    protected:
        void onRollerShutterStatusResponse(RollerShutterStatusResponse& response);
        DeltaDoreDeviceInfo* getDeviceInfo(int network, int node);

        RequestClass getContextRequestClass() { return contextRequestClass;}
        void setContextRequestClass(RequestClass reqClass) {
            contextRequestClass=reqClass;
            if (contextRequestClass == CurrentConsumptionRequest_t){
                contextResponseClass = ThermicSystemStatusResponse_t;
            }else{
                contextResponseClass=CurrentConsumptionResponse_t;
            }
        }
        ResponseClass getContextResponseClass() { return contextResponseClass;}
        void setContextResponseClass(ResponseClass resClass) { contextResponseClass=resClass;}

        int getContextRequestNetwork() { return contextRequestNetwork;}
        void setContextRequestNetwork(int network) { contextRequestNetwork = network;}

        int getContextRequestNode() { return contextRequestNode;}
        void setContextRequestNode(int node) { contextRequestNode = node;}

    private:
        SerialPort device;
        Controller* controller;
        sem_t semAck;
        bool acked;
        RequestClass contextRequestClass;
        ResponseClass contextResponseClass;
        int contextRequestNetwork;
        int contextRequestNode;
        DeltaDoreDeviceInfo* allDeviceInfo[MAX_NETWORK_NUM][MAX_NODE_NUM];
};

#endif // DELTADOREX2DRIVER_H
