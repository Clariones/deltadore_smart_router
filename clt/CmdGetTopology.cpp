#include "clt/CmdGetTopology.h"
#include "driver/cJSON.h"

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
    cJSON* pResponse = pDriver->getTopology();
    printf("%s\n", cJSON_Print(pResponse));
    cJSON_Delete(pResponse);
}

const char* CmdGetTopology::getSummary()
{
    return "Show currently recognized network and nodes";
}

const char* CmdGetTopology::getCmdKey()
{
    return "getTopology";
}
