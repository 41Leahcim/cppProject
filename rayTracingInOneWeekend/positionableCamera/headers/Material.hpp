#ifndef MATERIAL_HPP

#define MATERIAL_HPP

#include "Ray.hpp"

struct HitRecord;

class Material{
public:
    virtual bool scatter(const Ray&, const HitRecord&, Color&, Ray&) const = 0;
};

#endif
