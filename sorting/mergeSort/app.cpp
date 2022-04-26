#include <iostream>
#include <vector>
#include <chrono>

using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::duration;
using std::chrono::high_resolution_clock;

template <class T> void mergeSort(std::vector<T>& list){
    if(list.size() > 2){
        std::vector<T> list2(list.begin(), list.begin() + list.size() / 2);
        std::vector<T> list3(list.begin() + list.size() / 2, list.end());

        mergeSort(list2);
        mergeSort(list3);

        size_t i = 0, j = 0, k = 0;
        while(i < list2.size() && j < list3.size()){
            if(list2[i] <= list3[j]){
                list[k++] = list2[i++];
            }else{
                list[k++] = list3[j++];
            }
        }
        while(i < list2.size()){
            list[k++] = list2[i++];
        }
        while(j < list3.size()){
            list[k++] = list3[j++];
        }
    }else if(list.size() == 2 && list[0] > list[1]){
        T tmp = list[0];
        list[0] = list[1];
        list[1] = tmp;
    }
}

//const uint32_t max = 450000000;
//const uint32_t max =   1000000;
const uint32_t max =   30000000;

int main(){
    std::vector<uint32_t> list;
    time_point<system_clock> start, end;
    duration<float> took;
    //for(uint32_t i = 1000000;i < 1000000000;i += 1000000){
    for(uint32_t j = max;j > 0;j--){
        list.push_back(j);
    }
    start = high_resolution_clock::now();
    mergeSort(list);
    end = high_resolution_clock::now();
    took = end - start;
    std::cout << max << ": " << took.count() << "s\n";
    list.clear();
//    }
}
