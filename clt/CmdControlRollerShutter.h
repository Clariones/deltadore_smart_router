#ifndef CMDCONTROLROLLERSHUTTER_H
#define CMDCONTROLROLLERSHUTTER_H

#include "clt/CommandHandler.h"

using namespace deltadoreX2d;


class CmdControlRollerShutter : public ICommandHandler
{
    public:
        CmdControlRollerShutter();
        virtual ~CmdControlRollerShutter();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();

    protected:

    private:
};

#endif // CMDCONTROLROLLERSHUTTER_H
