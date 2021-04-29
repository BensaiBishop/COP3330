//
// Created by bensa on 05/11/2020.
//

#include "UserList.h"
#include <iostream>
#include <vector>
#include <algorithm>
//constructor
template<class H> UserList<H>::UserList() {

}

//add to List
template<class H> void UserList<H>::addList(H *item) {
    // add if not already in the list.
    if (find(list.begin(),list.end(),item)==list.end()){
        //once item has not been found push back into list.
        list.push_back(item);
    }
}
//show list
template<class H> void UserList<H>::showList() {

    //I would like to use a function like this to display the name of the users in the list, but it out puts IEEE hex
    //how to fix?
/*
    for(int i=0;i<list.size();i++){
        std::cout<<list[i]<<std::endl;
    }
*/
    std::cout<<list.size()<<" pair of eyes watch you..."<<std::endl;
}