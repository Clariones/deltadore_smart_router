#ifndef CMDCONTROLLIGHT_H
#define CMDCONTROLLIGHT_H

#include "clt/CommandHandler.h"

using namespace deltadoreX2d;

class CmdControlLight: public ICommandHandler
{
    public:
        CmdControlLight();
        virtual ~CmdControlLight();
    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();

    protected:

    private:
};

#endif // CMDCONTROLLIGHT_H
