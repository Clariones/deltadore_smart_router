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
#include "rollershutter/RollerShutterInfoResponse.h"
#include "rollershutter/RollerShutterCommandArg.h"
#include "light/LightCommandArg.h"
#include "light/LightStatusResponse.h"
#include "light/LightInfoResponse.h"
#include "light/LightColorResponse.h"
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

        cJSON* deleteNode(int network, int node);
        cJSON* registerNode(int network);

        cJSON* queryRollerShutterStatus(int network, int node);
        cJSON* queryRollerShutterInfo(int network, int node);
        cJSON* controlRollerShutter(int network, int node, const RollerShutterCommandArg& action);
        cJSON* openRollerShutter(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::UP);}
        cJSON* openRollerShutterSlowly(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::UP_SLOW);}
        cJSON* closeRollerShutter(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::DOWN);}
        cJSON* closeRollerShutterSlowly(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::DOWN_SLOW);}
        cJSON* stopRollerShutter(int network, int node) { return controlRollerShutter(network, node, RollerShutterCommandArg::STOP);}

        cJSON* queryLightStatus(int network, int node);
        cJSON* queryLightInfo(int network, int node);
        cJSON* controlLight(int network, int node, const LightCommandArg& action);
        cJSON* setLightLevel(int network, int node, int level);
        cJSON* switchOffLight(int network, int node){ return controlLight(network, node, LightCommandArg::DOWN);}
        cJSON* switchOnLight(int network, int node){ return controlLight(network, node, LightCommandArg::UP);}
        cJSON* stopLight(int network, int node){ return controlLight(network, node, LightCommandArg::STOP);}
        cJSON* rampUpLight(int network, int node){ return controlLight(network, node, LightCommandArg::UP_SLOW);}
        cJSON* ramDownLight(int network, int node){ return controlLight(network, node, LightCommandArg::DOWN_SLOW);}
        cJSON* preset1Light(int network, int node){ return controlLight(network, node, LightCommandArg::GO_FAVORITE_1);}
        cJSON* alarmPairingLight(int network, int node){ return controlLight(network, node, LightCommandArg::ALARM_PAIRING);}
        cJSON* standOutLight(int network, int node){ return controlLight(network, node, LightCommandArg::STAND_OUT);}
        cJSON* preset2Light(int network, int node){ return controlLight(network, node, LightCommandArg::GO_FAVORITE_2);}
        cJSON* toggleLight(int network, int node){ return controlLight(network, node, LightCommandArg::TOGGLE);}
        cJSON* setLightColor(int network, int node, int red, int green, int blue);
        cJSON* queryLightColor(int network, int node);

        cJSON* debugPrintRead(bool enablePrint);

    public:
        void init(const char* devName, const char* storageFile);
        void waitAck();
        bool initSuccess() { return device.initSuccess() && controller != NULL;}

    protected:
        // callbacks
        void onRollerShutterStatusResponse(RollerShutterStatusResponse& response);
        void onRollerShutterInfoResponse(RollerShutterInfoResponse& response);
        void onLightStatusResponse(LightStatusResponse& response);
        void onLightInfoResponse(LightInfoResponse& response);
        void onLightColorResponse(LightColorResponse& response);

        // internal functions
        int tryToGetDeviceType(int network, int node);

        // command handling common functions
        DeltaDoreDeviceInfo* getDeviceInfo(int network, int node);
        Network* checkNetwork(int network, char * errMsg, int msgLen);
        bool checkNode(Network* pNetwork, int node, char* errMsg, int msgLen);
        Request * createRequest(RequestClass reqClass);
        void beginTransaction(Request* req);

        // member getter and setters
        RequestClass getContextRequestClass() { return contextRequestClass;}
        void setContextRequestClass(RequestClass reqClass);
        ResponseClass getContextResponseClass() { return contextResponseClass;}
        void setContextResponseClass(ResponseClass resClass) { contextResponseClass=resClass;}

        int getContextRequestNetwork() { return contextRequestNetwork;}
        void setContextRequestNetwork(int network) { contextRequestNetwork = network;}

        int getContextRequestNode() { return contextRequestNode;}
        void setContextRequestNode(int node) { contextRequestNode = node;}

    protected:
        bool initDeviceNames();
        void saveDeviceNames();

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
        FILE * fdStorage;
        const char* storageFileName;

};

#endif // DELTADOREX2DRIVER_H
