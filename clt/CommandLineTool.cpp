#include "clt/CommandLineTool.h"

#include "clt/CmdGetTopology.h"
#include "clt/CmdQueryRollershutterStatus.h"
#include "clt/CmdQueryRollershutterInfo.h"
#include "clt/CmdControlRollerShutter.h"
#include "clt/CmdDeleteNode.h"
#include "clt/CmdRegisterNode.h"
#include "clt/CmdControlLight.h"
#include "clt/CmdQueryLight.h"

#ifndef NULL
#define NULL (void*)0
#endif

#define MAX_CANDIDATES 10
static ICommandHandler* candidates[MAX_CANDIDATES];
static int foundCandidates = 0;
static bool startsWith(const char* wholeString, const char* prefix)
{
    if (wholeString == prefix){
        return true;
    }
    int nStr = strlen(wholeString);
    int nPre = strlen(prefix);
    if (nPre > nStr){
        return false;
    }
    if (strncmp(wholeString, prefix, nPre) == 0){
        return true;
    }else{
        return false;
    }
}


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
    m_pHandlers[m_handlerNum++] = new CmdRegisterNode();
    m_pHandlers[m_handlerNum++] = new CmdDeleteNode();
    m_pHandlers[m_handlerNum++] = new CmdControlLight();
    m_pHandlers[m_handlerNum++] = new CmdQueryLight();
    m_pHandlers[m_handlerNum++] = new CmdControlRollerShutter();
    m_pHandlers[m_handlerNum++] = new CmdQueryRollershutterStatus();
    m_pHandlers[m_handlerNum++] = new CmdQueryRollershutterInfo();


}


void CommandLineTool::run()
{
    char* cmdBuffer = new char[100];

    for(;;)
    {
        printf("\n#");
        scanf("%s", cmdBuffer);
        if (strcmp("exit", cmdBuffer) == 0)
        {
            break;
        }
        if (strcmp("help", cmdBuffer) == 0)
        {
            showHelp();
            continue;
        }
        ICommandHandler* handler = findHandler(cmdBuffer);
        if (handler == NULL)
        {
            if (foundCandidates == 0){
                printf("%s not recognized as a valid command. Please try \"help\"", cmdBuffer);
                continue;
            }
            if (foundCandidates == 1){
                handler = candidates[0];
                printf("execute command %s\n", handler->getCmdKey());
                handler->handle(cmdBuffer, m_pDriver);
                continue;
            }
            printf("%s cannot be recognized as unified command, do you mean:\n");
            for(int i=0;i<foundCandidates;i++){
                printf("\t%s\n", candidates[i]->getCmdKey());
            }
            continue;
        }
        handler->handle(cmdBuffer, m_pDriver);
    }


    delete cmdBuffer;
}

ICommandHandler* CommandLineTool::findHandler(const char* cmdBuffer)
{
    ICommandHandler* pHandler;
    foundCandidates = 0;
    for(int i=0; i<m_handlerNum; i++)
    {
        pHandler = m_pHandlers[i];
        if (strcmp(cmdBuffer, pHandler->getCmdKey()) == 0)
        {
            return pHandler;
        }
        if (startsWith(pHandler->getCmdKey(), cmdBuffer)){
            if (foundCandidates < MAX_CANDIDATES){
                candidates[foundCandidates++] = pHandler;
            }
        }
    }
    return NULL;
}

void CommandLineTool::showHelp()
{
    ICommandHandler* pHandler;
    for(int i=0; i<m_handlerNum; i++)
    {
        pHandler = m_pHandlers[i];
        printf("[%s]\t%s :\n[help]\t\t%s\n", "help", pHandler->getCmdKey(), pHandler->getSummary());
    }
}

