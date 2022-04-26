// stuck at the end of the chapter, generates weird images (See ppm file)
#include <iostream>

#include "../headers/common.hpp"

Color rayColor(const Ray& ray, const Hittable& world, uint16_t depth){
    if(depth == 0){
        return Color(0, 0, 0);
    }
    HitRecord record;
    if(world.hit(ray, 0.001, infinity, record)){
        Ray scattered;
        Color attenuation;
        if(record.materialPointer->scatter(ray, record, attenuation, scattered)){
            return attenuation * rayColor(scattered, world, depth - 1);
        }else{
            return Color(0, 0, 0);
        }
    }
    Vec3 unitDirection = unitVector(ray.getDirection());
    double time = 0.5 * (unitDirection.getY() + 1);
    return (1.0 - time) * Color(1, 1, 1) + time * Color(0.5, 0.7, 1);
}

int main(){
    // set the image properties
    clock_t start = clock(), took;
    const double aspectRatio = 16 / 9.0;
    const uint16_t imageWith = 400;
    const uint16_t imageHeight = static_cast<int>(imageWith / aspectRatio);
    const uint8_t samplesPerPixel = 100;
    const uint8_t depth = 50;

    // set the World properties
    HittableList world;
    std::shared_ptr<Material> materialGround = std::make_shared<Lambertian>(Color(0.8, 0.8, 0));
    std::shared_ptr<Material> materialCenter = std::make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
    std::shared_ptr<Material> materialLeft = std::make_shared<Dielectric>(1.5);
    std::shared_ptr<Material> materialRight = std::make_shared<Metal>(Color(0.8, 0.6, 0.2), 0);

    world.add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100, materialGround));
    world.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5, materialCenter));
    world.add(std::make_shared<Sphere>(Point3(-1, 0, -1), 0.5, materialLeft));
    world.add(std::make_shared<Sphere>(Point3(-1, 0, -1), -0.45, materialLeft));
    world.add(std::make_shared<Sphere>(Point3(1, 0, -1), 0.5, materialRight));

    // create a camer
    Camera camera(Point3(-2, 2, 1), Point3(0, 0, -1), Vec3(0, 1, 0), 90, aspectRatio);

    // Render the image
    std::cout << "P3\n" << imageWith << " " << imageHeight << "\n255\n";
    for(int16_t y = imageHeight - 1;y >= 0;y--){
        std::cerr << "\rScanlinesremaining: " << y << " " << std::flush;
        for(uint16_t x = 0;x < imageWith;x++){
            Color pixelColor(0, 0, 0);
            for(int sample = 0;sample < samplesPerPixel;sample++){
                double u = (x + randomDouble()) / (imageWith - 1);
                double v = (y + randomDouble()) / (imageHeight - 1);
                Ray ray = camera.getRay(u, v);
                pixelColor += rayColor(ray, world, depth);
            }
            writeColor(std::cout, pixelColor, samplesPerPixel);
        }
    }
    std::cerr << "\nDone\n";
    took = clock() - start;
    std::cerr << (double)took / CLOCKS_PER_SEC << "\n";
}
