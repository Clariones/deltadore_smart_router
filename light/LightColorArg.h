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

#ifndef LIGHTCOLORARG_H
#define LIGHTCOLORARG_H

#include "control/NodeArg.h"

namespace deltadoreX2d
{

class LightColorArg : public NodeArg
{
    public :
        LightColorArg(int red, int green, int blue);
        ~LightColorArg();

        int getRedValue() const;
        int getGreenValue() const;
        int getBlueValue() const;
		bool instanceOf(ArgClass type) const;
		NodeArg* clone() const;
		void* derived();

    private :
        int m_red;
        int m_green;
        int m_blue;
};
}

#endif /* LIGHTCOLORARG_H */
