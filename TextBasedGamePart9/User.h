//
// Created by bensa on 02/10/2020.
//

#ifndef UNTITLED8_USER_H
#define UNTITLED8_USER_H
#include<iostream>

using std::string;
using std::ostream;

enum UserTypes {NORMAL,SUPERUSER,UNKNOWN};

//////////////////////////////////////////////////////
//class for user
class User{
private:
    string moniker; //moniker or new name
    int UserType{};
    static int index;
    string name;
    int indexCurrentRoom{};
public:
    // constructor
    User();
    User(string n, int i);

    //virtual function moniker
    virtual void givemoniker();

    //set and get moniker
    string getMoniker() const;
    void setMoniker(string m);

    // set and get name
    string getName() const;
    void setName (string n);

    //accessor and mutator for UserType
    int getUserType() const;
    void setUserType(int userTyp);

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
