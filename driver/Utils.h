#ifndef UTILS_H
#define UTILS_H

#include     <stdio.h>
#include     <stdlib.h>
#include     <unistd.h>
#include     <sys/types.h>
#include     <sys/stat.h>
#include     "string.h"
#include     <fcntl.h>
#include     <termios.h>
#include     <errno.h>

extern void dumpHex(const char* prefix, const void* pData, int size);

extern int openDevice(const char* devName, int options);
extern ssize_t readDevice (int fd, void *buf, size_t nbytes);
extern ssize_t writeDevice (int fd, const void *buf, size_t n);
extern int closeDevice(int fd);

#endif // UTILS_H
