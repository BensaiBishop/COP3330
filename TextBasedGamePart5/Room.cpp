//
// Created by bensa on 02/10/2020.
//

#include "Room.h"
#include<iostream>
using namespace std;

// return the name of the room
string Room::getName() const {
    return this->Name;
}

//set the name of the room
void Room::setName(string nm) {
    this->Name = nm;
}

//implement the operator for Room
ostream& operator<<(ostream& outputStream,const Room& room){
    outputStream<<room.Name;
    outputStream<<room.Desc;
    return outputStream;
}
