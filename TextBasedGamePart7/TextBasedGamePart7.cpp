/* Name: Benjamin Bishop
Date: 25 Oct. 2020
Section: 0011
Assignment: Text Based program part 6
Due Date: 28 Oct. 2020
About this project: This is a simple text based adventure game utilizing an array of instances of a class,
 addition of member data and functions to an existing class. It has been separated by class, and includes to use of pointers.
 Now includes the SuperUser class.
Assumptions: User should be about to input their desired direction in the form of N,S,W,E (the cardinal directions)
 and navigate within the set rooms of the program. Supports multiple users and includes an 'observe' option.
 Also include a new save and load data functions with the appropriate options.
All work below was performed by Benjamin Bishop */

// students - you need to put program header here

/*The following comment is a copy of my g++ test run
 *
 *
bbishop@linprog1.cs.fsu.edu:~/COP3330/textGame7>make
make: `TextGame' is up to date.
bbishop@linprog1.cs.fsu.edu:~/COP3330/textGame7>TextGame
Would you like to load save data?(Y/N)
n
What is your name?
Dudley
Welcome to my game!

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
SUPERUSER

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
Dudley, you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
o
You look but find no one...

Ben's turn.
SUPERUSER

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
Dudley, you are currently at the Forest
It is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
e
Dudley, you are now in Cliff

Ben's turn.
SUPERUSER

~~~~~~~~~~~~~~~~~~~~~~~~~~
Ben, you are currently at the Road
A long, rocky, dirt road. You can't determine the depths of which it reaches. The more you think about it the more unnerving it becomes.The only way to go is north.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
q
Would you like to save current data to file?(Y/N)
n
Thank you for playing...

Dudley's turn.

~~~~~~~~~~~~~~~~~~~~~~~~~~
Dudley, you are currently at the Cliff
A cliff at the sea. A sheer drop into the vast expanse of water below. The moonlight shows you a glimpse of a figure in the dark waters.Whatever it is, it's massive.The only way to go is west.
~~~~~~~~~~~~~~~~~~~~~~~~~~
You can observe for others by pressing 'O'
Where do you move? N,S,E,W
q
Would you like to save current data to file?(Y/N)
y
Thank you for playing...
bbishop@linprog1.cs.fsu.edu:~/COP3330/textGame7>

*/
#include <vector>
#include <iostream>
#include <fstream>

using std::endl;

#include "User.h"
#include "Room.h"
#include "SuperUser.h"

//number of rooms
const int NUM_ROOMS=5;

//prototypes

// sets up rooms
void initRooms(Room rooms[]);
// sets up user
void initUser(std::vector<User *> &users);
//User selects an action
void promptUserAction(User *u, const Room rooms[], string &strCh);
//implement Users Action
void implementUserAction(User *u,const Room rooms[],const string strCh,const std::vector<User*>&users);
//display user type
void displayUser(User *u);
//save current name and current room index
void saveUserData(std::vector<User *> users);
//load file save data
void loadUserData(std::vector<User *>& users);


int main() {
    Room rooms[NUM_ROOMS];
    std::vector<User *> users;

    //prompt to load data from file
    string strLoad;
    std::cout<<"Would you like to load save data?(Y/N)\n";
    std::cin>>strLoad;
    if ((strLoad=="Y")||(strLoad=="y"))
        //load user and room data
        loadUserData(users);
    else {
        User *user1 = new User;
        SuperUser * user2 = new SuperUser;
        initUser(users);
        //users.push_back(user1);
        users.push_back(user2);
    }
    //initialize rooms
    Room * roomPtr;
    roomPtr = rooms;
    initRooms(roomPtr);

    //welcome
    std::cout << "Welcome to my game!" << std::endl;

    string UserAction;
    int index=0;
    do
    {
        //display current user name

        std::cout<<std::endl<<*users[index]<<"'s turn.\n";
        // prompt action
        promptUserAction(users[index],rooms,UserAction);
        implementUserAction(users[index],rooms,UserAction,users);
        //implementing user removal from vector
        if(UserAction=="Q" || UserAction=="q"){

            users.erase(users.begin()+index);
        }
        //finding index of next user
        index=User::nextUser(users.size());


    } while (!users.empty());
    //continue until no more users

    return 0;
}

