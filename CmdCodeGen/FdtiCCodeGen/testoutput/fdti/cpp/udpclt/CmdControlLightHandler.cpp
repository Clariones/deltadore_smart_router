/**
 * File name: CmdControlLightHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */
#include "CmdControlLightHandler.h"

#define CMD_NAME "controlLight"
#define MAX_OPTION_LENTH 14

CmdControlLightHandler::CmdControlLightHandler(){
}

CmdControlLightHandler::~CmdControlLightHandler(){
}

const char* CmdControlLightHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
    int network;
    int node;

    // first string always the command, so just skip it
    const char* pCurrentParam = getNextParamStartPosition(pCmd);;
    
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    getParamInt(pCurrentParam, &network);
    if (!isValidNetwork(network)){
        return newWrongIntParamResponse("Invalid network number %d", network);
    }
    
    pCurrentParam = getNextParamStartPosition(pCurrentParam);
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    getParamInt(pCurrentParam, &node);
    if (!isValidNode(node)){
        return newWrongIntParamResponse("Invalid node number %d", node);
    }
    
    pCurrentParam = getNextParamStartPosition(pCurrentParam);
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    char* option = new char[strlen(pCurrentParam) + 1];
    cJSON* pResponse = NULL;
    getParamString(pCurrentParam, option);
    if (strlen(option) >= MAX_OPTION_LENTH){
        delete option;
        return newWrongStringParamResponse("invalid option %s", option);
    } else if (strcmp("off", option) == 0 ) {
        pResponse = pDriver->switchOffLight(network, node );
    } else if (strcmp("on", option) == 0 ) {
        pResponse = pDriver->switchOnLight(network, node );
    } else if (strcmp("ram-up", option) == 0 ) {
        pResponse = pDriver->rampUpLight(network, node );
    } else if (strcmp("ram-down", option) == 0 ) {
        pResponse = pDriver->ramDownLight(network, node );
    } else if (strcmp("stop", option) == 0 ) {
        pResponse = pDriver->stopLight(network, node );
    } else if (strcmp("stand-out", option) == 0 ) {
        pResponse = pDriver->standOutLight(network, node );
    } else if (strcmp("alarm-pairing", option) == 0 ) {
        pResponse = pDriver->alarmPairingLight(network, node );
    } else if (strcmp("toggle", option) == 0 ) {
        pResponse = pDriver->toggleLight(network, node );
    } else if (strcmp("preset-1", option) == 0 ) {
        pResponse = pDriver->preset1Light(network, node );
    } else if (strcmp("preset-2", option) == 0 ) {
        pResponse = pDriver->preset2Light(network, node );
    } else {
        delete option;
        return newWrongStringParamResponse("invalid option %s", option);
    }
    
    delete option;
    return newResponse(pResponse);
}

const char * CmdControlLightHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdControlLightHandler::getUsage(){
    return "Usage:\n" \
        "    controlLight <network> <node> option\n" \
        "Params:\n" \
        "    network: the network number of target device, 0~11\n" \
        "    node: the node number of target device, 0~15\n" \
        "    option: the valid action options. Can be:\n" \
        "        off on ram-up ram-down stop stand-out alarm-pairing toggle preset-1 preset-2";
}

#undef MAX_OPTION_LENTH
#undef CMD_NAME