#include "CmdRegisterNode.h"

CmdRegisterNode::CmdRegisterNode()
{
    //ctor
}

CmdRegisterNode::~CmdRegisterNode()
{
    //dtor
}

void CmdRegisterNode::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    int network;
    scanf("%d", &network);
    cJSON* pResponse = pDriver->registerNode(network);
    printf("%s\n", cJSON_Print(pResponse));
    cJSON_Delete(pResponse);
}

const char* CmdRegisterNode::getSummary()
{
    return "registerNode <network>\n[help]\t\tRegister new node into a network";
}

const char* CmdRegisterNode::getCmdKey()
{
    return "registerNode";
}
