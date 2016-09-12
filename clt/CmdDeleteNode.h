#ifndef CMDDELETENODE_H
#define CMDDELETENODE_H

#include "clt/CommandHandler.h"

using namespace deltadoreX2d;

class CmdDeleteNode : public ICommandHandler
{
    public:
        CmdDeleteNode();
        virtual ~CmdDeleteNode();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();
    protected:

    private:
};

#endif // CMDDELETENODE_H
