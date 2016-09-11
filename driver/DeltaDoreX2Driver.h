#ifndef DELTADOREX2DRIVER_H
#define DELTADOREX2DRIVER_H

#include "requirement.h"
#include "driver/SerialPort.h"

#include "control/Node.h"
#include "control/Response.h"
#include "control/Request.h"
#include "rollershutter/RollerShutterStatusResponse.h"
#include "control/NodeDiscoveredEvent.h"
#include "control/Controller.h"
#include "control/Factory.h"
#include "control/MeshController.h"
#include "control/DirectController.h"
#include "control/Network.h"
#include "control/Node.h"

 #include <semaphore.h>

using namespace deltadoreX2d;

class DeltaDoreX2Driver: public AcknowledgmentListener, public EndTransactionListener, public NodeDiscoveredListener
{
    public:
        DeltaDoreX2Driver();
        virtual ~DeltaDoreX2Driver();

    // callback functions
    public:
        virtual void acknowledgment(const AcknowledgmentEvent& evt);
        virtual void endTransaction(const EndTransactionEvent& evt);
        virtual void nodeDiscovered(const NodeDiscoveredEvent& evt);
    // command interfaces
    public:
        void getTopology(char* buffer, int sizen);

    public:
        void init(const char* devName);
        void waitAck();

    private:
        SerialPort device;
        Controller* controller;
        sem_t semAck;
};

#endif // DELTADOREX2DRIVER_H
