# deltadore_smart_router
C Driver for deltadore controller in smart router

## build process
1. Checkout this project into somewhere, let's say "${prj_home}"
2. Make sure you have 'make' program installed
3. run command to make it, such as 

    > make clean all
4. You will get TestFDTI.out as the output

## run it
The usage is 

     sudo ./TestFDTI.out <device name> 
     
for example

    sudo ./TestFDTI.out /dev/tty/USB0

## interact with device
after you run into this program, will see a prompt 

    #

Input "help" will show you all commands:

    #help
    [help]	getTopology :
    [help]		Show currently recognized network and nodes
    [help]	registerNode :
    [help]		registerNode <network>
    [help]		Register new node into a network
    [help]	deleteNode :
    [help]		deleteNode <network> <node>
    [help]		Delete node from network
    [help]	controlLight :
    [help]		controlLight <network> <node> <action>
    [help]		action: on, off, ram-up, ram-down, stop, stand-out, alarm-pairing, toggle, preset-1, preset-2
    [help]	queryLightStatus :
    [help]		queryLightStatus <network> <node>
    [help]		Query light device status
    [help]	controlLightColor :
    [help]		controlLightColor <network> <node> <red> <green> <blue>
    [help]		red, green, blue: are integer between 0~255
    [help]	queryLightStatus :
    [help]		queryLightStatus <network> <node>
    [help]		Query light device status
    [help]	queryLightInfo :
    [help]		queryLightInfo <network> <node>
    [help]		Query light device info
    [help]	controlRollerShutter :
    [help]		controlRollerShutter <network> <node> <action>
    [help]		action: up, down, stop, up-slow, down-slow
    [help]	queryRollerShutterStatus :
    [help]		queryRollerShutterStatus <network> <node>
    [help]		Query roller shutter device status
    [help]	queryRollerShutterInfo :
    [help]		queryRollerShutterInfo <network> <node>
    [help]		Query roller shutter device information
    [help]	debugEnablePrintRead :
    [help]		debugEnablePrintRead <true|false>
    [help]		Enable the printing or not when read from serial port. This just used for debugging. 
    [help]	exit:
    [help]		close device and exit program

Enjoy.
