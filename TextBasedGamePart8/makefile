# TextBaseGame makefile

CC= g++ -std=c++11
TextGame: TextBasedGamePart8.o Room.o User.o SuperUser.o
	$(CC) TextBasedGamePart8.o Room.o User.o SuperUser.o -o TextGame

TextBasedGamePart8.o: TextBasedGamePart8.cpp
	$(CC) -c TextBasedGamePart8.cpp

Room.o: Room.h Room.cpp
	$(CC) -c Room.h
	$(CC) -c Room.cpp

User.o: User.h User.cpp
	$(CC) -c User.h
	$(CC) -c User.cpp

SuperUser.o: SuperUser.h SuperUser.cpp
	$(CC) -c SuperUser.h
	$(CC) -c SuperUser.cpp

clean:
	rm -rf *o TextGame
