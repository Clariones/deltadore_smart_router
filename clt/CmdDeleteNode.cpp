#include "CmdDeleteNode.h"

CmdDeleteNode::CmdDeleteNode()
{
    //ctor
}

CmdDeleteNode::~CmdDeleteNode()
{
    //dtor
}
void CmdDeleteNode::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    int network, node;
    scanf("%d %d", &network, &node);
    cJSON* pResponse = pDriver->deleteNode(network, node);
    printf("%s\n", cJSON_Print(pResponse));
    delete(pResponse);
}

const char* CmdDeleteNode::getSummary()
{
    return "deleteNode <network> <node>\n[help]\t\tDelete node from network";
}

const char* CmdDeleteNode::getCmdKey()
{
    return "deleteNode";
}
