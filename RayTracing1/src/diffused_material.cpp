#include "Diffused_Material.hpp"
#include "Hittable.hpp"

bool Diffused_Material::scatter(const Ray& ray_in, const Hit_record& rec, color& attenuation, Ray& scattered) const {
   // color based on the normal vector
   auto scatter_direction = rec.normal + random_unit_vector();
   if(scatter_direction.near_zero()) {
      scatter_direction = rec.normal;
   }
   scattered = Ray(rec.point, scatter_direction);
   attenuation = reflectance;

   return true;   
}