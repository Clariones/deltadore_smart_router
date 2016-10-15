/**
 * File name: CmdDeleteNodeHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */
#include "CmdDeleteNodeHandler.h"

#define CMD_NAME "deleteNode"

CmdDeleteNodeHandler::CmdDeleteNodeHandler(){
}

CmdDeleteNodeHandler::~CmdDeleteNodeHandler(){
}

const char* CmdDeleteNodeHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
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

    cJSON* pResponse = pDriver->deleteNode(network, node);
    
    return newResponse(pResponse);
}

const char * CmdDeleteNodeHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdDeleteNodeHandler::getUsage(){
    return "Delete node from network\n" \
        "Usage:\n" \
        "    deleteNode <network> <node>";
}

#undefine CMD_NAME