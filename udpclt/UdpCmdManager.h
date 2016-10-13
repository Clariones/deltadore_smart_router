#ifndef UDPCMDMANAGER_H
#define UDPCMDMANAGER_H

#include <pthread.h>
#include "udp_server.h"
#include "BaseCmdHandler.h"
#include "driver/DeltaDoreX2Driver.h"
#include "driver/cJSON.h"

#define MAX_HANDLERS_NUMBER 30

class UdpCmdManager
{
    public:
        UdpCmdManager();
        virtual ~UdpCmdManager();

    public:
        void setPort(int port);
        int getPort();
        pthread_t start();
        void stop();
        void release();
        DeltaDoreX2Driver* getDriver() { return pDriver;};
        void setDriver(DeltaDoreX2Driver* pDeviceDriver) { pDriver = pDeviceDriver;};
        void sendResponse(const char* pResponse, const void* pRemoteArg);

    protected:
        void run();
        static void* startRoutine(void* pThis){
            UdpCmdManager* pServer = (UdpCmdManager*) pThis;
            pServer->run();
            return pThis;
        }
        void processCommand(const char* pCmdName, const char* pCmdInput, const remote_node* pRemoteNode);
        const char* responseCommandUnknown(const char* pCmdName);
        const char* getHelpMessage(const char* pCmdInput);

    protected:
        int port;
        pthread_t threadId;
        udp_server * pUdpServer;
        char* recvBuffer;
        bool runningFlag;
        BaseCmdHandler* handlers[MAX_HANDLERS_NUMBER];
        DeltaDoreX2Driver* pDriver;
};

#endif // UDPCMDMANAGER_H
