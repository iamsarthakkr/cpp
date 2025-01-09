#pragma once
#define CAMERA_H

#include "Ray_tracing.hpp"

class Camera {
public:
   Camera();
   Ray get_ray(double x_offset, double y_offset);

private:
   Vec3D m_origin;
   Vec3D m_lower_left_corner;
   Vec3D m_horizontal;
   Vec3D m_vertical;
};