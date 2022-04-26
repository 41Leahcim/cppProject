#ifndef RTWEEKEND_HPP

#define RTWEEKEND_HPP

#include <limits>
#include <cstdlib>

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degreesToRadians(double degrees){
    return degrees * pi / 180;
}

inline double randomDouble(){
    return rand() / (RAND_MAX + 1.0);
}

inline double randomDouble(double minimum, double maximum){
    return minimum + (maximum - minimum) * randomDouble();
}

inline double clamp(double x, double minimum, double maximum){
    if(x < minimum){
        return minimum;
    }else if(x > maximum){
        return maximum;
    }else{
        return x;
    }
}

// Common headers
#include "HittableList.hpp"
#include "Color.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Dielectric.hpp"

#endif
