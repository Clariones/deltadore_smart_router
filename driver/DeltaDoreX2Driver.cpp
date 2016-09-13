#include "assert.h"
#include "driver/DeltaDoreX2Driver.h"

#include "rollershutter/RollerShutterCommandArg.h"

using namespace deltadoreX2d;
using namespace std;

#define SIMPLE_SUCCESS_RESPONSE(root)                   \
    cJSON_AddStringToObject(root,"message","success");  \
    cJSON_AddBoolToObject(root,"success", true)

#define SIMPLE_ERROR_RESPONSE(root, errMsg)             \
    cJSON_AddStringToObject(root,"message",errMsg);     \
    cJSON_AddBoolToObject(root,"success", false)

#define PREPARE_REQUEST(root, network, node)                        \
    char errMsg[100];                                               \
    Network* net = checkNetwork(network, errMsg, sizeof(errMsg));   \
    if (net == NULL){                                               \
        SIMPLE_ERROR_RESPONSE(root, errMsg);                        \
        return root;                                                \
    }                                                               \
    if (!checkNode(net, node, errMsg, sizeof(errMsg))){             \
        SIMPLE_ERROR_RESPONSE(root, errMsg);                        \
        return root;                                                \
    }                                                               \
    acked = false;                                                  \
    setContextRequestNetwork(network);                              \
    setContextRequestNode(node);                                    \



DeltaDoreX2Driver::DeltaDoreX2Driver()
{
    //ctor
}

DeltaDoreX2Driver::~DeltaDoreX2Driver()
{
    //dtor
    controller->close();
    sem_destroy(&semAck);
}
void DeltaDoreX2Driver::init(const char* devName)
{
    // self init
    sem_init(&semAck, 0, 0);
    for(int i=0; i<MAX_NETWORK_NUM; i++)
    {
        for(int j=0; j<MAX_NODE_NUM; j++)
        {
            allDeviceInfo[i][j] = NULL;
        }
    }
    // init serial port device
    device.init(devName);
    Controller* ctrl = Factory::createController();
    ctrl->addAcknowledgmentListener(this);
    MeshController* meshctrl = ctrl->convert<MeshController*>();
    meshctrl->addEndTransactionListener(this);
    meshctrl->addNodeDiscoveredListener(this);

    ctrl->open(&device, &device);
    meshctrl->initNetworks();
    controller = ctrl;
}

void DeltaDoreX2Driver::acknowledgment(const AcknowledgmentEvent& evt)
{
    const Acknowledgment ack = evt.getAcknowledgment();
    printf("got ACK %s\n", ack.toString().c_str());
    acked = (ack == Acknowledgment::ACK);

    // at last, release ACK semaphore
    if (ack == Acknowledgment::ACK || ack==Acknowledgment::PRE_ACK)
    {
        sem_post(&semAck);
    }
}
void DeltaDoreX2Driver::waitAck()
{
    sem_wait(&semAck);
}
Request* DeltaDoreX2Driver::createRequest(RequestClass reqClass)
{
    MeshController* mCtrl = controller->convert<MeshController*>();
    Request *req = mCtrl->createRequest(reqClass);
    setContextRequestClass(reqClass);
    return req;
}
void DeltaDoreX2Driver::beginTransaction(Request* req){
    MeshController* mCtrl = controller->convert<MeshController*>();
    mCtrl->beginTransaction(req);
}

