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

#include "requirement.h"

namespace deltadoreX2d
{

// ################ X2dException ##############

X2dException::X2dException() : m_description("Exception in X2D Library")
{
	//
}

X2dException::X2dException(const std::string& description) : m_description(description)
{
	//
}

X2dException::~X2dException() throw()
{
	//
}

const char* X2dException::what() const throw()
{
	return m_description.c_str();
}

// ################ RecursiveLock ##############

RecursiveLock::RecursiveLock()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&m_lock, &attr);
	pthread_mutexattr_destroy(&attr);
}

RecursiveLock::~RecursiveLock()
{
	//
}

void RecursiveLock::lock()
{
    pthread_mutex_lock(&m_lock);
}

void RecursiveLock::unlock()
{
    pthread_mutex_unlock(&m_lock);
}

// ################ Runnable ##############

Runnable::Runnable()
{
	//
}

Runnable::~Runnable()
{
	//
}

void Runnable::start()
{
	pthread_create(&m_thread, NULL, start_routine, this);
}

void Runnable::join()
{
	pthread_join(m_thread, NULL);
}

void Runnable::sleep()
{
	//usleep(20000);
}

void* Runnable::start_routine(void* arg)
{
	((Runnable*)arg)->run();
	return NULL;
}

// ################ Date ##############

Date::Date() : m_date(time(NULL))
{
	//
}

Date::Date(time_t date) : m_date(date)
{
	//
}

Date::~Date()
{
	//
}

time_t Date::getValue() const
{
	return m_date;
}

int Date::getElapsedSecondsSince(Date date)
{
	return (int)(m_date - date.m_date);
}

// ################ Calendar ##############

Calendar::Calendar()
{
	memset(&m_calendar, 0, sizeof(tm));
}

Calendar::~Calendar()
{
	//
}

const int Calendar::YEAR=0;
const int Calendar::MONTH=1;
const int Calendar::DAY_OF_MONTH=2;
const int Calendar::HOUR_OF_DAY=3;
const int Calendar::MINUTE=4;
const int Calendar::SECOND=5;
const int Calendar::MILLISECOND=6;

int Calendar::get(int type) const
{
	switch(type)
	{
	case Calendar::YEAR:
		return m_calendar.tm_year + 1900;
	case Calendar::MONTH:
		return m_calendar.tm_mon;
	case Calendar::DAY_OF_MONTH:
		return m_calendar.tm_mday;
	case Calendar::HOUR_OF_DAY:
		return m_calendar.tm_hour;
	case Calendar::MINUTE:
		return m_calendar.tm_min;
	case Calendar::SECOND:
		return m_calendar.tm_sec;
	case Calendar::MILLISECOND:
		return 0;
	}
    return 0;
}

void Calendar::set(int type, int value)
{
	switch(type)
	{
	case Calendar::YEAR:
		m_calendar.tm_year = value - 1900;
	case Calendar::MONTH:
		m_calendar.tm_mon = value;
	case Calendar::DAY_OF_MONTH:
		m_calendar.tm_mday = value;
	case Calendar::HOUR_OF_DAY:
		m_calendar.tm_hour = value;
	case Calendar::MINUTE:
		m_calendar.tm_min = value;
	case Calendar::SECOND:
		m_calendar.tm_sec = value;
	//case Calendar::MILLISECOND:
	}
}

Date Calendar::getTime()
{
    return Date(mktime(&m_calendar));
}

void Calendar::setTime(const Date& time)
{
	time_t date = time.getValue();
	localtime_r(&date, &m_calendar);
}
}
