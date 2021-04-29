#include <iostream>
/* Name: Benjamin Bishop
Date: 4 Sept. 2020
Section: 0011
Assignment: Text Based program part 1
Due Date: 9 Sept. 2002
About this project: This is a simple text based adventure game utilizing an array of instances of a class,
 addition of member data and functions to an existing class
Assumptions: User should be about to input their desired direction in the form of N,S,W,E (the cardinal directions)
 and navigate within the set rooms of the program.
All work below was performed by Benjamin Bishop */

// students - you need to put program header here

/*The following comment is a copy of my g++ test run
 *
 * a.out  TextBasedGame.cpp
bbishop@linprog3.cs.fsu.edu:~/COP3330/TextGame>a.out
What is your name?john
Welcome john to my game!
john you are currently at the Cave
A dark and damp cave. The darkness is seems to grip at your feet.You hear the whistling of the wind through the trees just outside the entrance.The only way to go is south.
Where do you move? N,S,E,W
N
john, you can not move north from Cave
john you are currently at the Cave
A dark and damp cave. The darkness is seems to grip at your feet.You hear the whistling of the wind through the trees just outside the entrance.The only way to go is south.
Where do you move? N,S,E,W
s
john, you are now in Forest
john you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
Where do you move? N,S,E,W
N^H
 is not a valid option.
john you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
Where do you move? N,S,E,W
n
john, you are now in Cave
john you are currently at the Cave
A dark and damp cave. The darkness is seems to grip at your feet.You hear the whistling of the wind through the trees just outside the entrance.The only way to go is south.
Where do you move? N,S,E,W
s^H
 is not a valid option.
john you are currently at the Cave
A dark and damp cave. The darkness is seems to grip at your feet.You hear the whistling of the wind through the trees just outside the entrance.The only way to go is south.
Where do you move? N,S,E,W
S
john, you are now in Forest
john you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
Where do you move? N,S,E,W
e
john, you are now in Cliff
john you are currently at the Cliff
A cliff at the sea. A sheer drop into the vast expanse of water below. The moonlight shows you a glimpse of a figure in the dark waters.Whatever it is, it's massive.The only way to go is west.
Where do you move? N,S,E,W
e
john, you can not move east from Cliff
john you are currently at the Cliff
A cliff at the sea. A sheer drop into the vast expanse of water below. The moonlight shows you a glimpse of a figure in the dark waters.Whatever it is, it's massive.The only way to go is west.
Where do you move? N,S,E,W
s
john, you can not move south from Cliff
john you are currently at the Cliff
A cliff at the sea. A sheer drop into the vast expanse of water below. The moonlight shows you a glimpse of a figure in the dark waters.Whatever it is, it's massive.The only way to go is west.
Where do you move? N,S,E,W
w
john, you are now in Forest
john you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
Where do you move? N,S,E,W
W
john, you are now in Clearing
john you are currently at the Clearing
A open clearing in the forest. This place feels dangerous. No tree's to hide behind and the moon seems to glare at you with evil intent.The only way to go is east.
Where do you move? N,S,E,W
e
john, you are now in Forest
john you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
Where do you move? N,S,E,W
s
john, you are now in Road
john you are currently at the Road
A long, rocky, dirt road. You can't determine the depths of which it reaches. The more you think about it the more unnerving it becomes.The only way to go is north.
Where do you move? N,S,E,W
q
Thank you for playing...
*/

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
    string getName() {
        return Name;
    };

    //set the name of the room
    void setName(string nm) {
        Name = nm;
    };
    // set the desc of the room
    void setRoomDesc(string s);
    // get the desc
    string getRoomDesc();

    //set the index of the room to the north
    void setIndexRoomToNorth(int indx);
    //get the index of the room to the north
    int getIndexRoomToNorth();

    //set the index of the room to the south
    void setIndexRoomToSouth(int indx);
    //get the index of the room to the south
    int getIndexRoomToSouth();

    //set the index of the room to the East
    void setIndexRoomToEast(int indx);
    //get the index of the room to the East
    int getIndexRoomToEast();

    //set the index of the room to the West
    void setIndexRoomToWest(int indx);
    //get the index of the room to the West
    int getIndexRoomToWest();
};
//////////////////////////////////////////////////////
//structure for user
struct user
{
    string name;
    int indexCurrentRoom;
};
////////////////////////////////////////////////////
// sets up rooms
void initRooms(Room rooms[]);
// sets up user
void initUser(user &u);

//User selects an action
void promptUserAction(user u,Room rooms[],string &strCh);
//implement Users Action
void implementUserAction(user &u,Room rooms[],string strCh);

