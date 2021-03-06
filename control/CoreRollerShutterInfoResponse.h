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

#ifndef COREROLLERSHUTTERINFORESPONSE_H
#define COREROLLERSHUTTERINFORESPONSE_H

#include "control/CoreResponse.h"
#include "rollershutter/RollerShutterInfoResponse.h"
#include "rollershutter/RollerShutterActuatorType.h"

namespace deltadoreX2d
{

class CoreRollerShutterInfoResponse : public CoreResponse, public virtual RollerShutterInfoResponse
{
    public :
        CoreRollerShutterInfoResponse(int channelCount, const RollerShutterActuatorType& actuatorType);
        ~CoreRollerShutterInfoResponse();

        int getChannelCount() const;
		const RollerShutterActuatorType& getActuatorType() const;
		bool instanceOf(ResponseClass type) const;
		Response* clone() const;
		void* derived();

    private :
        int m_channelCount;
        RollerShutterActuatorType m_actuatorType;
};
}

#endif /* COREROLLERSHUTTERINFORESPONSE_H */
