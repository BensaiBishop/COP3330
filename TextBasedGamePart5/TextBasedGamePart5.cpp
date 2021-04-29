/* Name: Benjamin Bishop
Date: 02 Oct. 2020
Section: 0011
Assignment: Text Based program part 1
Due Date: 04 Oct. 2020
About this project: This is a simple text based adventure game utilizing an array of instances of a class,
 addition of member data and functions to an existing class
Assumptions: User should be about to input their desired direction in the form of N,S,W,E (the cardinal directions)
 and navigate within the set rooms of the program. Supports multiple users and includes an 'observe' option.
 At this point. The classes have been seperated into header and implementation files.
All work below was performed by Benjamin Bishop */

// students - you need to put program header here

/*The following comment is a copy of my g++ test run
bbishop@linprog7.cs.fsu.edu:~/COP3330/textGame5>make
g++ -std=c++11 -c TextBasedGamePart5.cpp
g++ -std=c++11 -c Room.h
g++ -std=c++11 -c Room.cpp
g++ -std=c++11 -c User.h
g++ -std=c++11 -c User.cpp
g++ -std=c++11 TextBasedGamePart5.o Room.o User.o -o TextGame
bbishop@linprog7.cs.fsu.edu:~/COP3330/textGame5>TextGame
What is your name?Dudley
Welcome to my game!

Dudley's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Cave
A dark and damp cave. The darkness is seems to grip at your feet.You hear the whistling of the wind through the trees just outside the entrance.The only way to go is south.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
o
You look but find no one...

Ben's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Ben, you are currently at the Cliff
A cliff at the sea. A sheer drop into the vast expanse of water below. The moonlight shows you a glimpse of a figure in the dark waters.Whatever it is, it's massive.The only way to go is west.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
w
Ben, you are now in Forest

Dudley's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Cave
A dark and damp cave. The darkness is seems to grip at your feet.You hear the whistling of the wind through the trees just outside the entrance.The only way to go is south.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
s
Dudley, you are now in Forest

Ben's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Ben, you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
O
Dudley and Ben are together at the Forest

Dudley's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
w
Dudley, you are now in Clearing

Ben's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Ben, you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
s
Ben, you are now in Road

Dudley's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Clearing
A open clearing in the forest. This place feels dangerous. No tree's to hide behind and the moon seems to glare at you with evil intent.The only way to go is east.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
w
Dudley, you can not move west from Clearing

Ben's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Ben, you are currently at the Road
A long, rocky, dirt road. You can't determine the depths of which it reaches. The more you think about it the more unnerving it becomes.The only way to go is north.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
q
Thank you for playing...

Dudley's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Clearing
A open clearing in the forest. This place feels dangerous. No tree's to hide behind and the moon seems to glare at you with evil intent.The only way to go is east.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
Q
Thank you for playing...
bbishop@linprog7.cs.fsu.edu:~/COP3330/textGame5>

*/
#include <vector>
#include <iostream>
#include "User.h"
#include "Room.h"

using namespace std;

//number of rooms
const int NUM_ROOMS=5;




// sets up rooms
void initRooms(Room rooms[]);
// sets up user
void initUser(User &u);
//User selects an action
void promptUserAction(User *u, const Room rooms[], string &strCh);
//implement Users Action
void implementUserAction(User *u,const Room rooms[],const string strCh,const vector<User>&users);

int main() {
    Room rooms[NUM_ROOMS];
    // Add a definition of user as an instance of user class

    User user1("",0);
    User user2;

    //initialize user and rooms
    Room * roomPtr;
    roomPtr = rooms;

    initRooms(roomPtr);
    initUser(user1);
    
    //vector of users
    vector<User>users;
    users.push_back(user1);
    users.push_back(user2);

    //welcome
    cout << "Welcome to my game!" << endl;

    string UserAction;
    int index=0;
    do
    {
        //display current user name
        cout<<endl<<users[index]<<"'s turn.\n";
        // prompt action
        promptUserAction(&users[index],rooms,UserAction);
        implementUserAction(&users[index],rooms,UserAction,users);
        //implementing user removal from vector
        if(UserAction=="Q" || UserAction=="q"){
            users.erase(users.begin()+index);
        }
        //finding index of next user
        index=User::nextUser(users.size());




    } while (users.size()>0);
    //continue until no more users

    return 0;
}

