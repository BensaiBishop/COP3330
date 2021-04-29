/* Name: Benjamin Bishop
Date: 6 Nov. 2020
Section: 0011
Assignment: Priority queue
Due Date: 26 Nov. 2020
About this project: this is a priority queue. where 0 is the highest priority and any greater number is of lower priority.
Assumptions: User should be able to input a value and assign it a priority. then remove elements from the stack with the highest
 priority being removed first.

All work below was performed by Benjamin Bishop */

// students - you need to put program header here

/*The following comment is a copy of my g++ test run
*/

#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include "queue.h"
#include "queue.cpp"
#include "iterator.h"

int main() {
    Queue<char> q;
    int opt, priority;
    char data;
    while (opt != 3)
    {
        std::cout << "press 1 to insert an element\n"
                     "press 2 to remove an element\n"
                     "or enter 3 to quit\n";
        std::cin >> opt;

        if (opt == 1)
        {
            std::cout << "Input element to be added: ";
            std::cin >> data;
            std::cout << "enter its priority: ";
            std::cin >> priority;
            q.add(data, priority);
            std::cout << std::endl;

        }
        else if (opt == 2)
        {
            std::cout << q.remove() << std::endl;
        }
        else if (opt == 3)
        {
            exit(0);
        }
        else
        {
            std::cout<< "invalid opt."<<std::endl;
        }
    }
    return 0;
}


