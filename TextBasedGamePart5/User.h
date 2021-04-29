//
// Created by bensa on 02/10/2020.
//

#ifndef UNTITLED8_USER_H
#define UNTITLED8_USER_H
#include<iostream>
using namespace std;
//////////////////////////////////////////////////////
//class for user
class User{
private:
    static int index;
    string name;
    int indexCurrentRoom;
public:
    // constructor
    User(string n, int i);

    User();

    // set and get name
    string getName() const;

    void setName (string n);

    // set and get room
    int getindexCurrentRoom() const;

    void setindexCurrentRoom(int i);

    //creating turn order using vector size
    static int nextUser(int size);

    friend ostream& operator <<(ostream& outputStream, const User& u);
    friend bool operator ==(const User &user1, const User &user2);

};
//override for user name
ostream& operator<<(ostream& outputStream, const User& u);

//bool for same room
bool operator ==(const User &user1, const User &user2);

////////////////////////////////////////////////////


#endif //UNTITLED8_USER_H
