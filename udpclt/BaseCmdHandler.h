#ifndef BASECMDHANDLER_H
#define BASECMDHANDLER_H

#include "driver/DeltaDoreX2Driver.h"
#include "driver/cJSON.h"

typedef const char* CMD_RETURN_TYPE;

class BaseCmdHandler
{
    public:
        BaseCmdHandler();
        virtual ~BaseCmdHandler();

    protected:
        virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver) = 0;
        virtual const char * getCommandName() = 0;
        virtual const char * getUsage() = 0;

    protected:
        virtual CMD_RETURN_TYPE getNextParamStartPosition(const char * pCmd);
        virtual bool isValidNetwork(int networkId);
        virtual bool isValidNode(int nodeId);
        virtual CMD_RETURN_TYPE newMissingRequiredParametersResponse();
        virtual CMD_RETURN_TYPE newWrongIntParamResponse(const char* pMsg, int arg);
        virtual CMD_RETURN_TYPE newWrongStringParamResponse(const char* pMsg, const char* pArg);
        virtual CMD_RETURN_TYPE newResponse(const cJSON* pResponse);
        virtual void getParamInt(const char* pInput, int* pArg);
        virtual void getParamString(const char* pInput, const char* pArg);

    private:
};

#endif // BASECMDHANDLER_H
