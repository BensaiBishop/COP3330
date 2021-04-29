CC= g++ -std=c++11

start: queue.o Node.o PriorityQ.o  
	$(CC) queue.o Node.o PriorityQ.o -o Sort

Node.o: Node.cpp Node.h 
	$(CC) -c Node.cpp 
	$(CC) -c Node.h
	
queue.o: queue.cpp queue.h 
	$(CC) -c queue.cpp 
	$(CC) -c queue.h	

PriorityQ.o: PriorityQ.cpp iterator.h 
	$(CC) -c PriorityQ.cpp 
	$(CC) -c iterator.h
	
clean:
	rm -rf *o sort
