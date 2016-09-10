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

#ifndef TELEPHONETRANSMITTERSTATUS_H
#define TELEPHONETRANSMITTERSTATUS_H

#include "requirement.h"

namespace deltadoreX2d
{

class TelephoneTransmitterStatus
{
    public :
        TelephoneTransmitterStatus(int value);
        ~TelephoneTransmitterStatus();

        static const TelephoneTransmitterStatus IDLE ;
        static const TelephoneTransmitterStatus RINGING ;
        static const TelephoneTransmitterStatus CURRENT_INCOMING_VOICE_CALL;
        static const TelephoneTransmitterStatus CURRENT_INCOMING_DIGITAL_CALL ;
        static const TelephoneTransmitterStatus DIALING;
        static const TelephoneTransmitterStatus CURRENT_OUTGOING_VOICE_CALL1;
        static const TelephoneTransmitterStatus CURRENT_OUTGOING_VOICE_CALL2;
        static const TelephoneTransmitterStatus CURRENT_OUTGOING_VOICE_CALL3;
        static const TelephoneTransmitterStatus CURRENT_OUTGOING_VOICE_CALL4;
        static const TelephoneTransmitterStatus CURRENT_OUTGOING_DIGITAL_CALL ;
        static const TelephoneTransmitterStatus NO_DIAL_TONE ;
        static const TelephoneTransmitterStatus BUSY ;
        static const TelephoneTransmitterStatus CALL_CYCLE_FAILURE;
        static const TelephoneTransmitterStatus WRONG_ACCESS_CODE ;
        static const TelephoneTransmitterStatus CHANGING_SETTINGS ;
        static TelephoneTransmitterStatus valueOf(int value);

        int toInt() const;
		const std::string& toString() const;

		bool operator==(const TelephoneTransmitterStatus &other) const;
		bool operator!=(const TelephoneTransmitterStatus &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* TELEPHONETRANSMITTERSTATUS_H */
