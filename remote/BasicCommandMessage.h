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

#ifndef BASICCOMMANDMESSAGE_H
#define BASICCOMMANDMESSAGE_H

#include "control/Message.h"
#include "remote/BasicCommand.h"

namespace deltadoreX2d
{

class BasicCommandMessage : public virtual Message
{
    public :
        virtual ~BasicCommandMessage(){};

        virtual const BasicCommand& getCommand() const=0;
        virtual void setCommand(const BasicCommand& command)=0;
};
}

#endif /* BASICCOMMANDMESSAGE_H */
