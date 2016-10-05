/**
 * File name: CmdControlLightColorHandler.cpp
 * Author: Clariones Wang
 * Email: Clariones@163.com
 *
 * All rights reserved.
 */
#include "CmdControlLightColorHandler.h"

#define CMD_NAME "controlLightColor"

CmdControlLightColorHandler::CmdControlLightColorHandler(){
}

CmdControlLightColorHandler::~CmdControlLightColorHandler(){
}

void CmdControlLightColorHandler::handle(const char* pCmd, DeltaDoreX2Driver* pDriver){
    int network;
    int node;
    int red;
    int green;
    int blue;
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
    getParamInt(pCurrentParam, &red);
    if (!isValidIntParam(red, 0, 255){
        return newWrongIntParamResponse("invalid red value %d, should be in [0, 255]", red);
    }
    
    pCurrentParam = getNextParamStartPosition(pCurrentParam);
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    getParamInt(pCurrentParam, &green);
    if (!isValidIntParam(green, 0, 255){
        return newWrongIntParamResponse("invalid green value %d, should be in [0, 255]", green);
    }
    
    pCurrentParam = getNextParamStartPosition(pCurrentParam);
    if (pCurrentParam == NULL){
        return newMissingRequiredParametersResponse();
    }
    getParamInt(pCurrentParam, &blue);
    if (!isValidIntParam(blue, 0, 255){
        return newWrongIntParamResponse("invalid blue value %d, should be in [0, 255]", blue);
    }


    cJSON* pResponse = pDriver->setLightColor(network, node, red, green, blue);
    return newResponse(pResponse);
}

const char * CmdControlLightColorHandler::getCommandName(){
    return CMD_NAME;
}

const char * CmdControlLightColorHandler::getUsage(){
    return "Usage:\n" \
        "    controlLightColor <network> <node> <red> <green> <blue>\n" \
        "Params:\n" \
        "    network: the network number of target device, 0~11\n" \
        "    node: the node number of target device, 0~15\n" \
        "    red: red value of the color\n" \
        "    green: green value of the color\n" \
        "    blue: blue value of the color";
}

#undefine CMD_NAME