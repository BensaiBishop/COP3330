//
// Created by bensa on 24/10/2020.
//
#include "User.h"
#ifndef UNTITLED8_SUPERUSER_H
#define UNTITLED8_SUPERUSER_H


class SuperUser : public User {
public:
    SuperUser();

    friend ostream& operator <<(ostream& outputStream, const SuperUser& s);

};


#endif //UNTITLED8_SUPERUSER_H
