
#ifndef WORK5_PERSON_H
#define WORK5_PERSON_H

#include <iostream>
#include <string>
#include "Address.h"

using namespace std;

class Person {
private:
    string name;
    int id;
    Address personAddress;


public:
    Person(string name="Ornit", int id =555, const Address &personAddress = Address());
    virtual ~Person();
    virtual void printPersonData() const = 0;
    bool operator==(const Person &other)const;

    string getName () const
    {
        return name;
    }

    int getId () const
    {
        return id;
    }
    Address getPersonAddress () const
    {
        return personAddress;
    }
};


#endif //WORK5_PERSON_H
