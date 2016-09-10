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

#ifndef CURRENTRANSFORMERDEFINITIONMESSAGE_H
#define CURRENTRANSFORMERDEFINITIONMESSAGE_H

#include "control/Message.h"
#include "metering/RegisterSelection.h"

namespace deltadoreX2d
{

class CurrentTransformerDefinitionMessage : public virtual Message
{
    public :
        virtual ~CurrentTransformerDefinitionMessage(){};

        virtual const RegisterSelection& getCurrentTransformer1Definition() const=0;
        virtual void setCurrentTransformer1Definition(const RegisterSelection& selection)=0;
        virtual const RegisterSelection& getCurrentTransformer2Definition() const=0;
        virtual void setCurrentTransformer2Definition(const RegisterSelection& selection)=0;
        virtual const RegisterSelection& getCurrentTransformer3Definition() const=0;
        virtual void setCurrentTransformer3Definition(const RegisterSelection& selection)=0;
};
}

#endif /* CURRENTRANSFORMERDEFINITIONMESSAGE_H */
