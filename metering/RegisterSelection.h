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

#ifndef REGISTERSELECTION_H
#define REGISTERSELECTION_H

#include "requirement.h"

namespace deltadoreX2d
{

class RegisterSelection
{
    public :
        RegisterSelection(int value) ;
        ~RegisterSelection();

        static const RegisterSelection CURRENT_TRANSFORMER1;
        static const RegisterSelection CURRENT_TRANSFORMER2;
        static const RegisterSelection CURRENT_TRANSFORMER3;
        static const RegisterSelection HEATING;
        static const RegisterSelection HOT_WATER;
        static const RegisterSelection TOTAL;
        static const RegisterSelection COOLING;
        static const RegisterSelection HEATING_AND_COOLING;
        static const RegisterSelection ELECTRICITY_PRODUCTION;
        static RegisterSelection valueOf(int value);

        int toInt() const;
		const std::string& toString() const;

		bool operator==(const RegisterSelection &other) const;
		bool operator!=(const RegisterSelection &other) const;

   private :
		std::string m_name;
		int m_value;
};
}

#endif /* REGISTERSELECTION_H */
