#ifndef COMMANDLINETOOL_H
#define COMMANDLINETOOL_H

#include "requirement.h"
#include "control/Controller.h"
#include "clt/CommandHandler.h"

using namespace deltadoreX2d;


class CommandLineTool
{
    public:
        CommandLineTool();
        virtual ~CommandLineTool();

    public:
        void init(DeltaDoreX2Driver* pDriver);
        void run();

    protected:
        ICommandHandler* findHandler(const char * cmdBuffer);
        void showHelp();

    protected:
        DeltaDoreX2Driver* m_pDriver;
        static ICommandHandler* m_pHandlers[];
        int m_handlerNum;
};

#endif // COMMANDLINETOOL_H
