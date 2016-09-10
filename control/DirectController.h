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

#ifndef DIRECTCONTROLLER_H
#define DIRECTCONTROLLER_H

#include "control/Controller.h"
#include "control/MessageReceivedListener.h"
#include "control/Message.h"
#include "control/RadioFrequency.h"

namespace deltadoreX2d
{

class DirectController : public virtual Controller
{
    public :
        virtual ~DirectController(){};

        virtual void addMessageReceivedListener(MessageReceivedListener* listener)=0;
        virtual void removeMessageReceivedListener(MessageReceivedListener* listener)=0;
        virtual void setEnrollmentListeningMode(bool enabled)=0;
        virtual void setEnrollmentListeningMode(int port)=0;
        virtual void clearEnrolledSources()=0;
        virtual void sendMessage(Message* message, const RadioFrequency& frequency)=0;
        virtual Message* createMessage(MessageClass type)=0;
};
}

#endif /* DIRECTCONTROLLER_H */
