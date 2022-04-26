#include "../headers/Vec3.hpp"
#include "../headers/common.hpp"

Vec3::Vec3() : element{0, 0, 0} {}

Vec3::Vec3(double element0, double element1, double element2) : element{element0, element1, element2} {}

double Vec3::getX() const{ return element[0]; }

double Vec3::getY() const{ return element[1]; }

double Vec3::getZ() const{ return element[2]; }

double Vec3::length() const{ return sqrt(lengthSquared()); }

double Vec3::lengthSquared() const{ return element[0] * element[0] + element[1] * element[1] + element[2] * element[2]; }

bool Vec3::nearZero() const{
    // return true if the vector is close to zero in all dimensions
    bool result = true;
    for(uint8_t i = 0;i < 3;i++){
        result = result && fabs(element[i]) < 1e-8;
    }
    return result;
}

Vec3 Vec3::operator-() const{ return Vec3(-element[0], element[1], element[2]); }

double Vec3::operator[](const size_t i) const{
    if(i < 3){
        return element[i];
    }else{
        throw "ERROR AT VEC3[]: Index out of bounds!\n";
    }
}

double& Vec3::operator[](const size_t i){
    if(i < 3){
        return element[i];
    }else{
        throw "ERROR AT VEC3[]: Index out of bounds!\n";
    }
}

Vec3& Vec3::operator+=(const Vec3& other){
    element[0] += other.element[0];
    element[1] += other.element[1];
    element[2] += other.element[2];
    return *this;
}

Vec3& Vec3::operator*=(const double times){
    element[0] *= times;
    element[1] *= times;
    element[2] *= times;
    return *this;
}

Vec3& Vec3::operator/=(const double times){
    element[0] /= times;
    element[1] /= times;
    element[2] /= times;
    return *this;
}

inline Vec3 Vec3::random(){
    return Vec3(randomDouble(), randomDouble(), randomDouble());
}

inline Vec3 Vec3::random(const double minimum, const double maximum){
    return Vec3(randomDouble(minimum, maximum), randomDouble(minimum, maximum), randomDouble(minimum, maximum));
}

Vec3 randomInUnitSphere(){
    Vec3 point = Vec3::random(-1, 1);
    while(point.lengthSquared() >= 1){
        point = Vec3::random(-1, 1);
    }
    return point;
}

Vec3 randomUnitVector(){
    return unitVector(randomInUnitSphere());
}

Vec3 randomInHemisphere(const Vec3& normal){
    Vec3 inUnitSphere = randomInUnitSphere();
    if(dot(inUnitSphere, normal) > 0){
        return inUnitSphere;
    }else{
        return -inUnitSphere;
    }
}

Vec3 reflect(const Vec3& v, const Vec3& n){
    return v - 2 * dot(v, n) * n;
}

Vec3 refract(const Vec3& uv, const Vec3& n, const double etaiOverEtat){
    double cosTheta = fmin(dot(-uv, n), 1);
    Vec3 rOutPerp = etaiOverEtat * (uv + cosTheta * n);
    Vec3 rOutParallel = -sqrt(fabs(1.0 - rOutPerp.lengthSquared())) * n;
    return rOutPerp + rOutParallel;
}
