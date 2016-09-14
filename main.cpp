#include <stdio.h>

#include "driver/DeltaDoreX2Driver.h"
#include "clt/CommandLineTool.h"


#include "driver/DataMap.h"

int main(int argc, char ** argv)
{
    if (argc < 2){
        printf("Must input device name.\nFor example:\n\tTestFDTI /dev/ttyUSB0\n\n");
        return 2;
    }
    DeltaDoreX2Driver driver;
    const char* devName = argv[1];
    driver.init(devName);
    if (!driver.initSuccess()){
        printf("DeltaDore Driver init failed.\n");
        return 3;
    }
    CommandLineTool tool;

    tool.init(&driver);
    driver.waitAck();
    tool.run();
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

