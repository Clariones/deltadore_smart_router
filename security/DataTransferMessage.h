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

#ifndef DATATRANSFERMESSAGE_H
#define DATATRANSFERMESSAGE_H

#include "control/AlarmMessage.h"

namespace deltadoreX2d
{

class DataTransferMessage : public virtual AlarmMessage
{
	public :
		virtual ~DataTransferMessage(){};

		virtual int getDataPacketIndex() const=0;
		virtual void setDataPacketIndex(int index)=0;
		virtual bool isChecksum() const=0;
		virtual void setChecksum()=0;
		virtual bool isEndOfTransfer() const=0;
		virtual void setEndOfTransfer()=0;
		virtual const vector<byte>& getDataPacket() const=0;
		virtual void setDataPacket(const vector<byte>& data)=0;
};
}

#endif // DATATRANSFERMESSAGE_H

