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

#include "control/Node.h"

namespace deltadoreX2d
{

Node::Node(int value)
{
	m_value = value;
	if (value == 0) { m_name = "NODE0"; }
	else if (value == 1) { m_name = "NODE1"; }
	else if (value == 2) { m_name = "NODE2"; }
	else if (value == 3) { m_name = "NODE3"; }
	else if (value == 4) { m_name = "NODE4"; }
	else if (value == 5) { m_name = "NODE5"; }
	else if (value == 6) { m_name = "NODE6"; }
	else if (value == 7) { m_name = "NODE7"; }
	else if (value == 8) { m_name = "NODE8"; }
	else if (value == 9) { m_name = "NODE9"; }
	else if (value == 10) { m_name = "NODE10"; }
	else if (value == 11) { m_name = "NODE11"; }
	else if (value == 12) { m_name = "NODE12"; }
	else if (value == 13) { m_name = "NODE13"; }
	else if (value == 14) { m_name = "NODE14"; }
	else if (value == 15) { m_name = "NODE15"; }
	else { throw X2dException("Invalid argument => Node::Node(int value)"); }
}

Node::~Node()
{
    //
}

const Node Node::NODE0 = Node(0);
const Node Node::NODE1 = Node(1);
const Node Node::NODE2 = Node(2);
const Node Node::NODE3 = Node(3);
const Node Node::NODE4 = Node(4);
const Node Node::NODE5 = Node(5);
const Node Node::NODE6 = Node(6);
const Node Node::NODE7 = Node(7);
const Node Node::NODE8 = Node(8);
const Node Node::NODE9 = Node(9);
const Node Node::NODE10 = Node(10);
const Node Node::NODE11 = Node(11);
const Node Node::NODE12 = Node(12);
const Node Node::NODE13 = Node(13);
const Node Node::NODE14 = Node(14);
const Node Node::NODE15 = Node(15);

Node Node::valueOf(int value)
{
    return Node(value);
}

int Node::toInt() const
{
    return m_value;
}

const std::string& Node::toString() const
{
	return m_name;
}

bool Node::operator==(const Node &other) const {
	return (m_value == other.toInt());
}

bool Node::operator!=(const Node &other) const {
	return !(*this == other);
}
}
