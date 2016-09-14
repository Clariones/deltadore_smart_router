#include "CmdControlLightColor.h"

CmdControlLightColor::CmdControlLightColor()
{
    //ctor
}

CmdControlLightColor::~CmdControlLightColor()
{
    //dtor
}
void CmdControlLightColor::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    cJSON* pResponse = NULL;
    char option[20];
    int network, node, red, blue, green;
    scanf("%d %d %d %d %d", &network, &node, &red, &green, &blue);
    pResponse = pDriver->setLightColor(network, node, red, green, blue);
    printf("%s\n", cJSON_Print(pResponse));
    cJSON_Delete(pResponse);
}

const char* CmdControlLightColor::getSummary()
{
    return "controlLightColor <network> <node> <red> <green> <blue>\n[help]\t\tred, green, blue: are integer between 0~255";
}

const char* CmdControlLightColor::getCmdKey()
{
    return "controlLightColor";
}
