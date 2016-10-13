/**
 * File name: CmdControlLightHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDCONTROLLIGHTHANDLER_INCLUDE__
#define __CMDCONTROLLIGHTHANDLER_INCLUDE__

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

#endif // __CMDCONTROLLIGHTHANDLER_INCLUDE__