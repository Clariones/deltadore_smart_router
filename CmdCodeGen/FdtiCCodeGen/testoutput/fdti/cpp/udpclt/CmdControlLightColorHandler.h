/**
 * File name: CmdControlLightColorHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDCONTROLLIGHTCOLORHANDLER_INCLUDE__
#define __CMDCONTROLLIGHTCOLORHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdControlLightColorHandler: public BaseCmdHandler {

public:
    CmdControlLightColorHandler();
    virtual ~CmdControlLightColorHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDCONTROLLIGHTCOLORHANDLER_INCLUDE__