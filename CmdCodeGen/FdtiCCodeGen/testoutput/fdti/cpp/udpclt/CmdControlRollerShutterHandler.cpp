/**
 * File name: CmdControlRollerShutterHandler.cpp
 * Author: Clariones Wang
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

const char* CmdControlRollerShutterHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
    int network;
    int node;

    // first string always the command, so just skip it
    const char* pCurrentParam = pCmd;
    
    // process paramter: network
    pCurrentParam = getNextParamStartPosition(pCurrentParam);;
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    getParamInt(pCurrentParam, &network);
    if (!isValidNetwork(network)){
        return newWrongIntParamResponse("Invalid network number %d", network);
    }
    // process parameter: node 
    pCurrentParam = getNextParamStartPosition(pCurrentParam);
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    getParamInt(pCurrentParam, &node);
    if (!isValidNode(node)){
        return newWrongIntParamResponse("Invalid node number %d", node);
    }
    // process parameter: option
    pCurrentParam = getNextParamStartPosition(pCurrentParam);
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    char* option = new char[strlen(pCurrentParam) + 1];
    cJSON* pResponse = NULL;
    getParamString(pCurrentParam, option);
    if (strlen(option) >= MAX_OPTION_LENTH){
        const char* pResult =  newWrongStringParamResponse("invalid option %s", option);
        delete option;
        return pResult;
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
        const char* pResult = newWrongStringParamResponse("invalid option %s", option);
        delete option;
        return pResult;
    }
    
    delete option;
    return newResponse(pResponse);
}

const char * CmdControlRollerShutterHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdControlRollerShutterHandler::getUsage(){
    return "control roller-shutter device\n" \
        "Usage:\n" \
        "    controlRollerShutter <network> <node> option\n" \
        "Params:\n" \
        "    network: the network number of target device, 0~11\n" \
        "    node: the node number of target device, 0~15\n" \
        "    option: the valid action options. Can be:\n" \
        "        up down up-slow down-slow stop";
}

#undef MAX_OPTION_LENTH
#undef CMD_NAME