// sets up rooms
void initRooms(Room rooms[])
{
    //init Cave
    rooms[0].setName("Cave");
    rooms[0].setIndexRoomToNorth(-99);
    rooms[0].setIndexRoomToEast(-99);
    rooms[0].setIndexRoomToWest(-99);
    rooms[0].setIndexRoomToSouth(1);
    rooms[0].setRoomDesc("\nA dark and damp cave. The darkness is seems to grip at your feet."
                         "You hear the whistling of the wind through the trees just outside the entrance."
                         "The only way to go is south.");
    //init Forest
    rooms[1].setName("Forest");
    rooms[1].setIndexRoomToNorth(0);
    rooms[1].setIndexRoomToEast(2);
    rooms[1].setIndexRoomToWest(3);
    rooms[1].setIndexRoomToSouth(4);
    rooms[1].setRoomDesc("\nIt is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.");
    //init Cliff
    rooms[2].setName("Cliff");
    rooms[2].setIndexRoomToNorth(-99);
    rooms[2].setIndexRoomToEast(-99);
    rooms[2].setIndexRoomToWest(1);
    rooms[2].setIndexRoomToSouth(-99);
    rooms[2].setRoomDesc("\nA cliff at the sea. A sheer drop into the vast expanse of water below. The moonlight shows you a glimpse of a figure in the dark waters."
                         "Whatever it is, it's massive."
                         "The only way to go is west.");
    //init Clearing
    rooms[3].setName("Clearing");
    rooms[3].setIndexRoomToNorth(-99);
    rooms[3].setIndexRoomToEast(1);
    rooms[3].setIndexRoomToWest(-99);
    rooms[3].setIndexRoomToSouth(-99);
    rooms[3].setRoomDesc("\nA open clearing in the forest. This place feels dangerous. No tree's to hide behind and the moon seems to glare at you with evil intent."
                         "The only way to go is east.");
    //init Road
    rooms[4].setName("Road");
    rooms[4].setIndexRoomToNorth(1);
    rooms[4].setIndexRoomToEast(-99);
    rooms[4].setIndexRoomToWest(-99);
    rooms[4].setIndexRoomToSouth(-99);
    rooms[4].setRoomDesc("\nA long, rocky, dirt road. You can't determine the depths of which it reaches. "
                         "The more you think about it the more unnerving it becomes."
                         "The only way to go is north.");
}

// sets up user
void initUser(User &u)
{
    string name;
    //prompt user for name
    cout<<"What is your name?";
    cin>>name;
    u.setName(name);
    u.setindexCurrentRoom(0);
}

