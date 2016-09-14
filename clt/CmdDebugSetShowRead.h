#ifndef CMDDEBUGSETSHOWREAD_H
#define CMDDEBUGSETSHOWREAD_H


#include "clt/CommandHandler.h"

using namespace deltadoreX2d;

class CmdDebugSetShowRead: public ICommandHandler
{
    public:
        CmdDebugSetShowRead();
        virtual ~CmdDebugSetShowRead();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();

    protected:

    private:
};

#endif // CMDDEBUGSETSHOWREAD_H
