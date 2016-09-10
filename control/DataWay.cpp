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

#include "control/DataWay.h"

namespace deltadoreX2d
{

DataWay::DataWay(int value)
{
	m_value = value;
	if (value == 0) { m_name = "UPLOAD"; }
	else if (value == 1) { m_name = "DOWNLOAD"; }
	else { throw X2dException("Invalid argument => DataWay::DataWay(int value)"); }
}

DataWay::~DataWay()
{
     //
}

const DataWay DataWay::UPLOAD = DataWay(0);
const DataWay DataWay::DOWNLOAD = DataWay(1);

DataWay DataWay::valueOf(int value)
{
    return DataWay(value);
}

int DataWay::toInt() const
{
    return m_value;
}

const std::string& DataWay::toString() const
{
	return m_name;
}

bool DataWay::operator==(const DataWay &other) const {
	return (m_value == other.toInt());
}

bool DataWay::operator!=(const DataWay &other) const {
	return !(*this == other);
}
}
