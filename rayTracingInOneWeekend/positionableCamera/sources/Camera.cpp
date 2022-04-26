#include "../headers/Camera.hpp"

Camera::Camera(Point3 lookFrom, Point3 lookAt, Vec3 viewUp, double verticalFieldOfView, double aspectRatio){
    double theta = degreesToRadians(verticalFieldOfView);
    double height = tan(theta / 2);
    double viewportHeight = 2 * height;
    double viewportWidth = aspectRatio * viewportHeight;

    Vec3 w = unitVector(lookFrom - lookAt);
    Vec3 u = unitVector(cross(viewUp, w));
    Vec3 v = cross(w, u);

    origin = lookFrom;
    horizontal = viewportWidth * u;
    vertical = viewportHeight * v;
    lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - w;
}

Ray Camera::getRay(double s, double t) const{
    return Ray(origin, lowerLeftCorner + s * horizontal + t * vertical - origin);
}
