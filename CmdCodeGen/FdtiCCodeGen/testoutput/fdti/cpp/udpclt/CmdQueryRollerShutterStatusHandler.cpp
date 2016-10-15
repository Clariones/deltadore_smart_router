/**
 * File name: CmdQueryRollerShutterStatusHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */
#include "CmdQueryRollerShutterStatusHandler.h"

#define CMD_NAME "queryRollerShutterStatus"

CmdQueryRollerShutterStatusHandler::CmdQueryRollerShutterStatusHandler(){
}

CmdQueryRollerShutterStatusHandler::~CmdQueryRollerShutterStatusHandler(){
}

const char* CmdQueryRollerShutterStatusHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
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
    

    cJSON* pResponse = pDriver->queryRollerShutterStatus(network, node,);
    return newResponse(pResponse);
}

const char * CmdQueryRollerShutterStatusHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdQueryRollerShutterStatusHandler::getUsage(){
    return "query roller shutter status information\n" \
        "Usage:\n" \
        "    queryRollerShutterStatus <network> <node>\n" \
        "Params:\n" \
        "    network: the network number of target device, 0~11\n" \
        "    node: the node number of target device, 0~15\n" \
        "";
}

#undefine CMD_NAME