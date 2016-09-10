#include "Utils.h"



int openDevice(const char* devName, int options){
    return open(devName, options);
}

ssize_t readDevice (int fd, void *buf, size_t nbytes){
    ssize_t n = read(fd, buf, nbytes);
//    if (n > 0){
//        dumpHex("Read", buf, n);
//    }
    return n;
}
ssize_t writeDevice (int fd, const void *buf, size_t n){
    dumpHex("Send", buf, n);
    return write (fd, buf, n);
}
int closeDevice(int fd){
    return close(fd);
}

void dumpHex(const char* prefix, const void* pData, int size){
    for(int i=0;i<size;i++){
        if (i % 32 == 0){
            if (i == 0){
                printf("%s:", prefix);
            }else{
                printf("\n%s ", prefix);
            }
        }else if (i % 16 == 0){
            printf("  ");
        }
        printf(" %02X", ((const unsigned char*)pData)[i]);
    }
    if (size % 32 != 0){
        printf("\n");
    }
}
