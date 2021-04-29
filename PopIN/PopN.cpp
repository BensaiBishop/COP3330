
/* Name: Benjamin Bishop
Date: 6 Nov. 2020
Section: 0011
Assignment: Priority queue
Due Date: 26 Nov. 2020
About this project: This is the Stack files modified with the PopN function. Should be able to enter in the five elements
 then be prompted to remove a number of elements from the stack. It should display all elements removed and is the removed
 elements exceed the capacity of the stack it should return and error.

All work below was performed by Benjamin Bishop */

// students - you need to put program header here

/*The following comment is a copy of my g++ test run
 bbishop@linprog8.cs.fsu.edu:~>cd COP3330/Pop
bbishop@linprog8.cs.fsu.edu:~/COP3330/Pop>ls
iterator.h  makefile  Node.cpp  Node.h  PopN.cpp  Stack.cpp  Stack.h
bbishop@linprog8.cs.fsu.edu:~/COP3330/Pop>make
g++ -std=c++11 -c Stack.cpp
g++ -std=c++11 -c Stack.h
g++ -std=c++11 -c Node.cpp
g++ -std=c++11 -c Node.h
g++ -std=c++11 -c PopN.cpp
g++ -std=c++11 -c iterator.h
g++ -std=c++11 Stack.o Node.o PopN.o -o pop
bbishop@linprog8.cs.fsu.edu:~/COP3330/Pop>pop
enter 5 integers
1
enter element
2
enter element
3
enter element
4
enter element
5
enter element
Now enter the number of elements you would like removed from the stackThis utilizes the PopN function
1
5<-removed element
2
4<-removed element
3<-removed element
2
2<-removed element
1<-removed element
Again? (y/n)
y
enter 5 integers
1
enter element
2
enter element
3
enter element
4
enter element
5
enter element
Now enter the number of elements you would like removed from the stackThis utilizes the PopN function
5
5<-removed element
4<-removed element
3<-removed element
2<-removed element
1<-removed element
Again? (y/n)
y
enter 5 integers
1
enter element
2
enter element
3
enter element
4
enter element
5
enter element
Now enter the number of elements you would like removed from the stackThis utilizes the PopN function
3
5<-removed element
4<-removed element
3<-removed element
3
2<-removed element
1<-removed element
Error: popping an empty stack.
bbishop@linprog8.cs.fsu.edu:~/COP3330/Pop>
*/

#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "iterator.h"

int main() {

    char ans;
    int k=0;
    do {
        Stack<int> s;
        std::cout << "enter 5 integers\n";
        //1
        std::cin >> k;
        s.push(k);
        std::cout << "enter element"<< std::endl;
        //2
        std::cin >> k;
        s.push(k);
        std::cout << "enter element"<< std::endl;
        //3
        std::cin >> k;
        s.push(k);
        std::cout << "enter element"<< std::endl;
        //4
        std::cin >> k;
        s.push(k);
        std::cout << "enter element"<< std::endl;
        //5
        std::cin >> k;
        s.push(k);
        std::cout << "enter element"<< std::endl;

        std::cout << "Now enter the number of elements you would like removed from the stack"
                     "This utilizes the PopN function\n";
        while (! s.isEmpty()) {
            int j;
            std::cin >> j;
            s.PopN(j);
        }
        std::cout <<"Again? (y/n)\n";
        std::cin >> ans;
        std::cin.ignore(10000, '\n');
    }while (ans != 'n' && ans != 'N');
    return 0;
}
