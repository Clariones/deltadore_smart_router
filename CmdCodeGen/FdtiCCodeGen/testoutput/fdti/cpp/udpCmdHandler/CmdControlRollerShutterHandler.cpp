/**
 * File name: CmdControlRollerShutterHandler.cpp
 * Author: Clariones Wang
 * Email: Clariones@163.com
 *
 * All rights reserved.
 */
#include "CmdControlRollerShutterHandler.h"

#define CMD_NAME "controlRollerShutter"
#define MAX_OPTION_LENTH 11

CmdControlRollerShutterHandler::CmdControlRollerShutterHandler(){
}

CmdControlRollerShutterHandler::~CmdControlRollerShutterHandler(){
}

void CmdControlRollerShutterHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
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
    getParamString(option);
    if (strlen(option) >= MAX_OPTION_LENTH){
        delete option;
        return newWrongStringParamResponse("invalid option %s", option);
    } else if (strcmp("up", option) == 0 ) {
        pResponse = pDriver->openRollerShutter(network, node );
    } else if (strcmp("down", option) == 0 ) {
        pResponse = pDriver->closeRollerShutter(network, node );
    } else if (strcmp("up-slow", option) == 0 ) {
        pResponse = pDriver->openRollerShutterSlowly(network, node );
    } else if (strcmp("down-slow", option) == 0 ) {
        pResponse = pDriver->closeRollerShutterSlowly(network, node );
    } else if (strcmp("stop", option) == 0 ) {
        pResponse = pDriver->stopRollerShutter(network, node );
    } else {
        delete option;
        return newWrongStringParamResponse("invalid option %s", option);
    }
    
    delete option;
    return newResponse(pResponse);
}

const char * CmdControlRollerShutterHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdControlRollerShutterHandler::getUsage(){
    return "Usage:\n" \
        "    controlRollerShutter <network> <node> option\n" \
        "Params:\n" \
        "    network: the network number of target device, 0~11\n" \
        "    node: the node number of target device, 0~15\n" \
        "    option: the valid action options. Can be:\n" \
        "        up down up-slow down-slow stop";
}

#undefine MAX_OPTION_LENTH
#undefine CMD_NAME