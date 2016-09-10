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

#ifndef COREALARMPHERIPHERALLABELMESSAGE_H
#define COREALARMPHERIPHERALLABELMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "security/AlarmPeripheralLabelMessage.h"

namespace deltadoreX2d
{

class CoreAlarmPeripheralLabelMessage : public CoreAlarmMessage, public virtual AlarmPeripheralLabelMessage
{
	public :
		CoreAlarmPeripheralLabelMessage();
		CoreAlarmPeripheralLabelMessage(const std::vector<byte>& frame);
		~CoreAlarmPeripheralLabelMessage();

        Family getFamily() const;
        void setEnrollmentRequest(bool value);
        void setAnswerRequest(bool value);
		void setTestMode(bool value);

		int getProductId() const;
		void setProductId(int id);
		const AlarmProductType getProductType() const;
		const AlarmProductLabel& getLabel() const;
		void setLabel(const AlarmProductLabel& label);
		int getLabelNumber() const;
		void setLabelNumber(int number);
		const std::string& getCustomLabel() const;
		void setCustomLabel(const std::string& label);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

	private :
		int m_productId;
		AlarmProductLabel m_label;
		int m_labelNumber;
		std::string m_customLabel;
};
}

#endif // COREALARMPHERIPHERALLABELMESSAGE_H
