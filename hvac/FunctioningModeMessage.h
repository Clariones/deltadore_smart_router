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

#ifndef FUNCTIONINGMODEMESSAGE_H
#define FUNCTIONINGMODEMESSAGE_H

#include "control/Message.h"
#include "hvac/HeatingSetting.h"

namespace deltadoreX2d
{

class FunctioningModeMessage : public virtual Message
{
    public :
        virtual ~FunctioningModeMessage(){};

        virtual const HeatingSetting& getMode() const=0;
        virtual void setMode(const HeatingSetting& mode)=0;
        virtual int getDuration() const=0;
        virtual void setDuration(int duration)=0;
        virtual bool isManual() const=0;
        virtual void setManual(bool value)=0;
};
}

#endif // FUNCTIONINGMODEMESSAGE_H
