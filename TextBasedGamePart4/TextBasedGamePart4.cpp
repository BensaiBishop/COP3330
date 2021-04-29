/* Name: Benjamin Bishop
Date: 25 Sept. 2020
Section: 0011
Assignment: Text Based program part 1
Due Date: 27 Sept. 2020
About this project: This is a simple text based adventure game utilizing an array of instances of a class,
 addition of member data and functions to an existing class
Assumptions: User should be about to input their desired direction in the form of N,S,W,E (the cardinal directions)
 and navigate within the set rooms of the program. Supports multiple users and includes an 'observe' option
All work below was performed by Benjamin Bishop */

// students - you need to put program header here

/*The following comment is a copy of my g++ test run
bbishop@linprog4.cs.fsu.edu:~/COP3330/textGame4>ls
a.out  tbg4.cpp
bbishop@linprog4.cs.fsu.edu:~/COP3330/textGame4>a.out
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
W
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
Someone is here with you. It's Dudley

Dudley's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
O
Someone is here with you. It's Ben

Ben's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Ben, you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
w
Ben, you are now in Clearing

Dudley's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
S
Dudley, you are now in Road

Ben's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Ben, you are currently at the Clearing
A open clearing in the forest. This place feels dangerous. No tree's to hide behind and the moon seems to glare at you with evil intent.The only way to go is east.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
q
Thank you for playing...

Dudley's turn.
~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Road
A long, rocky, dirt road. You can't determine the depths of which it reaches. The more you think about it the more unnerving it becomes.The only way to go is north.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
Q
Thank you for playing...
bbishop@linprog4.cs.fsu.edu:~/COP3330/textGame4>

*/
#include <vector>
#include <iostream>

using namespace std;

//number of rooms
const int NUM_ROOMS=5;

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
    string getName() const {
        return this->Name;
    };

    //set the name of the room
    void setName(string nm) {
        this->Name = nm;
    };
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
    ostream& operator<<(ostream& outputStream,const Room& room){
        outputStream<<room.Name;
        outputStream<<room.Desc;
        return outputStream;
    }
//////////////////////////////////////////////////////
//class for user
class User{
private:
    static int index;
    string name;
    int indexCurrentRoom;
public:
    // constructor
    User(string n, int i):name(n), indexCurrentRoom(i){}

    User(){name= "Ben", indexCurrentRoom=2;}

    // set and get name
    string getName() const {
        return this->name;
    }
    void setname (string n){
        this->name = n;
    }
    // set and get room
    int getindexCurrentRoom() const {return this->indexCurrentRoom;}
    void setindexCurrentRoom(int i){this->indexCurrentRoom = i;}

    //creating turn order using vector size
    static int nextUser(int size){
        //increment the index
        index++;
        //set index to zero is reaches or exceeds vector size
        if (index>=size)
            index=0;
        return index;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //temp solution for 'observe function'
    static int temp;
    static int nexTurn(int size){
        //increment the index
        temp++;
        //set index to zero is reaches or exceeds vector size
        if (temp>=size)
            temp=0;
        return temp;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    friend ostream& operator <<(ostream& outputStream, const User& u);
    friend bool operator ==(const User &user1, const User &user2);
};
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
    //~~~~~~~~~~~~~~~~
    int User::temp=0;
    //~~~~~~~~~~~~~~~~

////////////////////////////////////////////////////

// sets up rooms
void initRooms(Room rooms[]);
// sets up user
void initUser(User &u);
//User selects an action
void promptUserAction(const User *u, const Room rooms[], string &strCh);
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
    u.setname(name);
    u.setindexCurrentRoom(0);
}

//User Action
void promptUserAction(const User *u, const Room rooms[], string &strCh)
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
        // if user wants to check room for another user
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        //programmer note; optimize the observe function
        int temp;
        temp=User::nexTurn(users.size());
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        User company = users[0];
        for (int i=1;i < users.size(); i++) {

            if (company == users[i])
                cout << "Someone is here with you. It's " << users[temp] << endl;
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