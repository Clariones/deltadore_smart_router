#include "clt/CmdQueryRollershutterInfo.h"

CmdQueryRollershutterInfo::CmdQueryRollershutterInfo()
{
    //ctor
}

CmdQueryRollershutterInfo::~CmdQueryRollershutterInfo()
{
    //dtor
}

void CmdQueryRollershutterInfo::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    int network, node;
    scanf("%d %d", &network, &node);
    cJSON* pResponse = pDriver->queryRollerShutterInfo(network, node);
    printf("%s\n", cJSON_Print(pResponse));
    cJSON_Delete(pResponse);
}

const char* CmdQueryRollershutterInfo::getSummary()
{
    return "queryRollerShutterInfo <network> <node>\n[help]\t\tQuery roller shutter device information";
}

const char* CmdQueryRollershutterInfo::getCmdKey()
{
    return "queryRollerShutterInfo";
}
