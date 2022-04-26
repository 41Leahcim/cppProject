#ifndef HITTABLE_HPP

#define HITTABLE_HPP

#include "Ray.hpp"

struct HitRecord{
    Point3 point;
    Vec3 normal;
    double time;
};

class Hittable{
    public:
        virtual bool hit(const Ray&, const double, const double, HitRecord&) const = 0;
};

#endif
