#ifndef LAMBERTIAN_HPP

#define LAMBERTIAN_HPP

#include "Material.hpp"

class Lambertian : public Material{
public:
    Lambertian(const Color&);
    virtual bool scatter(const Ray&, const HitRecord&, Color&, Ray&) const override;
private:
    Color albedo;
};

#endif
