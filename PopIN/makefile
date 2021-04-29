CC= g++ -std=c++11

start: Stack.o Node.o PopN.o  
	$(CC) Stack.o Node.o PopN.o -o pop

Node.o: Node.cpp Node.h 
	$(CC) -c Node.cpp 
	$(CC) -c Node.h
	
Stack.o: Stack.cpp Stack.h 
	$(CC) -c Stack.cpp 
	$(CC) -c Stack.h	

PopN.o: PopN.cpp iterator.h 
	$(CC) -c PopN.cpp 
	$(CC) -c iterator.h
	
clean:
	rm -rf *o pop
