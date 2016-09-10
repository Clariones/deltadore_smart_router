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

#ifndef ALARMPRODUCLABEL_H
#define ALARMPRODUCLABEL_H

#include "requirement.h"

namespace deltadoreX2d
{

class AlarmProductLabel
{
    public :
        AlarmProductLabel(int value);
        ~AlarmProductLabel();

        static const AlarmProductLabel OTHER;
        static const AlarmProductLabel WORKSHOP;
        static const AlarmProductLabel BATHROOM;
        static const AlarmProductLabel OFFICE;
        static const AlarmProductLabel TOILET;
        static const AlarmProductLabel BASEMENT;
        static const AlarmProductLabel CELLAR;
        static const AlarmProductLabel BEDROOM ;
        static const AlarmProductLabel HALLWAY;
        static const AlarmProductLabel KITCHEN;
        static const AlarmProductLabel STAIRWAY;
        static const AlarmProductLabel GARAGE;
        static const AlarmProductLabel ATTIC;
        static const AlarmProductLabel HALL;
        static const AlarmProductLabel SHOP;
        static const AlarmProductLabel RECEPTION;
        static const AlarmProductLabel STORAGE_ROOM;
        static const AlarmProductLabel WAITING_ROOM;
        static const AlarmProductLabel LOUNGE;
        static const AlarmProductLabel DINING_ROOM;
        static const AlarmProductLabel SHOPWINDOW;
        static const AlarmProductLabel AREA;
		static const AlarmProductLabel ENTRY;
		static const AlarmProductLabel SECRETARIAT;
		static const AlarmProductLabel ROOM;
		static const AlarmProductLabel LOBBY;
		static const AlarmProductLabel COMPANY;
        static const AlarmProductLabel LANDING;
        static const AlarmProductLabel CLEARANCE;
        static AlarmProductLabel valueOf(int value);

		int toInt() const;
		const std::string& toString() const;

		bool operator==(const AlarmProductLabel &other) const;
		bool operator!=(const AlarmProductLabel &other) const;

    private :
		std::string m_name;
		int m_value;
};
}

#endif /* ALARMPRODUCLABEL_H */
