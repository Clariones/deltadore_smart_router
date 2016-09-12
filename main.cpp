#include <iostream>

#include "driver/DeltaDoreX2Driver.h"
#include "clt/CommandLineTool.h"


#include "driver/DataMap.h"

int main()
{
    DeltaDoreX2Driver driver;
    const char* devName = "/dev/ttyUSB0";
    driver.init(devName);
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

