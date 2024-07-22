
#ifndef WORK5_CLIENT_H
#define WORK5_CLIENT_H
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class Client : public Person{
private:
    bool isActive;

public:
    Client(string name , int id , const Address &clientAddress , bool isActive=false);
     virtual ~Client();
    void setIsActive(bool isActive)
    {
        this->isActive=isActive;
    }
    bool getIsActive()
    {
        return isActive;
    }

    //@ovveride
    void printPersonData()const;
};


#endif //WORK5_CLIENT_H
