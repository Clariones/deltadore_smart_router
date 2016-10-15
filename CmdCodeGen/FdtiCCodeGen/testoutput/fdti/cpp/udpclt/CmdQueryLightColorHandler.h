/**
 * File name: CmdQueryLightColorHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDQUERYLIGHTCOLORHANDLER_INCLUDE__
#define __CMDQUERYLIGHTCOLORHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdQueryLightColorHandler: public BaseCmdHandler {

public:
    CmdQueryLightColorHandler();
    virtual ~CmdQueryLightColorHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDQUERYLIGHTCOLORHANDLER_INCLUDE__