void DeltaDoreX2Driver::endTransaction(const EndTransactionEvent& evt)
{
    printf("End transaction\n");
    std::vector<Node> nodes = evt.getRequest()->nodes();
    std::vector<Node>::iterator it;
    for(it = nodes.begin(); it != nodes.end(); it++)
    {
        Node node = *it;
        Response* resp = evt.getResponse(node)->clone();
        printf("Response status is %s\n", resp->getStatus().toString().c_str());
        if(resp->instanceOf (RollerShutterStatusResponse_t))
        {
            printf("Response is RollerShutterStatusResponse_t\n");
            RollerShutterStatusResponse* shutterResp = resp->convert<RollerShutterStatusResponse*>();
            onRollerShutterStatusResponse(*shutterResp);
        }else if (resp->instanceOf(LightStatusResponse_t)){
            printf("Response is LightStatusResponse_t\n");
            LightStatusResponse* lightResp = resp->convert<LightStatusResponse*>();
            onLightStatusResponse(*lightResp);
        }else if (resp->instanceOf(LightColorResponse_t)){
            printf("Response is LightColorResponse_t\n");
        }else if (resp->instanceOf(LightInfoResponse_t)){
            printf("Response is LightInfoResponse_t\n");
        }else if (resp->instanceOf(RollerShutterInfoResponse_t)){
            printf("Response is RollerShutterInfoResponse_t\n");
            RollerShutterInfoResponse* shutterResp = resp->convert<RollerShutterInfoResponse*>();
            onRollerShutterInfoResponse(*shutterResp);
        }else {
            printf("Response is unknown\n");
            DeltaDoreDeviceInfo* pDevice = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
            pDevice->setLastResponseStatus(resp->getStatus());
        }

    }
}

DeltaDoreDeviceInfo* DeltaDoreX2Driver::getDeviceInfo(int network, int node)
{
    DeltaDoreDeviceInfo* pDev = allDeviceInfo[network][node];
    if (pDev == NULL)
    {
        pDev = new DeltaDoreDeviceInfo();
        allDeviceInfo[network][node] = pDev;
    }
    return pDev;
}

void DeltaDoreX2Driver::setContextRequestClass(RequestClass reqClass)
{
    contextRequestClass=reqClass;
    if (contextRequestClass == CurrentConsumptionRequest_t)
    {
        contextResponseClass = ThermicSystemStatusResponse_t;
    }
    else
    {
        contextResponseClass=CurrentConsumptionResponse_t;
    }
}

Network* DeltaDoreX2Driver::checkNetwork(int network, char* errMsg, int msgLen)
{
    if (network >= MAX_NETWORK_NUM){
        snprintf(errMsg, msgLen, "network ID max value is %d", MAX_NETWORK_NUM-1);
        return NULL;
    }

    MeshController* mCtrl = controller->convert<MeshController*>();
    Network* pNetwork = mCtrl->getNetwork(network);
    if (pNetwork == NULL)
    {
        snprintf(errMsg, msgLen, "network %d not exist", network);
        return NULL;
    }
    return pNetwork;
}

bool DeltaDoreX2Driver::checkNode(Network* pNetwork, int node, char* errMsg, int msgLen)
{
    assert(pNetwork != NULL);
    if (node >= MAX_NODE_NUM){
        snprintf(errMsg, msgLen, "node ID max value is %d", MAX_NODE_NUM-1);
        return false;
    }
    vector<Node> nodes = pNetwork->getTopology();
    vector<Node>::iterator it;
    for(it=nodes.begin(); it != nodes.end(); it ++){
        Node cNode = * it;
        if (cNode.toInt() == node){
            return true;
        }
    }
    snprintf(errMsg, msgLen, "node %d not existed in network %d", node, pNetwork->getIdentifier());
    return false;
}


