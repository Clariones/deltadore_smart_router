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

#ifndef STATISTIC_H
#define STATISTIC_H

#include "requirement.h"

namespace deltadoreX2d
{

class Statistic
{
    public :
        Statistic();

        int getReceivedCount() const;
        int getSentCount() const;
        int getErrorCount() const;
        int getTimeoutCount() const;
        void incrementReceivedCount();
        void incrementSentCount();
        void incrementErrorCount();
        void incrementTimeoutCount();
        void clear();

	private :
        volatile int m_receivedCount;
        volatile int m_sentCount;
        volatile int m_errorCount;
        volatile int m_timeoutCount;
		RecursiveLock m_lock;
};
}

#endif /* STATISTIC_H */
