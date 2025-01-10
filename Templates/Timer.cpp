#include <bits/stdc++.h>

class Timer {
public:
    Timer() { m_start = std::chrono::high_resolution_clock::now(); }
    ~Timer() {
        m_end = std::chrono::high_resolution_clock::now();
        m_duration = (m_end - m_start);
        float ms = m_duration.count() * 1000.0f;
        std::cerr << "\nDone... Timer took: " << ms << " ms.\n"; 
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;
    std::chrono::duration<float> m_duration;
};