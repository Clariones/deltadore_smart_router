#ifndef CMDQUERYLIGHT_H
#define CMDQUERYLIGHT_H

#include "clt/CommandHandler.h"

class CmdQueryLight : public ICommandHandler
{
    public:
        CmdQueryLight();
        virtual ~CmdQueryLight();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();

    protected:

    private:
};

#endif // CMDQUERYLIGHT_H
