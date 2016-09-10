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
** mleforestier        | 092410           | First version
** ylebret             | 280212           | refactoring
*/

#ifndef COREFUNCTIONINGMODEMESSAGE_H
#define COREFUNCTIONINGMODEMESSAGE_H

#include "control/CoreDomesticMessage.h"
#include "hvac/FunctioningModeMessage.h"

namespace deltadoreX2d
{

class CoreFunctioningModeMessage : public CoreDomesticMessage, public virtual FunctioningModeMessage
{
    public :
        CoreFunctioningModeMessage();
        CoreFunctioningModeMessage(const std::vector<byte>& frame);
        ~CoreFunctioningModeMessage();

        Family getFamily() const;

        const HeatingSetting& getMode() const;
        void setMode(const HeatingSetting& mode);
        int getDuration() const;
        void setDuration(int duration);
        bool isManual() const;
        void setManual(bool value);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        HeatingSetting m_mode;
        int m_duration;
        bool m_isManual;
};
}

#endif // COREFUNCTIONINGMODEMESSAGE_H
