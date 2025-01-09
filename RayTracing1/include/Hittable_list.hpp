#pragma once
#define HITTABLE_LIST

#include "Hittable.hpp"

#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

class Hittable_list: public Hittable {
public:
   Hittable_list() {};
   Hittable_list(shared_ptr<Hittable> object);

   void add(shared_ptr<Hittable> object);
   bool hit(const Ray& ray, double t_min, double t_max, Hit_record& rec) const override;

private:
   vector<shared_ptr<Hittable>> m_objects;
};