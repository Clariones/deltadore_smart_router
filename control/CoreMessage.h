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

#ifndef COREMESSAGE_H
#define COREMESSAGE_H

#include "control/Message.h"
#include "control/RadioFrequency.h"

namespace deltadoreX2d
{

class CoreMessage : public virtual Message
{
    public :
        CoreMessage();
        CoreMessage(const std::vector<byte>& frame);
        virtual ~CoreMessage();

		int getSourceAddress() const;
        int getDestinationPort() const;
        int getSourceType() const;
        void setSourceType(int type);
        bool isEnrollmentRequest() const;
        void setEnrollmentRequest(bool value);
        bool isAnswerRequest() const;
        void setAnswerRequest(bool value);
        bool isBatteryFaulty() const;
        void setBatteryFaulty(bool value);
        bool isSelfProtectionFaulty() const;
        void setSelfProtectionFaulty(bool value);
        bool isInternalFaulty() const;
        void setInternalFaulty(bool value);
		const MessagePriority& getPriority() const;
		void setPriority(const MessagePriority& priority);
        virtual void serialize(std::vector<byte>& frame) const;

        RadioFrequency m_frequency;

	protected :
        int m_sourceAddress;
        int m_destinationPort;
		bool m_isTestMode;
		bool m_isAnswerRequest;
		bool m_isBatteryFaulty;
        bool m_isSelfProtectionFaulty;
        bool m_isInternalFaulty;
		int m_sourceType;
		MessagePriority m_messagePriority;
};
}

#endif // COREMESSAGE_H
