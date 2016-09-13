#include "clt/CmdQueryRollershutterStatus.h"

CmdQueryRollershutterStatus::CmdQueryRollershutterStatus()
{
    //ctor
}

CmdQueryRollershutterStatus::~CmdQueryRollershutterStatus()
{
    //dtor
}

void CmdQueryRollershutterStatus::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    int network, node;
    scanf("%d %d", &network, &node);
    cJSON* pResponse = pDriver->queryRollerShutterStatus(network, node);
    printf("%s\n", cJSON_Print(pResponse));
    delete(pResponse);
}

const char* CmdQueryRollershutterStatus::getSummary()
{
    return "queryRollerShutterStatus <network> <node>\n[help]\t\tQuery roller shutter device status";
}

const char* CmdQueryRollershutterStatus::getCmdKey()
{
    return "queryRollerShutterStatus";
}
