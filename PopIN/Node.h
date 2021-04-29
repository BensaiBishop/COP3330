//
// Created by bensa on 03-Dec-20.
//

#ifndef POPIN_NODE_H
#define POPIN_NODE_H


template<class T>
class Node
{
public:
    Node(T theData, Node<T>* theLink);
    Node<T>* getLink( );
    const T getData( );
    void setData(const T& theData);
    void setLink(Node<T>* pointer);
private:
    T data;
    Node<T> *link;
};


#endif //POPIN_NODE_H
