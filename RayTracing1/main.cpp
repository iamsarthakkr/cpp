#include "Ray_tracing.hpp"

#include "Camera.hpp"
#include "Color.hpp"
#include "Hittable_list.hpp"
#include "Sphere.hpp"
#include "Material.hpp"
#include "Diffused_Material.hpp"
#include "Metal.hpp"
#include "Dielectric.hpp"

#include <iostream>


// gives the color of a ray based on its y coordinate value
// gradient varies from white for y = 0 to cyan (24, 163, 126)
color ray_color(const Ray& ray, const Hittable_list& world, int depth) {
   if(depth < 0) {
      // No more light gathered
      return Color::black;
   }

   Hit_record rec;
   if(world.hit(ray, 0.001, infinity, rec)) {
      // color based on the normal vector
      Ray scattered;
      color attenuation;
      if(rec.material_ptr->scatter(ray, rec, attenuation, scattered)) {
         return attenuation * ray_color(scattered, world, depth - 1);
      }
      return Color::black;
   }
   
   // color for background
   auto unit_direction = unit_vector(ray.direction());
   auto t = 0.5 * (unit_direction.y() + 1.0);            // since y can be between [-1, 1], scaling it to be btw [0, 1]
      
   // linear interpolation : coloval = (1 - y) * initial_value + y * final_value
   return (1 - t) * Color::white + t * Color::sky_blue;
}

int main() {
   // Image setup
   const auto aspect_ratio = 16.0 / 9.0;
   const int image_height = 1080;
   const int image_width = static_cast<int>(image_height * aspect_ratio);
   const int samples_per_pixel = 100;                                            // for getting average value for the color of a pixel based on its surroundings
   const int bounces = 8;                                                       // for the number of reflections

   // World
   Hittable_list world;
   const shared_ptr<Material> material_ground = make_shared<Diffused_Material>(Color::grass);
   // auto material_ground = make_shared<Dielectric>(color(0.8, 0.8, 0.0));
   auto material_middle = make_shared<Diffused_Material>(color(0.1, 0.2, 0.5));
   auto material_left   = make_shared<Dielectric>(1.5);
   auto material_right  = make_shared<Metal>(color(0.8, 0.6, 0.2), 0.0);


   world.add(make_shared<Sphere>(point3D(0, -100.5, -1), 100, material_ground));
   world.add(make_shared<Sphere>(point3D(1, 0, -1), 0.5, material_middle));
   world.add(make_shared<Sphere>(point3D(-0.8, -0.2, -1), 0.3, material_left));
   // world.add(make_shared<Sphere>(point3D(1.0, 0, -1), 0.5, material_right));

   // Setting up camera
   Camera cam;

   // Render
   std::cout << "P3\n";
   std::cout << image_width << " " << image_height << "\n";
   std::cout << "255\n";

   for(int i = image_height - 1; i >= 0; --i) {
      std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
      for(int j = 0; j < image_width; j++) {
         color pixel_color(0, 0, 0);
         // get the total color for this pixel using its surroundings
         for(int iter = 0; iter < samples_per_pixel; iter++) {
            // offsets relative to the left cornder of the image
            auto y_offset = (double) (i + random_double(-1.0, 1.0)) / (image_height - 1);
            auto x_offset = (double) (j + random_double(-1.0, 1.0)) / (image_width - 1);

            auto ray = cam.get_ray(x_offset, y_offset);
            pixel_color += ray_color(ray, world, bounces);
         }

         Color::write_color(std::cout, pixel_color, samples_per_pixel);
      }
   }
   std::cerr << "\nDone.\n";
}