void DeltaDoreX2Driver::onRollerShutterStatusResponse(RollerShutterStatusResponse& response)
{
    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    setContextResponseClass(RollerShutterStatusResponse_t);
    device->setDeviceType(DeltaDoreDeviceInfo::DEVICE_TYPE_ROLLER_SHUTTER);
    device->setLastResponseStatus(response.getStatus());

    device->setPosition(response.getPosition());
    device->setFavoritePosition(response.isFavoritePosition());
    device->setIntrusionDetected(response.isIntrusionDetected());
    device->setLoweringFaulty(response.isLoweringFaulty());
    device->setObstacleFaulty(response.isObstacleFaulty());
    device->setOverheatingFaulty(response.isOverheatingFaulty());
    device->setRaisingFaulty(response.isRaisingFaulty());

}
void DeltaDoreX2Driver::onRollerShutterInfoResponse(RollerShutterInfoResponse& response)
{
    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    setContextResponseClass(RollerShutterInfoResponse_t);
    device->setDeviceType(DeltaDoreDeviceInfo::DEVICE_TYPE_ROLLER_SHUTTER);
    device->setLastResponseStatus(response.getStatus());

    device->setChannelCount(response.getChannelCount());
    device->setActuatorType(response.getActuatorType());
}
void DeltaDoreX2Driver::onLightStatusResponse(LightStatusResponse& response)
{
    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    setContextResponseClass(LightStatusResponse_t);
    device->setDeviceType(DeltaDoreDeviceInfo::DEVICE_TYPE_LIGHT);
    device->setLastResponseStatus(response.getStatus());

    device->setLevel(response.getLevel());
    device->setOverloadFaulty(response.isOverloadFaulty());
    device->setCommandFaulty(response.isCommandFaulty());
    device->setOverheatingFaulty(response.isOverheatingFaulty());
    device->setFavoritePosition(response.isFavoritePosition());
    device->setPresenceDetected(response.isPresenceDetected());
    device->setTwilight(response.isTwilight());

}


void DeltaDoreX2Driver::nodeDiscovered(const NodeDiscoveredEvent& evt)
{
    printf("In network %d found node %d\n", evt.getNetwork()->getIdentifier(), evt.getNode().toInt());
}

/**
 * return JSON format should be like this:
 * {   "message":"success"|"<any other message>",
 *     "success": true | false,
 *     "data": {
 *          "<network id>" : [ {<node x>, <node y}],
 *          "<network id>" : [ {<node x>, <node y}]
 *     }
 * }
 *
 */
cJSON* DeltaDoreX2Driver::getTopology()
{
    char buffer[10];
    cJSON* root=cJSON_CreateObject();

    MeshController* ctrl = controller->convert<MeshController*>();
    int nn = ctrl->getNetworkCount();
    if (nn == 0)
    {
        SIMPLE_ERROR_RESPONSE(root, "No any network");
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);

    cJSON* pResponseData=cJSON_CreateObject();
    cJSON_AddItemToObject(root, "data", pResponseData);



    for(int i = 0; i < nn; i++)
    {
        Network* pNetwork = ctrl->getNetwork(i);
        if (pNetwork == NULL)
        {
            continue;
        }
        cJSON* pNetWorkData=cJSON_CreateArray();
        snprintf(buffer, sizeof(buffer)-1, "%d", pNetwork->getIdentifier());

        cJSON_AddItemToObject(pResponseData, buffer, pNetWorkData);

        vector<Node> nodes = pNetwork->getTopology();
        vector<Node>::iterator it;
        for(it=nodes.begin(); it != nodes.end(); it++)
        {
            Node node = *it;
            snprintf(buffer, sizeof(buffer)-1, "%d", node.toInt());
            cJSON* pNodeData=cJSON_CreateObject();
            cJSON_AddNumberToObject(pNodeData, "id", node.toInt());
            cJSON_AddStringToObject(pNodeData, "name", "unknown");

            cJSON_AddItemToArray(pNetWorkData, pNodeData);

        }
    }
    return root;
}


