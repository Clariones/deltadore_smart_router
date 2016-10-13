#include "BaseCmdHandler.h"

BaseCmdHandler::BaseCmdHandler()
{
    //ctor
}

BaseCmdHandler::~BaseCmdHandler()
{
    //dtor
}

const char* BaseCmdHandler::getNextParamStartPosition(const char* pCmd)
{
    // TODO
    return NULL;
}

bool BaseCmdHandler::isValidNetwork(int networkId)
{
    // TODO
    return false;
}

bool BaseCmdHandler::isValidNode(int nodeId)
{
    // TODO
    return false;
}
CMD_RETURN_TYPE BaseCmdHandler::newWrongIntParamResponse(const char* pMsg, int pArg)
{
    // TODO
    return NULL;
}

CMD_RETURN_TYPE BaseCmdHandler::newMissingRequiredParametersResponse()
{
    // TODO
    return NULL;
}

CMD_RETURN_TYPE BaseCmdHandler::newWrongStringParamResponse(const char* pMsg, const char* pArg)
{
    // TODO
    return NULL;
}

CMD_RETURN_TYPE BaseCmdHandler::newResponse(const cJSON* pResponse)
{
    // TODO
    return NULL;
}

void BaseCmdHandler::getParamInt(const char* pInput, int* pArg)
{

}

void BaseCmdHandler::getParamString(const char* pInput, const char* pArg)
{

}



