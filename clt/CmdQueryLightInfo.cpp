#include "clt/CmdQueryLightInfo.h"

CmdQueryLightInfo::CmdQueryLightInfo()
{
    //ctor
}

CmdQueryLightInfo::~CmdQueryLightInfo()
{
    //dtor
}
void CmdQueryLightInfo::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    int network, node;
    scanf("%d %d", &network, &node);
    cJSON* pResponse = pDriver->queryLightInfo(network, node);
    printf("%s\n", cJSON_Print(pResponse));
    cJSON_Delete(pResponse);
}

const char* CmdQueryLightInfo::getSummary()
{
    return "queryLightInfo <network> <node>\n[help]\t\tQuery light device info";
}

const char* CmdQueryLightInfo::getCmdKey()
{
    return "queryLightInfo";
}
