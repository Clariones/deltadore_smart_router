#include <iostream>

#include "driver/DeltaDoreX2Driver.h"
#include "clt/CommandLineTool.h"


int main()
{
    DeltaDoreX2Driver driver;
    const char* devName = "/dev/ttyUSB0";
    driver.init(devName);
    CommandLineTool tool;

    tool.init(&driver);
    tool.run();
    return 0;
}
