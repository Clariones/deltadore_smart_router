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

#ifndef THERMICREGULATIONSTATUSRESPONSE_H
#define THERMICREGULATIONSTATUSRESPONSE_H

#include "control/Response.h"
#include "hvac/ThermicHeatLevel.h"
#include "hvac/ThermicRegulationMode.h"

namespace deltadoreX2d
{

class ThermicRegulationStatusResponse : public virtual Response
{
	public :
		virtual ~ThermicRegulationStatusResponse(){};

		virtual const ThermicHeatLevel& getLevel() const=0;
		virtual const ThermicRegulationMode& getMode() const=0;
		virtual bool isLevelTemporary() const=0;
		virtual bool isProductionCurrent() const=0;
		virtual bool isLoadSheddingCurrent() const=0;
		virtual bool isEntranceOpened() const=0;
		virtual bool isPresenceDetected() const=0;
		virtual bool isTemperatureSensorRadioFault() const=0;
		virtual bool isTemperatureSensorShortCircuit() const=0;
		virtual bool isTemperatureSensorOpenCircuit() const=0;
		virtual bool isProductionFault() const=0;
};
}

#endif // THERMICREGULATIONSTATUSRESPONSE_H
