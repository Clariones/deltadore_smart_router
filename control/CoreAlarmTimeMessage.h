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

#ifndef COREALARMTIMEMESSAGE_H
#define COREALARMTIMEMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "security/AlarmTimeMessage.h"

namespace deltadoreX2d
{

class CoreAlarmTimeMessage : public CoreAlarmMessage, public virtual AlarmTimeMessage
{
	public :
		CoreAlarmTimeMessage();
		CoreAlarmTimeMessage(const std::vector<byte>& frame);
		~CoreAlarmTimeMessage();

        Family getFamily() const;
        void setEnrollmentRequest(bool value);
        void setAnswerRequest(bool value);
		void setTestMode(bool value);
        bool isBatteryFaulty() const;
        void setBatteryFaulty(bool value);

		const Date& getDate() const;
		void setDate(const Date& date);
		bool isAccurate() const;
		void setAccurate(bool value);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

	private :
		Date m_date;
};
}

#endif // COREALARMPHERIPHERALDELETIONMESSAGE_H
