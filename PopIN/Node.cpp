//
// Created by bensa on 03-Dec-20.
//

#include <iostream>
#include "Node.h"
using std::cout;

template<class T>
Node<T>::Node(T theData, Node<T>* theLink) : data(theData), link(theLink)
{}


template<class T>
Node<T> *Node<T>::getLink() {
    return link;
}

template<class T>
const T Node<T>::getData() {
    return data;
}

template<class T>
void Node<T>::setData(const T &theData) {
    data = theData;
}

template<class T>
void Node<T>::setLink(Node<T>* pointer) {
    link = pointer;
}
