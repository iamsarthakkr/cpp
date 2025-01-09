#pragma once
#define VEC3D_H

#include "Ray_tracing.hpp"

#include <iostream>

class Vec3D {
public:
   Vec3D() : m_data{0, 0, 0} {}
   Vec3D(double x, double y, double z) : m_data{x, y, z} {}

   double x() const;
   double y() const;
   double z() const;
   double operator[] (int i) const;
   double& operator[] (int i);

   Vec3D operator-() const;
   Vec3D& operator+=(const Vec3D& v);
   Vec3D& operator*=(const double t);
   Vec3D& operator/=(const double t);

   double length() const;
   double length_squared() const;
   bool near_zero() const;

   inline static Vec3D random() {
      return Vec3D(random_double(), random_double(), random_double());
   }

   inline static Vec3D random(double min, double max) {
      return Vec3D(random_double(min, max), random_double(min, max), random_double(min, max));
   }

private:
   double m_data[3];
};

// Utility functions

inline std::ostream& operator<<(std::ostream& out, const Vec3D& v) {
   return out << v[0] << " " << v[1] << " " << v[2];
}

inline Vec3D operator+(const Vec3D& a, const Vec3D& b) {
   return Vec3D(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

inline Vec3D operator-(const Vec3D& a, const Vec3D& b) {
   return Vec3D(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

inline Vec3D operator*(const Vec3D& a, const Vec3D& b) {
   return Vec3D(a[0] * b[0], a[1] * b[1], a[2] * b[2]);
}

inline Vec3D operator*(double t, const Vec3D& a) {
   return Vec3D(a[0] * t, a[1] * t, a[2] * t);
}

inline Vec3D operator*(const Vec3D& a, double t) {
   return t * a;
}

inline Vec3D operator/(const Vec3D& a, double t) {
   return (1 / t) * a;
}

inline double dot(const Vec3D&a, const Vec3D& b) {
   return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

inline Vec3D cross(const Vec3D& a, const Vec3D& b) {
   return Vec3D(
      a[1] * b[2] - a[3] * b[2],
      -a[0] * b[2] + a[2] - b[0],
      a[0] * b[1] - a[1] - b[0]
   );
}

inline Vec3D unit_vector(const Vec3D& v) {
   return v / v.length();
}

// For lazy diffusion
inline Vec3D random_in_unit_sphere() {
   Vec3D ret;
   while (true) {
      auto p = Vec3D::random(-1, 1);
      if (p.length_squared() >= 1) continue;
      ret = p;
      break;
   }
   return ret;
}

// For true lambertian reflection
inline Vec3D random_unit_vector() {
   return unit_vector(random_in_unit_sphere());
}

// For uniform scattering for all angles
inline Vec3D random_in_hemisphere(const Vec3D& normal) {
   auto in_unit = random_in_unit_sphere();
   if(dot(normal, in_unit)) {
      // in same hemisphere
      return in_unit;
   }
   return -in_unit;
}

// For perfect reflection
inline Vec3D reflect(const Vec3D& ray, const Vec3D& normal) {
   return ray - 2 * dot(ray, normal) * normal;
}

// For refraction
inline Vec3D refract(const Vec3D& ray_in, const Vec3D& normal, const double refractive_index_relative) {
   // refracted ray perpendicular to normal: mu * (R + (-R . N)N)
   // refracted ray parallet to normal: -sqrt(1 - |R_parallel}^2) N
   auto cos_theta = fmin(dot(-ray_in, normal), 1.0);
   auto r_parallel = refractive_index_relative * (ray_in + cos_theta * normal);
   // std::cerr << "cos_thetha " << cos_theta << ' ' << r_parallel.length_squared() << '\n';
   auto r_perpendicular = -sqrt(fabs(1 - r_parallel.length_squared())) * normal;
   // std::cerr << r_perpendicular << '\n';

   return r_parallel + r_perpendicular; 
}

using point3D = Vec3D;  // 3D point
using color = Vec3D;    // RGB color