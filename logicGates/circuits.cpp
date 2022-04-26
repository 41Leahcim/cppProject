#include "circuits.h"

uint8_t halfAdder(uint8_t a, uint8_t b){
    uint8_t sum, carry;
    sum = XOR(a, b);
    carry = AND(a, b);
    return (carry << 1) | sum;
}

uint8_t fullAdder(uint8_t a, uint8_t b, uint8_t c){
    uint8_t sum, carry;
    sum = (a ^ b ^ c) & 1;
    carry = ((c & (a | b)) | (a & b)) & 1;
    return (carry << 1) | sum;
}

inline uint64_t adder(const uint64_t a, const uint64_t b, const uint8_t size){
    uint64_t result;
    uint8_t carry, i;
    carry = halfAdder(a, b);
    result = carry & 1;
    for(i = 1;i < size;i++){
        carry = fullAdder(a >> i, b >> i, carry >> 1);
        result |= (carry & 1) << i;
    }
    return result;
}

uint8_t adder_8bit(const uint8_t a, const uint8_t b){
    return adder(a, b, 8);
}

uint16_t adder_16bit(const uint16_t a, const uint16_t b){
    return adder(a, b, 16);
}

uint32_t adder_32bit(const uint32_t a, const uint32_t b){
    return adder(a, b, 32);
}

uint64_t adder_64bit(const uint64_t a, uint64_t b){
    return adder(a, b, 64);
}
