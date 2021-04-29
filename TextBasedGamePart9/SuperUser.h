//
// Created by bensa on 24/10/2020.
//
#include "User.h"
#ifndef UNTITLED8_SUPERUSER_H
#define UNTITLED8_SUPERUSER_H


class SuperUser : public User {
public:
    SuperUser();

    //function to allow user to pray
    void Pray();
    //accessor and mutator for PrayGuidance
    bool getPrayGuidance() const;
    void setPrayGuidance(bool pray);

    //function moniker
    void givemoniker();


    friend ostream& operator <<(ostream& outputStream, const SuperUser& s);

private:
    bool bPrayGuidance;

};


#endif //UNTITLED8_SUPERUSER_H
