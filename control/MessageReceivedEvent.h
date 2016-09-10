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

#ifndef MESSAGERECEIVEDEVENT_H
#define MESSAGERECEIVEDEVENT_H

#include "control/Message.h"
#include "control/RadioFrequency.h"

namespace deltadoreX2d
{

class DirectController;

class MessageReceivedEvent
{
    public :
        MessageReceivedEvent(DirectController* source, Message* message, const RadioFrequency& frequency);
        ~MessageReceivedEvent();

        DirectController* getSource() const;
        const Message* getMessage() const;
        const RadioFrequency& getRadioFrequency() const;

    private :
        DirectController* m_source;
        Message* m_message;
        RadioFrequency m_frequency;
};
}

#endif // MESSAGERECEIVEDEVENT_H
