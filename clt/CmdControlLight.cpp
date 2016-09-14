#include "CmdControlLight.h"

CmdControlLight::CmdControlLight()
{
    //ctor
}

CmdControlLight::~CmdControlLight()
{
    //dtor
}
void CmdControlLight::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    cJSON* pResponse = NULL;
    char option[20];
    int network, node;
    scanf("%d %d %s", &network, &node, option);
    if (!strcmp(option, "on")){
        pResponse = pDriver->switchOnLight(network, node);
    }else if (!strcmp(option, "off")){
        pResponse = pDriver->switchOffLight(network, node);
    }else if (!strcmp(option, "ram-up")){
        pResponse = pDriver->rampUpLight(network, node);
    }else if (!strcmp(option, "ram-down")){
        pResponse = pDriver->ramDownLight(network, node);
    }else if (!strcmp(option, "stop")){
        pResponse = pDriver->stopLight(network, node);
    }else if (!strcmp(option, "stand-out")){
        pResponse = pDriver->standOutLight(network, node);
    }else if (!strcmp(option, "alarm-pairing")){
        pResponse = pDriver->alarmPairingLight(network, node);
    }else if (!strcmp(option, "toggle")){
        pResponse = pDriver->toggleLight(network, node);
    }else if (!strcmp(option, "preset-1")){
        pResponse = pDriver->preset1Light(network, node);
    }else if (!strcmp(option, "preset-2")){
        pResponse = pDriver->preset2Light(network, node);
    }else {
        printf("action %s not valid, usage:\n[help]\t%s\n",option, getSummary());
    }

    if (pResponse != NULL){
        printf("%s\n", cJSON_Print(pResponse));
        cJSON_Delete(pResponse);
    }
}

const char* CmdControlLight::getSummary()
{
    return "controlLight <network> <node> <action>\n[help]\t\taction: on, off, ram-up, ram-down, stop, stand-out, alarm-pairing, toggle, preset-1, preset-2";
}

const char* CmdControlLight::getCmdKey()
{
    return "controlLight";
}
