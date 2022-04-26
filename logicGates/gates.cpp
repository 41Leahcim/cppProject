#include "gates.h"

uint8_t OR(uint8_t a, uint8_t b){
    return (a | b) & 1;
}

uint8_t AND(uint8_t a, uint8_t b){
    return (a & b) & 1;
}

uint8_t NOT(uint8_t in){
    return (~in) & 1;
}

uint8_t XOR(uint8_t a, uint8_t b){
    return (a ^ b) & 1;
}

uint8_t NOR(uint8_t a, uint8_t b){
    return (~(a | b)) & 1;
}

uint8_t NAND(uint8_t a, uint8_t b){
    return (~(a & b)) & 1;
}

uint8_t XNOR(uint8_t a, uint8_t b){
    return (~(a ^ b)) & 1;
}
