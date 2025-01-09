#pragma once
#define MATERIAL_H

#include "Ray_tracing.hpp"

struct Hit_record;

class Material {
public:   
   // method to check whether material scatters the incomming ray and also calculate by how much
   virtual bool scatter(const Ray& ray_in, const Hit_record& rec, color& attenuation, Ray& scattered) const = 0;
};
