#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(69);

class Random {
typedef long long ll;
public:
    Random(const mt19937_64& _rng): m_rng(_rng) {}
public:
    bool next_bool() { return next_int(2); }
    int next_int() { return next_int(INT32_MAX); }
    int next_int(int x) { return (int)next_long(ll(x)); }
    int next_int(int a, int b) { return (int)next_long(ll(a), ll(b)); }
    ll next_long() { return m_rng(); }
    ll next_long(ll x) { return next_long(0, x); }
    ll next_long(ll a, ll b) { return std::uniform_int_distribution<ll>(a, b - 1)(m_rng); }
    vector<int> next_vector(int n, int mx = 1e9) { vector<int> a(n); for (int& x : a) x = next_int(mx + 1); return a; }
    vector<ll> next_vectorll(int n, ll mx = 1e18) { vector<ll> a(n); for (ll& x : a) x = next_long(mx + 1); return a; }
private:
    mt19937_64 m_rng;
};
Random Rng(rng);