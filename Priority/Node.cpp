//
// Created by bensa on 26-Nov-20.
//

#include <iostream>
#include "Node.h"
using std::cout;

template<class T>
Node<T>::Node(T theData, T thePriority, Node<T>* theLink) : data(theData), link(theLink), priority(thePriority)
{}


template<class T>
Node<T> *Node<T>::getLink() {
    return link;
}

template<class T>
const T Node<T>::getData() {
    return data;
}
//get priority
template<class T>
const T Node<T>::getPriority(){
    return priority;
}

template<class T>
void Node<T>::setData(const T &theData) {
    data = theData;
}
//set priority
template<class T>
void Node<T>::setPriority(const T &thePriority){
    priority = thePriority;
}

template<class T>
void Node<T>::setLink(Node<T>* pointer) {
    link = pointer;
}