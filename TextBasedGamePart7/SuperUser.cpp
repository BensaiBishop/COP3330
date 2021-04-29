//
// Created by bensa on 24/10/2020.
//

#include "SuperUser.h"

SuperUser::SuperUser(){
    this->setUserType(SUPERUSER);
}

User::User() {name= "Ben", indexCurrentRoom=2;}

ostream& operator<<(ostream& outputStream, const SuperUser& s){
    outputStream << "SUPERUSER\n";
    return outputStream;
}