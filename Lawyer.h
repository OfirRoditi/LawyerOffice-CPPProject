
#ifndef WORK5_LAWYER_H
#define WORK5_LAWYER_H

#include "Person.h"
#include "Client.h"
#include <iostream>
#include <string>
using namespace std;

class Lawyer : public Person {
private:
    int yearsOfSeniority;
    Client** activeClients;
    int numActiveClients;
    Client** pastClients;
    int numPastClients;
public:
    Lawyer(string name, int id,const Address &personAddress , int yearsOfSeniority,  int numActiveClients,  int numPastClients);
    int getNumPastClients() const;
    Client **getActiveClients() const;
    Client **getPastClients() const;
    virtual ~Lawyer();
    void printPersonData() const;
    void salary()const;
    void closeClientCase(int id);
    Lawyer& operator+=( Client *client);
    int getNumActiveClients() const;

};


#endif //WORK5_LAWYER_H
