#include "../headers/Sphere.hpp"

Sphere::Sphere(){}

Sphere::Sphere(const Point3& cen, const double rad, std::shared_ptr<Material> material)
               : center(cen), radius(rad), materialPointer(material) {}

bool Sphere::hit(const Ray& ray, const double minimumTime, const double maximumTime, HitRecord& record) const{
    Vec3 originCenter(ray.getOrigin() - center);
    double a = ray.getDirection().lengthSquared();
    double halfB = dot(originCenter, ray.getDirection());
    double c = originCenter.lengthSquared() - radius * radius;

    double discriminant = halfB * halfB - a * c;
    if(discriminant < 0){
        return false;
    }
    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range
    double root = (-halfB - sqrtd) / a;
    if(root < minimumTime || root > maximumTime){
        root = (-halfB + sqrtd) / a;
        if(root < minimumTime || root > maximumTime){
            return false;
        }
    }
    record.time = root;
    record.point = ray.at(record.time);
    Vec3 outwardNormal = (record.point - center) / radius;
    record.setFaceNormal(ray, outwardNormal);
    record.materialPointer = materialPointer;
    return true;
}
