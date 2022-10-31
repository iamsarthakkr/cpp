#include <bits/stdc++.h>

template<int md> 
class Modular {
public:
   Modular():value(0) {}

   template<typename T>
   Modular(T v) {
      value = normalize(v);
   }   

   const int& operator()() const { return value; }

   template<typename U>
   explicit operator U() const { return static_cast<U>(value); }

   constexpr static int mod() { return md; }

   Modular& operator+=(const Modular& other) {
      value += other.value;
      if(value >= mod()) value -= mod();
      return *this;
   }

   Modular& operator-=(const Modular& other) {
      value -= other.value;
      if(value < 0) value += mod();

      return *this;
   }

   Modular& operator++() {
      return *this += 1;
   }

   Modular& operator++(int) {
      Modular result(*this);
      *this += 1;
      return result;
   }

   Modular& operator--() {
      return *this -= 1;
   }

   Modular& operator--(int) {
      Modular result(*this);
      *this -= 1;
      return result;
   }

      Modular operator-() const { 
      return Modular(-value);
   }

   template<typename U>
   Modular& operator+=(const U& other) {
      return *this += Modular(other);
   }

   template<typename U>
   Modular& operator-=(const U& other) {
      return *this -= Modular(other);
   }

      Modular operator-() const { 
      return Modular(-value);
   }

   
   
   template <typename V, int mod>
   friend V& operator>>(V& stream, Modular<mod>& number);

private:
   template<typename T>
   static int normalize(T x) {
      int v;
      if(-mod() <= x && x < mod()) v = static_cast<int>(x);
      else v = static_cast<int>(x % mod());

      if(v < 0) v += mod();
      return v;
   }   

private:
   int value;
};

template <typename U, int mod>
U& operator<<(U& stream, const Modular<mod>& number) {
  return stream << number();
}
 
template <typename V, int mod>
V& operator>>(V& stream, Modular<mod>& number) {
   long long x;
   stream >> x;
   number.value = Modular<mod>::normalize(x);
   return stream;
}




