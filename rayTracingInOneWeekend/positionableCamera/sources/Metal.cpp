#include "../headers/Metal.hpp"
#include "../headers/Hittable.hpp"

Metal::Metal(const Color& albe, double fuzziness) : albedo(albe), fuzz(fuzziness){}

bool Metal::scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const{
    Vec3 reflected = reflect(unitVector(rayIn.getDirection()), record.normal);
    scattered = Ray(record.point, reflected + fuzz * randomInUnitSphere());
    attenuation = albedo;
    return dot(scattered.getDirection(), record.normal) > 0;
}
