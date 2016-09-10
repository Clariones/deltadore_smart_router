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

#ifndef ALARMTIMEMESSAGE_H
#define ALARMTIMEMESSAGE_H

#include "control/AlarmMessage.h"

namespace deltadoreX2d
{

class AlarmTimeMessage : public virtual AlarmMessage
{
	public :
		virtual ~AlarmTimeMessage(){};

		virtual const Date& getDate() const=0;
		virtual void setDate(const Date& date)=0;
		virtual bool isAccurate() const=0;
		virtual void setAccurate(bool value)=0;
};
}

#endif // ALARMPHERIPHERALDELETIONMESSAGE_H

