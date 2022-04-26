#ifndef HITTABLE_HPP

#define HITTABLE_HPP

#include "Ray.hpp"
#include <memory>

class Material;

struct HitRecord{
    Point3 point;
    Vec3 normal;
    std::shared_ptr<Material> materialPointer;
    double time;
    bool frontFace;

    inline void setFaceNormal(const Ray& ray, const Vec3& outwardNormal){
        frontFace = dot(ray.getDirection(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable{
    public:
        virtual bool hit(const Ray&, const double, const double, HitRecord&) const = 0;
};

#endif
