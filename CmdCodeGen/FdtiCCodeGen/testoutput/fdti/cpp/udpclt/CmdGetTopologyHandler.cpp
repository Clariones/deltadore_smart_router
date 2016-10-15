/**
 * File name: CmdGetTopologyHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */
#include "CmdGetTopologyHandler.h"

#define CMD_NAME "getTopology"

CmdGetTopologyHandler::CmdGetTopologyHandler(){
}

CmdGetTopologyHandler::~CmdGetTopologyHandler(){
}

const char* CmdGetTopologyHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
    // first string always the command, so just skip it
    const char* pCurrentParam = pCmd;


    cJSON* pResponse = pDriver->getTopology();
    
    return newResponse(pResponse);
}

const char * CmdGetTopologyHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdGetTopologyHandler::getUsage(){
    return "Get currently recognized network and nodes\n" \
        "Usage:\n" \
        "    getTopology";
}

#undefine CMD_NAME