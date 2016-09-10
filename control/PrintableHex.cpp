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

#include "control/PrintableHex.h"

namespace deltadoreX2d
{

std::vector<byte> PrintableHex::getBytes(const std::string& s)
{
	std::vector<byte> result = std::vector<byte>();

	const char* ptr = s.c_str();
	for (unsigned int i = 0; i <= s.length()/3; i++)
	{
		byte buffer;
		sscanf(ptr, "%2hhx", &buffer);
		result.push_back(buffer);
		ptr += 3;
	}
    return result;
}

std::string PrintableHex::getString(const std::vector<byte>& byteArray)
{
    std::string result = std::string();

	for(unsigned int i = 0; i < byteArray.size(); i++)
    {
		if (i != 0) { result.append(" "); }
        char buffer[3];
        sprintf(buffer, "%02X ", byteArray[i]);
        result.append(buffer);
    }
    return result;
}
}
