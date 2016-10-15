/**
 * File name: CmdDeleteNodeHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDDELETENODEHANDLER_INCLUDE__
#define __CMDDELETENODEHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdDeleteNodeHandler: public BaseCmdHandler {

public:
    CmdDeleteNodeHandler();
    virtual ~CmdDeleteNodeHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDDELETENODEHANDLER_INCLUDE__