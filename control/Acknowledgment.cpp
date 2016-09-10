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

#include "control/Acknowledgment.h"

namespace deltadoreX2d
{

Acknowledgment::Acknowledgment(int value)
{
	m_value = value;
	if (value == 0) { m_name = "ACK"; }
	else if (value == 1) { m_name = "NACK"; }
	else if (value == 2) { m_name = "PRE_ACK"; }
	else { throw X2dException("Invalid argument => Acknowledgment::Acknowledgment(int value)"); }
}

Acknowledgment::~Acknowledgment()
{
    //
}

const Acknowledgment Acknowledgment::ACK = Acknowledgment(0);
const Acknowledgment Acknowledgment::NACK = Acknowledgment(1);
const Acknowledgment Acknowledgment::PRE_ACK = Acknowledgment(2);

Acknowledgment Acknowledgment::valueOf(int value)
{
    return Acknowledgment(value);
}

int Acknowledgment::toInt() const
{
    return m_value;
}

const std::string& Acknowledgment::toString() const
{
    return m_name;
}

bool Acknowledgment::operator==(const Acknowledgment &other) const {
	return (m_value == other.toInt());
}

bool Acknowledgment::operator!=(const Acknowledgment &other) const {
	return !(*this == other);
}
}
