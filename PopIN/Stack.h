//
// Created by bensa on 03-Dec-20.
//

#ifndef POPIN_STACK_H
#define POPIN_STACK_H
#include "Node.h"

template<class T>
class Stack
{
public:
    Stack( );
    //Initializes the object to an empty stack.

    Stack(const Stack<T>& aStack);

    Stack<T>& operator =(const Stack<T>& rightSide);

    virtual ~Stack( );

    void push(T stackFrame);
    //Postcondition: stackFrame has been added to the stack.

    T pop( );

    //PopN will take an int to continue to remove until it has reached that int
    T PopN(int j);

    bool isEmpty( ) const;
    //Returns true if the stack is empty. Returns false otherwise.
private:
    Node<T> *top;
};


#endif //POPIN_STACK_H
