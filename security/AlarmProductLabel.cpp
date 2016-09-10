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

#include "security/AlarmProductLabel.h"

namespace deltadoreX2d
{

AlarmProductLabel::AlarmProductLabel(int value)
{
	m_value = value;
	if (value == 0) { m_name = "OTHER"; }
	else if (value == 1) { m_name = "WORKSHOP"; }
	else if (value == 2) { m_name = "BATHROOM"; }
	else if (value == 3) { m_name = "OFFICE"; }
	else if (value == 4) { m_name = "TOILET"; }
	else if (value == 5) { m_name = "BASEMENT"; }
	else if (value == 6) { m_name = "CELLAR"; }
	else if (value == 7) { m_name = "BEDROOM"; }
	else if (value == 8) { m_name = "HALLWAY"; }
	else if (value == 9) { m_name = "KITCHEN"; }
	else if (value == 10) { m_name = "STAIRWAY"; }
	else if (value == 11) { m_name = "GARAGE"; }
	else if (value == 12) { m_name = "ATTIC"; }
	else if (value == 13) { m_name = "HALL"; }
	else if (value == 14) { m_name = "SHOP"; }
	else if (value == 15) { m_name = "RECEPTION"; }
	else if (value == 16) { m_name = "STORAGE_ROOM"; }
	else if (value == 17) { m_name = "WAITING_ROOM"; }
	else if (value == 18) { m_name = "LOUNGE"; }
	else if (value == 19) { m_name = "DINING_ROOM"; }
	else if (value == 20) { m_name = "SHOPWINDOW"; }
	else if (value == 21) { m_name = "AREA"; }
	else if (value == 22) { m_name = "ENTRY"; }
	else if (value == 23) { m_name = "SECRETARIAT"; }
	else if (value == 24) { m_name = "ROOM"; }
	else if (value == 25) { m_name = "LOBBY"; }
	else if (value == 26) { m_name = "COMPANY"; }
	else if (value == 27) { m_name = "CLEARANCE"; }
	else if (value == 28) { m_name = "LANDING"; }
	else { throw X2dException("Invalid argument => AlarmProductLabel::AlarmProductLabel(int value)"); }
}

AlarmProductLabel::~AlarmProductLabel()
{
    //
}

const AlarmProductLabel AlarmProductLabel::OTHER = AlarmProductLabel(0);
const AlarmProductLabel AlarmProductLabel::WORKSHOP = AlarmProductLabel(1);
const AlarmProductLabel AlarmProductLabel::BATHROOM = AlarmProductLabel(2);
const AlarmProductLabel AlarmProductLabel::OFFICE = AlarmProductLabel(3);
const AlarmProductLabel AlarmProductLabel::TOILET = AlarmProductLabel(4);
const AlarmProductLabel AlarmProductLabel::BASEMENT = AlarmProductLabel(5);
const AlarmProductLabel AlarmProductLabel::CELLAR = AlarmProductLabel(6);
const AlarmProductLabel AlarmProductLabel::BEDROOM = AlarmProductLabel(7);
const AlarmProductLabel AlarmProductLabel::HALLWAY = AlarmProductLabel(8);
const AlarmProductLabel AlarmProductLabel::KITCHEN = AlarmProductLabel(9);
const AlarmProductLabel AlarmProductLabel::STAIRWAY = AlarmProductLabel(10);
const AlarmProductLabel AlarmProductLabel::GARAGE = AlarmProductLabel(11);
const AlarmProductLabel AlarmProductLabel::ATTIC = AlarmProductLabel(12);
const AlarmProductLabel AlarmProductLabel::HALL = AlarmProductLabel(13);
const AlarmProductLabel AlarmProductLabel::SHOP = AlarmProductLabel(14);
const AlarmProductLabel AlarmProductLabel::RECEPTION = AlarmProductLabel(15);
const AlarmProductLabel AlarmProductLabel::STORAGE_ROOM = AlarmProductLabel(16);
const AlarmProductLabel AlarmProductLabel::WAITING_ROOM = AlarmProductLabel(17);
const AlarmProductLabel AlarmProductLabel::LOUNGE = AlarmProductLabel(18);
const AlarmProductLabel AlarmProductLabel::DINING_ROOM = AlarmProductLabel(19);
const AlarmProductLabel AlarmProductLabel::SHOPWINDOW = AlarmProductLabel(20);
const AlarmProductLabel AlarmProductLabel::AREA = AlarmProductLabel(21);
const AlarmProductLabel AlarmProductLabel::ENTRY =AlarmProductLabel(22);
const AlarmProductLabel AlarmProductLabel::SECRETARIAT = AlarmProductLabel(23);
const AlarmProductLabel AlarmProductLabel::ROOM = AlarmProductLabel(24);
const AlarmProductLabel AlarmProductLabel::LOBBY = AlarmProductLabel(25);
const AlarmProductLabel AlarmProductLabel::COMPANY = AlarmProductLabel(26);
const AlarmProductLabel AlarmProductLabel::CLEARANCE = AlarmProductLabel(27);
const AlarmProductLabel AlarmProductLabel::LANDING = AlarmProductLabel(28);

AlarmProductLabel AlarmProductLabel::valueOf(int value)
{
    return AlarmProductLabel(value);
}

int AlarmProductLabel::toInt() const
{
    return m_value;
}

const std::string& AlarmProductLabel::toString() const
{
	return m_name;
}

bool AlarmProductLabel::operator==(const AlarmProductLabel &other) const {
	return (m_value == other.toInt());
}

bool AlarmProductLabel::operator!=(const AlarmProductLabel &other) const {
	return !(*this == other);
}
}
