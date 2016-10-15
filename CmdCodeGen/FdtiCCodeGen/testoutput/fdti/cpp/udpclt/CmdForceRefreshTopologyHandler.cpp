/**
 * File name: CmdForceRefreshTopologyHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */
#include "CmdForceRefreshTopologyHandler.h"

#define CMD_NAME "forceRefreshTopology"

CmdForceRefreshTopologyHandler::CmdForceRefreshTopologyHandler(){
}

CmdForceRefreshTopologyHandler::~CmdForceRefreshTopologyHandler(){
}

const char* CmdForceRefreshTopologyHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
    // first string always the command, so just skip it
    const char* pCurrentParam = pCmd;


    cJSON* pResponse = pDriver->refreshTopology();
    
    return newResponse(pResponse);
}

const char * CmdForceRefreshTopologyHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdForceRefreshTopologyHandler::getUsage(){
    return "Get currently recognized network and nodes\n" \
        "Usage:\n" \
        "    forceRefreshTopology";
}

#undefine CMD_NAME