int main() {
    Room rooms[NUM_ROOMS];
    user user1;

    //initialize user and rooms
    initRooms(rooms);
    initUser(user1);

    //welcome
    cout << "Welcome "<<user1.name<<" to my game!" << endl;

    string UserAction;
    do
    {
        promptUserAction(user1,rooms,UserAction);
        implementUserAction(user1,rooms,UserAction);

    } while ((UserAction != "Q")&&(UserAction != "q"));
    //continue until user decides to quit


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
    rooms[0].setRoomDesc("A dark and damp cave. The darkness is seems to grip at your feet."
                            "You hear the whistling of the wind through the trees just outside the entrance."
                            "The only way to go is south.");
    //init Forest
    rooms[1].setName("Forest");
    rooms[1].setIndexRoomToNorth(0);
    rooms[1].setIndexRoomToEast(2);
    rooms[1].setIndexRoomToWest(3);
    rooms[1].setIndexRoomToSouth(4);
    rooms[1].setRoomDesc("It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.");
    //init Cliff
    rooms[2].setName("Cliff");
    rooms[2].setIndexRoomToNorth(-99);
    rooms[2].setIndexRoomToEast(-99);
    rooms[2].setIndexRoomToWest(1);
    rooms[2].setIndexRoomToSouth(-99);
    rooms[2].setRoomDesc("A cliff at the sea. A sheer drop into the vast expanse of water below. The moonlight shows you a glimpse of a figure in the dark waters."
                            "Whatever it is, it's massive."
                            "The only way to go is west.");
    //init Clearing
    rooms[3].setName("Clearing");
    rooms[3].setIndexRoomToNorth(-99);
    rooms[3].setIndexRoomToEast(1);
    rooms[3].setIndexRoomToWest(-99);
    rooms[3].setIndexRoomToSouth(-99);
    rooms[3].setRoomDesc("A open clearing in the forest. This place feels dangerous. No tree's to hide behind and the moon seems to glare at you with evil intent."
                         "The only way to go is east.");
    //init Road
    rooms[4].setName("Road");
    rooms[4].setIndexRoomToNorth(1);
    rooms[4].setIndexRoomToEast(-99);
    rooms[4].setIndexRoomToWest(-99);
    rooms[4].setIndexRoomToSouth(-99);
    rooms[4].setRoomDesc("A long, rocky, dirt road. You can't determine the depths of which it reaches. "
                            "The more you think about it the more unnerving it becomes."
                            "The only way to go is north.");
}

// sets up user
void initUser(user &u)
{
    //prompt user for name
    cout<<"What is your name?";
    cin>>u.name;
    u.indexCurrentRoom=0;
}

//User Action
void promptUserAction(user u,Room rooms[],string &strCh)
{
    // tell user where they are
    cout<<u.name<<" you are currently at the "<<rooms[u.indexCurrentRoom].getName()<<endl;
    cout<< rooms[u.indexCurrentRoom].getRoomDesc() << endl;
    //prompt user for choice
    cout<<"Where do you move? N,S,E,W"<<endl;
    cin>>strCh;
}
//implement Users Action
void implementUserAction(user &u,Room rooms[],string strCh)
{
    if ((strCh =="N") ||(strCh =="n"))
    {
        //user has selected to move north

        // is it possible to move north from the room the user
        //is currently in
        int indxRoomNorth = rooms[u.indexCurrentRoom].getIndexRoomToNorth();
        if (indxRoomNorth != -99)
        {
            u.indexCurrentRoom = indxRoomNorth;
            cout<<u.name<<", you are now in "<<rooms[u.indexCurrentRoom].getName()<<endl;

        } else {
            cout<<u.name<<", you can not move north from "<<rooms[u.indexCurrentRoom].getName()<<endl;
        }
    }
    else if ((strCh =="S") ||(strCh =="s"))
    {
        //user has selected to move south

        // is it possible to move south from the room the user
        //is currently in
        int indxRoomSouth = rooms[u.indexCurrentRoom].getIndexRoomToSouth();
        if (indxRoomSouth != -99)
        {
            u.indexCurrentRoom = indxRoomSouth;
            cout<<u.name<<", you are now in "<<rooms[u.indexCurrentRoom].getName()<<endl;

        } else {
            cout<<u.name<<", you can not move south from "<<rooms[u.indexCurrentRoom].getName()<<endl;
        }
    }
    else if ((strCh =="E") ||(strCh =="e"))
    {
        //user has selected to move east

        // is it possible to move east from the room the user
        //is currently in
        int indxRoomEast = rooms[u.indexCurrentRoom].getIndexRoomToEast();
        if (indxRoomEast != -99)
        {
            u.indexCurrentRoom = indxRoomEast;
            cout<<u.name<<", you are now in "<<rooms[u.indexCurrentRoom].getName()<<endl;

        } else {
            cout<<u.name<<", you can not move east from "<<rooms[u.indexCurrentRoom].getName()<<endl;
        }
    }
    else if ((strCh =="W") ||(strCh =="w"))
    {
        //user has selected to move west

        // is it possible to move west from the room the user
        //is currently in
        int indxRoomWest = rooms[u.indexCurrentRoom].getIndexRoomToWest();
        if (indxRoomWest != -99)
        {
            u.indexCurrentRoom = indxRoomWest;
            cout<<u.name<<", you are now in "<<rooms[u.indexCurrentRoom].getName()<<endl;

        } else {
            cout<<u.name<<", you can not move west from "<<rooms[u.indexCurrentRoom].getName()<<endl;
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
};

//get the index of the room to the north
int Room::getIndexRoomToNorth()
{
    return IndexOfRoomToNorth;
};

//set the index of the room to the south
void Room::setIndexRoomToSouth(int indx)
{
    IndexOfRoomToSouth=indx;
};

//get the index of the room to the south
int Room::getIndexRoomToSouth()
{
    return IndexOfRoomToSouth;
};

//set the index of the room to the East
void Room::setIndexRoomToEast(int indx)
{
    IndexOfRoomToEast=indx;
};

//get the index of the room to the East
int Room::getIndexRoomToEast()
{
    return IndexOfRoomToEast;
};

//set the index of the room to the West
void Room::setIndexRoomToWest(int indx)
{
    IndexOfRoomToWest=indx;
};

//get the index of the room to the south
int Room::getIndexRoomToWest()
{
    return IndexOfRoomToWest;
};
//get the desc
void Room::setRoomDesc(string s){
    Desc = s;
}
string Room::getRoomDesc(){
    return Desc;
};