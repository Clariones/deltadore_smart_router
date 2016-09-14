/*
 * SerialPort.h
 *
 *  Created on: Sep 6, 2016
 *      Author: clariones
 */

#ifndef SERIALPORT_H_
#define SERIALPORT_H_


#include     <stdio.h>
#include     <stdlib.h>
#include     <unistd.h>
#include     <sys/types.h>
#include     <sys/stat.h>
#include     "string.h"
#include     <fcntl.h>
#include     <termios.h>
#include     <errno.h>
#include    "requirement.h"

using namespace deltadoreX2d;

class SerialPort :public InputStream, public OutputStream{
public:
	SerialPort();
	virtual ~SerialPort();

public:
	void init(const char * devName);
	virtual int read(void* buffer, int size);
	virtual int write(void* buffer, int size);
	virtual void close();
	bool initSuccess() { return devID > 0;}
protected:
	void send(unsigned char * data, int size);
	int readOne();
	int readBatch(unsigned char * buffer, int size);
protected:
	int devID;
	const char* m_devName;
};

#endif /* SERIALPORT_H_ */
