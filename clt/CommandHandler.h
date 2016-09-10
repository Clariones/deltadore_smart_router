#ifndef COMMANDHANDLER_INCLUDED
#define COMMANDHANDLER_INCLUDED
#include "requirement.h"
#include "control/Controller.h"
#include "driver/DeltaDoreX2Driver.h"

using namespace deltadoreX2d;

class ICommandHandler {

public :
        virtual void handle(const char* pCmd, DeltaDoreX2Driver* pDriver) = 0;
        virtual const char* getSummary() = 0;
        virtual const char* getCmdKey() = 0;
};

#endif // COMMANDHANDLER_INCLUDED