//User Action
void promptUserAction(User *u, const Room rooms[], string &strCh)
{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    // tell user where they are
    cout<<u->getName()<<", you are currently at the "<<rooms[u->getindexCurrentRoom()]<<endl;
    //prompt user for choice
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
          "You can observe for others by pressing 'O'\n";
    cout<<"Where do you move? N,S,E,W"<<endl;
    cin>>strCh;
}
//implement Users Action
void implementUserAction(User *u,const Room rooms[],const string strCh,const vector<User>&users)
{
    if ((strCh == "O")||(strCh == "o"))
    {
        User company = users[0];
        for (int i=1;i < users.size(); i++) {

            if (company == users[i])
                cout <<company<<" and "<<users[i]<<" are together at the "<<rooms[u->getindexCurrentRoom()].getName()<< endl;
            else
                cout << "You look but find no one...\n";
        }
    }
    else if ((strCh =="N") ||(strCh =="n"))
    {
        //user has selected to move north

        // is it possible to move north from the room the user
        //is currently in
        int indxRoomNorth = rooms[u->getindexCurrentRoom()].getIndexRoomToNorth();
        if (indxRoomNorth != -99)
        {
            u->setindexCurrentRoom(indxRoomNorth);
            cout<<u->getName()<<", you are now in "<<rooms[u->getindexCurrentRoom()].getName()<<endl;

        } else {
            cout<<u->getName()<<", you can not move north from "<<rooms[u->getindexCurrentRoom()].getName()<<endl;
        }
    }
    else if ((strCh =="S") ||(strCh =="s"))
    {
        //user has selected to move south

        // is it possible to move south from the room the user
        //is currently in
        int indxRoomSouth = rooms[u->getindexCurrentRoom()].getIndexRoomToSouth();
        if (indxRoomSouth != -99)
        {
            u->setindexCurrentRoom(indxRoomSouth);
            cout<<u->getName()<<", you are now in "<<rooms[u->getindexCurrentRoom()].getName()<<endl;

        } else {
            cout<<u->getName()<<", you can not move south from "<<rooms[u->getindexCurrentRoom()].getName()<<endl;
        }
    }
    else if ((strCh =="E") ||(strCh =="e"))
    {
        //user has selected to move east

        // is it possible to move east from the room the user
        //is currently in
        int indxRoomEast = rooms[u->getindexCurrentRoom()].getIndexRoomToEast();
        if (indxRoomEast != -99)
        {
            u->setindexCurrentRoom(indxRoomEast);
            cout<<u->getName()<<", you are now in "<<rooms[u->getindexCurrentRoom()].getName()<<endl;

        } else {
            cout<<u->getName()<<", you can not move east from "<<rooms[u->getindexCurrentRoom()].getName()<<endl;
        }
    }
    else if ((strCh =="W") ||(strCh =="w"))
    {
        //user has selected to move west

        // is it possible to move west from the room the user
        //is currently in
        int indxRoomWest = rooms[u->getindexCurrentRoom()].getIndexRoomToWest();
        if (indxRoomWest != -99)
        {
            u->setindexCurrentRoom(indxRoomWest);
            cout<<u->getName()<<", you are now in "<<rooms[u->getindexCurrentRoom()].getName()<<endl;

        } else {
            cout<<u->getName()<<", you can not move west from "<<rooms[u->getindexCurrentRoom()].getName()<<endl;
        }
    }
    else if ((strCh =="Q") ||(strCh =="q"))
    {
        //user has selected to quit
        cout<<"Thank you for playing..."<<endl;
    }
    else
    {
        //user has selected an invalid option
        cout<<strCh<<" is not a valid option."<<endl;
    }
}
////////////////////////////////////////
// Room class
//set the index of the room to the north
void Room::setIndexRoomToNorth(int indx)
{
    IndexOfRoomToNorth=indx;
}

//get the index of the room to the north
int Room::getIndexRoomToNorth() const {
    return IndexOfRoomToNorth;
}

//set the index of the room to the south
void Room::setIndexRoomToSouth(int indx)
{
    IndexOfRoomToSouth=indx;
}

//get the index of the room to the south
int Room::getIndexRoomToSouth() const {
    return IndexOfRoomToSouth;
}

//set the index of the room to the East
void Room::setIndexRoomToEast(int indx)
{
    IndexOfRoomToEast=indx;
}

//get the index of the room to the East
int Room::getIndexRoomToEast() const {
    return IndexOfRoomToEast;
}

//set the index of the room to the West
void Room::setIndexRoomToWest(int indx)
{
    IndexOfRoomToWest=indx;
}

//get the index of the room to the south
int Room::getIndexRoomToWest() const {
    return IndexOfRoomToWest;
}
//get the desc
void Room::setRoomDesc(string s){
    this->Desc = s;
}
string Room::getRoomDesc(){
    return this->Desc;
}