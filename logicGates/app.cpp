#include <iostream>
#include <ctime>
#include "circuits.h"

void accuracyTest_add8(){
    uint8_t a, b;
    bool succeed = true;
    std::cout << "Accuracy test 8-bit addition: ";
    for(uint16_t i = 0;i < (1 << 16) - 1;i++){
        a = i & 255;
        b = i >> 8;
        if((uint8_t)(a + b) != adder_8bit(a, b)){
            std::cout << (uint16_t)a << " + " << (uint16_t)b << " != " << (uint16_t)adder_8bit(a, b) << "\n";
            std::cout << (uint16_t)a << " + " << (uint16_t)b << " = " << a + b << "\n";
            succeed = false;
        }
    }
    if(succeed){
        std::cout << "succeed\n";
    }else{
        std::cout << "failed\n";
    }
}

void accuracyTest_add16(){
    uint16_t a, b;
    bool succeed = true;
    std::cout << "Accuracy test 16-bit addition: ";
    for(uint32_t i = 0;i < (1LU << 32) - 1;i++){
        a = i & ((1 << 16) - 1);
        b = i >> 16;
        if((uint16_t)(a + b) != adder_16bit(a, b)){
            std::cout << a << " + " << b << " != " << adder_16bit(a, b) << "\n";
            std::cout << a << " + " << b << " = " << (uint16_t)(a + b) << "\n";
        }
    }
    if(succeed){
        std::cout << "succeed\n";
    }else{
        std::cout << "failed\n";
    }
}

void performanceTest_add8(){
    const uint32_t calculations = 64000000;
    std::cout << "Performed " << calculations << " 8-bit additions in ";
    clock_t start, took;
    start = clock();
    for(uint32_t i = 0;i < calculations;i++){
        (uint32_t)adder_8bit(i, i >> 8);
    }
    took = clock() - start;
    std::cout << (double)took / CLOCKS_PER_SEC << " seconds.\n";
}

void performanceTest_add16(){
    const uint32_t calculations = 32000000;
    std::cout << "Performed " << calculations << " 16-bit additions in ";
    clock_t start, took;
    start = clock();
    for(uint32_t i = 0;i < calculations;i++){
        adder_16bit(i, i >> 8);
    }
    took = clock() - start;
    std::cout << (double)took / CLOCKS_PER_SEC << " seconds.\n";
}

int main(){
    accuracyTest_add8();
    performanceTest_add8();
    accuracyTest_add16();
    performanceTest_add16();
}
