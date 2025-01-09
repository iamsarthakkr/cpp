#pragma once
#define HITTABLE_H

#include "Ray_tracing.hpp"

class Material;

// Struct to hold the info about the strike point of a ray with a hittable object
struct Hit_record {
   point3D point;
   Vec3D normal;
   double t;
   bool front_face;
   shared_ptr<Material> material_ptr;

   inline void set_face_normal(const Ray& ray, const Vec3D& outward_normal) {
      if(dot(ray.direction(), outward_normal) > 0) {
         // ray is inside and thus the normal will point towards the center
         front_face = false;
         normal = -outward_normal;
      } else {
         front_face = true;
         normal = outward_normal;
      }
   }
};

class Hittable {
public:
   virtual bool hit(const Ray& ray, double min_t, double max_t, Hit_record& rec) const = 0;
};