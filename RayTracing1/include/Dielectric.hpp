#pragma once
#define DIELECTRIC_H

#include "Ray_tracing.hpp"
#include "Material.hpp"

class Dielectric : public Material {
public:
   Dielectric() : ir(1) {}
   Dielectric(const double& ir) : ir(ir) {}

   virtual bool scatter(const Ray& ray_in, const Hit_record& rec, color& attenuation, Ray& scattered) const override;

private: 
   double ir;
};