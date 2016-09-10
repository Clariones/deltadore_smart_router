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

#ifndef LIGHTSTATUSRESPONSE_H
#define LIGHTSTATUSRESPONSE_H

#include "control/Response.h"

namespace deltadoreX2d
{

class LightStatusResponse : public virtual Response
{
    public :
        virtual ~LightStatusResponse(){};

        virtual int getLevel() const=0;
        virtual bool isOverloadFaulty() const=0;
        virtual bool isCommandFaulty() const=0;
        virtual bool isOverheatingFaulty() const=0;
        virtual bool isFavoritePosition() const=0;
        virtual bool isPresenceDetected() const=0;
        virtual bool isTwilight() const=0;
};
}

#endif /* LIGHTSTATUSRESPONSE_H */
