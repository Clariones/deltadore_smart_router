/**
 * File name: CmdQueryLightStatusHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDQUERYLIGHTSTATUSHANDLER_INCLUDE__
#define __CMDQUERYLIGHTSTATUSHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdQueryLightStatusHandler: public BaseCmdHandler {

public:
    CmdQueryLightStatusHandler();
    virtual ~CmdQueryLightStatusHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDQUERYLIGHTSTATUSHANDLER_INCLUDE__