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

#include "control/Checksum.h"

namespace deltadoreX2d
{

short Checksum::calculate(const std::vector<byte>& byteArray, int index, int length)
{
    int cs = 0;
    for (int i = 0; i < index + length; i++)
    {
        cs += byteArray[i] & 0xFF;
    }
    cs = (~cs) + 1;
    return (short)cs;
}

short Checksum::calculate(const std::vector<byte>& byteArray)
{
	return calculate(byteArray, 0, byteArray.size());
}

void Checksum::add(std::vector<byte>& byteArray)
{
    short cs = calculate(byteArray);
	byteArray.push_back((byte)(cs >> 8));
	byteArray.push_back((byte)(cs & 0xFF));
}

bool Checksum::check(const std::vector<byte>& byteArray)
{
	short cs = (short)((byteArray[byteArray.size() - 2] << 8) + (byteArray[byteArray.size() -1] & 0xFF));
	if (cs == calculate(byteArray, 0, byteArray.size() - 2))
    {
        return true;
    }
    return false;
}
}
