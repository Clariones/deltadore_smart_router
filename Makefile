#
#    HSGW Project Build Makefile

CPP	= c++
GCC	= gcc
RM	= rm -f
INC	= -I.
LIBS 	= -lc -lm -lpthread -ldl
CP	= /bin/cp

CFLAGS = -fPIC -O2 -fno-builtin 

ARCH = -m64

VERSION = 1
TARGET = TestFDTI.out

all:$(TARGET)
OBJECTS = common/CommonSettingArg.o\
	light/LightCommandArg.o\
	light/LightSettingArg.o\
	light/LightActuatorType.o\
	light/LightColorArg.o\
	metering/RegisterUnit.o\
	metering/RegisterSelection.o\
	metering/ElectricityTariff.o\
	metering/CompositeRegisterSelection.o\
	metering/ElectricityTariffOption.o\
	hvac/ThermicReheatingMode.o\
	hvac/ThermicRegulationCommandArg.o\
	hvac/ThermicFanMode.o\
	hvac/ThermicSystemCommandArg.o\
	hvac/ThermicDelayTime.o\
	hvac/ThermicDelayTimeArg.o\
	hvac/HeatingMode.o\
	hvac/ThermicSystemMode.o\
	hvac/HeatingSetting.o\
	hvac/ThermicHeatLevel.o\
	hvac/ThermicSettingArg.o\
	hvac/ThermicAntiFrostAdjustmentArg.o\
	hvac/ThermicSystemOutput.o\
	hvac/ThermicRegulationMode.o\
	hvac/ThermicActuatorType.o\
	hvac/ThermicPipeworkSupply.o\
	hvac/ThermicFanSpeed.o\
	sensor/DetectorType.o\
	sensor/TemperatureArg.o\
	sensor/Temperature.o\
	sensor/TemperatureType.o\
	control/CoreCurrentConsumptionRequest.o\
	control/Acknowledgment.o\
	control/CoreSetRoomTemperatureRequest.o\
	control/CoreGetOutdoorTemperatureRequest.o\
	control/CoreAlarmPeripheralDeletionMessage.o\
	control/CoreLightStatusResponse.o\
	control/CoreThermicSystemStatusRequest.o\
	control/CoreThermicInfoResponse.o\
	control/CoreThermicSystemCommandRequest.o\
	control/CoreVariationCommandMessage.o\
	control/RadioFrequency.o\
	control/Statistic.o\
	control/DirectCodec.o\
	control/CoreThermicSettingRequest.o\
	control/CoreRmRequest.o\
	control/CoreLightSettingRequest.o\
	control/CoreDetectionMessage.o\
	control/CoreEnrollmentMessage.o\
	control/NetworkCodec.o\
	control/CoreThermicInfoRequest.o\
	control/Codec.o\
	control/CoreNetwork.o\
	control/Checksum.o\
	control/CoreRollerShutterSettingRequest.o\
	control/CoreSetOutdoorTemperatureRequest.o\
	control/CoreAlarmCentralUnitMessage.o\
	control/ResponseStatus.o\
	control/CoreLightColorResponse.o\
	control/CoreAlarmCommandPanelMessage.o\
	control/CoreFunctioningModeMessage.o\
	control/CoreDomesticMessage.o\
	control/CoreCommonSettingRequest.o\
	control/CoreHeatingLevelMessage.o\
	control/CoreAlarmEventMessage.o\
	control/CoreDataTransferMessage.o\
	control/CoreVariationMessage.o\
	control/CoreThermicAntiFrostAdjustmentRequest.o\
	control/CoreCurrentTransformerDefinitionMessage.o\
	control/CoreCompositeMeterReadingMessage.o\
	control/NodeArg.o\
	control/CoreController.o\
	control/CoreThermicGetDelayTimeRequest.o\
	control/CoreDistressMessage.o\
	control/CoreAlarmTimeMessage.o\
	control/CoreRollerShutterCommandRequest.o\
	control/CoreLightCommandRequest.o\
	control/CoreThermicRegulationCommandRequest.o\
	control/CoreMessage.o\
	control/CoreThermicSystemStatusResponse.o\
	control/CoreDiagnosticOverheatingResponse.o\
	control/CoreAlarmCommandMessage.o\
	control/CoreSirenMessage.o\
	control/CoreAlarmMessage.o\
	control/CoreResponse.o\
	control/CoreLightSetColorRequest.o\
	control/CoreCurrentConsumptionResponse.o\
	control/Factory.o\
	control/MessageReceivedEvent.o\
	control/CoreDiagnosticOverheatingRequest.o\
	control/CoreMeterReadingMessage.o\
	control/DataWay.o\
	control/CoreLightInfoRequest.o\
	control/NodeDiscoveredEvent.o\
	control/CoreThermicRegulationStatusRequest.o\
	control/MessagePriority.o\
	control/EndTransactionEvent.o\
	control/CoreTemperatureResponse.o\
	control/CoreThermicDelayTimeResponse.o\
	control/CorePowerConsumptionRequest.o\
	control/CoreTemperatureInfoResponse.o\
	control/CoreRollerShutterInfoRequest.o\
	control/CoreRollerShutterStatusResponse.o\
	control/CoreTemperatureInfoRequest.o\
	control/CoreScenarioCommandMessage.o\
	control/CorePowerConsumptionResponse.o\
	control/CoreBasicCommandMessage.o\
	control/FrameIoEvent.o\
	control/CoreEnergyConsumptionRequest.o\
	control/CoreThermicSetDelayTimeRequest.o\
	control/CoreDataTransferNotificationMessage.o\
	control/CoreTelephoneTransmitterMessage.o\
	control/CoreThermicRegulationStatusResponse.o\
	control/CoreTemperatureMessage.o\
	control/CoreRollerShutterStatusRequest.o\
	control/AcknowledgmentEvent.o\
	control/CoreGetRoomTemperatureRequest.o\
	control/PrintableHex.o\
	control/CoreMpRequest.o\
	control/CoreRequest.o\
	control/CoreAlarmPeripheralLabelMessage.o\
	control/CoreRollerShutterInfoResponse.o\
	control/CoreAlarmLogViewMessage.o\
	control/MeshCodec.o\
	control/CoreEnergyConsumptionResponse.o\
	control/CoreLightStatusRequest.o\
	control/CoreLightInfoResponse.o\
	control/CoreLightGetColorRequest.o\
	control/Node.o\
	security/AlarmProductType.o\
	security/TelephoneTransmitterStatus.o\
	security/AlarmCentralUnitType.o\
	security/AlarmCommand.o\
	security/AlarmStatus.o\
	security/AlarmEvent.o\
	security/AlarmFunctioningMode.o\
	security/AlarmLogType.o\
	security/AlarmProductLabel.o\
	requirement.o\
	remote/BasicCommand.o\
	remote/VariationCommand.o\
	rollershutter/RollerShutterSettingArg.o\
	rollershutter/RollerShutterActuatorType.o\
	rollershutter/RollerShutterCommandArg.o\
	driver/cJSON.o\
	driver/DataMap.o\
	driver/DeltaDoreDeviceInfo.o\
	driver/DeltaDoreX2Driver.o\
	driver/SerialPort.o\
	driver/Utils.o\
	clt/CmdControlLight.o\
	clt/CmdControlRollerShutter.o\
	clt/CmdDeleteNode.o\
	clt/CmdGetTopology.o\
	clt/CmdQueryLight.o\
	clt/CmdQueryLightInfo.o\
	clt/CmdQueryRollershutterInfo.o\
	clt/CmdQueryRollershutterStatus.o\
	clt/CmdRegisterNode.o\
	clt/CommandLineTool.o\
	clt/CmdDebugSetShowRead.o\
	main.o

$(TARGET):$(OBJECTS)
	$(CPP) $(ARCH) -Wl,-soname,$(TARGET) $(CFLAGS)  -O2 -o $@ $(OBJECTS) $(LIBS)


install:$(TARGET)
	sudo $(CP) $(TARGET) /usr/lib


.cpp.o:
	$(CPP) $(ARCH) $(INC) -Wall $(CFLAGS)  -c $< -o $@

.c.o:
	$(GCC) $(ARCH) $(INC) -Wall $(CFLAGS) -c $<  -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET) $(L2OBJS) $(L3OBJS) *~

