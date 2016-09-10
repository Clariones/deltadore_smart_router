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

#ifndef NODE_H
#define NODE_H

#include "requirement.h"

namespace deltadoreX2d
{

class Node
{
    public :
        Node(int value);
        ~Node();

        static const Node NODE0;
        static const Node NODE1;
        static const Node NODE2;
        static const Node NODE3;
        static const Node NODE4;
        static const Node NODE5;
        static const Node NODE6;
        static const Node NODE7;
        static const Node NODE8;
        static const Node NODE9;
        static const Node NODE10;
        static const Node NODE11 ;
        static const Node NODE12;
        static const Node NODE13 ;
        static const Node NODE14 ;
        static const Node NODE15;
        static Node valueOf(int value);

        int toInt() const;
		const std::string& toString() const;

		bool operator==(const Node &other) const;
		bool operator!=(const Node &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* NODE_H */
