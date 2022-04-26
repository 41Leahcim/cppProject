#ifndef CAMERA_HPP

#define CAMERA_HPP

#include "common.hpp"

class Camera{
public:
    Camera(Point3 lookFrom, Point3 lookAt, Vec3 viewUp, double verticalFieldOfView, double aspectRatio);
    Ray getRay(double, double) const;
private:
    Point3 origin;
    Point3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;
};

#endif
