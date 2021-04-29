//
// Created by bensa on 24/10/2020.
//

#include "SuperUser.h"
#include <iostream>
SuperUser::SuperUser(){
    this->setUserType(SUPERUSER);
}

//accessor and mutator for PrayGuidance
bool SuperUser::getPrayGuidance() const{
    return this->bPrayGuidance;
}
void SuperUser::setPrayGuidance(bool pray){
    this -> bPrayGuidance;
}

//function to allow user to pray
void SuperUser::Pray(){
    std::cout<<"You pray to a higher power for guidance. You find yourself elsewhere.\n";

    bPrayGuidance=true;
}

//function moniker
void SuperUser::givemoniker(){
    //prompt for moniker
    string m;
    std::cout<<"Please enter your moniker\n";
    std::cin>>m;
    //set moniker
    this->setMoniker(m);
    //display congrats
    std::cout<<"+rep\n";
}

ostream& operator<<(ostream& outputStream, const SuperUser& s){
    outputStream << "SUPERUSER\n";
    return outputStream;
}