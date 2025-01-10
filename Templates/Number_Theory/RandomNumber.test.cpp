#include <bits/stdc++.h>
using namespace std;

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else 
#define debug(...) 69
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(69);

class Random {
public:
    Random(const mt19937_64& _rng): m_rng(_rng) {}
public:
    template<typename T> T next(T min, T max) { return static_cast<T>(uniform_real_distribution<long double>(min, max)(rng)); } 
    template<typename T> T next(T max) { return next(static_cast<T>(0), max); } 
    template<typename T> T next() { return next(numeric_limits<T>::min(), numeric_limits<T>::max()); } 
    template<typename T> vector<T> next_vector(int n, T max = numeric_limits<T>::max()) { vector<T> ret(n); for(auto& v: ret) v = next(max); return ret; }
    template<typename T> vector<T> next_vector(int n, T min, T max) { vector<T> ret(n); for(auto& v: ret) v = next(min, max); return ret; }
private:
    mt19937_64 m_rng;
};
Random Rng(rng);

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

void Test_Int() {
    Timer t;
    int TESTS = 10;
    for(int iter = 0; iter < TESTS; iter++) {
        cout << "Next: " << Rng.next<int>() << '\n';
    }
}

void Test_Int_2() {
    Timer t;
    int TESTS = 10;
    for(int iter = 0; iter < TESTS; iter++) {
        cout << "Next: " << Rng.next<int>(1000) << '\n';
    }
}
void Test_Int_Vector() {
    Timer t;
    int TESTS = 10;
    for(int iter = 0; iter < TESTS; iter++) {
        vector<int> a = Rng.next_vector<int>(10, 1000);
        for(auto& x: a) cout << x << "\n";
    }
}

void Test_Double() {
    Timer t;
    int TESTS = 10;
    for(int iter = 0; iter < TESTS; iter++) {
        cout << "Next: " << Rng.next<double>(1000) << '\n';
    }
}

void Test_Double_Vector() {
    Timer t;
    int TESTS = 10;
    for(int iter = 0; iter < TESTS; iter++) {
        vector<double> a = Rng.next_vector<double>(10, 1000);
        for(auto& x: a) cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout << setprecision(12) << fixed;

    Test_Int();
    Test_Int_2();
    Test_Int_Vector();
    Test_Double();

    return 0;
}