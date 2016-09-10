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

#include "control/Statistic.h"

namespace deltadoreX2d
{

Statistic::Statistic()
{
	//
}

int Statistic::getReceivedCount() const
{
    return m_receivedCount;
}

int Statistic::getSentCount() const
{
    return m_sentCount;
}

int Statistic::getErrorCount() const
{
    return m_errorCount;
}

int Statistic::getTimeoutCount() const
{
    return m_timeoutCount;
}

void Statistic::incrementReceivedCount()
{
	m_lock.lock();
    m_receivedCount++;
	m_lock.unlock();
}

void Statistic::incrementSentCount()
{
	m_lock.lock();
    m_sentCount++;
	m_lock.unlock();
}

void Statistic::incrementErrorCount()
{
	m_lock.lock();
    m_errorCount++;
	m_lock.unlock();
}

void Statistic::incrementTimeoutCount()
{
	m_lock.lock();
    m_timeoutCount++;
	m_lock.unlock();
}

void Statistic::clear()
{
	m_lock.lock();
    m_receivedCount = 0;
    m_sentCount = 0;
    m_errorCount = 0;
    m_timeoutCount = 0;
	m_lock.unlock();
}
}
