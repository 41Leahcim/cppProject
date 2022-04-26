#ifndef TESTER_HPP

#define TESTER_HPP

#include <iostream>

class Tester{
public:
    Tester(){
        creations++;
    }
    Tester(size_t id){
        creations++;
    }

    Tester(const Tester& other){
        kopies++;
    }

    ~Tester(){
        deletions++;
    }
    static size_t creations;
    static size_t kopies;
    static size_t deletions;
};

size_t Tester::creations = 0;
size_t Tester::kopies = 0;
size_t Tester::deletions = 0;

#endif
