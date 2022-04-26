#include <unistd.h>

#include "Tester.hpp"
#include "Vector.hpp"

int main(){
    Vector<Tester> testers;
    Vector<Tester> testers2;
    Vector<Tester> testers3;
    Vector<Tester> testers4;
    size_t i;
    for(i = 0;i < UINT32_MAX;i++){
        testers.pushBack(i);
        testers2.pushBack(i);
        testers3.pushBack(i);
        testers4.pushBack(i);
        testers.at(i);
    }

    std::cout << testers.size() << " / " << testers.maxSize() << "\n";

    sleep(1);

    while(testers.size() > 0){
        testers.popBack();
    }
    
    std::cout << testers.size() << " / " << testers.maxSize() << "\n";

    sleep(1);

    try{
        testers.at(0);
    }catch(const char *errorMessage){
        std::cout << errorMessage << "\n";
    }

    sleep(1);
    
    std::cout << "Creations: " << Tester::creations <<
                 "\nKopies: " << Tester::kopies <<
                 "\ndeletions: " << Tester::deletions << "\n";
}
