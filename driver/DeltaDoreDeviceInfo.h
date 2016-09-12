#ifndef DELTADOREDEVICEINFO_H
#define DELTADOREDEVICEINFO_H

#include "control/ResponseStatus.h"
using namespace deltadoreX2d;

class DeltaDoreDeviceInfo
{
    public:
        DeltaDoreDeviceInfo();
        virtual ~DeltaDoreDeviceInfo();

    public:
        static const int DEVICE_TYPE_UNKNOWN = 0;
        static const int DEVICE_TYPE_LIGHT = 1;
        static const int DEVICE_TYPE_ROLLER_SHUTTER = 2;


    public:
        int getDeviceType() { return m_deviceType;}
        void setDeviceType(int dType) {m_deviceType=dType;}

        ResponseStatus getLastResponseStatus() {return ResponseStatus::valueOf(m_lstResponseStatus);}
        void setLastResponseStatus(const ResponseStatus& status) { m_lstResponseStatus = status.toInt();}

        bool isFavoritePosition() {return m_favoritePosition;}
        void setFavoritePosition(bool value) { m_favoritePosition=value;}

        bool isIntrusionDetected() {return m_intrusionDetected;};
        void setIntrusionDetected(bool value) { m_intrusionDetected=value;}

        bool isLoweringFaulty() {return m_loweringFaulty;}
        void setLoweringFaulty(bool value) { m_loweringFaulty=value;}

        bool isObstacleFaulty() {return m_obstacleFaulty;}
        void setObstacleFaulty(bool value) { m_obstacleFaulty=value;}

        bool isOverheatingFaulty() {return m_overheatingFaulty;}
        void setOverheatingFaulty(bool value) { m_overheatingFaulty=value;}

        bool isRaisingFaulty() {return m_raisingFaulty;}
        void setRaisingFaulty(bool value) { m_raisingFaulty=value;}

        int getLevel() {return m_level;}
        void setLevel(int value) {m_level = value;}

        int getPosition() {return m_position;}
        void setPosition(int value) {m_position = value;}

    protected:
        int m_deviceType;
        bool m_favoritePosition;
        bool m_intrusionDetected;
        bool m_loweringFaulty;
        bool m_obstacleFaulty;
        bool m_overheatingFaulty;
        bool m_raisingFaulty;
        int m_level;
        int m_position;
        int m_lstResponseStatus;
    private:
};

#endif // DELTADOREDEVICEINFO_H
