#include "Hittable.hpp"
#include "Metal.hpp"
#include "Hittable.hpp"

bool Metal::scatter(const Ray& ray_in, const Hit_record& rec, color& attenuation, Ray& scattered) const {
   auto reflected = reflect(ray_in.direction(), rec.normal);
   scattered = Ray(rec.point, reflected + fuzziness * random_in_unit_sphere());
   attenuation = reflectance;

   return dot(scattered.direction(), rec.normal) > 0;
}