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
** ylebret             | 280212           | refactoring
*/

#include "metering/CompositeRegisterSelection.h"

namespace deltadoreX2d
{

CompositeRegisterSelection::CompositeRegisterSelection(int value)
{
	m_value = value;
	if (value == 6) { m_name = "HEATING__HOT_WATER__TOTAL"; }
	else if (value == 10) { m_name = "CURRENT_TRANSFORMERS_1_2_3"; }
	else { throw X2dException("Invalid argument => CompositeRegisterSelection::CompositeRegisterSelection(int value)"); }
}

CompositeRegisterSelection::~CompositeRegisterSelection()
{
    //
}

const CompositeRegisterSelection CompositeRegisterSelection::HEATING__HOT_WATER__TOTAL = CompositeRegisterSelection(6);
const CompositeRegisterSelection CompositeRegisterSelection::CURRENT_TRANSFORMERS_1_2_3 = CompositeRegisterSelection(10);

CompositeRegisterSelection CompositeRegisterSelection::valueOf(int value)
{
    return CompositeRegisterSelection(value);
}

int CompositeRegisterSelection::toInt() const
{
    return m_value;
}

const std::string& CompositeRegisterSelection::toString() const
{
	return m_name;
}

bool CompositeRegisterSelection::operator==(const CompositeRegisterSelection &other) const {
	return (m_value == other.toInt());
}

bool CompositeRegisterSelection::operator!=(const CompositeRegisterSelection &other) const {
	return !(*this == other);
}
}
