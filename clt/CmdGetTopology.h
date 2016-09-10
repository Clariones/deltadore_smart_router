#ifndef CMDGETTOPOLOGY_H
#define CMDGETTOPOLOGY_H

#include "clt/CommandHandler.h"

using namespace deltadoreX2d;

class CmdGetTopology : public ICommandHandler
{
    public:
        CmdGetTopology();
        virtual ~CmdGetTopology();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();
    protected:

    private:
};

#endif // CMDGETTOPOLOGY_H
