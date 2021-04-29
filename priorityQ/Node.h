//
// Created by bensa on 26-Nov-20.
//

#ifndef PRIORITY_NODE_H
#define PRIORITY_NODE_H


template<class T>
class Node
{
public:
    Node(T theData, T thePriority, Node<T>* theLink);
    Node<T>* getLink( );
    const T getData( );
    const T getPriority( );  //creating set and get for priority
    void setPriority(const T& thePriority);
    void setData(const T& theData);
    void setLink(Node<T>* pointer);
private:
    T priority;     //new priority element
    T data;
    Node<T> *link;
};



#endif //PRIORITY_NODE_H
