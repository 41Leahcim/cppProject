#ifndef SPHERE_HPP

#define SPHERE_HPP

#include "Hittable.hpp"
#include "Vec3.hpp"

class Sphere : public Hittable{
public:
    Sphere();
    Sphere(const Point3&, const double, std::shared_ptr<Material> material);
    virtual bool hit(const Ray&, const double, const double, HitRecord&) const override;
private:
    Point3 center;
    double radius;
    std::shared_ptr<Material> materialPointer;
};

#endif
