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

#ifndef CORETHERMICREGULATIONSTATUSRESPONSE_H
#define CORETHERMICREGULATIONSTATUSRESPONSE_H

#include "control/CoreResponse.h"
#include "hvac/ThermicHeatLevel.h"
#include "hvac/ThermicRegulationMode.h"
#include "hvac/ThermicRegulationStatusResponse.h"

namespace deltadoreX2d
{

class CoreThermicRegulationStatusResponse : public CoreResponse, public virtual ThermicRegulationStatusResponse
{
	public :
		CoreThermicRegulationStatusResponse(const ThermicHeatLevel& level,
											const ThermicRegulationMode& mode,
											bool isLevelTemporary,
											bool isProductionCurrent,
											bool isLoadSheddingCurrent,
											bool isEntranceOpened,
											bool isPresenceDetected,
											bool isTemperatureSensorRadioFault,
											bool isTemperatureSensorShortCircuit,
											bool isTemperatureSensorOpenCircuit,
											bool isProductionFault);
		~CoreThermicRegulationStatusResponse();

		const ThermicHeatLevel& getLevel() const;
		const ThermicRegulationMode& getMode() const;
		bool isLevelTemporary() const;
		bool isProductionCurrent() const;
		bool isLoadSheddingCurrent() const;
		bool isEntranceOpened() const;
		bool isPresenceDetected() const;
		bool isTemperatureSensorRadioFault() const;
		bool isTemperatureSensorShortCircuit() const;
		bool isTemperatureSensorOpenCircuit() const;
		bool isProductionFault() const;
		bool instanceOf(ResponseClass type) const;
		Response* clone() const;
		void* derived();

	private :
		ThermicHeatLevel m_level;
		ThermicRegulationMode m_mode;
		bool m_isLevelTemporary;
		bool m_isProductionCurrent;
		bool m_isLoadSheddingCurrent;
		bool m_isEntranceOpened;
		bool m_isPresenceDetected;
		bool m_isTemperatureSensorRadioFault;
		bool m_isTemperatureSensorShortCircuit;
		bool m_isTemperatureSensorOpenCircuit;
		bool m_isProductionFault;
};
}

#endif // CORETHERMICREGULATIONSTATUSRESPONSE_H
