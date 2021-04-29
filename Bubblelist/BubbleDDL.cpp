
/* Name: Benjamin Bishop
Date: 20 Nov. 2020
Section: 0011
Assignment: Linked Program List
Due Date: 22 Nov. 2020
About this project: Bubble sort a linked list
All work below was performed by Benjamin Bishop */

// students - you need to put program header here

/*The following comment is a copy of my g++ test run
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DoublyLinkedIntNode.h"


//bubble sort
void bubbleSort(DoublyLinkedIntNodePtr &head);

//function to print list
void printList(DoublyLinkedIntNodePtr &head);

//function to create new DLL
void headInsert(DoublyLinkedIntNodePtr& head, int theData);

/*
//swap function
template<class T>
void swapValues(T &a, T &b);
*/

/////////////////////////////////////////////////////////
int main() {
    //establishing random number
    srand(time(0));
    short int num;

    //initialize DLL
    DoublyLinkedIntNode* root = new DoublyLinkedIntNode();

    //fill list with random numbers
    for (int i = 0; i < 10; ++i) {
        num = rand()+1;
        headInsert(root, num);
    }

    //print unsorted elements
    std::cout<<"Unsorted List:\n "; printList(root);
    std::cout<<std::endl;

    //sort the elements
    bubbleSort(root);
    std::cout<<"Sorted in ascending order:\n "; printList(root);
    return 0;
}
/////////////////////////////////////////////////////////

//bubble sort
void bubbleSort(DoublyLinkedIntNodePtr &head){
//my bubble sort is pushing in a zero in the beginning. Why?
    DoublyLinkedIntNodePtr t1,t2,t3;
    int temp;
    t1 = head;
    for (int k = 0; k < 10-1; ++k) {

        t2 = head;
        t3 = t2->getNextLink();
        for (int j = 0; j < 10-k-1 ;j++){
            if (t2->getData() > t3->getData()){

                //swapValues(t2,t3);
                temp=t2->getData();
                t2->setData(t3->getData());
                t3->setData(temp);

            }
            t2 = t3;
            t3 = t3->getNextLink();
        }
        t1 = t1->getNextLink();
    }
}

/*
//swapfunction
template<class T>
void swapValues(T& a, T& b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}
*/

void printList(DoublyLinkedIntNodePtr &head){
    DoublyLinkedIntNodePtr temp = head;
    for (int i = 0; i < 10; ++i) {
        std::cout<<temp->getData()<<", ";
        temp = temp->getNextLink();
    }
}

//create new DLL
void headInsert(DoublyLinkedIntNodePtr& head, int theData){
    DoublyLinkedIntNode* newHead = new DoublyLinkedIntNode(theData, NULL, head);
    head->setPreviousLink(newHead);
    head = newHead;
}