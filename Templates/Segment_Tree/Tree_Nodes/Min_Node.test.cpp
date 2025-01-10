#include <bits/stdc++.h>
using namespace std;

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else 
#define debug(...) 69
#endif

template<typename Node> class SegtreeImpl {
public:
    // Initialize with empty values
    SegtreeImpl(int n) { m_size = 1; while(m_size < n) m_size *= 2; m_tree.assign(2 * m_size, Node()); }
    // initialize with list of values
    template<typename T = Node> SegtreeImpl(vector<T>& info) : SegtreeImpl((int)info.size()) { build<T>(info, 0, 0, m_size); }
    // set value for a node
    void set(int i, const Node& v) { setImpl(i, v, 0, 0, m_size); }
    // get value of node i
    Node get(int i) { return getImpl(i, i + 1, 0, 0, m_size); }
    // get result for range l ... r - 1
    Node get(int l, int r) { return getImpl(l, r, 0, 0, m_size); }

private:
    // set implementation
    void setImpl(int i, const Node& v, int node, int lx, int rx) {
        if(rx - lx == 1) { m_tree[node] = v; return; } // leaf node
        int m = (lx + rx) >> 1;
        if(i < m) { setImpl(i, v, 2 * node + 1, lx, m); }
        else      { setImpl(i, v, 2 * node + 2, m, rx); }
        recalc(node, lx, rx);
    }
    // calc operation
    Node getImpl(int l, int r, int node, int lx, int rx) {
        if(rx <= l || r <= lx) { return Node(); } // neutral element
        if(l <= lx && rx <= r) { return m_tree[node]; } // covered

        int m = (lx + rx) >> 1;
        auto left = getImpl(l, r, 2 * node + 1, lx, m);
        auto right = getImpl(l, r, 2 * node + 2, m, rx);
        return Node::merge(left, right);
    }
private:
    template<typename T = Node> void build(const vector<T>& info, int node, int lx, int rx) {
        if(rx - lx == 1) { // leaf node
            if(lx < (int) info.size()) { 
                m_tree[node] = info[lx]; 
            }
            return;
        }
        int m = (lx + rx) >> 1; build(info, 2 * node + 1, lx, m); build(info, 2 * node + 2, m, rx); recalc(node, lx, rx);
    }
private:
    // recalculate value for a node
    void recalc(int node, int lx, int rx) {
        if(rx - lx == 1) { return; } // leaf node
        m_tree[node] = Node::merge(m_tree[2 * node + 1], m_tree[2 * node + 2]);
    }
private:
    int m_size;
    vector<Node> m_tree;
};

// Min node for seg tree
template<typename T> class Min_Node {
public:
    Min_Node() {}
    template<typename U> Min_Node(U v) : min(v) {}
public:
    static Min_Node merge(const Min_Node& a, const Min_Node& b);
public:
    T min = numeric_limits<T>::max();
};

string to_string(const Min_Node<int>& info) { return "{ " + to_string(info.min) + " }"; }

template<typename T> Min_Node<T> Min_Node<T>::merge(const Min_Node<T>& a, const Min_Node<T>& b) {
    Min_Node res;
    res.min = std::min(a.min, b.min);
    return res;
} 

template<typename T> using Segtree = SegtreeImpl<Min_Node<T>>;


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(69);

class Random {
    typedef long double ld;
public:
    Random(const mt19937_64& _rng): m_rng(_rng) {}
public:
    template<typename T> T next(T min, T max) { return static_cast<T>(uniform_real_distribution<ld>(static_cast<ld>(min), static_cast<ld>(max))(rng)); } 
    template<typename T> T next(T max = numeric_limits<T>::max()) { return next(static_cast<T>(0), max); } 
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

template<typename T>
void Test_Segment(T max = numeric_limits<T>::max()) {
    Timer t;
    int RUNS = 10, TESTS = 10000;
    for(int iter = 0; iter < RUNS; iter++) {
        cout << "\rRunning test " << iter + 1 << "..." << std::flush;

        int n = Rng.next<int>(10, 10000);
        vector<T> a = Rng.next_vector<T>(n);

        Segtree<T> st(a);

        for(int test = 0; test < TESTS; test++) {
            int l, r;
            do {
                l = Rng.next<int>(0, n - 1), r = Rng.next(0, n - 1); 
            } while(l > r);

            T v = st.get(l, r + 1).min;
            T cv = numeric_limits<T>::max();
            for(int i = l; i <= r; i++) if(a[i] < cv) cv = a[i];
            assert(v == cv);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout << setprecision(12) << fixed;

    Test_Segment<int>(1000);
    Test_Segment<long long>(1000);
    Test_Segment<long double>();

    return 0;
}