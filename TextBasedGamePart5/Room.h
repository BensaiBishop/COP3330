//
// Created by bensa on 02/10/2020.
//

#ifndef UNTITLED8_ROOM_H
#define UNTITLED8_ROOM_H
#include<iostream>
using namespace std;

//room class
class Room
{
private:
    string Desc;
    string Name;
    int IndexOfRoomToNorth;
    int IndexOfRoomToSouth;
    int IndexOfRoomToEast;
    int IndexOfRoomToWest;
public:
    // return the name of the room
    string getName() const ;


    //set the name of the room
    void setName(string nm);
    // set the desc of the room
    void setRoomDesc(string s);
    // get the desc
    string getRoomDesc();

    //set the index of the room to the north
    void setIndexRoomToNorth(int indx);
    //get the index of the room to the north
    int getIndexRoomToNorth() const;

    //set the index of the room to the south
    void setIndexRoomToSouth(int indx);
    //get the index of the room to the south
    int getIndexRoomToSouth() const;

    //set the index of the room to the East
    void setIndexRoomToEast(int indx);
    //get the index of the room to the East
    int getIndexRoomToEast() const;

    //set the index of the room to the West
    void setIndexRoomToWest(int indx);
    //get the index of the room to the West
    int getIndexRoomToWest() const;

    //adding friend
    friend ostream& operator <<(ostream& outputStream, const Room& room);
};
//implement the operator for Room
ostream& operator<<(ostream& outputStream,const Room& room);



#endif //UNTITLED8_ROOM_H
