#include<string>
#include<vector>

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

template<int md> 
class Modular {
   static_assert(md > 0, "MOD must be positive");

public:
   Modular():v(0) {}

   template<typename T>
   Modular(T v_) {
      v = normalize(v_);
   }   

   constexpr static int mod() { return md; }

   const int& operator()() const { return v; }
   template<typename U> explicit operator U() const { return static_cast<U>(v); }

   Modular& operator += (const Modular& other) { v = normalize((int64_t)v + (int64_t)other.v); return *this; }
   Modular& operator -= (const Modular& other) { v = normalize((int64_t)v - (int64_t)other.v); return *this; }
   Modular& operator *= (const Modular& other) { v = normalize((int64_t)v * (int64_t)other.v); return *this; }
   Modular& operator /= (const Modular& other) { *this *= Modular(inverse(other.v, mod())); return *this; }

   template<typename U> Modular& operator += (const U& other) { return *this += Modular(other); }
   template<typename U> Modular& operator -= (const U& other) { return *this -= Modular(other); }
   template<typename U> Modular& operator *= (const U& other) { return *this *= Modular(other); }
   template<typename U> Modular& operator /= (const U& other) { return *this /= Modular(other); }

   Modular& operator ++ () { return *this += 1; }
   Modular& operator -- () { return *this -= 1; }

   Modular& operator ++ (int) { Modular result(*this); *this += 1; return result; }
   Modular& operator -- (int) { Modular result(*this); *this -= 1; return result; }

   Modular operator + () const { return Modular(v); }
   Modular operator - () const { return Modular(-v); }

   friend Modular operator + (const Modular& a, const Modular& b) { return Modular(a) += b; }
   friend Modular operator - (const Modular& a, const Modular& b) { return Modular(a) -= b; }
   friend Modular operator * (const Modular& a, const Modular& b) { return Modular(a) *= b; }
   friend Modular operator / (const Modular& a, const Modular& b) { return Modular(a) /= b; }

   template<typename U> friend Modular operator + (const Modular& a, const U& b) { return Modular(a) += b; }
   template<typename U> friend Modular operator - (const Modular& a, const U& b) { return Modular(a) -= b; }
   template<typename U> friend Modular operator * (const Modular& a, const U& b) { return Modular(a) *= b; }
   template<typename U> friend Modular operator / (const Modular& a, const U& b) { return Modular(a) /= b; }

   template<typename U> friend Modular operator + (const U& a, const Modular& b) { return Modular(a) += b; }
   template<typename U> friend Modular operator - (const U& a, const Modular& b) { return Modular(a) -= b; }
   template<typename U> friend Modular operator * (const U& a, const Modular& b) { return Modular(a) *= b; }
   template<typename U> friend Modular operator / (const U& a, const Modular& b) { return Modular(a) /= b; }

   friend bool operator == (const Modular& a, const Modular& b) { return a.v == b.v; }
   friend bool operator != (const Modular& a, const Modular& b) { return !(a == b); }

   template<typename U> friend bool operator == (const Modular& a, const U& b) { return a.v == Modular(b); }
   template<typename U> friend bool operator == (const U& a, const Modular& b) { return Modular(a) == b; }

   template<typename U> friend bool operator != (const Modular& a, const U& b) { return a.v != Modular(b); }
   template<typename U> friend bool operator != (const U& a, const Modular& b) { return Modular(a) != b; }

   friend bool operator < (const Modular& a, const Modular& b) { return a.v < b.v; }
   template<typename U> friend bool operator < (const Modular& a, const U& b) { return a < Modular(b); }
   template<typename U> friend bool operator < (const U& a, const Modular& b) { return Modular(a) < b; }

   friend bool operator <= (const Modular& a, const Modular& b) { return a.v <= b.v; }
   template<typename U> friend bool operator <= (const Modular& a, const U& b) { return a <= Modular(b); }
   template<typename U> friend bool operator <= (const U& a, const Modular& b) { return Modular(a) <= b; }

   friend bool operator > (const Modular& a, const Modular& b) { return a.v > b.v; }
   template<typename U> friend bool operator > (const Modular& a, const U& b) { return a > Modular(b); }
   template<typename U> friend bool operator > (const U& a, const Modular& b) { return Modular(a) > b; }

   friend bool operator >= (const Modular& a, const Modular& b) { return a.v >= b.v; }
   template<typename U> friend bool operator >= (const Modular& a, const U& b) { return a >= Modular(b); }
   template<typename U> friend bool operator >= (const U& a, const Modular& b) { return Modular(a) >= b; }

   friend std::ostream& operator << (std::ostream& out, const Modular& n) { return out << int(n); }
   friend std::istream& operator >> (std::istream& in, Modular& n) { int64_t v_; in >> v_; n = Modular(v_); return in; }

private:
   template<typename T>
   static int normalize(T x) {
      int v = static_cast<int>(x % mod());

      if(v < 0) v += mod();
      return v;
   }   

private:
   int v;
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

template <int T>
std::string to_string(const Modular<T>& number) {
  return to_string(number());
}

constexpr int MOD = 10;
using Mint = Modular<MOD>;

std::vector<Mint> fact(1, 1);
std::vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
   if (k < 0 || k > n) {
      return 0;
   }

   while((int)fact.size() < n + 1) {
      fact.push_back(fact.back() * (int)fact.size());
      inv_fact.push_back(1 / fact.back());
   }

   return fact[n] * inv_fact[k] * inv_fact[n - k];
}