# BubbleDDL makefile
# DoublyLinkedIntNode.h

CC= g++ -std=c++11

Sort: BubbleDDL.o  
	$(CC) BubbleDDL.o -o Sort

BubbleDDL.o: BubbleDDL.cpp DoublyLinkedIntNode.h 
	$(CC) -c BubbleDDL.cpp 
	$(CC) -c DoublyLinkedIntNode.h
#	
#DoublyLinkedIntNode.o: DoublyLinkedIntNode.h
#	$(CC) -c DoublyLinkedIntNode.h
#

clean:
	rm -rf *o sort
