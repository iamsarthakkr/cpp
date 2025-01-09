#pragma once
#define METAL_H

#include "Ray_tracing.hpp"
#include "Material.hpp"

class Metal : public Material {
public:
   Metal() : reflectance({1, 1, 1}) {}
   Metal(const color& reflectance, const double fuzz) : reflectance(reflectance), fuzziness(fuzz < 1 ? fuzz : 1.0) {}

   virtual bool scatter(const Ray& ray_in, const Hit_record& rec, color& attenuation, Ray& scattered) const override;

private: 
   color reflectance;
   double fuzziness;
};