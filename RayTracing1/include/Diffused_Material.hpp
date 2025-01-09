#pragma once
#define DIFFUSED_MATERIAL_H

#include "Ray_tracing.hpp"
#include "Material.hpp"

class Diffused_Material : public Material {
public:
   Diffused_Material() : reflectance({1, 1, 1}) {}
   Diffused_Material(const color& reflectance) : reflectance(reflectance) {}

   virtual bool scatter(const Ray& ray_in, const Hit_record& rec, color& attenuation, Ray& scattered) const override;

private: 
   color reflectance;
};