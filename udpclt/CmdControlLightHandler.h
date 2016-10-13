#ifndef CMDCONTROLLIGHTHANDLER_H_INCLUDED
#define CMDCONTROLLIGHTHANDLER_H_INCLUDED

#include "BaseCmdHandler.h"

class CmdControlLightHandler: public BaseCmdHandler {

public:
    CmdControlLightHandler();
    virtual ~CmdControlLightHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // CMDCONTROLLIGHTHANDLER_H_INCLUDED
