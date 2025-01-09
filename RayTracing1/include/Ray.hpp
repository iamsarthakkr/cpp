#pragma once
#define RAY_H

#include "Vec3D.hpp"

class Ray {
public:
   Ray() {}
   Ray(const point3D& origin, const Vec3D& direction) : m_origin(origin), m_direction(direction) {}

   point3D origin() const;
   Vec3D direction() const;

   point3D at(double t) const;
   
public:
   point3D m_origin;
   Vec3D m_direction;
};