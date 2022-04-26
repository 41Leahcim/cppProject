#include "../headers/Color.hpp"
#include "../headers/common.hpp"

#include <iostream>

void writeColor(std::ostream& output, const Color& pixelColor, int samplesPerPixel){
    double red = pixelColor.getX();
    double green = pixelColor.getY();
    double blue = pixelColor.getZ();

    // Divide the color by the number of samples and gamma-correct for gamme=2.0 (exponent = 1 / gamma = 1/2 = sqrt)
    double scale = 1.0 / samplesPerPixel;
    red = sqrt(scale * red);
    green = sqrt(scale * green);
    blue = sqrt(scale * blue);

    // write the translated [0, 255] value of each color component.
    output << static_cast<int>(256 * clamp(red, 0, 0.999)) << " "
           << static_cast<int>(256 * clamp(green, 0, 0.999)) << " "
           << static_cast<int>(256 * clamp(blue, 0, 0.999)) << "\n";
}
