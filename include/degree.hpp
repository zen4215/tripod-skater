#pragma once

class Degree {
    public:
    Degree(float x);
    
    void  set(float x);
    float get();

    void  add(float x);
    void  times(float x);

    float more(float x);
    bool  isInBetween(Degree& begin, Degree& end);

    private:
    float m_num;
};

Degree::Degree(float x) { set(x); }

void Degree::set(float x) {
    x = (int)x % 360;
    if(x < 0) x += 360; // 余りの符号は割られる数と同じ
    m_num = x;
}
float Degree::get() { return m_num; }

void Degree::add  (float x) { this->set(m_num + x); }
void Degree::times(float x) { this->set(m_num * x); }

float Degree::more(float x) {
    float num_backup = m_num;
    this->add(x);
    float num_return = this->get();
    this->set(num_backup);
    return num_return;
}
bool Degree::isInBetween(Degree& begin, Degree& end) {
    if(end.get() > begin.get()) return m_num > begin.get() && m_num < end.get(); 
    else                        return (m_num > begin.get() && m_num < 360) || (m_num < end.get() && m_num >= 0);
}
