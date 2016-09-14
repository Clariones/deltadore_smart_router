#include "clt/CmdQueryLightColor.h"

CmdQueryLightColor::CmdQueryLightColor()
{
    //ctor
}

CmdQueryLightColor::~CmdQueryLightColor()
{
    //dtor
}
void CmdQueryLightColor::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    int network, node;
    scanf("%d %d", &network, &node);
    cJSON* pResponse = pDriver->queryLightStatus(network, node);
    printf("%s\n", cJSON_Print(pResponse));
    cJSON_Delete(pResponse);
}

const char* CmdQueryLightColor::getSummary()
{
    return "queryLightStatus <network> <node>\n[help]\t\tQuery light device status";
}

const char* CmdQueryLightColor::getCmdKey()
{
    return "queryLightStatus";
}
