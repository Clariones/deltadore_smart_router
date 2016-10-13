/**
 * File name: CmdControlRollerShutterHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDCONTROLROLLERSHUTTERHANDLER_INCLUDE__
#define __CMDCONTROLROLLERSHUTTERHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdControlRollerShutterHandler: public BaseCmdHandler {

public:
    CmdControlRollerShutterHandler();
    virtual ~CmdControlRollerShutterHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDCONTROLROLLERSHUTTERHANDLER_INCLUDE__