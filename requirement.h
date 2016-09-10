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

#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
//#include <iostream>
//#include <assert.h>

using namespace std;

namespace deltadoreX2d
{

typedef unsigned char byte;

typedef enum
{
    SECURITY = 0x00,
  	COMMON,
    REMOTE,
    METERING,
    SENSOR,
    ENROLLEMENT,
    HVAC,
    LIGHT,
    ROLLERSHUTTER,
    DIAGNOSTIC,
    OTHER
} Family;

class X2dException : public exception
{
	public:
		X2dException();
		X2dException(const std::string& description);
		~X2dException() throw();

		const char* what() const throw();

	private:
		std::string m_description;
};

// pthread version
// may be adapted to another library
class RecursiveLock
{
	public:
		RecursiveLock();
		~RecursiveLock();

		void lock();
		void unlock();

	private:
        pthread_mutex_t m_lock;
};

// pthread version
// may be adapted to another library
class Runnable
{
	public:
		Runnable();
		~Runnable();

		void start();
		void join();
		void sleep(); // may be used to lower cpu consumption if needed

		virtual void run()=0;

	private:
		static void* start_routine(void* arg);

        pthread_t m_thread;
};

class InputStream
{
    public :
        virtual ~InputStream(){};

        virtual void close()= 0; // may be used to prevent blocking behavior when stopping
		virtual int read(void* buffer, int size) = 0;
};

class OutputStream
{
    public :
        virtual ~OutputStream(){};

        virtual void close()=0; // may be used to prevent blocking behavior when stopping
		virtual int write(void* buffer, int size) = 0;
};

// C time version
// may be adapted to another library
class Date
{
    public :
		Date();
        Date(time_t date);
		~Date();

		time_t getValue() const;
		int getElapsedSecondsSince(Date date);

    private :
		time_t m_date;
};

// C time version
// may be adapted to another library
class Calendar
{
    public :
        Calendar();
		~Calendar();

        static const int YEAR;
        static const int MONTH;
        static const int DAY_OF_MONTH;
        static const int HOUR_OF_DAY;
        static const int MINUTE;
        static const int SECOND;
        static const int MILLISECOND;

        int get(int type) const;
        void set(int type, int value);
        Date getTime();
        void setTime(const Date& time);

    private :
		struct tm m_calendar;
};
}

#endif // REQUIREMENT_H
