#include "UdpCmdManager.h"
#include <stdio.h>
#include <string.h>

#include "CmdControlLightHandler.h"

#define HANDLER(name) \
    handlers[i++] = new name();                   \
    if (i >= MAX_HANDLERS_NUMBER){                                  \
        printf("Can only have %d handlers\n", MAX_HANDLERS_NUMBER); \
        exit(-1);                                                   \
    }else{                                                          \
        printf("UDP command handler " #name " created\n");           \
    }
static const char* RESP(const char* pStr){
    char* pBuf = new char[strlen(pStr)+1];
    strcpy(pBuf, pStr);
    return pBuf;
}

UdpCmdManager::UdpCmdManager()
{
    int i = 0;
    HANDLER(CmdControlLightHandler)
    HANDLER(CmdControlLightHandler)
//    handlers[i++] = new CmdControlLightHandler();
//    if (i >= MAX_HANDLERS_NUMBER){
//        printf("Can only have %d handlers\n", MAX_HANDLERS_NUMBER);
//        exit(-1);
//    }
    handlers[i++] = NULL;
}

UdpCmdManager::~UdpCmdManager()
{
    //dtor
}
void UdpCmdManager::setPort(int pPort)
{
    port = pPort;
}

int UdpCmdManager::getPort()
{
    return port;
}

pthread_t UdpCmdManager::start()
{
    runningFlag = true;
    pUdpServer = udp_server_new();
    pUdpServer->bind(pUdpServer, port);
    recvBuffer = new char[1600];
    pthread_create (&threadId, NULL, &startRoutine, this);

    return threadId;
}

void UdpCmdManager::run(){
    printf("UDP command listener is running...\n");
    remote_node remoteNode;
    char* commandBuffer = new char[1500];

    while(runningFlag){
        int len = pUdpServer->recv(pUdpServer, &remoteNode, recvBuffer, 1600);
        if (len <= 0){
            continue;
        }
        recvBuffer[len] = 0;
        printf("Got message: %s\n", recvBuffer);

        if (strcmp("exit", commandBuffer) == 0){
            sendResponse(RESP("degele"), &remoteNode);
            this->stop();
            break;
        }
        if (strcmp("help", commandBuffer) == 0){
            sendResponse(getHelpMessage(recvBuffer), &remoteNode);
            continue;
        }
        sscanf(recvBuffer, "%s", commandBuffer);
        printf("Command name is %s\n", commandBuffer);
        processCommand(commandBuffer, recvBuffer, &remoteNode);
    }
    delete commandBuffer;
}
const char* UdpCmdManager::getHelpMessage(const char* pCmdInput)
{
    if (strcmp("help", pCmdInput) == 0){
        // only help. not help for a topic
        char* pResult = new char[MAX_UDP_SIZE+1];
        int pos = sprintf(pResult, "Below commands are valid:\n");
        char* pBuff = pResult + pos;
        for(int i=0;i<MAX_HANDLERS_NUMBER;i++){
            BaseCmdHandler* pHandler = handlers[i];
            if (pHandler == NULL){
                return pResult;
            }
            pos += sprintf(pBuff, "  %s\n", pHandler->getCommandName());
            pBuff = pResult + pos;
        }
    }
    return RESP("TODO: help on topic");
}

void UdpCmdManager::sendResponse(const char* pResponse, const void* pRemoteArg)
{
    remote_node* pRemoteNode = (remote_node*)pRemoteArg;
    pUdpServer->send(pUdpServer, pRemoteNode, pResponse, MAX_UDP_SIZE);
    delete pResponse;
}

const char* UdpCmdManager::responseCommandUnknown(const char* pCmdName)
{
    char* pData = new char[MAX_UDP_SIZE+1];
    sprintf(pData, "Command %s unknown. Try help for valid command list", pCmdName);
    return pData;
}

void UdpCmdManager::processCommand(const char* pCmdName, const char* pCmdInput, const remote_node* pRemoteNode)
{
    for(int i=0;i<MAX_HANDLERS_NUMBER;i++){
        BaseCmdHandler* pHandler = handlers[i];
        if (pHandler == NULL){
            sendResponse(responseCommandUnknown(pCmdName), pRemoteNode);
            return;
        }

        if (strcmp(pCmdName, pHandler->getCommandName()) == 0){
            sendResponse(pHandler->handle(pCmdInput, getDriver()), pRemoteNode);
            return;
        }
    }
}

void UdpCmdManager::stop()
{
    printf("Set running flag to false\n");
    runningFlag = false;
}

void UdpCmdManager::release()
{
    pthread_join(threadId, (void**)0);
    pUdpServer->close(pUdpServer);
    udp_server_delete(pUdpServer);
    delete recvBuffer;
    recvBuffer = 0;
}
