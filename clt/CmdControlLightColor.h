#ifndef CmdControlLightColor_H
#define CmdControlLightColor_H

#include "clt/CommandHandler.h"

using namespace deltadoreX2d;

class CmdControlLightColor: public ICommandHandler
{
    public:
        CmdControlLightColor();
        virtual ~CmdControlLightColor();
    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();

    protected:

    private:
};

#endif // CmdControlLightColor_H
