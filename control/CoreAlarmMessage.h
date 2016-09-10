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

#ifndef COREALARMMESSAGE_H
#define COREALARMMESSAGE_H

#include "control/CoreMessage.h"
#include "control/AlarmMessage.h"

namespace deltadoreX2d
{

class CoreAlarmMessage : public CoreMessage, public virtual AlarmMessage
{
    public :
        CoreAlarmMessage();
        CoreAlarmMessage(const std::vector<byte>& frame);
        ~CoreAlarmMessage();

        int getSourcePort() const;
        void setSourcePort(int port);
		bool isTestMode() const;
		void setTestMode(bool value);
		int getDestinationAddress() const;
		void setDestinationAddress(int address);
        void serialize(std::vector<byte>& frame) const;

	protected :
		int m_destinationAddress;
};
}

#endif /* COREALARMMESSAGE_H */
