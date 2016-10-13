#include <stdio.h>

#include "driver/DeltaDoreX2Driver.h"
#include "clt/CommandLineTool.h"


#include "driver/DataMap.h"

static const char* usage = "Usage:\n" \
    "    FdtiDriver <option> <option-value>\n" \
    "option\n" \
    "    --device  : device name. For example: /dev/ttyUSB0\n" \
    "    --udp_port: UDP listening port number for CLT commands. For example: 1800\n" \
    "\nExample:\n" \
    "    FdtiDriver --device /dev/ttyUSB0 --udp_port 1800";
#define MAX_ARG_VALUE_SIZE 100
#define FILE_NAME_LENGTH 20
#define STORAGE_FILE "/device.json"
static char* argDeviceName;
static int argUdpPort;
static char* argStoragePath;

bool isValidArguments(){
    if (argDeviceName == NULL) return false;
    if (argUdpPort <= 0) return false;

    return true;
}

int lastIndexOf(const char* pStr, char c, int from){
    for(int i=from; i>=0; i--){
        if (pStr[i] == c){
            return i;
        }
    }
    return -1;
}
int main(int argc, char ** argv)
{
    if (argc < 5){
        printf(usage);
        return 2;
    }

    argDeviceName = NULL;
    argUdpPort = -1;
    int len = strlen(argv[0]);
    int lstPos = lastIndexOf(argv[0], '/', len);
    argStoragePath = new char[lstPos + FILE_NAME_LENGTH];
    char* pArgPath = argStoragePath;
    strncpy(pArgPath, argv[0], lstPos);
    pArgPath += lstPos;
    strncpy(pArgPath, STORAGE_FILE, FILE_NAME_LENGTH);

    for(int i=1;i<argc;i+=2){
        if (strcmp(argv[i], "--device") == 0){
            argDeviceName = argv[i+1];
            continue;
        }
        if (strcmp(argv[i], "--udp_port") == 0){
            sscanf(argv[i+1], "%d", &argUdpPort);
        }
    }

    if (!isValidArguments()){
        printf(usage);
        return 2;
    }
    printf("Input params:\n\tdevice: %s\n\tudp port: %d\n\tstorage path:%s\n", argDeviceName, argUdpPort, argStoragePath);

    DeltaDoreX2Driver driver;
    const char* devName = argv[1];
    driver.init(devName, argStoragePath);
    if (!driver.initSuccess()){
        printf("DeltaDore Driver init failed.\n");
        return 3;
    }
//    CommandLineTool tool;
//
//    tool.init(&driver);
//    tool.run();
/*     const char* ppp = "this is a test";
 *     strcmp(ppp, ppp);
 *
 *     DataMap d1("d1", "d1 is a string");
 *     char * pStr = (char*)d1.getValue();
 *     printf("%s ==> %s\n", d1.getName(), pStr);
 *
 *
 *     DataMap d2("d2", 1000);
 *     int d2Val = *(int*) d2.getValue();
 *     printf("%s ==> %d\n", d2.getName(), d2Val);
 *
 *     DataMap d3("d3", 123.4);
 *     double d3Val = *(double*) d3.getValue();
 *     printf("%s ==> %f\n", d3.getName(), d3Val);
 *
 *     try{
 *     d3.pushBool("test", false);
 *     }catch (const char * err){
 *         printf("get error %s\n", err);
 *     }
 */

    return 0;
}

