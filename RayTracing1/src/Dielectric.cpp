#include "Dielectric.hpp"
#include "Hittable.hpp"

bool Dielectric::scatter(const Ray& ray_in, const Hit_record& rec, color& attenuation, Ray& scattered) const {
   // color based on the normal vector

   auto unit_vec = unit_vector(ray_in.direction());
   auto unit_direction = unit_vector(ray_in.direction());
   // auto unit_normal = unit_vector(rec.normal);
   auto relative_ir = rec.front_face ? 1.0 / ir : ir;

   // std::cerr << "Relative ir: " << relative_ir << '\n'; 
   auto cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
   auto sin_theta = sqrt(1 - cos_theta * cos_theta);
   
   bool cannot_refract = sin_theta * relative_ir > 1.0;


   Vec3D direction;

   if(cannot_refract) {
      direction = reflect(unit_vec, rec.normal);
   } else {
      direction = refract(unit_vec, rec.normal, relative_ir);
   }

   // std::cerr << refracted << '\n';

   scattered = Ray(rec.point, direction);
   attenuation = color(1, 1, 1);

   return true;   
}