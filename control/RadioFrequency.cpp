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

#include "control/RadioFrequency.h"

namespace deltadoreX2d
{

RadioFrequency::RadioFrequency(int value)
{
	m_value = value;
	if (value == 0) { m_name = "AM"; }
	else if (value == 1) { m_name = "FM"; }
	else { throw X2dException("Invalid argument => RadioFrequency::RadioFrequency(int value)"); }
}

RadioFrequency::~RadioFrequency()
{
    //
}

const RadioFrequency RadioFrequency::AM = RadioFrequency(0);
const RadioFrequency RadioFrequency::FM = RadioFrequency(1);

RadioFrequency RadioFrequency::valueOf(int value)
{
    return RadioFrequency(value);
}

int RadioFrequency::toInt() const
{
    return m_value;
}

const std::string& RadioFrequency::toString() const
{
	return m_name;
}

bool RadioFrequency::operator==(const RadioFrequency &other) const {
	return (m_value == other.toInt());
}

bool RadioFrequency::operator!=(const RadioFrequency &other) const {
	return !(*this == other);
}
}
