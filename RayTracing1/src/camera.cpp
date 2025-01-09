#include "Ray_tracing.hpp"

#include "Camera.hpp"

Camera::Camera() {   
   // Setting virtual viewport dimension (to pass our rays through)
   auto aspect_ratio = 16.0 / 9.0;
   auto viewport_height = 2.0;
   auto viewport_width = viewport_height * aspect_ratio;
   auto focal_length = 1.0;

   // Setting up camera position
   m_origin = Vec3D(0, 0, 0);
   m_horizontal = Vec3D(viewport_width, 0, 0);                                                        // vector for width
   m_vertical = Vec3D(0, viewport_height, 0);                                                         // vector for height
   m_lower_left_corner = m_origin - m_horizontal / 2 - m_vertical / 2 - Vec3D(0, 0, focal_length);    // vector to the lower left corner of the viewport   
}

Ray Camera::get_ray(double x_offset, double y_offset) {
   auto ray_direction = m_lower_left_corner + x_offset * m_horizontal + y_offset * m_vertical;
   return Ray(m_origin, ray_direction);
}