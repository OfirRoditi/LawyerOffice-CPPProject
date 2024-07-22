
#include "Client.h"
#include <iostream>
#include <string>
using namespace std;

Client::Client(string name, int id,const Address &clientAddress, bool isActive):
Person(name,id,clientAddress) ,isActive(isActive=false)  {

}
Client::~Client() {

}


void Client::printPersonData()const  {
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Address: ";
    getPersonAddress().printAdress();

}
