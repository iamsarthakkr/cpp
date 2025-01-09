#pragma once
#define SPHERE_H

#include "Hittable.hpp"

class Sphere : public Hittable {
public:
   Sphere() {}
   Sphere(const point3D& center, const double radius, shared_ptr<Material> material_ptr)
   : center(center), radius(radius), material_ptr(material_ptr) {}

   bool hit(const Ray& ray, double t_min, double t_max, Hit_record& rec) const override;

public:
   point3D center;
   double radius;   
   shared_ptr<Material> material_ptr;
};