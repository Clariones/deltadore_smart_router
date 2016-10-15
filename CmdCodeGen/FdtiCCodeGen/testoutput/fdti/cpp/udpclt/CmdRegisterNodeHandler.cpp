/**
 * File name: CmdRegisterNodeHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */
#include "CmdRegisterNodeHandler.h"

#define CMD_NAME "registerNode"

CmdRegisterNodeHandler::CmdRegisterNodeHandler(){
}

CmdRegisterNodeHandler::~CmdRegisterNodeHandler(){
}

const char* CmdRegisterNodeHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
    int network;
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

    cJSON* pResponse = pDriver->registerNode(network);
    
    return newResponse(pResponse);
}

const char * CmdRegisterNodeHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdRegisterNodeHandler::getUsage(){
    return "Register a new device into an appointed network\n" \
        "Usage:\n" \
        "    registerNode <network>";
}

#undefine CMD_NAME