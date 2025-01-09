#include "Ray_tracing.hpp"
#include "Color.hpp"

#include <iostream>

void Color::write_color(std::ostream& out, const color& pixel_color, const int samples_per_pixel) {
   auto r = pixel_color.x();
   auto g = pixel_color.y();
   auto b = pixel_color.z();

   // factoring for number of sources for this pixel and gamma correction
   auto factor = 1.0 / samples_per_pixel;
   r = sqrt(r * factor);
   g = sqrt(g * factor);
   b = sqrt(b * factor);

   // Translate each value to [0, 255]
   r = static_cast<int>(256 * clamp(r, 0.0, 0.999));
   g = static_cast<int>(256 * clamp(g, 0.0, 0.999));
   b = static_cast<int>(256 * clamp(b, 0.0, 0.999));
   
   out << r << ' ' << g << ' ' << b << '\n';
}
