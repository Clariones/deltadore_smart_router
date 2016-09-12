#ifndef CMDREGISTERNODE_H
#define CMDREGISTERNODE_H


#include "clt/CommandHandler.h"

using namespace deltadoreX2d;

class CmdRegisterNode: public ICommandHandler
{
    public:
        CmdRegisterNode();
        virtual ~CmdRegisterNode();

    public:
        virtual void handle(const char* cmd, DeltaDoreX2Driver* pDriver);
        virtual const char* getSummary();
        virtual const char* getCmdKey();

    protected:

    private:
};

#endif // CMDREGISTERNODE_H
