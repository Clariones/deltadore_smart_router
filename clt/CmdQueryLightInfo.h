#ifndef CmdQueryLightInfo_H
#define CmdQueryLightInfo_H

#include "clt/CommandHandler.h"

class CmdQueryLightInfo : public ICommandHandler
{
    public:
        CmdQueryLightInfo();
        virtual ~CmdQueryLightInfo();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();

    protected:

    private:
};

#endif // CmdQueryLightInfo_H
