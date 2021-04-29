//
// Created by bensa on 20-Nov-20.
//

#ifndef BUBBLELIST_DOUBLYLINKEDINTNODE_H
#define BUBBLELIST_DOUBLYLINKEDINTNODE_H
//provided by class
class DoublyLinkedIntNode
{
public:
    //constructor
    DoublyLinkedIntNode ( ){}
    //constructor that takes parameters
    DoublyLinkedIntNode (int theData, DoublyLinkedIntNode* previous,
                         DoublyLinkedIntNode* next)
            : data(theData), nextLink(next), previousLink(previous) {}
    DoublyLinkedIntNode* getNextLink( ) const
    { return nextLink; }
    DoublyLinkedIntNode* getPreviousLink( ) const
    { return previousLink; }
    int getData( ) const
    { return data; }
    void setData(int theData)
    { data = theData; }
    void setNextLink(DoublyLinkedIntNode* pointer)
    { nextLink = pointer; }
    void setPreviousLink(DoublyLinkedIntNode* pointer)
    { previousLink = pointer; }
private:
    int data;
    DoublyLinkedIntNode *nextLink;
    DoublyLinkedIntNode *previousLink;
};

typedef DoublyLinkedIntNode* DoublyLinkedIntNodePtr;

#endif //BUBBLELIST_DOUBLYLINKEDINTNODE_H
