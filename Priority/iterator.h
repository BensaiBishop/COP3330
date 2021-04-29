//
// Created by bensa on 26-Nov-20.
//

#ifndef PRIORITY_ITERATOR_H
#define PRIORITY_ITERATOR_H
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "Node.h"

template<class T>
class ListIterator
{
public:
    ListIterator( ) : current(NULL) {}

    ListIterator(Node<T>* initial) : current(initial) {}

    const T& operator *( ) const { return current->getData( ); }
    //Precondition: Not equal to the default constructor object,
    //that is, current != NULL.

    ListIterator& operator ++( ) //Prefix form
    {
        current = current->getLink( );
        return *this;
    }

    ListIterator operator ++(int) //Postfix form
    {
        ListIterator startVersion(current);
        current = current->getLink( );
        return startVersion;
    }

    bool operator ==(const ListIterator& rightSide) const
    { return (current == rightSide.current); }

    bool operator !=(const ListIterator& rightSide) const
    { return (current != rightSide.current); }

    //The default assignment operator and copy constructor
    //should work correctly for ListIterator,
private:
    Node<T> *current;
};

#endif //PRIORITY_ITERATOR_H
