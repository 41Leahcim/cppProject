#include "../headers/Sphere.hpp"

Sphere::Sphere(){}

Sphere::Sphere(const Point3& c, const double r) : center(c), radius(r) {}

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
    record.normal = (record.point - center) / radius;

    return true;
}
