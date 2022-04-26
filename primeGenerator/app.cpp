// this program generates, prints, and saves all 32 bit primes in 272.535 seconds
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

const uint32_t ARRAY_LENGTH = UINT32_MAX;

int main(){
    clock_t start = clock(), took;
    std::vector<bool> primes(ARRAY_LENGTH);
    // 275.65 made room for uninitialized bools
    uint64_t i;
    uint32_t j;
    primes[0] = 0;
    primes[1] = 0;
    for(j = 2;j < ARRAY_LENGTH;j++){
        primes[j] = 1;
    }
    j = 2;
    std::ofstream file("primes.txt");
    while(j < ARRAY_LENGTH){
        for(i = j + j;i < ARRAY_LENGTH;i += j){
            primes[i] = 0;
        }
        std::cout << j << "\n";
        file << j << "\n";
        while(++j < ARRAY_LENGTH && !primes[j]);
    }
    file.close();
    took = clock() - start;
    std::cout << "Generating, printing and storing all primes, took " << (double)took / CLOCKS_PER_SEC << " seconds.\n";
}
