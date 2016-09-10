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

#ifndef ALARMPHERIPHERALLABELMESSAGE_H
#define ALARMPHERIPHERALLABELMESSAGE_H

#include "control/AlarmMessage.h"
#include "security/AlarmProductType.h"
#include "security/AlarmProductLabel.h"

namespace deltadoreX2d
{

class AlarmPeripheralLabelMessage : public virtual AlarmMessage
{
	public :
		virtual ~AlarmPeripheralLabelMessage(){};

		virtual int getProductId() const=0;
		virtual void setProductId(int id)=0;
		virtual const AlarmProductType getProductType() const=0;
		virtual const AlarmProductLabel& getLabel() const=0;
		virtual void setLabel(const AlarmProductLabel& label)=0;
		virtual int getLabelNumber() const=0;
		virtual void setLabelNumber(int number)=0;
		virtual const std::string& getCustomLabel() const=0;
		virtual void setCustomLabel(const std::string& label)=0;
};
}

#endif // ALARMPHERIPHERALLABELMESSAGE_H

