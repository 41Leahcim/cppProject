#include "../headers/Ray.hpp"

Ray::Ray(){}

Ray::Ray(const Point3& orig, const Vec3& dir) :
        origin(orig), direction(dir){
}

Point3 Ray::getOrigin() const{ return origin; }

Vec3 Ray::getDirection() const{ return direction; }

Point3 Ray::at(double time) const{
    return origin + time * direction;
}
