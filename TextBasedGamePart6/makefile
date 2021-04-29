# TextBaseGame makefile

CC= g++ -std=c++11
TextGame: TextBasedGamePart6.o Room.o User.o
	$(CC) TextBasedGamePart6.o Room.o User.o -o TextGame

TextBasedGamePart6.o: TextBasedGamePart6.cpp
	$(CC) -c TextBasedGamePart6.cpp

Room.o: Room.h Room.cpp
	$(CC) -c Room.h
	$(CC) -c Room.cpp

User.o: User.h User.cpp
	$(CC) -c User.h
	$(CC) -c User.cpp

clean:
	rm -rf *o TextGame