// sets up rooms
void initRooms(Room rooms[])
{
    //init Cave
    rooms->setName("Cave");
    rooms->setIndexRoomToNorth(-99);
    rooms->setIndexRoomToEast(-99);
    rooms->setIndexRoomToWest(-99);
    rooms->setIndexRoomToSouth(1);
    rooms->setRoomDesc("\nA dark and damp cave. The darkness is seems to grip at your feet."
                       "You hear the whistling of the wind through the trees just outside the entrance."
                       "The only way to go is south.");
    //init Forest
    (rooms+1)->setName("Forest");
    (rooms+1)->setIndexRoomToNorth(0);
    (rooms+1)->setIndexRoomToEast(2);
    (rooms+1)->setIndexRoomToWest(3);
    (rooms+1)->setIndexRoomToSouth(4);
    (rooms+1)->setRoomDesc("\nIt is night. The towering trees give off an oppressive aura as they twist and howl at you through moonlight.");
    //init Cliff
    (rooms+2)->setName("Cliff");
    (rooms+2)->setIndexRoomToNorth(-99);
    (rooms+2)->setIndexRoomToEast(-99);
    (rooms+2)->setIndexRoomToWest(1);
    (rooms+2)->setIndexRoomToSouth(-99);
    (rooms+2)->setRoomDesc("\nA cliff at the sea. A sheer drop into the vast expanse of water below. The moonlight shows you a glimpse of a figure in the dark waters."
                           "Whatever it is, it's massive."
                           "The only way to go is west.");
    //init Clearing
    (rooms+3)->setName("Clearing");
    (rooms+3)->setIndexRoomToNorth(-99);
    (rooms+3)->setIndexRoomToEast(1);
    (rooms+3)->setIndexRoomToWest(-99);
    (rooms+3)->setIndexRoomToSouth(-99);
    (rooms+3)->setRoomDesc("\nA open clearing in the forest. This place feels dangerous. No tree's to hide behind and the moon seems to glare at you with evil intent."
                           "The only way to go is east.");
    //init Road
    (rooms+4)->setName("Road");
    (rooms+4)->setIndexRoomToNorth(1);
    (rooms+4)->setIndexRoomToEast(-99);
    (rooms+4)->setIndexRoomToWest(-99);
    (rooms+4)->setIndexRoomToSouth(-99);
    (rooms+4)->setRoomDesc("\nA long, rocky, dirt road. You can't determine the depths of which it reaches. "
                           "The more you think about it the more unnerving it becomes."
                           "The only way to go is north.");
}

// sets up user
void initUser(std::vector<User *> &users)
{
    string name;
    //prompt user for name
    std::cout<<"What is your name?\n";
    //read in name
    std::cin>>name;

    User* u = new User;

    u->setName(name);
    u->setindexCurrentRoom(0);
    users.push_back(u);

}

//User Action
void promptUserAction(User *u, const Room rooms[], string &strCh)
{
    displayUser(u);
    std::cout<<endl;
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    // tell user where they are
    std::cout<<u->getName()<<", you are currently at the "<<rooms[u->getindexCurrentRoom()]<<endl;
    //prompt user for choice
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
               "You can observe for others by pressing 'O'\n";
    std::cout<<"Where do you move? N,S,E,W"<<std::endl;
    std::cin>>strCh;
}
//implement Users Action
void implementUserAction(User *u,const Room rooms[],const string strCh,const std::vector<User*>&users)
{
    if ((strCh == "O")||(strCh == "o"))
    {

            if (users[0] == users[1])
                std::cout <<users[0]<<" and "<<users[1]<<" are together at the "<<rooms[u->getindexCurrentRoom()].getName()<< endl;
            else
                std::cout << "You look but find no one...\n";

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
            std::cout<<u->getName()<<", you are now in "<<rooms[u->getindexCurrentRoom()].getName()<<endl;

        } else {
            std::cout<<u->getName()<<", you can not move north from "<<rooms[u->getindexCurrentRoom()].getName()<<endl;
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
            std::cout<<u->getName()<<", you are now in "<<rooms[u->getindexCurrentRoom()].getName()<<endl;

        } else {
            std::cout<<u->getName()<<", you can not move south from "<<rooms[u->getindexCurrentRoom()].getName()<<endl;
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
            std::cout<<u->getName()<<", you are now in "<<rooms[u->getindexCurrentRoom()].getName()<<endl;

        } else {
            std::cout<<u->getName()<<", you can not move east from "<<rooms[u->getindexCurrentRoom()].getName()<<endl;
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
            std::cout<<u->getName()<<", you are now in "<<rooms[u->getindexCurrentRoom()].getName()<<endl;

        } else {
            std::cout<<u->getName()<<", you can not move west from "<<rooms[u->getindexCurrentRoom()].getName()<<endl;
        }
    }
    else if ((strCh =="Q") ||(strCh =="q"))
    {
        //user has selected to quit

        //prompt for save
        string strSave;
        std::cout<<"Would you like to save current data to file?(Y/N)\n";
        std::cin>>strSave;
        if ((strSave=="y")||(strSave=="Y")){
            //save current data to file
            saveUserData(users);
        }
        std::cout<<"Thank you for playing..."<<endl;
    }
    else
    {
        //user has selected an invalid option
        std::cout<<strCh<<" is not a valid option."<<endl;
    }
}

void displayUser(User * u){
    if (u->getUserType()==SUPERUSER) {
        SuperUser *s = (SuperUser *) u;
        std::cout << (*s);
    }
}

//save user name and room index
void saveUserData(std::vector<User *> users)
{
    std::ofstream outputFile("Name&Index.txt",std::ios_base::app);
    if(outputFile.fail()){
        std::cout<<"Error opening file, Name&Index.txt";
        exit(1);
    }
    for(int i=0;i<users.size();i++){
        outputFile<<users[i]->getName()<<endl;
        int roomIndex = users[i]->getindexCurrentRoom();
        outputFile<<users[i]->getUserType();
        outputFile<<roomIndex<<endl;
    }
    outputFile.close();
}

//load file save data
void loadUserData(std::vector<User *>& users)
{
    std::ifstream inputFile("Name&Index.txt");
    if(inputFile.fail()){
        std::cout<<"Error couldn't open the file, Name&Index.txt\n";
        exit(1);
    }
    int i=0;
    int roomIndex;
    string strName;
    User *u = new User;
    while (inputFile>>strName){

        (u+i)->setName(strName);
        inputFile>>roomIndex;
        (u+i)->setindexCurrentRoom(roomIndex);
        i++;
    }
    users.push_back(u);
    inputFile.close();
}