#include "../headers/Lambertian.hpp"
#include "../headers/Hittable.hpp"

Lambertian::Lambertian(const Color& albe) : albedo(albe){}

bool Lambertian::scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const{
    Vec3 scatterDirection = record.normal + randomUnitVector();
    if(scatterDirection.nearZero()){
        scatterDirection = record.normal;
    }
    scattered = Ray(record.point, scatterDirection);
    attenuation = albedo;
    return true;
}
