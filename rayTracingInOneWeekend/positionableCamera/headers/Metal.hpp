#ifndef METAL_HPP

#define METAL_HPP

#include "Material.hpp"

class Metal : public Material{
public:
    Metal(const Color&, const double);

    virtual bool scatter(const Ray&, const HitRecord&, Color&, Ray&) const override;
private:
    Color albedo;
    double fuzz;
};

#endif
