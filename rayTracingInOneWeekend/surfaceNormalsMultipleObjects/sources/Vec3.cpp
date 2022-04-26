#include "../headers/Vec3.hpp"

Vec3::Vec3() : element{0, 0, 0} {}

Vec3::Vec3(double element0, double element1, double element2) : element{element0, element1, element2} {}

double Vec3::getX() const{ return element[0]; }

double Vec3::getY() const{ return element[1]; }

double Vec3::getZ() const{ return element[2]; }

double Vec3::length() const{ return sqrt(lengthSquared()); }

double Vec3::lengthSquared() const{ return element[0] * element[0] + element[1] * element[1] + element[2] * element[2]; }

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
