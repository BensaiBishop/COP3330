//
// Created by bensa on 26-Nov-20.
//

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "iterator.h"

template<class T>
class Queue
{
public:
    typedef ListIterator<T> Iterator;

    Queue( );
    Queue(const Queue<T>& aQueue);
    Queue<T>& operator =(const Queue<T>& rightSide);
    virtual ~Queue( );

    void add(T item, T priority); //adding priority

    T remove( );

    bool isEmpty( ) const;

    Node<T> * getFront( ) const { return front; }
    Node<T> * getBack( ) const { return back; }

    Iterator begin( ) const { return Iterator(front); }
    Iterator end( ) const { return Iterator( ); }
    //The end iterator has end( ).current == NULL.
    //Note that you cannot dereference this iterator.
private:
    Node<T> *front;//Points to the head of a linked list.
    //Items are removed at the head
    Node<T> *back;//Points to the node at the other end of the linked list.
    //Items are added at this end.
};
#endif //PRIORITY_QUEUE_H
