#include "../headers/Color.hpp" 
#include "../headers/Ray.hpp"
#include "../headers/Vec3.hpp"

#include <iostream>

double hitSphere(const Point3& center, double radius, const Ray& ray){
    Vec3 originCenter = ray.getOrigin() - center;
    double a = ray.getDirection().lengthSquared();
    double halfB = dot(originCenter, ray.getDirection());
    double c = originCenter.lengthSquared() - radius * radius;
    double discriminant = halfB * halfB - a * c;
    if(discriminant < 0){
        return -1;
    }else{
        return (-halfB - sqrt(discriminant)) / a;
    }
}

Color rayColor(const Ray& ray){
    double time = hitSphere(Point3(0, 0, -1), 0.5, ray);
    if(time > 0){
        Vec3 normal(unitVector(ray.at(time) - Vec3(0, 0, -1)));
        return 0.5 * Color(normal.getX() + 1, normal.getY() + 1, normal.getZ() + 1);
    }
    Vec3 unitDirection = unitVector(ray.getDirection());
    time = 0.5 * (unitDirection.getY() + 1);
    return (1.0 - time) * Color(1, 1, 1) + time * Color(0.5, 0.7, 1);
}

int main(){
    // set the image properties
    clock_t start = clock(), took;
    const double aspectRatio = 16 / 9.0;
    const uint16_t imageWith = 400;
    const uint16_t imageHeight = static_cast<int>(imageWith / aspectRatio);

    // set the camera properties
    double viewportHeight = 2;
    double viewportWidth = aspectRatio * viewportHeight;
    double focalLength = 1;

    Point3 origin(0, 0, 0);
    Vec3 horizontal(viewportWidth, 0, 0);
    Vec3 vertical(0, viewportHeight, 0);
    Vec3 lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);

    // Render the image
    std::cout << "P3\n" << imageWith << " " << imageHeight << "\n255\n";
    for(int16_t y = imageHeight - 1;y >= 0;y--){
        std::cerr << "\rScanlinesremaining: " << y << " " << std::flush;
        for(uint16_t x = 0;x < imageWith;x++){
            double u = double(x) / (imageWith - 1);
            double v = double(y) / (imageHeight - 1);
            Ray ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
            Color pixelColor = rayColor(ray);
            writeColor(std::cout, pixelColor);
        }
    }
    std::cerr << "\nDone\n";
    took = clock() - start;
    std::cerr << (double)took / CLOCKS_PER_SEC << "\n";
}
