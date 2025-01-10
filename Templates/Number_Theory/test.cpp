#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < n; i++)
#define ford(i, n) for(int i = n - 1; i >= 0; i--)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define forr(i, l, r) for(int i = l; i <= r; i++)
#define forrd(i, l, r) for(int i = r; i >= l; i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(a) (int)(a).size()
#define sq(x) (x) * (x)

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else 
#define debug(...) 69
#endif

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<typename VarMod>
class VarModInt {
public:
    using Type = typename decay<decltype(VarMod::value)>::type;

public:
    VarModInt(): v(0) {}

    template<typename T>
    VarModInt(T v_) {
        v = normalize(v_);
    }

    static const Type mod() { return VarMod::value; }

    const Type& operator()() const { return v; }
    template<typename U> explicit operator U() const { return static_cast<U>(v); }

    VarModInt& operator += (const VarModInt& other) { v = normalize((int64_t)v + (int64_t)other.v); return *this; }
    VarModInt& operator -= (const VarModInt& other) { v = normalize((int64_t)v - (int64_t)other.v); return *this; }
    VarModInt& operator *= (const VarModInt& other) { v = normalize((int64_t)v * (int64_t)other.v); return *this; }
    VarModInt& operator /= (const VarModInt& other) { *this *= VarModInt(inverse(other.v, mod())); return *this; }

    template<typename U> VarModInt& operator += (const U& other) { return *this += VarModInt(other); }
    template<typename U> VarModInt& operator -= (const U& other) { return *this -= VarModInt(other); }
    template<typename U> VarModInt& operator *= (const U& other) { return *this *= VarModInt(other); }
    template<typename U> VarModInt& operator /= (const U& other) { return *this /= VarModInt(other); }

    VarModInt& operator ++ () { return *this += 1; }
    VarModInt& operator -- () { return *this -= 1; }

    VarModInt operator ++ (int) { VarModInt result(*this); *this += 1; return result; }
    VarModInt operator -- (int) { VarModInt result(*this); *this -= 1; return result; }

    VarModInt operator + () const { return VarModInt(v); }
    VarModInt operator - () const { return VarModInt(-v); }

    friend VarModInt operator + (const VarModInt& a, const VarModInt& b) { return VarModInt(a) += b; }
    friend VarModInt operator - (const VarModInt& a, const VarModInt& b) { return VarModInt(a) -= b; }
    friend VarModInt operator * (const VarModInt& a, const VarModInt& b) { return VarModInt(a) *= b; }
    friend VarModInt operator / (const VarModInt& a, const VarModInt& b) { return VarModInt(a) /= b; }

    template<typename U> friend VarModInt operator + (const VarModInt& a, const U& b) { return VarModInt(a) += b; }
    template<typename U> friend VarModInt operator - (const VarModInt& a, const U& b) { return VarModInt(a) -= b; }
    template<typename U> friend VarModInt operator * (const VarModInt& a, const U& b) { return VarModInt(a) *= b; }
    template<typename U> friend VarModInt operator / (const VarModInt& a, const U& b) { return VarModInt(a) /= b; }

    template<typename U> friend VarModInt operator + (const U& a, const VarModInt& b) { return VarModInt(a) += b; }
    template<typename U> friend VarModInt operator - (const U& a, const VarModInt& b) { return VarModInt(a) -= b; }
    template<typename U> friend VarModInt operator * (const U& a, const VarModInt& b) { return VarModInt(a) *= b; }
    template<typename U> friend VarModInt operator / (const U& a, const VarModInt& b) { return VarModInt(a) /= b; }

    friend bool operator == (const VarModInt& a, const VarModInt& b) { return a.v == b.v; }
    friend bool operator != (const VarModInt& a, const VarModInt& b) { return !(a == b); }

    template<typename U> friend bool operator == (const VarModInt& a, const U& b) { return a.v == VarModInt(b); }
    template<typename U> friend bool operator == (const U& a, const VarModInt& b) { return VarModInt(a) == b; }

