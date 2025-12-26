#pragma once

#include <exception>

#include <IcsHardSerialClass.h>

class KRS3304R2 {
    public:
    KRS3304R2(IcsHardSerialClass& ics, const uint8_t id);
    
    void setDegree(float deg);

    private:
    static constexpr uint8_t MOTION_RANGE {135};

    IcsHardSerialClass& m_ics;
    const uint8_t       m_id;
};

KRS3304R2::KRS3304R2(IcsHardSerialClass& ics, const uint8_t id) : m_ics(ics), m_id(id) {}

void KRS3304R2::setDegree(float deg) {
    if(deg > MOTION_RANGE || deg < MOTION_RANGE) throw std::invalid_argument("krs3304r2::setDegree(): invaild degree, confirm motion range.");
    m_ics.setPos(m_id, m_ics.degPos(deg));
}
