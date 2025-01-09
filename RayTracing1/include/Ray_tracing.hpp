#pragma once
#define RAY_TRACING_H

#include <cmath>
#include <memory>
#include <limits>
#include <random>

// Common usings
using std::sqrt;
using std::shared_ptr;
using std::make_shared;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
   return degrees * pi / 180.0;
}

// gives a random real number between [min, max)
inline double random_double(double min, double max) {
   static std::mt19937_64 rng(696969);
   static std::uniform_real_distribution<double> distribution(min, max);
   return distribution(rng);
}

// gives a random real number between [0, 1)
inline double random_double() { 
   return random_double(0.0, 1.0); 
}

// clamps a value between [min, max]
inline double clamp(double val, double min, double max) {
   if(val < min) return min;
   if(val > max) return max;
   return val;
}

// Headers
#include "Vec3D.hpp"
#include "Ray.hpp"