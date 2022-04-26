#ifndef LINKED_LIST_HPP

#define LINKED_LIST_HPP

#include <iostream>
#include "node.hpp"

class EmptyListException : public std::exception{
public:
    EmptyListException(const char *message) : errorMessage(message){}
    const char* what() const noexcept{
        return errorMessage;
    }
private:
    const char *errorMessage;
};

template <typename T>
class LinkedList{
public:
    LinkedList() : length(0), head(NULL), tail(NULL){}
    
    size_t size() const{ return length; }

    T& get(size_t index) const{
        if(index >= length){
            throw std::out_of_range("Index out of bounds at LinkedList::get!\n");
        }
        Node<T> *current = head;
        while(index-- > 0){
            current = current->next;
        }
        return current->value;
    }

    void push_back(const T& value){
        Node<T> *newNode = new Node<T>(value, tail);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void push_front(const T& value){
        Node<T> *newNode = new Node<T>(value, NULL, head);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            head->previous = newNode;
            head = newNode;
        }
        length++;
    }

    T pop_back(){
        if(tail == NULL){
            throw EmptyListException("Empty list at LinkedList::pop_back!");
        }
        T value = std::move(tail->value);
        Node<T> *oldTail = tail;
        tail = tail->previous;
        if(tail == NULL){
            head = NULL;
        }else{
            tail->next = NULL;
        }
        length--;
        delete oldTail;
        return value;
    }

    T pop_front(){
        if(head == NULL){
            throw EmptyListException("Empty list at LinkedList::pop_front!");
        }
        T value = std::move(head->value);
        Node<T> *oldHead = head;
        head = head->next;
        if(head == NULL){
            tail = NULL;
        }else{
            head->previous = NULL;
        }
        length--;
        delete oldHead;
        return value;
    }

    void clear(){
        Node<T> *index = head;
        while(index != NULL){
            Node<T> *next = index->next;
            delete index;
            index = next;
        }
        head = NULL;
        tail = NULL;
    }

    ~LinkedList(){
        clear();
    }
private:
    size_t length;
    Node<T> *head;
    Node<T> *tail;
};

#endif
