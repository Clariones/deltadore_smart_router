#include "clt/CmdGetTopology.h"

CmdGetTopology::CmdGetTopology()
{
    //ctor
}

CmdGetTopology::~CmdGetTopology()
{
    //dtor
}
void CmdGetTopology::handle(const char* pCmd, DeltaDoreX2Driver* pDriver)
{
    char* buffer = new char[1024];
    pDriver->getTopology(buffer, 1024);
    printf("%s\n", buffer);
    delete(buffer);
}

const char* CmdGetTopology::getSummary()
{
    return "Show currently recognized network and nodes";
}

const char* CmdGetTopology::getCmdKey()
{
    return "showNetwork";
}
