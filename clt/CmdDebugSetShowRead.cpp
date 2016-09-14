#include "CmdDebugSetShowRead.h"

CmdDebugSetShowRead::CmdDebugSetShowRead()
{
    //ctor
}

CmdDebugSetShowRead::~CmdDebugSetShowRead()
{
    //dtor
}
void CmdDebugSetShowRead::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    char buffer[100];
    scanf("%s", buffer);
    cJSON* pResponse = pDriver->debugPrintRead(strcmp("true", buffer)==0);
    printf("%s\n", cJSON_Print(pResponse));
    delete(pResponse);
}

const char* CmdDebugSetShowRead::getSummary()
{
    return "debugEnablePrintRead <true|false>\n[help]\t\tEnable the printing or not when read from serial port. This just used for debugging. ";
}

const char* CmdDebugSetShowRead::getCmdKey()
{
    return "debugEnablePrintRead";
}
