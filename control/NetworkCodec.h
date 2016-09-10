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

#ifndef NETWORKCODEC_H
#define NETWORKCODEC_H

#include "control/Codec.h"
#include "control/CoreNetwork.h"
#include "control/Node.h"

namespace deltadoreX2d
{

class NetworkCodec : public Codec
{
    public :
        NetworkCodec(CoreController* controller);
        ~NetworkCodec();

        void decode(const std::vector<byte>& frame, int ctrl);
        void getAllTopology();
        void startNodeDiscovery(bool automatic, int retries);
        void scan();
        void addCurrentNode();
        void scanNode(const Node& node);
        void deleteNode(const Node& node, bool forced);
        void deleteAllNodes();
        void deleteReachableNodes();
        void deleteUnreachableNodes();
        void setAllTopology(const std::vector<byte>& frame);
        void setTopology(const std::vector<byte>& frame);
		void setNetwork(CoreNetwork* network);

	private :
        CoreNetwork* m_network;
};
}

#endif /* NETWORKCODEC_H */
