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
** mleforestier        | 052511           | First version
** ylebret             | 280212           | refactoring
*/

#include "hvac/ThermicSystemCommandArg.h"

namespace deltadoreX2d
{

ThermicSystemCommandArg::ThermicSystemCommandArg(const ThermicSystemMode& systemMode,
												const ThermicFanMode& fanMode,
												const ThermicReheatingMode& reheatingMode,
												bool isDehumidifying,
												bool isFreeCooling) :
												m_systemMode(systemMode),
												m_fanMode(fanMode),
												m_reheatingMode(reheatingMode),
												m_isDehumidifying(isDehumidifying),
												m_isFreeCooling(isFreeCooling)
{
	//
}

ThermicSystemCommandArg::~ThermicSystemCommandArg()
{
	//
}

const ThermicSystemMode& ThermicSystemCommandArg::getSystemMode() const
{
	return m_systemMode;
}

const ThermicFanMode& ThermicSystemCommandArg::getFanMode() const
{
	return m_fanMode;
}

const ThermicReheatingMode& ThermicSystemCommandArg::getReheatingMode() const
{
	return m_reheatingMode;
}

bool ThermicSystemCommandArg::isDehumidifying() const
{
	return m_isDehumidifying;
}

bool ThermicSystemCommandArg::isFreeCooling() const
{
	return m_isFreeCooling;
}

bool ThermicSystemCommandArg::instanceOf(ArgClass type) const
{
	if (type == ThermicSystemCommandArg_t) { return true; }
	return false;
}

NodeArg* ThermicSystemCommandArg::clone() const
{
	return new ThermicSystemCommandArg(*this);
}

void* ThermicSystemCommandArg::derived()
{
	return this;
}
}
