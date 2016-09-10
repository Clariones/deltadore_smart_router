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

#ifndef COREDATATRANSFERMESSAGE_H
#define COREDATATRANSFERMESSAGE_H

#include "control/CoreAlarmMessage.h"
#include "security/DataTransferMessage.h"

namespace deltadoreX2d
{

class CoreDataTransferMessage : public CoreAlarmMessage, public virtual DataTransferMessage
{
	public :
		CoreDataTransferMessage();
		CoreDataTransferMessage(const std::vector<byte>& frame);
		~CoreDataTransferMessage();

        Family getFamily() const;
        void setEnrollmentRequest(bool value);
		void setTestMode(bool value);
        void setDestinationAddress(int address);

		int getDataPacketIndex() const;
		void setDataPacketIndex(int index);
		bool isChecksum() const;
		void setChecksum();
		bool isEndOfTransfer() const;
		void setEndOfTransfer();
		const vector<byte>& getDataPacket() const;
		void setDataPacket(const vector<byte>& data);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

	private :
		int m_index;
		bool m_checksum;
		std::vector<byte> m_data;
};
}

#endif // COREDATATRANSFERMESSAGE_H
