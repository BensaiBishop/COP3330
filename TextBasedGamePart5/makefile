# TextBaseGame makefile

CC= g++ -std=c++11
TextGame: TextBasedGamePart5.o Room.o User.o
	$(CC) TextBasedGamePart5.o Room.o User.o -o TextGame

TextBasedGamePart5.o: TextBasedGamePart5.cpp
	$(CC) -c TextBasedGamePart5.cpp

Room.o: Room.h Room.cpp
	$(CC) -c Room.h
	$(CC) -c Room.cpp

User.o: User.h User.cpp
	$(CC) -c User.h
	$(CC) -c User.cpp

clean:
	rm -rf *o TextGame
