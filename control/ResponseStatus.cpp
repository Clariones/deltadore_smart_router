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

#include "control/ResponseStatus.h"

namespace deltadoreX2d
{

ResponseStatus::ResponseStatus(int value)
{
	m_value = value;
	if (value == 0) { m_name = "OK"; }
	else if (value == 1) { m_name = "UNEXISTING_NODE"; }
	else if (value == 2) { m_name = "UNREACHABLE_NODE"; }
	else if (value == 3) { m_name = "NOT_CAPABLE_NODE"; }
	else { throw X2dException("Invalid argument => ResponseStatus::ResponseStatus(int value)"); }
}

ResponseStatus::~ResponseStatus()
{
    //
}

const ResponseStatus ResponseStatus::OK = ResponseStatus(0);
const ResponseStatus ResponseStatus::UNEXISTING_NODE = ResponseStatus(1);
const ResponseStatus ResponseStatus::UNREACHABLE_NODE = ResponseStatus(2);
const ResponseStatus ResponseStatus::NOT_CAPABLE_NODE = ResponseStatus(3);

ResponseStatus ResponseStatus::valueOf(int value)
{
    return ResponseStatus(value);
}

int ResponseStatus::toInt() const
{
    return m_value;
}

const std::string& ResponseStatus::toString() const
{
	return m_name;
}

bool ResponseStatus::operator==(const ResponseStatus &other) const {
	return (m_value == other.toInt());
}

bool ResponseStatus::operator!=(const ResponseStatus &other) const {
	return !(*this == other);
}
}
