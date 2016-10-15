/**
 * File name: CmdGetTopologyHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDGETTOPOLOGYHANDLER_INCLUDE__
#define __CMDGETTOPOLOGYHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdGetTopologyHandler: public BaseCmdHandler {

public:
    CmdGetTopologyHandler();
    virtual ~CmdGetTopologyHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDGETTOPOLOGYHANDLER_INCLUDE__