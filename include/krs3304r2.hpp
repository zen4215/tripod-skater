#pragma once

#include <IcsHardSerialClass.h>

class KRS3304R2 {
    public:
    KRS3304R2(IcsHardSerialClass ics, const uint8_t id);
    
    void setDegree(float deg);

    private:
    IcsHardSerialClass m_ics;
    const uint8_t      m_id;
};
