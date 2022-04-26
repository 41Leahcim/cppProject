#ifndef SPHERE_HPP

#define SPHERE_HPP

#include "Hittable.hpp"
#include "Vec3.hpp"

class Sphere : public Hittable{
public:
    Sphere();
    Sphere(const Point3&, const double);
    virtual bool hit(const Ray&, const double, const double, HitRecord&) const override;
private:
    Point3 center;
    double radius;
};

#endif
