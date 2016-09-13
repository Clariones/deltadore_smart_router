#include "clt/CmdQueryLight.h"

CmdQueryLight::CmdQueryLight()
{
    //ctor
}

CmdQueryLight::~CmdQueryLight()
{
    //dtor
}
void CmdQueryLight::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    int network, node;
    scanf("%d %d", &network, &node);
    cJSON* pResponse = pDriver->queryLightStatus(network, node);
    printf("%s\n", cJSON_Print(pResponse));
    delete(pResponse);
}

const char* CmdQueryLight::getSummary()
{
    return "queryLightStatus <network> <node>\n[help]\t\tQuery light device status";
}

const char* CmdQueryLight::getCmdKey()
{
    return "queryLightStatus";
}
