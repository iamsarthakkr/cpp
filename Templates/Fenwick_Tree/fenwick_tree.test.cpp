#include <bits/stdc++.h>
using namespace std;

template <typename T> class Fenwick {
  public:
    Fenwick(int n, T v = static_cast<T>(0)) { m_fenwick.assign(n, v); }
    template <typename U> Fenwick(const vector<U> &a) { m_fenwick.assign(a.begin(), a.end()); }

    // Update node i with value v
    void update(int i, T v) {
        int j = i;
        while(j < (int)m_fenwick.size()) {
            m_fenwick[j] += v;
            j = j | (j + 1);
        }
    }
    // Get sum from l ... r
    T get(int l, int r) { return pref(r) - pref(l - 1); }

  private:
    T pref(int r) {
        int i = r;
        T res = 0;
        while(i >= 0) {
            res += m_fenwick[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }

  private:
    std::vector<T> m_fenwick;
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(69);

class Random {
  public:
    Random(const mt19937_64 &_rng) : m_rng(_rng) {}

  public:
    template <typename T> T next(T min, T max) { return static_cast<T>(uniform_real_distribution<long double>(min, max)(rng)); }
    template <typename T> T next(T max = numeric_limits<T>::max()) { return next(static_cast<T>(0), max); }
    template <typename T> vector<T> next_vector(int n, T max = numeric_limits<T>::max()) {
        vector<T> ret(n);
        for(auto &v : ret) v = next(max);
        return ret;
    }
    template <typename T> vector<T> next_vector(int n, T min, T max) {
        vector<T> ret(n);
        for(auto &v : ret) v = next(min, max);
        return ret;
    }

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

void Test() {
    Timer t;
    int n = 1000;
    vector<int> a = Rng.next_vector<int>(n, (int)1e5);

    Fenwick<long long> fw(a);

    int TESTS = 1e6;
    for(int test = 0; test < TESTS; test++) {
        cout << "\rRunning test " << test + 1 << "..." << std::flush;
        bool add = Rng.next<bool>();
        if(add) {
            int i = Rng.next<int>(n - 1), v = Rng.next<int>((int)1e3);
            fw.update(i, v);
        } else {
            int l, r;
            do {
                l = Rng.next(n - 1), r = Rng.next(n - 1);
            } while(l > r);

            auto s = fw.get(l, r);
            long long v = 0;
            for(int i = l; i <= r; i++) v += a[i];
            assert(s == v);
        }
    }
}

int main() {

    Test();

    return 0;
}
