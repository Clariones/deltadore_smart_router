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

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "requirement.h"
#include "control/FrameReceivedListener.h"
#include "control/FrameSentListener.h"
#include "control/AcknowledgmentListener.h"

namespace deltadoreX2d
{

class CoreController;

class Controller
{
    public :
        virtual ~Controller(){};

        virtual int getReceivedCount()=0;
        virtual int getSentCount()=0;
        virtual int getErrorCount()=0;
        virtual int getTimeoutCount()=0;
        virtual void open(InputStream* in, OutputStream* out)=0;
        virtual void close()=0;
        virtual void clearStatistics()=0;
        virtual void addFrameReceivedListener(FrameReceivedListener* listener)=0;
        virtual void removeFrameReceivedListener(FrameReceivedListener* listener)=0;
        virtual void addFrameSentListener(FrameSentListener* listener)=0;
        virtual void removeFrameSentListener(FrameSentListener* listener)=0;
        virtual void addAcknowledgmentListener(AcknowledgmentListener* listener)=0;
        virtual void removeAcknowledgmentListener(AcknowledgmentListener* listener)=0;
        virtual void sendFrame(std::vector<byte>& frame)=0;
        virtual void sendFrame(const std::string& hexString)=0;
		virtual CoreController* core()=0;

		template<class T> T convert() { return (T)this->core(); }
};
}

#endif /* CONTROLLER_H */
