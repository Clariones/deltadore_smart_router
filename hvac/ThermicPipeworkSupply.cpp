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
** mleforestier        | 052311           | First version
** ylebret             | 280212           | refactoring
*/

#include "hvac/ThermicPipeworkSupply.h"

namespace deltadoreX2d
{

ThermicPipeworkSupply::ThermicPipeworkSupply(int value)
{
	m_value = value;
	if (value == 0) { m_name = "UNKNOWN"; }
	else if (value == 1) { m_name = "HOT_WATER"; }
	else if (value == 2) { m_name = "COLD_WATER"; }
	else if (value == 3) { m_name = "NA"; }
	else { 	throw X2dException("Invalid argument => ThermicPipeworkSupply::ThermicPipeworkSupply(int value)"); }
}

ThermicPipeworkSupply::~ThermicPipeworkSupply()
{
	//
}

const ThermicPipeworkSupply ThermicPipeworkSupply::UNKNOWN = ThermicPipeworkSupply(0);
const ThermicPipeworkSupply ThermicPipeworkSupply::HOT_WATER = ThermicPipeworkSupply(1);
const ThermicPipeworkSupply ThermicPipeworkSupply::COLD_WATER = ThermicPipeworkSupply(2);
const ThermicPipeworkSupply ThermicPipeworkSupply::NA = ThermicPipeworkSupply(3);

ThermicPipeworkSupply ThermicPipeworkSupply::valueOf(int value)
{
	return ThermicPipeworkSupply(value);
}

int ThermicPipeworkSupply::toInt() const
{
	return m_value;
}

const std::string& ThermicPipeworkSupply::toString() const
{
	return m_name;
}

bool ThermicPipeworkSupply::operator==(const ThermicPipeworkSupply &other) const {
	return (m_value == other.toInt());
}

bool ThermicPipeworkSupply::operator!=(const ThermicPipeworkSupply &other) const {
	return !(*this == other);
}
}
