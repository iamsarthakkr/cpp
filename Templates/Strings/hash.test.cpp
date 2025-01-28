#include <bits/stdc++.h>
using namespace std;

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
class ModInt {
public:
    using Type = typename decay<decltype(VarMod::value)>::type;

public:
    ModInt(): v(0) {}

    template<typename T>
    ModInt(T v_) {
        v = normalize(v_);
    }

    static const Type mod() { return VarMod::value; }

    const Type& operator()() const { return v; }
    template<typename U> explicit operator U() const { return static_cast<U>(v); }

    ModInt& operator += (const ModInt& other) { v = normalize((int64_t)v + (int64_t)other.v); return *this; }
    ModInt& operator -= (const ModInt& other) { v = normalize((int64_t)v - (int64_t)other.v); return *this; }
    ModInt& operator *= (const ModInt& other) { v = normalize((int64_t)v * (int64_t)other.v); return *this; }
    ModInt& operator /= (const ModInt& other) { *this *= ModInt(inverse(other.v, mod())); return *this; }

    template<typename U> ModInt& operator += (const U& other) { return *this += ModInt(other); }
    template<typename U> ModInt& operator -= (const U& other) { return *this -= ModInt(other); }
    template<typename U> ModInt& operator *= (const U& other) { return *this *= ModInt(other); }
    template<typename U> ModInt& operator /= (const U& other) { return *this /= ModInt(other); }

    ModInt& operator ++ () { return *this += 1; }
    ModInt& operator -- () { return *this -= 1; }

    ModInt operator ++ (int) { ModInt result(*this); *this += 1; return result; }
    ModInt operator -- (int) { ModInt result(*this); *this -= 1; return result; }

    ModInt operator + () const { return ModInt(v); }
    ModInt operator - () const { return ModInt(-v); }

    friend ModInt operator + (const ModInt& a, const ModInt& b) { return ModInt(a) += b; }
    friend ModInt operator - (const ModInt& a, const ModInt& b) { return ModInt(a) -= b; }
    friend ModInt operator * (const ModInt& a, const ModInt& b) { return ModInt(a) *= b; }
    friend ModInt operator / (const ModInt& a, const ModInt& b) { return ModInt(a) /= b; }

    template<typename U> friend ModInt operator + (const ModInt& a, const U& b) { return ModInt(a) += b; }
    template<typename U> friend ModInt operator - (const ModInt& a, const U& b) { return ModInt(a) -= b; }
    template<typename U> friend ModInt operator * (const ModInt& a, const U& b) { return ModInt(a) *= b; }
    template<typename U> friend ModInt operator / (const ModInt& a, const U& b) { return ModInt(a) /= b; }

    template<typename U> friend ModInt operator + (const U& a, const ModInt& b) { return ModInt(a) += b; }
    template<typename U> friend ModInt operator - (const U& a, const ModInt& b) { return ModInt(a) -= b; }
    template<typename U> friend ModInt operator * (const U& a, const ModInt& b) { return ModInt(a) *= b; }
    template<typename U> friend ModInt operator / (const U& a, const ModInt& b) { return ModInt(a) /= b; }

    friend bool operator == (const ModInt& a, const ModInt& b) { return a.v == b.v; }
    friend bool operator != (const ModInt& a, const ModInt& b) { return !(a == b); }

    template<typename U> friend bool operator == (const ModInt& a, const U& b) { return a.v == ModInt(b); }
    template<typename U> friend bool operator == (const U& a, const ModInt& b) { return ModInt(a) == b; }

    template<typename U> friend bool operator != (const ModInt& a, const U& b) { return a.v != ModInt(b); }
    template<typename U> friend bool operator != (const U& a, const ModInt& b) { return ModInt(a) != b; }

    friend bool operator < (const ModInt& a, const ModInt& b) { return a.v < b.v; }
    template<typename U> friend bool operator < (const ModInt& a, const U& b) { return a < ModInt(b); }
    template<typename U> friend bool operator < (const U& a, const ModInt& b) { return ModInt(a) < b; }

    friend bool operator <= (const ModInt& a, const ModInt& b) { return a.v <= b.v; }
    template<typename U> friend bool operator <= (const ModInt& a, const U& b) { return a <= ModInt(b); }
    template<typename U> friend bool operator <= (const U& a, const ModInt& b) { return ModInt(a) <= b; }

    friend bool operator > (const ModInt& a, const ModInt& b) { return a.v > b.v; }
    template<typename U> friend bool operator > (const ModInt& a, const U& b) { return a > ModInt(b); }
    template<typename U> friend bool operator > (const U& a, const ModInt& b) { return ModInt(a) > b; }

    friend bool operator >= (const ModInt& a, const ModInt& b) { return a.v >= b.v; }
    template<typename U> friend bool operator >= (const ModInt& a, const U& b) { return a >= ModInt(b); }
    template<typename U> friend bool operator >= (const U& a, const ModInt& b) { return ModInt(a) >= b; }

    friend std::ostream& operator << (std::ostream& out, const ModInt& n) { return out << Type(n); }
    friend std::istream& operator >> (std::istream& in, ModInt& n) { int64_t v_; in >> v_; n = ModInt(v_); return in; }

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
std::string to_string(const ModInt<T>& number) {
    return to_string(number());
}

/*
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value = 1000000007;
ModType& md = VarMod::value;

using Mint = ModInt<VarMod>;
*/

constexpr int md = 1000000007;
using Mint = ModInt<std::integral_constant<decay<decltype(md)>::type, md>>;

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



template<typename Mod>
class Hash {
public:
    Hash() {}
    Hash(const string& s, const char first = 'a', int coeff = 31) {
        int n = (int)s.size(); m_hash.assign(n, 0); m_power.resize(n, 1);

        // h[i] = s[0] + s[1] * coeff + s[2] * coeff^2 + ...
        for(int i = 1; i < n; i++) m_power[i] = coeff * m_power[i - 1];

        m_hash[0] = static_cast<Mod>(s[0] - first + 1);
        for(int i = 1; i < n; i++) m_hash[i] = m_hash[i - 1] + static_cast<Mod>(s[i] - first + 1) * m_power[i];
    }
    const Mod& operator()() const { return m_hash.back(); }
    const Mod& get(int i) const { return m_hash[i]; }
    Mod get(int l, int r) {
        Mod r_hash = m_hash[r], l_hash = l > 0 ? m_hash[l - 1] : static_cast<Mod>(0);
        return (r_hash - l_hash) / m_power[l];
    }

private:
    vector<Mod> m_hash;
    vector<Mod> m_power;
};

constexpr int md1 = 1000000007;
constexpr int md2 = 998244353;
using Mint1 = ModInt<std::integral_constant<decay<decltype(md1)>::type, md1>>;
using Mint2 = ModInt<std::integral_constant<decay<decltype(md2)>::type, md2>>;



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout << setprecision(12) << fixed;

    string s, t;
    int k;
    cin >> s >> t >> k;
    int n = (int)s.size();

    Hash<Mint1> h1(s);
    Hash<Mint2> h2(s);

    vector<int> bad(26, 0);
    for(int i = 0; i < 26; i++) bad[i] = t[i] == '0';

    vector<pair<int, int>> res;
    for(int l = 0; l < n; l++) {
        int bad_cnt = 0;
        for(int r = l; r < n; r++) {
            bad_cnt += bad[s[r] - 'a'];

            if(bad_cnt <= k) {
                res.emplace_back(h1.get(l, r)(), h2.get(l, r)());
            } else {
                break;
            }
        }
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());

    cout << (int)res.size() << '\n';

    return 0;
}