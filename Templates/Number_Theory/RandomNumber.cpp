#include <bits/stdc++.h>
using namespace std;

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
Random random(rng);