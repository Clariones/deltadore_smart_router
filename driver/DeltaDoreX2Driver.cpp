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
    for(int i=0;i<MAX_NETWORK_NUM;i++){
        for(int j=0;j<MAX_NODE_NUM;j++){
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
    if (ack == Acknowledgment::ACK || ack==Acknowledgment::PRE_ACK){
        sem_post(&semAck);
    }
}
void DeltaDoreX2Driver::waitAck(){
    sem_wait(&semAck);
}

void DeltaDoreX2Driver::endTransaction(const EndTransactionEvent& evt)
{

    std::vector<Node> nodes = evt.getRequest()->nodes();
    std::vector<Node>::iterator it;
    for(it = nodes.begin(); it != nodes.end(); it++) {
        Node node = *it;
        Response* resp = evt.getResponse(node)->clone();
        if(resp->instanceOf (RollerShutterStatusResponse_t)) {
            RollerShutterStatusResponse* shutterResp = resp->convert<RollerShutterStatusResponse*>();
            onRollerShutterStatusResponse(*shutterResp);
        }

    }
}

DeltaDoreDeviceInfo* DeltaDoreX2Driver::getDeviceInfo(int network, int node)
{
    DeltaDoreDeviceInfo* pDev = allDeviceInfo[network][node];
    if (pDev == NULL){
        pDev = new DeltaDoreDeviceInfo();
        allDeviceInfo[network][node] = pDev;
    }
    return pDev;
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
cJSON* DeltaDoreX2Driver::getTopology(){
    char buffer[10];
    cJSON* root=cJSON_CreateObject();

    MeshController* ctrl = controller->convert<MeshController*>();
    int nn = ctrl->getNetworkCount();
    if (nn == 0){
        SIMPLE_ERROR_RESPONSE(root, "No any network");
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);

    cJSON* pResponseData=cJSON_CreateObject();
    cJSON_AddItemToObject(root, "data", pResponseData);



    for(int i = 0; i < nn; i++){
        Network* pNetwork = ctrl->getNetwork(i);
        if (pNetwork == NULL){
            continue;
        }
        cJSON* pNetWorkData=cJSON_CreateArray();
        snprintf(buffer, sizeof(buffer)-1, "%d", pNetwork->getIdentifier());

        cJSON_AddItemToObject(pResponseData, buffer, pNetWorkData);

        vector<Node> nodes = pNetwork->getTopology();
        vector<Node>::iterator it;
        for(it=nodes.begin();it != nodes.end(); it++){
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

cJSON* DeltaDoreX2Driver::queryRollerShutterStatus(int network, int node)
{
    cJSON* root=cJSON_CreateObject();
    MeshController* mCtrl = controller->convert<MeshController*>();
    Request *req = mCtrl->createRequest(RollerShutterStatusRequest_t);
    Network *net = mCtrl->getNetwork(network);
    if (net == NULL){
        SIMPLE_ERROR_RESPONSE(root, "Network ID not valid");
        return root;
    }

    req->setNetwork(net);
    req->addNode(Node::valueOf(node), RollerShutterCommandArg::NA);

    setContextRequestClass(RollerShutterStatusRequest_t);
    setContextRequestNetwork(network);
    setContextRequestNode(node);

    mCtrl->beginTransaction(req);
    waitAck();



    if (!acked){
        SIMPLE_ERROR_RESPONSE(root, "No response");
        return root;
    }

//    SIMPLE_SUCCESS_RESPONSE(root);
    if (getContextResponseClass() != RollerShutterStatusResponse_t){
        SIMPLE_ERROR_RESPONSE(root, "No response");
        return root;
    }

    DeltaDoreDeviceInfo* device = getDeviceInfo(getContextRequestNetwork(), getContextRequestNode());
    ResponseStatus status = device->getLastResponseStatus();
    if (status != ResponseStatus::OK){
        SIMPLE_ERROR_RESPONSE(root, status.toString().c_str());
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    cJSON* pData=cJSON_CreateObject();
    cJSON_AddItemToObject(root, "data", pData);

    cJSON_AddNumberToObject(pData, "position", device->getPosition());
    cJSON_AddBoolToObject(pData, "favoritePosition", device->isFavoritePosition());
    cJSON_AddBoolToObject(pData, "intrusionDetected", device->isIntrusionDetected());
    cJSON_AddBoolToObject(pData, "loweringFaulty", device->isLoweringFaulty());
    cJSON_AddBoolToObject(pData, "obstacleFaulty", device->isObstacleFaulty());
    cJSON_AddBoolToObject(pData, "overheatingFaulty", device->isOverheatingFaulty());
    cJSON_AddBoolToObject(pData, "raisingFaulty", device->isRaisingFaulty());
    return root;

}


cJSON* DeltaDoreX2Driver::deleteNode(int network, int node)
{
    cJSON* root=cJSON_CreateObject();

    MeshController* mCtrl = controller->convert<MeshController*>();
    Network* pNetwork = mCtrl->getNetwork(network);
    if (pNetwork == 0){
        char* buffer = new char[256];
        snprintf(buffer, 256, "network %d not exist\n", network);
        SIMPLE_ERROR_RESPONSE(root, buffer);
        delete buffer;
        return root;
    }
    Node tgtNode = Node::valueOf(node);
    pNetwork->deleteNode(tgtNode, true);
    waitAck();


    if (!acked){
        SIMPLE_ERROR_RESPONSE(root, "No response");
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    return root;
}


cJSON* DeltaDoreX2Driver::registerNode(int network)
{
    cJSON* root=cJSON_CreateObject();

    MeshController* mCtrl = controller->convert<MeshController*>();
    Network* pNetwork = mCtrl->getNetwork(network);
    if (pNetwork == 0){
        char* buffer = new char[256];
        snprintf(buffer, 256, "network %d not exist\n", network);
        SIMPLE_ERROR_RESPONSE(root, buffer);
        delete buffer;
        return root;
    }
    pNetwork->startNodeDiscovery(true);
    waitAck();


    if (!acked){
        SIMPLE_ERROR_RESPONSE(root, "No response");
        return root;
    }

    SIMPLE_SUCCESS_RESPONSE(root);
    return root;
}

cJSON* DeltaDoreX2Driver::controlRollerShutter(int network, int node, const RollerShutterCommandArg& action)
{
    cJSON* root=cJSON_CreateObject();
    MeshController* mCtrl = controller->convert<MeshController*>();
    Network *net = mCtrl->getNetwork(network);
    if (net == NULL){
        SIMPLE_ERROR_RESPONSE(root, "Network ID not valid");
        return root;
    }

    Request *req = mCtrl->createRequest(RollerShutterCommandRequest_t);
    req->setNetwork(net);
    req->addNode(Node::valueOf(node), action);

    setContextRequestClass(RollerShutterCommandRequest_t);
    setContextRequestNetwork(network);
    setContextRequestNode(node);

    mCtrl->beginTransaction(req);
    waitAck();

    if (!acked){
        SIMPLE_ERROR_RESPONSE(root, "No response");
        return root;
    }

        SIMPLE_SUCCESS_RESPONSE(root);
        return root;
}
