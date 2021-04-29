//
// Created by bensa on 02/10/2020.
//

#include "User.h"
#include<iostream>
using namespace std;

// constructor

User::User(string n, int i):name(n), indexCurrentRoom(i){}

User::User(){name= "Ben", indexCurrentRoom=2;}

// set and get name
string User::getName() const {
    return this->name;
}
void User::setName (string n){
    this->name = n;
}
// set and get room
int User::getindexCurrentRoom() const {return this->indexCurrentRoom;}
void User::setindexCurrentRoom(int i){this->indexCurrentRoom = i;}

//creating turn order using vector size
int User::nextUser(int size){
    //increment the index
    index++;
    //set index to zero is reaches or exceeds vector size
    if (index>=size)
        index=0;
    return index;
}


//override for user name
ostream& operator<<(ostream& outputStream, const User& u){
    outputStream << u.name;
    return outputStream;
}

//bool for same room
bool operator ==(const User &user1, const User &user2){
    if (user1.indexCurrentRoom == user2.indexCurrentRoom)
        return true;
    else
        return false;
}


//initializing index to 0
int User::index=0;


