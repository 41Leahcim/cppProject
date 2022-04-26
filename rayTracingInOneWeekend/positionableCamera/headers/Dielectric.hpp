#ifndef DIELECTRIC_HPP

#define DIELECTRIC_HPP

#include "Material.hpp"

class Dielectric : public Material{
public:
    Dielectric(const double);

    virtual bool scatter(const Ray&, const HitRecord&, Color&, Ray&) const override;
private:
    double refractionIndex;

    static double reflectance(double cosine, double reflectanceIndex){
        // Use Schlick's approximation for reflectance
        double r0 = (1 - reflectanceIndex) / (1 + reflectanceIndex);
        r0 = r0 * r0;
        return r0 + (1 - r0) * pow(1 - cosine, 5);
    }
};

#endif
