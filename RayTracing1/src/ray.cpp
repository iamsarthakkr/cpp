#include "Ray_tracing.hpp"
#include "Ray.hpp"

point3D Ray::origin() const { return m_origin; }
Vec3D Ray::direction() const { return m_direction; }

point3D Ray::at(double t) const {
   return m_origin + t * m_direction;
}