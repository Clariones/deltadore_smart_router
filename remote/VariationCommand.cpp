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

#include "remote/VariationCommand.h"

namespace deltadoreX2d
{

VariationCommand::VariationCommand(int value)
{
	m_value = value;
	if (value == 1) { m_name = "MORE"; }
	else if (value == 129) { m_name = "SHORT_RELEASED_MORE"; }
	else if (value == 65) { m_name = "LONG_RELEASED_MORE"; }
	else if (value == 2) { m_name = "LESS"; }
	else if (value == 130) { m_name = "SHORT_RELEASED_LESS"; }
	else if (value == 66) { m_name = "LONG_RELEASED_LESS"; }
	else if (value == 4) { m_name = "STOP"; }
	else { throw X2dException("Invalid argument => VariationCommand::VariationCommand(int value)"); }
}

VariationCommand::~VariationCommand()
{
    //
}

const VariationCommand VariationCommand::MORE = VariationCommand(1);
const VariationCommand VariationCommand::SHORT_RELEASED_MORE = VariationCommand(129);
const VariationCommand VariationCommand::LONG_RELEASED_MORE = VariationCommand(65);
const VariationCommand VariationCommand::LESS = VariationCommand(2);
const VariationCommand VariationCommand::SHORT_RELEASED_LESS = VariationCommand(130);
const VariationCommand VariationCommand::LONG_RELEASED_LESS = VariationCommand(66);
const VariationCommand VariationCommand::STOP = VariationCommand(4);

VariationCommand VariationCommand::valueOf(int value)
{
    return VariationCommand(value);
}

int VariationCommand::toInt() const
{
    return m_value;
}

const std::string& VariationCommand::toString() const
{
	return m_name;
}

bool VariationCommand::operator==(const VariationCommand &other) const {
	return (m_value == other.toInt());
}

bool VariationCommand::operator!=(const VariationCommand &other) const {
	return !(*this == other);
}
}
