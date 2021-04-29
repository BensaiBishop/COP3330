//
// Created by bensa on 26-Nov-20.
//

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"
#include "Node.h"
using std::cout;

//Uses cstddef:
template<class T>
Queue<T>::Queue( ) : front(NULL), back(NULL)
{
    //Intentionally empty.
}

//Uses cstddef:
template<class T>
bool Queue<T>::isEmpty( ) const
{
    return (back == NULL);//front == NULL would also work
}

//Uses cstddef:
template<class T>
void Queue<T>::add(T item, T priority)
{
    Node<T> *temp;
    temp = new Node<T>(item, priority, NULL);
    temp->setData(item);
    temp->setPriority(priority);

    if (front==NULL || priority < front->getPriority())
    {
        temp->setLink(front);
        front = temp;
        //front = back = new Node<T>(item, priority, NULL);//sets both
        //front and back to point to the only node
    }
    else// organizing entries for priority
    {
        back = front;
        while (back->getLink()!=NULL&&back->getLink()->getPriority()<=priority)
            back=back->getLink();
        temp->setLink(back->getLink());
        back->setLink(temp);

        //back->setLink(new Node<T>(item,priority, NULL));
        //back = back->getLink( );

    }
}

//Uses cstdlib and iostream:
template<class T>
T Queue<T>::remove( )
{

    Node<T> *temp;

    if (front == NULL)
    {
        cout << "Error:Removing an item from an empty queue.\n";
        exit(1);
    }
    else{
        char c;
        temp = front;
        c = temp->getData();
        front = front->getLink();
        Node<T> *discard;
        discard = temp;
        delete discard;
        return c;
    }
    /*
    T result = front->getData( );

    Node<T> *discard;
    discard = front;
    front = front->getLink( );
    if (front == NULL) //if you removed the last node
        back = NULL;

    delete discard;

    return result;
     */
}

template<class T>
Queue<T>::~Queue( )
{
    T next;
    while (! isEmpty( ))
        next = remove( );//remove calls delete.
}

//Uses cstddef:
template<class T>
Queue<T>::Queue(const Queue<T>& aQueue)
{
    if (aQueue.isEmpty( ))
        front = back = NULL;
    else
    {
        Node<T> *temp = aQueue.front;//temp moves
        //through the nodes from front to back of aQueue.

        back = new Node<T>(temp->getData( ), NULL);
        front = back;
        //First node created and filled with data.
        //New nodes are now added AFTER this first node.

        temp = temp->getLink( );//temp now points to second
        //node or NULL if there is no second node.

        while (temp != NULL)
        {
            back->setLink(new Node<T>(temp->getData( ), NULL));
            back = back->getLink( );
            temp = temp->getLink( );

        }
        //back->link == NULL
    }
}

//Uses cstddef:
template<class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& rightSide)
{
    if (front == rightSide.front)//if the queues are the same
        return *this;
    else //send left side back to freestore
    {
        T next;
        while (! isEmpty( ))
            next = remove( );//remove calls delete.
    }

    if (rightSide.isEmpty( ))
    {
        front = back = NULL;
        return *this;
    }
    else
    {
        Node<T> *temp = rightSide.front;//temp moves
        //through the nodes from front to back of rightSide.

        back = new Node<T>(temp->getData( ), NULL);
        front = back;
        //First node created and filled with data.
        //New nodes are now added AFTER this first node.

        temp = temp->getLink( );//temp now points to second
        //node or NULL if there is no second node.

        while (temp != NULL)
        {
            back->setLink(
                    new Node<T>(temp->getData( ), NULL));
            back = back->getLink( );
            temp = temp->getLink( );
        }
        //back->link == NULL;

        return *this;
    }
}