/*
** Copyright (C) 2010 Eff'Innov Technologies.  All rights reserved.
** May not be redistributed without prior written permission.
**
** Based on Java version by DeltaDore, subject to DeltaDore copyrights
**
** Note: Eff'Innov Technologies disclaims responsibility for any malfunction
** or error that may arise from any change to the current file, provided that such
** change have not been submitted to and formerly approved by Eff'Innov Technologies,
** prior to the occurence of such malfunction or error
**
** Author: Mickael Leforestier (mickael.leforestier@effinnov.com)
**
** History log:
** ------------------------------------------------------------------------------
** Author              | Date             | Changes
** ------------------------------------------------------------------------------
** mleforestier        | 092410           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef CORECONTROLLER_H
#define CORECONTROLLER_H

#include "control/DirectController.h"
#include "control/MeshController.h"
#include "control/CoreNetwork.h"
#include "control/Statistic.h"
#include "control/Codec.h"

namespace deltadoreX2d
{

class CoreController : public Runnable, public virtual MeshController, public virtual DirectController
{
    public :
        CoreController();
        ~CoreController();

        int getReceivedCount();
        int getSentCount();
        int getErrorCount();
        int getTimeoutCount();
        void addFrameReceivedListener(FrameReceivedListener* listener);
        void removeFrameReceivedListener(FrameReceivedListener* listener);
        void fireFrameReceived(const FrameIoEvent& evt);
        void addFrameSentListener(FrameSentListener* listener);
        void removeFrameSentListener(FrameSentListener* listener);
        void fireFrameSent(const FrameIoEvent& evt);
        void addAcknowledgmentListener(AcknowledgmentListener* listener);
        void removeAcknowledgmentListener(AcknowledgmentListener* listener);
        void fireAcknowledgment(const AcknowledgmentEvent& evt);
        void addMessageReceivedListener(MessageReceivedListener* listener);
        void removeMessageReceivedListener(MessageReceivedListener* listener);
        void fireMessageReceived(const MessageReceivedEvent& evt);
        void addEndTransactionListener(EndTransactionListener* listener);
        void removeEndTransactionListener(EndTransactionListener* listener);
        void fireEndTransaction(const EndTransactionEvent& evt);
        void addNodeDiscoveredListener(NodeDiscoveredListener* listener);
        void removeNodeDiscoveredListener(NodeDiscoveredListener* listener);
        void fireNodeDiscovered(const NodeDiscoveredEvent& evt);
        void open(InputStream* in, OutputStream* out);
        void close();
        void clearStatistics();
        void sendFrame(std::vector<byte>& frame);
        void sendFrame(const std::string& hexString);
        void setEnrollmentListeningMode(bool enabled);
        void setEnrollmentListeningMode(int port);
        void clearEnrolledSources();
        void sendMessage(Message* message, const RadioFrequency& frequency);
        Message* createMessage(MessageClass type);
        void initNetworks();
		void initNetworks(int count);
		int getNetworkCount();
        Network* getNetwork(int id);
        Request* createRequest(RequestClass type);
        void beginTransaction(Request* request);
        void writeOutput(std::vector<byte>& frame);
		void run();
		CoreController* core();

        volatile bool m_jobCancel;
		volatile bool m_jobRunning;
        InputStream* m_inputStream;
        OutputStream* m_outputStream;
        std::list<FrameSentListener*> m_frameSentListeners;
        std::list<FrameReceivedListener*> m_frameReceivedListeners;
        std::list<AcknowledgmentListener*> m_acknowledgmentListeners;
        std::list<MessageReceivedListener*> m_messageReceivedListeners;
        std::list<EndTransactionListener*> m_endTransactionListeners;
        std::list<NodeDiscoveredListener*> m_nodeDiscoveredListeners;
        Statistic m_stat;
        std::vector<CoreNetwork> m_networks;
        Codec* m_codec;
		RecursiveLock m_lock;
};
}

#endif /* CORECONTROLLER_H */
