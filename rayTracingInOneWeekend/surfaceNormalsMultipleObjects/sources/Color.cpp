#include "../headers/Color.hpp"

#include <iostream>

void writeColor(std::ostream& output, const Color& pixelColor){
    // write the translated [0, 255] value of each color component.
    output << static_cast<int>(255.999 * pixelColor.getX()) << " "
           << static_cast<int>(255.999 * pixelColor.getY()) << " "
           << static_cast<int>(255.999 * pixelColor.getZ()) << "\n";
}
