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

// Sum node for seg tree
template<typename T> class SumNode {
public:
    SumNode() {}
    template<typename U> SumNode(U v) { // Neutral element
        sum = v;
    }
public:
    static SumNode merge(const SumNode& a, const SumNode& b);
public:
    // NOTE: Initialize with neutral values
    T sum = 0;
};

string to_string(const SumNode<int>& info) { return "{ " + to_string(info.sum) + " }"; }

template<typename T> SumNode<T> SumNode<T>::merge(const SumNode<T>& a, const SumNode<T>& b) {
    SumNode res;
    res.sum = a.sum + b.sum;
    return res;
} 

template<typename T> using Segtree = SegtreeImpl<SumNode<T>>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(69);

class Random {
typedef long long ll;
public:
    Random(const mt19937_64& _rng): m_rng(_rng) {}

public:
    bool nextBoolean() { return nextInt(2); }
    int nextInt() { return nextInt(INT32_MAX); }
    int nextInt(int x) { return (int)nextLong(ll(x)); }
    int nextInt(int a, int b) { return (int)nextLong(ll(a), ll(b)); }
    ll nextLong() { return m_rng(); }
    ll nextLong(ll x) { return nextLong(0, x); }
    ll nextLong(ll a, ll b) { return std::uniform_int_distribution<ll>(a, b - 1)(m_rng); }
    vector<int> nextVector(int n, int mx = 1e9) { vector<int> a(n); for (int& x : a) x = nextInt(mx + 1); return a; }
    vector<ll> nextVectorll(int n, ll mx = 1e18) { vector<ll> a(n); for (ll& x : a) x = nextLong(mx + 1); return a; }
    
private:
    mt19937_64 m_rng;
};
Random Rng(rng);


void Test_Value() {
    int RUNS = 10000, TESTS = 1000;
    for(int iter = 0; iter < RUNS; iter++) {
        cout << "\rRunning test " << iter + 1 << "..." << std::flush;
        int n = Rng.nextInt(2, 5000);
        int MX = Rng.nextInt(100000);

        vector<int> a = Rng.nextVector(n, MX);
        Segtree<long long> st(a);

        for(int t = 0; t < TESTS; t++) {
            int i = Rng.nextInt(n);
            int v = (int)st.get(i).sum;
            assert(v == a[i]);
        }
    }
    cout << "\nDone Sum..." << '\n';
}

void Test_Sum() {
    int RUNS = 10, TESTS = 1000;
    for(int iter = 0; iter < RUNS; iter++) {
        cout << "\rRunning test " << iter + 1 << "..." << std::flush;
        int n = Rng.nextInt(2, 20000);
        int MX = Rng.nextInt(100000);
        vector<int> a = Rng.nextVector(n, MX);

        Segtree<int> st(a);

        for(int t = 0; t < TESTS; t++) {
            int l, r;
            do {
                l = Rng.nextInt(n), r = Rng.nextInt(n);
            } while(l > r);
            int v = (int)st.get(l, r + 1).sum;
            int cv = 0;
            for(int i = l; i <= r; i++) cv += a[i];
            assert(v == cv);
        }
    }
    cout << "\nDone Sum..." << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout << setprecision(12) << fixed;

    Test_Value();
    Test_Sum();

    return 0;
}