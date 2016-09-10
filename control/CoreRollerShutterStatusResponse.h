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

#ifndef COREROLLERSHUTTERSTATUSRESPONSE_H
#define COREROLLERSHUTTERSTATUSRESPONSE_H

#include "control/CoreResponse.h"
#include "rollershutter/RollerShutterStatusResponse.h"

namespace deltadoreX2d
{

class CoreRollerShutterStatusResponse : public CoreResponse, public virtual RollerShutterStatusResponse
{
    public :
        CoreRollerShutterStatusResponse(int position,
                                        bool isRaisingFaulty,
                                        bool isLoweringFaulty,
                                        bool isObstacleFaulty,
                                        bool isOverheatingFaulty,
                                        bool isFavoritePosition,
                                        bool isIntrusionDetected);
        ~CoreRollerShutterStatusResponse();

        int getPosition() const;
        bool isRaisingFaulty() const;
        bool isLoweringFaulty() const;
        bool isObstacleFaulty() const;
        bool isOverheatingFaulty() const;
        bool isFavoritePosition() const;
        bool isIntrusionDetected() const;
		bool instanceOf(ResponseClass type) const;
		Response* clone() const;
		void* derived();

    private :
        int m_position;
        bool m_isRaisingFaulty;
        bool m_isLoweringFaulty;
        bool m_isObstacleFaulty;
        bool m_isOverheatingFaulty;
        bool m_isFavoritePosition;
        bool m_isIntrusionDetected;
};
}

#endif // COREROLLERSHUTTERSTATUSRESPONSE_H
