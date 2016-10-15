/**
 * File name: CmdForceRefreshTopologyHandler.cpp
 * Author: Clariones Wang
 *
 * All rights reserved.
 */

#ifndef __CMDFORCEREFRESHTOPOLOGYHANDLER_INCLUDE__
#define __CMDFORCEREFRESHTOPOLOGYHANDLER_INCLUDE__

#include "BaseCmdHandler.h"

class CmdForceRefreshTopologyHandler: public BaseCmdHandler {

public:
    CmdForceRefreshTopologyHandler();
    virtual ~CmdForceRefreshTopologyHandler();

public:
    virtual const char * handle(const char* pCmd, DeltaDoreX2Driver* pDriver);
    virtual const char * getCommandName();
    virtual const char * getUsage();

};

#endif // __CMDFORCEREFRESHTOPOLOGYHANDLER_INCLUDE__