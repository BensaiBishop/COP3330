//
// Created by bensa on 02/10/2020.
//

#include "Room.h"
#include<iostream>


// return the name of the room
string Room::getName() const {
    return this->Name;
}

//set the name of the room
void Room::setName(string nm) {
    this->Name = nm;
}

//implement the operator for Room
std::ostream& operator<<(std::ostream& outputStream,const Room& room){
    outputStream<<room.Name;
    outputStream<<room.Desc;
    return outputStream;
}

////////////////////////////////////////
// Room class
//set the index of the room to the north
void Room::setIndexRoomToNorth(int indx)
{
    this->IndexOfRoomToNorth=indx;
}

//get the index of the room to the north
int Room::getIndexRoomToNorth() const {
    return this->IndexOfRoomToNorth;
}

//set the index of the room to the south
void Room::setIndexRoomToSouth(int indx)
{
    this->IndexOfRoomToSouth=indx;
}

//get the index of the room to the south
int Room::getIndexRoomToSouth() const {
    return this->IndexOfRoomToSouth;
}

//set the index of the room to the East
void Room::setIndexRoomToEast(int indx)
{
    this->IndexOfRoomToEast=indx;
}

//get the index of the room to the East
int Room::getIndexRoomToEast() const {
    return this->IndexOfRoomToEast;
}

//set the index of the room to the West
void Room::setIndexRoomToWest(int indx)
{
    this->IndexOfRoomToWest=indx;
}

//get the index of the room to the south
int Room::getIndexRoomToWest() const {
    return this->IndexOfRoomToWest;
}
//get the desc
void Room::setRoomDesc(string s){
    this->Desc = s;
}
string Room::getRoomDesc(){
    return this->Desc;
}
