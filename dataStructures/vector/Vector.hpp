#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <iostream>

template <class T>
class Vector{
public:
    Vector() : length(0), maxLength(1){
        items = new T[maxLength];
    }
    
    void pushBack(T element){
        items[length++] = std::move(element);
        if(length >= maxLength){
            maxLength =maxLength * 2 + 1;
            T *newArray = new T[maxLength];
            for(size_t i = 0;i < length;i++){
                newArray[i] = std::move(items[i]);
            }
            delete[] items;
            items = newArray;
        }
    }

    T& at(size_t index) const{
        if(index >= length){
            throw "ERROR: Index out of bounds!";
        }else{
            return items[index];
        }
    }

    size_t size() const{
        return length;
    }

    size_t maxSize() const{
        return maxLength;
    }

    void popBack(){
        if(length > 0){
            items[--length].~T();
        }
    }

    T& back(){
        return at(length - 1);
    }

    void clear(){
        while(length > 0){
            popBack();
        }
    }

    ~Vector(){
        clear();
        delete[] items;
    }
private:
    T *items;
    size_t length;
    size_t maxLength;
};

#endif
