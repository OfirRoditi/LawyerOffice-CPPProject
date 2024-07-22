
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;


Person::Person(string name, int id, const Address &personAddress)
        : name(name), id(id), personAddress(personAddress) {

}

Person::~Person() {};

//abstract//virtual
void Person::printPersonData() const {};


bool Person::operator==(const Person &other) const
{
    if (this->id == other.id)
    {
        return true;
    }
    return false;
}











