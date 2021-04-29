//
// Created by bensa on 05/11/2020.
//
#include <vector>
#ifndef TEXTBASEDGAMEPART8_CPP_USERLIST_H
#define TEXTBASEDGAMEPART8_CPP_USERLIST_H


template<class H>class UserList {
public:
    UserList();
    //add item to UserList
    void addList(H* item);
    //display UserList
    void showList();
private:
    std::vector<H*> list;

};


#endif //TEXTBASEDGAMEPART8_CPP_USERLIST_H
