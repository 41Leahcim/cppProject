#ifndef VEC3_HPP

#define VEC3_HPP

#include <iostream>
#include <cmath>

using std::sqrt;

class Vec3{
public:
    Vec3();
    Vec3(double, double, double);

    double getX() const;
    double getY() const;
    double getZ() const;
    double length() const;
    double lengthSquared() const;

    Vec3 operator-() const;
    double operator[](const size_t) const;
    double& operator[](const size_t);
    Vec3& operator+=(const Vec3&);
    Vec3& operator*=(const double);
    Vec3& operator/=(const double);
private:
    double element[3];
};

// define aliases for 3D points and RGB colors
using Point3 = Vec3;
using Color = Vec3;

// vec3 Utility Functions
inline std::ostream& operator<<(std::ostream& output, const Vec3& vector){
    return output << vector.getX() << " " << vector.getY() << " " << vector.getZ();
}

inline Vec3 operator+(const Vec3& left, const Vec3& right){
    return Vec3(left.getX() + right.getX(), left.getY() + right.getY(), left.getZ() + right.getZ());
}

inline Vec3 operator-(const Vec3& left, const Vec3& right){
    return Vec3(left.getX() - right.getX(), left.getY() - right.getY(), left.getZ() - right.getZ());
}

inline Vec3 operator*(const Vec3& left, const Vec3& right){
    return Vec3(left.getX() * right.getX(), left.getY() * right.getY(), left.getZ() * right.getZ());
}

inline Vec3 operator*(const double left, const Vec3& right){
    return Vec3(left * right.getX(), left * right.getY(), left * right.getZ());
}

inline Vec3 operator*(const Vec3& left, const double right){
    return right * left;
}

inline Vec3 operator/(const Vec3& left, double right){
    return (1 / right) * left;
}

inline double dot(const Vec3& left, const Vec3& right){
    return left.getX() * right.getX() + left.getY() * right.getY() + left.getZ() * right.getZ();
}

inline Vec3 unitVector(const Vec3& vector){
    return vector / vector.length();
}

#endif
