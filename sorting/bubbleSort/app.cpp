#include <iostream>
#include <vector>
#include <chrono>

using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::duration;
using std::chrono::high_resolution_clock;

template <class T> void bubbleSort(std::vector<T>& list){
    size_t i = 1;
    while(i < list.size()){
        if(list[i - 1] < list[i]){
            T tmp = list[i];
            list[i] = list[i - 1];
            list[i - 1] = tmp;
            if(i > 1){
                i++;
            }else{
                i--;
            }
        }else{
            i++;
        }
    }
}

const size_t max = 2000000000;

int main(){
    std::vector<uint32_t> list;
    time_point<system_clock> start, end;
    duration<float> took;
    for(uint32_t j = max;j > 0;j--){
        list.push_back(j);
    }
    start = high_resolution_clock::now();
    bubbleSort(list);
    end = high_resolution_clock::now();
    took = end - start;
    std::cout << max << ": " << took.count() << "s\n";
    list.clear();
}
