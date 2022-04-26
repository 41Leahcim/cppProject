#include <iostream>
#include <vector>

struct Tester{
    Tester(){
        created++;
    }

    Tester(const Tester& other){
        copies++;
    }

    ~Tester(){
        destroyed++;
    }
    
    static size_t created;
    static size_t copies;
    static size_t destroyed;
};

size_t Tester::created = 0;
size_t Tester::copies = 0;
size_t Tester::destroyed = 0;

int main(){
    const size_t VECTOR_SIZE = 1000000000;
    std::vector<Tester> testers;
    testers.reserve(VECTOR_SIZE);
    for(size_t i = 0;i < VECTOR_SIZE;i++){
        testers.emplace_back();
    }
    testers.clear();
    std::cout << "Created  : " << Tester::created <<
                 "\nCopied   : " << Tester::copies  <<
                 "\nDestroyed: " << Tester::destroyed << "\n";
}
