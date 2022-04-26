#ifndef NODE_HPP

#define NODE_HPP

template <typename T>
struct Node{
    T value;
    Node<T> *previous;
    Node<T> *next;
    Node(const T& val) : value(val), previous(NULL), next(NULL){}
    Node(const T& val, Node<T>* prev) : value(val), previous(prev), next(NULL){}
    Node(const T& val, Node<T>* prev, Node<T>* nex) : value(val), previous(prev), next(nex){}
};

#endif
