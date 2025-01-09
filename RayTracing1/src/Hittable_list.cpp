#include "Ray_tracing.hpp"
#include "Hittable_list.hpp"

Hittable_list::Hittable_list(shared_ptr<Hittable> object) { add(object); }

void Hittable_list::add(shared_ptr<Hittable> object) {
   m_objects.push_back(object);
}

bool Hittable_list::hit(const Ray& ray, double t_min, double t_max, Hit_record& rec) const {
   bool hit_any = false;
   auto closest_so_far = t_max;
   Hit_record temp_record;

   for(const auto object: m_objects) {
      if(object->hit(ray, t_min, closest_so_far, temp_record)) {
         hit_any = true;
         closest_so_far = temp_record.t;
         rec = temp_record;
      }
   }
   return hit_any;
}
