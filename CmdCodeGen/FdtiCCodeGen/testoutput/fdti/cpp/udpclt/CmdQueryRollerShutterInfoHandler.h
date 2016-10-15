/**
 * File name: CmdQueryRollerShutterInfoHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDQUERYROLLERSHUTTERINFOHANDLER_INCLUDE__
#define __CMDQUERYROLLERSHUTTERINFOHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdQueryRollerShutterInfoHandler: public BaseCmdHandler {

public:
    CmdQueryRollerShutterInfoHandler();
    virtual ~CmdQueryRollerShutterInfoHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDQUERYROLLERSHUTTERINFOHANDLER_INCLUDE__