    template<typename U> friend bool operator != (const VarModInt& a, const U& b) { return a.v != VarModInt(b); }
    template<typename U> friend bool operator != (const U& a, const VarModInt& b) { return VarModInt(a) != b; }

    friend bool operator < (const VarModInt& a, const VarModInt& b) { return a.v < b.v; }
    template<typename U> friend bool operator < (const VarModInt& a, const U& b) { return a < VarModInt(b); }
    template<typename U> friend bool operator < (const U& a, const VarModInt& b) { return VarModInt(a) < b; }

    friend bool operator <= (const VarModInt& a, const VarModInt& b) { return a.v <= b.v; }
    template<typename U> friend bool operator <= (const VarModInt& a, const U& b) { return a <= VarModInt(b); }
    template<typename U> friend bool operator <= (const U& a, const VarModInt& b) { return VarModInt(a) <= b; }

    friend bool operator > (const VarModInt& a, const VarModInt& b) { return a.v > b.v; }
    template<typename U> friend bool operator > (const VarModInt& a, const U& b) { return a > VarModInt(b); }
    template<typename U> friend bool operator > (const U& a, const VarModInt& b) { return VarModInt(a) > b; }

    friend bool operator >= (const VarModInt& a, const VarModInt& b) { return a.v >= b.v; }
    template<typename U> friend bool operator >= (const VarModInt& a, const U& b) { return a >= VarModInt(b); }
    template<typename U> friend bool operator >= (const U& a, const VarModInt& b) { return VarModInt(a) >= b; }

    friend std::ostream& operator << (std::ostream& out, const VarModInt& n) { return out << Type(n); }
    friend std::istream& operator >> (std::istream& in, VarModInt& n) { int64_t v_; in >> v_; n = VarModInt(v_); return in; }

private:
    template<typename T>
    static Type normalize(T x) {
        Type v = static_cast<Type>(x % mod());

        if(v < 0) v += mod();
        return v;
    }

private:
    Type v;
};

template<typename T, typename U>
T power(const T& base, const U& exp) {
    assert(exp >= 0);
    T x=base, res=1;
    U p=exp;
    while (p > 0) {
        if (p & 1) res*=x;
        x*=x;
        p>>=1;
    }
    return res;
}

template <typename T>
std::string to_string(const VarModInt<T>& number) {
    return to_string(number());
}

using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value = 1000000007;
ModType& md = VarMod::value;

using Mint = VarModInt<VarMod>;

// constexpr int md = 1000000007;
// using Mint = VarModInt<std::integral_constant<decay<decltype(md)>::type, md>>;

std::vector<Mint> fact(1, 1);
std::vector<Mint> inv_fact(1, 1);

/*
Mint C(int n, int k) {
    if (k < 0 || k > n) return 0;

    while((int)fact.size() < n + 1) {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
*/

ll add(__int128 x, __int128 y) {
    return (x + y) % md;
};

ll mul(__int128 x, __int128 y) {
    return (x * y) % md;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout << setprecision(12) << fixed;

    md = 100;

    Mint x = 5, y = 10;
    assert(x + y == add(5, 10));

    x = 99, y = 1;
    assert(x + y == add(99, 1));

    assert(x - 1 == 98);
    assert(x + 1 == 0);
    assert(y - 1 == 0);
    assert(y - 2 == 99);

    x = 5, y = 25;
    assert(x * y == mul(5, 25));
    assert(x * 2 == mul(5, 2));
    assert(2 * x == mul(2, 5));

    assert(++x == 6);
    x = 5;
    assert(x++ == 5);

    md = 1;
    x = 5, y = 1;
    assert(x * y == mul(5, 1));

    md = 1e9 + 7;
    ll xx = 1234567891011, yy = 23456789101112;
    x = xx, y = yy;
    assert((x + y) == add(xx, yy));
    assert((x * y) == mul(xx, yy));

    xx = 1234567891011234567LL, yy = 2345678910111212345LL;
    x = xx, y = yy;

    assert((x + y) == add(xx, yy));
    assert((x * y) == mul(xx, yy));

    cout << "Done...!" << '\n';
    return 0;
}