cJSON* DeltaDoreX2Driver::deleteNode(int network, int node)
{
    cJSON* root=cJSON_CreateObject();
    char errMsg[100];
    Network* net = checkNetwork(network, errMsg, sizeof(errMsg));
    if (net == NULL){
        SIMPLE_ERROR_RESPONSE(root, errMsg);
        return root;
    }
    if (!checkNode(net, node, errMsg, sizeof(errMsg))){
        SIMPLE_ERROR_RESPONSE(root, errMsg);
        return root;
    }

    Node tgtNode = Node::valueOf(node);
    net->deleteNode(tgtNode, true);
    waitAck();


    if (!acked)
    {
        SIMPLE_ERROR_RESPONSE(root, "No response");
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    return root;
}


cJSON* DeltaDoreX2Driver::registerNode(int network)
{
    cJSON* root=cJSON_CreateObject();
    char errMsg[100];
    Network* pNetwork = checkNetwork(network, errMsg, sizeof(errMsg));
    if (pNetwork == NULL){
        SIMPLE_ERROR_RESPONSE(root, errMsg);
        return root;
    }
    pNetwork->startNodeDiscovery(true);
    acked = false;
    waitAck();


    if (!acked)
    {
        SIMPLE_ERROR_RESPONSE(root, "No response");
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    return root;
}

cJSON* DeltaDoreX2Driver::queryRollerShutterStatus(int network, int node)
{
    cJSON* root=cJSON_CreateObject();
    PREPARE_REQUEST(root, network, node);

    Request *req = createRequest(RollerShutterStatusRequest_t);
    req->setNetwork(net);
    req->addNode(Node::valueOf(node), RollerShutterCommandArg::NA);

    beginTransaction(req);
    waitAck();



    if (!acked)
    {
        SIMPLE_ERROR_RESPONSE(root, "Response negative");
        return root;
    }

//    SIMPLE_SUCCESS_RESPONSE(root);
//    if (getContextResponseClass() != RollerShutterStatusResponse_t)
//    {
//        SIMPLE_ERROR_RESPONSE(root, "No response");
//        return root;
//    }

    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    ResponseStatus status = device->getLastResponseStatus();
    if (status != ResponseStatus::OK)
    {
        SIMPLE_ERROR_RESPONSE(root, status.toString().c_str());
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    cJSON* pData=cJSON_CreateObject();
    cJSON_AddItemToObject(root, "data", pData);

    cJSON_AddStringToObject(pData, "responseStatus", device->getLastResponseStatus().toString().c_str());
    cJSON_AddNumberToObject(pData, "position", device->getPosition());
    cJSON_AddBoolToObject(pData, "favoritePosition", device->isFavoritePosition());
    cJSON_AddBoolToObject(pData, "intrusionDetected", device->isIntrusionDetected());
    cJSON_AddBoolToObject(pData, "loweringFaulty", device->isLoweringFaulty());
    cJSON_AddBoolToObject(pData, "obstacleFaulty", device->isObstacleFaulty());
    cJSON_AddBoolToObject(pData, "overheatingFaulty", device->isOverheatingFaulty());
    cJSON_AddBoolToObject(pData, "raisingFaulty", device->isRaisingFaulty());
    return root;

}

cJSON* DeltaDoreX2Driver::queryRollerShutterInfo(int network, int node)
{
    cJSON* root=cJSON_CreateObject();
    PREPARE_REQUEST(root, network, node);

    Request *req = createRequest(RollerShutterInfoRequest_t);
    req->setNetwork(net);
    req->addNode(Node::valueOf(node), RollerShutterCommandArg::NA);

    beginTransaction(req);
    waitAck();



    if (!acked)
    {
        SIMPLE_ERROR_RESPONSE(root, "Response negative");
        return root;
    }

//    SIMPLE_SUCCESS_RESPONSE(root);
//    if (getContextResponseClass() != RollerShutterStatusResponse_t)
//    {
//        SIMPLE_ERROR_RESPONSE(root, "No response");
//        return root;
//    }

    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    ResponseStatus status = device->getLastResponseStatus();
    if (status != ResponseStatus::OK)
    {
        SIMPLE_ERROR_RESPONSE(root, status.toString().c_str());
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    cJSON* pData=cJSON_CreateObject();
    cJSON_AddItemToObject(root, "data", pData);

    cJSON_AddStringToObject(pData, "responseStatus", device->getLastResponseStatus().toString().c_str());
    cJSON_AddNumberToObject(pData, "channelCount", device->getChannelCount());
    cJSON_AddStringToObject(pData, "actuatorType", device->getActuatorType().toString().c_str());

    return root;

}

cJSON* DeltaDoreX2Driver::controlRollerShutter(int network, int node, const RollerShutterCommandArg& action)
{
    cJSON* root=cJSON_CreateObject();
    PREPARE_REQUEST(root, network, node);

    Request *req = createRequest(RollerShutterCommandRequest_t);
    req->setNetwork(net);
    req->addNode(Node::valueOf(node), action);

    beginTransaction(req);
    waitAck();

    if (!acked)
    {
        SIMPLE_ERROR_RESPONSE(root, "No response");
        return root;
    }
    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    ResponseStatus status = device->getLastResponseStatus();
    if (status != ResponseStatus::OK)
    {
        SIMPLE_ERROR_RESPONSE(root, status.toString().c_str());
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    return root;
}

cJSON* DeltaDoreX2Driver::queryLightStatus(int network, int node)
{
    cJSON* root=cJSON_CreateObject();
    PREPARE_REQUEST(root, network, node);

    Request *req = createRequest(LightStatusRequest_t);
    req->setNetwork(net);
    req->addNode(Node::valueOf(node), LightCommandArg::NA);

    beginTransaction(req);
    waitAck();



    if (!acked)
    {
        SIMPLE_ERROR_RESPONSE(root, "Response negative");
        return root;
    }

//    SIMPLE_SUCCESS_RESPONSE(root);
//    if (getContextResponseClass() != LightStatusResponse_t)
//    {
//        SIMPLE_ERROR_RESPONSE(root, "No response");
//        return root;
//    }

    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    ResponseStatus status = device->getLastResponseStatus();
    if (status != ResponseStatus::OK)
    {
        SIMPLE_ERROR_RESPONSE(root, status.toString().c_str());
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    cJSON* pData=cJSON_CreateObject();
    cJSON_AddItemToObject(root, "data", pData);

    cJSON_AddStringToObject(pData, "responseStatus", device->getLastResponseStatus().toString().c_str());
    cJSON_AddNumberToObject(pData, "level", device->getLevel());
    cJSON_AddBoolToObject(pData, "overloadFaulty", device->isOverloadFaulty());
    cJSON_AddBoolToObject(pData, "commandFaulty", device->isCommandFaulty());
    cJSON_AddBoolToObject(pData, "overheatingFaulty", device->isOverheatingFaulty());
    cJSON_AddBoolToObject(pData, "favoritePosition", device->isFavoritePosition());
    cJSON_AddBoolToObject(pData, "presenceDetected", device->isPresenceDetected());
    cJSON_AddBoolToObject(pData, "twilight", device->isTwilight());

    return root;

}


cJSON* DeltaDoreX2Driver::controlLight(int network, int node, const LightCommandArg& action)
{
    cJSON* root=cJSON_CreateObject();
    PREPARE_REQUEST(root, network, node);

    Request *req = createRequest(LightCommandRequest_t);
    req->setNetwork(net);
    req->addNode(Node::valueOf(node), action);

    beginTransaction(req);
    waitAck();

    if (!acked)
    {
        SIMPLE_ERROR_RESPONSE(root, "Response negative");
        return root;
    }
    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    ResponseStatus status = device->getLastResponseStatus();
    if (status != ResponseStatus::OK)
    {
        SIMPLE_ERROR_RESPONSE(root, status.toString().c_str());
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    return root;
}

cJSON* DeltaDoreX2Driver::setLightLevel(int network, int node, int level)
{
    int correctLevel = level;
    if (level < 0){
        correctLevel = 0;
    }else if (level > 100){
        correctLevel = 100;
    }
    return controlLight(network, node, LightCommandArg::percent(correctLevel));
}
