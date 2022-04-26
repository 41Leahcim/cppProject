#include "../headers/Dielectric.hpp"

#include "../headers/Hittable.hpp"
#include "../headers/common.hpp"

Dielectric::Dielectric(const double indexOfRefraction) : refractionIndex(indexOfRefraction){}

bool Dielectric::scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const{
    attenuation = Color(1, 1, 1);
    double refractionRatio = record.frontFace ? 1 / refractionIndex : refractionIndex;
    
    Vec3 unitDirection = unitVector(rayIn.getDirection());
    double cosTheta = fmin(dot(-unitDirection, record.normal), 1);
    double sinTheta = sqrt(1.0 - cosTheta * cosTheta);

    bool cannotRefract = refractionRatio * sinTheta > 1;
    Vec3 direction;

    if(cannotRefract || reflectance(cosTheta, refractionRatio) > randomDouble()){
        direction = reflect(unitDirection, record.normal);
    }else{
        direction = refract(unitDirection, record.normal, refractionRatio);
    }

    scattered = Ray(record.point, direction);

    return true;
}
