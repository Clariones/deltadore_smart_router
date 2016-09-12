#ifndef CMDQUERYROLLERSHUTTERSTATUS_H
#define CMDQUERYROLLERSHUTTERSTATUS_H

#include "clt/CommandHandler.h"


class CmdQueryRollershutterStatus : public ICommandHandler
{
    public:
        CmdQueryRollershutterStatus();
        virtual ~CmdQueryRollershutterStatus();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();
    protected:

    private:
};

#endif // CMDQUERYROLLERSHUTTERSTATUS_H
