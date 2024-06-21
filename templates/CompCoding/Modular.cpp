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

   Modular& operator+= (const Modular& other) { v = normalize((int64_t)v + (int64_t)other.v); return *this; }
   Modular& operator-= (const Modular& other) { v = normalize((int64_t)v - (int64_t)other.v); return *this; }
   Modular& operator*= (const Modular& other) { v = normalize((int64_t)v * (int64_t)other.v); return *this; }

   template<typename U> Modular& operator+= (const U& other) { return *this += Modular(other); }
   template<typename U> Modular& operator-= (const U& other) { return *this -= Modular(other); }
   template<typename U> Modular& operator*= (const U& other) { return *this *= Modular(other); }


   Modular& operator ++ () { return *this += 1; }
   Modular& operator -- () { return *this -= 1; }

   Modular& operator ++ (int) { Modular result(*this); *this += 1; return result; }
   Modular& operator -- (int) { Modular result(*this); *this -= 1; return result; }

   Modular operator+ () const { return Modular(-v); }
   Modular operator- () const { return Modular(-v); }

   friend Modular operator + (const Modular& a, const Modular& b) { return Modular(a) += b; }
   friend Modular operator - (const Modular& a, const Modular& b) { return Modular(a) -= b; }
   friend Modular operator * (const Modular& a, const Modular& b) { return Modular(a) *= b; }

   template<typename U> friend Modular operator + (const Modular& a, const U& b) { return Modular(a) += Modular(b); }
   template<typename U> friend Modular operator - (const Modular& a, const U& b) { return Modular(a) -= Modular(b); }
   template<typename U> friend Modular operator * (const Modular& a, const U& b) { return Modular(a) *= Modular(b); }

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

constexpr int MOD = 1000000009;
// using Mint = Modular<MOD>;