/**
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
** mleforestier        | 042611           | First version
** ylebret             | 280212           | refactoring
*/

#include "hvac/ThermicDelayTime.h"

namespace deltadoreX2d
{

ThermicDelayTime::ThermicDelayTime(int value)
{
	m_value = value;
	if (value == 0) { m_name = "STOP"; }
	else if (value == 0xFFFF) { m_name = "INFINITE"; }
	else if (value > 0 && value < 0xFFFF) { m_name = value + "s"; }
	else { throw X2dException("Invalid argument => ThermicDelayTime::ThermicDelayTime(int value)"); }
}

ThermicDelayTime::~ThermicDelayTime()
{
	//
}

const ThermicDelayTime ThermicDelayTime::STOP = ThermicDelayTime(0);
const ThermicDelayTime ThermicDelayTime::INFINITE = ThermicDelayTime(0xFFFF);

ThermicDelayTime ThermicDelayTime::valueOf(int value)
{
	return ThermicDelayTime(value);
}

ThermicDelayTime ThermicDelayTime::fromSeconds(int value)
{
	if (value > 0 && value < 0xFFFF)
	{
		return ThermicDelayTime(value);
	}
	throw X2dException("Invalid argument => ThermicDelayTime::fromSeconds(int value)");
}

int ThermicDelayTime::toInt() const
{
	return m_value;
}

const std::string& ThermicDelayTime::toString() const
{
	return m_name;
}

bool ThermicDelayTime::operator==(const ThermicDelayTime &other) const {
	return (m_value == other.toInt());
}

bool ThermicDelayTime::operator!=(const ThermicDelayTime &other) const {
	return !(*this == other);
}
}
