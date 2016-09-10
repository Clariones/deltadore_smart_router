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
** mleforestier        | 041211           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef ALARMMESSAGE_H
#define ALARMMESSAGE_H

#include "control/MessagePriority.h"

namespace deltadoreX2d
{

class AlarmMessage : public virtual Message
{
	public :
		virtual ~AlarmMessage(){};

		virtual bool isTestMode() const=0;
		virtual void setTestMode(bool value)=0;
		virtual int getDestinationAddress() const=0;
		virtual void setDestinationAddress(int address)=0;
};
}

#endif // ALARMMESSAGE_H
