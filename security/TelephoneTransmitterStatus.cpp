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

#include "security/TelephoneTransmitterStatus.h"

namespace deltadoreX2d
{

TelephoneTransmitterStatus::TelephoneTransmitterStatus(int value)
{
	m_value = value;
	if (value == 0) { m_name = "IDLE"; }
	else if (value == 1) { m_name = "RINGING"; }
	else if (value == 2) { m_name = "CURRENT_INCOMING_VOICE_CALL"; }
	else if (value == 3) { m_name = "CURRENT_INCOMING_DIGITAL_CALL"; }
	else if (value == 4) { m_name = "DIALING"; }
	else if (value == 5) { m_name = "CURRENT_OUTGOING_VOICE_CALL1"; }
	else if (value == 6) { m_name = "CURRENT_OUTGOING_VOICE_CALL2"; }
	else if (value == 7) { m_name = "CURRENT_OUTGOING_VOICE_CALL3"; }
	else if (value == 8) { m_name = "CURRENT_OUTGOING_VOICE_CALL4"; }
	else if (value == 9) { m_name = "CURRENT_OUTGOING_DIGITAL_CALL"; }
	else if (value == 10) { m_name = "NO_DIAL_TONE"; }
	else if (value == 11) { m_name = "BUSY"; }
	else if (value == 12) { m_name = "CALL_CYCLE_FAILURE"; }
	else if (value == 13) { m_name = "WRONG_ACCESS_CODE"; }
	else if (value == 14) { m_name = "CHANGING_SETTINGS"; }
	else { throw X2dException("Invalid argument => TelephoneTransmitterStatus::TelephoneTransmitterStatus(int value)"); }
}

TelephoneTransmitterStatus::~TelephoneTransmitterStatus()
{
    //
}

const TelephoneTransmitterStatus TelephoneTransmitterStatus::IDLE = TelephoneTransmitterStatus(0);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::RINGING = TelephoneTransmitterStatus(1);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CURRENT_INCOMING_VOICE_CALL = TelephoneTransmitterStatus(2);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CURRENT_INCOMING_DIGITAL_CALL = TelephoneTransmitterStatus(3);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::DIALING = TelephoneTransmitterStatus(4);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CURRENT_OUTGOING_VOICE_CALL1 = TelephoneTransmitterStatus(5);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CURRENT_OUTGOING_VOICE_CALL2 = TelephoneTransmitterStatus(6);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CURRENT_OUTGOING_VOICE_CALL3 = TelephoneTransmitterStatus(7);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CURRENT_OUTGOING_VOICE_CALL4 = TelephoneTransmitterStatus(8);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CURRENT_OUTGOING_DIGITAL_CALL = TelephoneTransmitterStatus(9);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::NO_DIAL_TONE = TelephoneTransmitterStatus(10);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::BUSY = TelephoneTransmitterStatus(11);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CALL_CYCLE_FAILURE = TelephoneTransmitterStatus(12);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::WRONG_ACCESS_CODE = TelephoneTransmitterStatus(13);
const TelephoneTransmitterStatus TelephoneTransmitterStatus::CHANGING_SETTINGS = TelephoneTransmitterStatus(14);

TelephoneTransmitterStatus TelephoneTransmitterStatus::valueOf(int value)
{
    return TelephoneTransmitterStatus(value);
}

int TelephoneTransmitterStatus::toInt() const
{
    return m_value;
}

const std::string& TelephoneTransmitterStatus::toString() const
{
	return m_name;
}

bool TelephoneTransmitterStatus::operator==(const TelephoneTransmitterStatus &other) const {
	return (m_value == other.toInt());
}

bool TelephoneTransmitterStatus::operator!=(const TelephoneTransmitterStatus &other) const {
	return !(*this == other);
}
}
