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

#ifndef CORELIGHTSTATUSRESPONSE_H
#define CORELIGHTSTATUSRESPONSE_H

#include "control/CoreResponse.h"
#include "light/LightStatusResponse.h"

namespace deltadoreX2d
{

class CoreLightStatusResponse : public CoreResponse, public virtual LightStatusResponse
{
    public :
        CoreLightStatusResponse(int level,
                                bool isOverloadFaulty,
                                bool isCommandFaulty,
                                bool isOverheatingFaulty,
                                bool isFavoritePosition,
                                bool isPresenceDetected,
                                bool isTwilight);
        ~CoreLightStatusResponse();

        int getLevel() const;
        bool isOverloadFaulty() const;
        bool isCommandFaulty() const;
        bool isOverheatingFaulty() const;
        bool isFavoritePosition() const;
        bool isPresenceDetected() const;
        bool isTwilight() const;
		bool instanceOf(ResponseClass type) const;
		Response* clone() const;
		void* derived();

	private :
        int m_level;
        bool m_isOverloadFaulty;
        bool m_isCommandFaulty;
        bool m_isOverheatingFaulty;
        bool m_isFavoritePosition;
        bool m_isPresenceDetected;
        bool m_isTwilight;
};
}

#endif /* CORELIGHTSTATUSRESPONSE_H */
