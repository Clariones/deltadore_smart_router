/**
 * File name: CmdQueryRollerShutterStatusHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDQUERYROLLERSHUTTERSTATUSHANDLER_INCLUDE__
#define __CMDQUERYROLLERSHUTTERSTATUSHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdQueryRollerShutterStatusHandler: public BaseCmdHandler {

public:
    CmdQueryRollerShutterStatusHandler();
    virtual ~CmdQueryRollerShutterStatusHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDQUERYROLLERSHUTTERSTATUSHANDLER_INCLUDE__