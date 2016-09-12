#include "CmdControlRollerShutter.h"

CmdControlRollerShutter::CmdControlRollerShutter()
{
    //ctor
}

CmdControlRollerShutter::~CmdControlRollerShutter()
{
    //dtor
}
void CmdControlRollerShutter::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    cJSON* pResponse = NULL;
    char option[20];
    int network, node;
    scanf("%d %d %s", &network, &node, option);
    if (!strcmp(option, "up")){
        pResponse = pDriver->openRollerShutter(network, node);
    }else if (!strcmp(option, "down")){
        pResponse = pDriver->closeRollerShutter(network, node);
    }else if (!strcmp(option, "up-slow")){
        pResponse = pDriver->openRollerShutterSlowly(network, node);
    }else if (!strcmp(option, "down-slow")){
        pResponse = pDriver->closeRollerShutterSlowly(network, node);
    }else if (!strcmp(option, "stop")){
        pResponse = pDriver->stopRollerShutter(network, node);
    }else {
        printf("%s\n", cJSON_Print(pResponse));
    }
    if (pResponse != NULL){
        delete(pResponse);
    }
}

const char* CmdControlRollerShutter::getSummary()
{
    return "controlRollerShutter <network> <node> <action>\n[help]\t\toption: up, down, stop, up-slow, down-slow";
}

const char* CmdControlRollerShutter::getCmdKey()
{
    return "controlRollerShutter";
}
