/**
 * File name: CmdRegisterNodeHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDREGISTERNODEHANDLER_INCLUDE__
#define __CMDREGISTERNODEHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdRegisterNodeHandler: public BaseCmdHandler {

public:
    CmdRegisterNodeHandler();
    virtual ~CmdRegisterNodeHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDREGISTERNODEHANDLER_INCLUDE__