/**
 * File name: CmdRegisterNodeHandler.cpp
 * Author: Clariones Wang
 * Email: Clariones@163.com
 *
 * All rights reserved.
 */
#include "CmdRegisterNodeHandler.h"

#define CMD_NAME "registerNode"

CmdRegisterNodeHandler::CmdRegisterNodeHandler(){
}

CmdRegisterNodeHandler::~CmdRegisterNodeHandler(){
}

void CmdRegisterNodeHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
    int network;
    // first string always the command, so just skip it
    const char* pCurrentParam = getNextParamStartPosition(pCmd);;
    
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    getParamInt(pCurrentParam, &network);
    if (!isValidNetwork(network)){
        return newWrongIntParamResponse("Invalid network number %d", network);
    }

    cJSON* pResponse = pDriver->registerNode(network );    
    return newResponse(pResponse);
}

const char * CmdRegisterNodeHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdRegisterNodeHandler::getUsage(){
    return "Usage:\n" \
        "    registerNode <network>";
}

#undefine CMD_NAME