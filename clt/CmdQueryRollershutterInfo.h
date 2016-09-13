#ifndef CmdQueryRollershutterInfo_H
#define CmdQueryRollershutterInfo_H

#include "clt/CommandHandler.h"


class CmdQueryRollershutterInfo : public ICommandHandler
{
    public:
        CmdQueryRollershutterInfo();
        virtual ~CmdQueryRollershutterInfo();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();
    protected:

    private:
};

#endif // CmdQueryRollershutterInfo_H
