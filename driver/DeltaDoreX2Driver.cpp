#include "driver/DeltaDoreX2Driver.h"

using namespace deltadoreX2d;
using namespace std;

DeltaDoreX2Driver::DeltaDoreX2Driver()
{
    //ctor
}

DeltaDoreX2Driver::~DeltaDoreX2Driver()
{
    //dtor
    controller->close();
}
void DeltaDoreX2Driver::init(const char* devName)
{
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

}

void DeltaDoreX2Driver::endTransaction(const EndTransactionEvent& evt)
{

}

void DeltaDoreX2Driver::nodeDiscovered(const NodeDiscoveredEvent& evt)
{

}

void DeltaDoreX2Driver::getTopology(char* buffer, int sizen){

    MeshController* ctrl = controller->convert<MeshController*>();
    int nn = ctrl->getNetworkCount();
    sprintf(buffer, "{\r\n");
    for(int i = 0; i < nn; i++){
        Network* pNetwork = ctrl->getNetwork(i);
        if (pNetwork == NULL){
            continue;
        }
        if (i == 0){
            sprintf(buffer, "%s  \"%d\":[", buffer, pNetwork->getIdentifier());
        }else{
            sprintf(buffer, "%s,\r\n  \"%d\":[", buffer, pNetwork->getIdentifier());
        }

        vector<Node> nodes = pNetwork->getTopology();
        vector<Node>::iterator it;
        bool isFirst = true;
        for(it=nodes.begin();it != nodes.end(); it++){
            Node node = *it;
            if (isFirst){
                sprintf(buffer, "%s%d", buffer, node.toInt());
                isFirst = false;
            }else{
                sprintf(buffer, "%s, %d", buffer, node.toInt());
            }
        }
        sprintf(buffer, "%s]", buffer);
    }
    sprintf(buffer, "%s\r\n}", buffer);
}
