/*
 * SerialPort.cpp
 *
 *  Created on: Sep 6, 2016
 *      Author: clariones
 */

#include "driver/SerialPort.h"
#include "driver/Utils.h"

SerialPort::SerialPort() : devID(0) {
}

SerialPort::~SerialPort() {
    close();
}

void SerialPort::init(const char* devName) {
	int fd = openDevice(devName, O_RDWR | O_NOCTTY );         //| O_NOCTTY | O_NDELAY
	if (-1 == fd) {
		perror("Can't Open Serial Port");
		devID = -1;
		return;
	} else {
		devID = fd;
	}
	printf("Open %s as device %d\n", devName, devID);
	m_devName = devName;
//	struct termio{
//		unsigned short  c_iflag; /* 输入模式标志 */
//	    unsigned short  c_oflag;     /* 输出模式标志 */
//	    unsigned short  c_cflag;     /* 控制模式标志*/
//	    unsigned short  c_lflag;     /* local mode flags */
//	    unsigned char    c_line;           /* line discipline */
//	    unsigned char    c_cc[NCC];    /* control characters */
//	};
	struct termios Opt;
	tcgetattr(fd, &Opt);

	// flush serial port, start to set new attributes
	tcflush(fd, TCIOFLUSH);

	// no verify, 8bit, 1 stop
//	Opt.c_cflag |= (CLOCAL | CREAD);
	Opt.c_cflag &= ~PARENB;
	Opt.c_cflag &= ~CSTOPB;
	Opt.c_cflag &= ~CSIZE;
	Opt.c_cflag |= CS8;

	// baud rate 38400
	cfsetispeed(&Opt, B38400);
	cfsetospeed(&Opt, B38400);

	// read time
	Opt.c_cc[VTIME] = 15; /* 设置超时15 seconds*/
	Opt.c_cc[VMIN] = 0; /* Update the options and do it NOW */

	// raw mode read/write
	Opt.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
	Opt.c_oflag  &= ~OPOST;   /*Output*/

	// Configuration take effect now
	int status = tcsetattr(fd, TCSANOW, &Opt);
	if (status != 0) {
		perror("tcsetattr fd1");
		return;
	}
	tcflush(fd, TCIOFLUSH);
}

void SerialPort::send(unsigned char * data, int size){
	int n = writeDevice(devID, data, size);
	printf("Send %d bytes\n", n);
	if (n != size){
		perror("Error send data");
	}
}

int SerialPort::readOne(){
	unsigned char buf[1];
	int n= readDevice(devID, buf, 1);
	if (n <= 0){
		return -1;
	}
	return buf[0];
}

int SerialPort::readBatch(unsigned char * buffer, int size){
	return readDevice(devID, buffer, size);
}

int SerialPort::read(void* buffer, int size)
{
    return readDevice(devID, buffer, size);
}

int SerialPort::write(void* buffer, int size)
{
    return writeDevice(devID, buffer, size);
}

void SerialPort::close()
{
    if (devID > 0){
        closeDevice(devID);
        printf("Device %s(%d) closed\n", m_devName, devID);
        devID = 0;
    }
}

