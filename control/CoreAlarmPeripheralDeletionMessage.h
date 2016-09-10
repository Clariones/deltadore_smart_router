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
** mleforestier        | 041311           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef COREALARMPHERIPHERALDELETIONMESSAGE_H
#define COREALARMPHERIPHERALDELETIONMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "security/AlarmPeripheralDeletionMessage.h"
#include "security/AlarmProductType.h"

namespace deltadoreX2d
{

class CoreAlarmPeripheralDeletionMessage : public CoreAlarmMessage, public virtual AlarmPeripheralDeletionMessage
{
	public :
		CoreAlarmPeripheralDeletionMessage();
		CoreAlarmPeripheralDeletionMessage(const std::vector<byte>& frame);
		~CoreAlarmPeripheralDeletionMessage();

        Family getFamily() const;
        void setEnrollmentRequest(bool value);
        void setAnswerRequest(bool value);
		void setTestMode(bool value);

		int getProductId() const;
		void setProductId(int id);
		const AlarmProductType getProductType() const;

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

	private :
		int m_productId;
};
}

#endif // COREALARMPHERIPHERALDELETIONMESSAGE_H
