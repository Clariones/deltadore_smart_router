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
** ylebret             | 280212           | First version
*/

#ifndef MESSAGEPRIORITY_H
#define MESSAGEPRIORITY_H

#include "requirement.h"

namespace deltadoreX2d
{

class MessagePriority
{
    public :
        MessagePriority(int value);
        MessagePriority(int value1, int value2);
        ~MessagePriority();

        static const MessagePriority NORMAL;
        static const MessagePriority IMPORTANT;
        static const MessagePriority PRIORITIZED;
        static const MessagePriority EXCLUSIVE;
        static MessagePriority valueOf(int value);
        static MessagePriority valueOf(int value1, int value2);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const MessagePriority &other) const;
		bool operator!=(const MessagePriority &other) const;

	private :
        std::string m_name;
        int m_value;
};
}

#endif /* MESSAGEPRIORITY_H */
