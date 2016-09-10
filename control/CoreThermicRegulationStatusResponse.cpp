/*
** Copyright (C) 2010 Eff'Innov Technologies.  All rights reserved.
** May not be redistributed without prior written permission.
**
** Based on Java version by DeltaDore, subject to DeltaDore copyrights
**
** Note: Eff'Innov Technologies disclaims responsibility for any malfunction
** or error that may arise from any change to the current file, provided that such
** change have not been submitted to and formerly approved by Eff'Innov Technologies,
** prior to the occurence of such malfunction or error
**
** Author: Mickael Leforestier (mickael.leforestier@effinnov.com)
**
** History log:
** ------------------------------------------------------------------------------
** Author              | Date             | Changes
** ------------------------------------------------------------------------------
** mleforestier        | 052511           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreThermicRegulationStatusResponse.h"

namespace deltadoreX2d
{

CoreThermicRegulationStatusResponse::CoreThermicRegulationStatusResponse(const ThermicHeatLevel& level,
																		const ThermicRegulationMode& mode,
																		bool isLevelTemporary,
																		bool isProductionCurrent,
																		bool isLoadSheddingCurrent,
																		bool isEntranceOpened,
																		bool isPresenceDetected,
																		bool isTemperatureSensorRadioFault,
																		bool isTemperatureSensorShortCircuit,
																		bool isTemperatureSensorOpenCircuit,
																		bool isProductionFault) :
	CoreResponse(ResponseStatus::OK),
	m_level(level),
	m_mode(mode),
	m_isLevelTemporary(isLevelTemporary),
	m_isProductionCurrent(isProductionCurrent),
	m_isLoadSheddingCurrent(isLoadSheddingCurrent),
	m_isEntranceOpened(isEntranceOpened),
	m_isPresenceDetected(isPresenceDetected),
	m_isTemperatureSensorRadioFault(isTemperatureSensorRadioFault),
	m_isTemperatureSensorShortCircuit(isTemperatureSensorShortCircuit),
	m_isTemperatureSensorOpenCircuit(isTemperatureSensorOpenCircuit),
	m_isProductionFault(isProductionFault)
{
	//
}

CoreThermicRegulationStatusResponse::~CoreThermicRegulationStatusResponse()
{
	//
}

const ThermicHeatLevel& CoreThermicRegulationStatusResponse::getLevel() const
{
	return m_level;
}

const ThermicRegulationMode& CoreThermicRegulationStatusResponse::getMode() const
{
	return m_mode;
}

bool CoreThermicRegulationStatusResponse::isLevelTemporary() const
{
	return m_isLevelTemporary;
}

bool CoreThermicRegulationStatusResponse::isProductionCurrent() const
{
	return m_isProductionCurrent;
}

bool CoreThermicRegulationStatusResponse::isLoadSheddingCurrent() const
{
	return m_isLoadSheddingCurrent;
}

bool CoreThermicRegulationStatusResponse::isEntranceOpened() const
{
	return m_isEntranceOpened;
}

bool CoreThermicRegulationStatusResponse::isPresenceDetected() const
{
	return m_isPresenceDetected;
}

bool CoreThermicRegulationStatusResponse::isTemperatureSensorRadioFault() const
{
	return m_isTemperatureSensorRadioFault;
}

bool CoreThermicRegulationStatusResponse::isTemperatureSensorShortCircuit() const
{
	return m_isTemperatureSensorShortCircuit;
}

bool CoreThermicRegulationStatusResponse::isTemperatureSensorOpenCircuit() const
{
	return m_isTemperatureSensorOpenCircuit;
}

bool CoreThermicRegulationStatusResponse::isProductionFault() const
{
	return m_isProductionFault;
}

bool CoreThermicRegulationStatusResponse::instanceOf(ResponseClass type) const
{
	if (type == ThermicRegulationStatusResponse_t) { return true; }
	return false;
}

Response* CoreThermicRegulationStatusResponse::clone() const
{
	return new CoreThermicRegulationStatusResponse(*this);
}

void* CoreThermicRegulationStatusResponse::derived()
{
	return (ThermicRegulationStatusResponse*)this;
}
}
