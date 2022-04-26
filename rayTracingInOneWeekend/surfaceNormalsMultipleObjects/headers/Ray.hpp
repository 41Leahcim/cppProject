#ifndef RAY_HPP

#define RAY_HPP

#include "Vec3.hpp"

class Ray{
public:
    Ray();
    Ray(const Point3&, const Vec3&);
    Point3 getOrigin() const;
    Vec3 getDirection() const;
    Point3 at(double) const;
private:
    Point3 origin;
    Vec3 direction;
};

#endif