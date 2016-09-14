#ifndef CmdQueryLightColor_H
#define CmdQueryLightColor_H

#include "clt/CommandHandler.h"

class CmdQueryLightColor : public ICommandHandler
{
    public:
        CmdQueryLightColor();
        virtual ~CmdQueryLightColor();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();

    protected:

    private:
};

#endif // CmdQueryLightColor_H
