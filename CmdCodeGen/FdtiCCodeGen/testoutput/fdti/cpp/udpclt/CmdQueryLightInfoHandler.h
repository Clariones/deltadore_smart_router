/**
 * File name: CmdQueryLightInfoHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDQUERYLIGHTINFOHANDLER_INCLUDE__
#define __CMDQUERYLIGHTINFOHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdQueryLightInfoHandler: public BaseCmdHandler {

public:
    CmdQueryLightInfoHandler();
    virtual ~CmdQueryLightInfoHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDQUERYLIGHTINFOHANDLER_INCLUDE__