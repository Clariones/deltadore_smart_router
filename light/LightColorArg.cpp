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

#include "light/LightColorArg.h"

namespace deltadoreX2d
{

LightColorArg::LightColorArg(int red, int green, int blue) : m_red(red), m_green(green), m_blue(blue)
{
	//
}

LightColorArg::~LightColorArg()
{
    //
}

int LightColorArg::getRedValue() const
{
    return m_red;
}

int LightColorArg::getGreenValue() const
{
    return m_green;
}

int LightColorArg::getBlueValue() const
{
    return m_blue;
}

bool LightColorArg::instanceOf(ArgClass type) const
{
	if (type == LightColorArg_t) { return true; }
	return false;
}

NodeArg* LightColorArg::clone() const
{
	return new LightColorArg(*this);
}

void* LightColorArg::derived()
{
	return this;
}
}
