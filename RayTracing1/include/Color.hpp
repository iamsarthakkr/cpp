#pragma once
#define COLOR_H

#include <iostream>
#include <Vec3D.hpp>



namespace Color {
   void write_color(std::ostream& out, const color& pixel_color, const int samples_per_pixel);
   inline color get_color_scaled(const int r, const int g, const int b) {
      return color(r / 256.0, g / 256.0, b / 256.0);
   }
   const color white(get_color_scaled(256, 256, 256));
   const color black(0, 0, 0);
   const color cyan(get_color_scaled(24, 163, 126));
   const color purple(get_color_scaled(103, 8, 135));
   const color sky_blue(get_color_scaled(60, 129, 193));
   const color grass(get_color_scaled(15, 117, 14));
   // const color sky_blue(132 / 256.0, 180 / 256.0, 255 / 256.0);
}
