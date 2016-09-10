#include "clt/CommandLineTool.h"

#include "clt/CmdGetTopology.h"

#ifndef NULL
#define NULL (void*)0
#endif

CommandLineTool::CommandLineTool()
{
    //ctor
}

CommandLineTool::~CommandLineTool()
{
    //dtor
}

void CommandLineTool::init(DeltaDoreX2Driver* pDriver)
{
    m_pDriver = pDriver;
    m_handlerNum = 0;
    m_pHandlers = (ICommandHandler**)malloc(100*sizeof(ICommandHandler*));
    m_pHandlers[m_handlerNum++] = new CmdGetTopology();
}


void CommandLineTool::run()
{
    char* cmdBuffer = new char[100];

    for(;;){
        printf("\n#");
        scanf("%s", cmdBuffer);
        if (strcmp("exit", cmdBuffer) == 0){
            break;
        }
        if (strcmp("help", cmdBuffer) == 0) {
            showHelp();
            continue;
        }
        ICommandHandler* handler = findHandler(cmdBuffer);
        if (handler == NULL){
            printf("%s not recognized as a valid command. Please try \"help\"", cmdBuffer);
            continue;
        }
        handler->handle(cmdBuffer, m_pDriver);
    }


    delete cmdBuffer;
}

ICommandHandler* CommandLineTool::findHandler(const char* cmdBuffer)
{
    ICommandHandler* pHandler;
    for(int i=0;i<m_handlerNum;i++){
        pHandler = m_pHandlers[i];
        if (strcmp(cmdBuffer, pHandler->getCmdKey()) == 0){
            return pHandler;
        }
    }
    return NULL;
}

void CommandLineTool::showHelp()
{
    ICommandHandler* pHandler;
    for(int i=0;i<m_handlerNum;i++){
        pHandler = m_pHandlers[i];
        printf("[%s]\t%s : %s\n", "help", pHandler->getCmdKey(), pHandler->getSummary());
    }
}
