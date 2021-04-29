//
// Created by bensa on 02/10/2020.
//

#include "User.h"
#include<iostream>

User::User() {name= "Ben", indexCurrentRoom=2;}

// constructor
User::User(string n, int i):name(n), indexCurrentRoom(i){}
//User::User() {name= "Ben", indexCurrentRoom=2;}
//User::User(){this->setUserType(UNKNOWN);}

// set and get name
string User::getName() const {
    return this->name;
}
void User::setName (string n){
    this->name = n;
}

//set and get moniker
string User::getMoniker() const{
    return this->getMoniker();
}
void User::setMoniker(string m){
    this->moniker=m;
}

//virtual function moniker
void User::givemoniker(){
    std::cout<<"You must be a SuperUser to be given a moniker\n";
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

//override for user name    //credit to Mr. Bohning
ostream& operator<<(ostream& outputStream, const User& u){
    outputStream << u.name<<"("<<u.UserType<<")";
    return outputStream;
}


//bool for same room
bool operator ==(const User &user1, const User &user2){
    if (user1.indexCurrentRoom == user2.indexCurrentRoom)
        return true;
    else
        return false;
}

//set and get UserType
int User::getUserType() const{
    return this->UserType;
}
void User::setUserType(int userTyp){
    this->UserType=userTyp;
}

//initializing index to 0
int User::index=0;


