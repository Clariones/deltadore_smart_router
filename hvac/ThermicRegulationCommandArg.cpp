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

#include "hvac/ThermicRegulationCommandArg.h"

namespace deltadoreX2d
{

ThermicRegulationCommandArg::ThermicRegulationCommandArg(const ThermicHeatLevel& level,
														const ThermicRegulationMode& mode,
														bool isLevelTemporary) :
														m_level(level),
														m_mode(mode),
														m_isLevelTemporary(isLevelTemporary)
{
	//
}

ThermicRegulationCommandArg::~ThermicRegulationCommandArg()
{
	//
}

const ThermicHeatLevel& ThermicRegulationCommandArg::getLevel() const
{
	return m_level;
}

const ThermicRegulationMode& ThermicRegulationCommandArg::getMode() const
{
	return m_mode;
}

bool ThermicRegulationCommandArg::isLevelTemporary() const
{
	return m_isLevelTemporary;
}

bool ThermicRegulationCommandArg::instanceOf(ArgClass type) const
{
	if (type == ThermicRegulationCommandArg_t) { return true; }
	return false;
}

NodeArg* ThermicRegulationCommandArg::clone() const
{
	return new ThermicRegulationCommandArg(*this);
}

void* ThermicRegulationCommandArg::derived()
{
	return this;
}
}
