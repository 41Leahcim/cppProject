#include <iostream>
#include "linkedList.hpp"

#define POP_BACK 1
#define POP_FRONT 1
#define GET 1

const size_t LIST_LENGTH = 100000000;

int main(){
    LinkedList<int> list;
    size_t i;
    std::cout << "Push front\n";
    for(i = 0;i < LIST_LENGTH;i++){
        list.push_front(i);
    }
    std::cout << "List size: " << list.size() << "\n";
#if POP_BACK
    std::cout << "Pop back\n";
    for(i = 0;i < LIST_LENGTH;i++){
        std::cout << list.pop_back() << "\n";
    }
#else
    list.clear();
#endif
    std::cout << "Push back\n";
    for(i = 0;i < LIST_LENGTH;i++){
        list.push_back(i);
    }
#if POP_FRONT
    std::cout << "Pop front\n";
    for(i = 0;i < LIST_LENGTH;i++){
        std::cout << list.pop_front() << "\n";
    }
#else
    list.clear();
#endif
    std::cout << "Push front\n";
    for(i = 0;i < LIST_LENGTH;i++){
        list.push_front(i);
    }
#if GET
    std::cout << "get\n";
    for(i = 0;i < LIST_LENGTH;i++){
        std::cout << list.get(i) << "\n";
    }
#endif
    std::cout << "Tests done.\n";
}
