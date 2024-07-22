
#ifndef WORK5_LAWFIRM_H
#define WORK5_LAWFIRM_H

#include "Address.h"
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

class LawFirm {
private:
    string officeName;
    Address *officeAddress;
    Person **peopleArray;
    int NumberOfPeople;

    void addClient();
    void addLawyer();
    void chooseLawyerForClient();
    void printAllDetailsOfLawyers();
    void printActiveClients();
    void printLawyerDetailsWithMaxClients();
    void closeClientCase();


public:
    LawFirm(string officeName = "DefaultName", Address *officeAddress = nullptr);
    ~LawFirm();
    void menu();
    int getNumOfActiveClients();
};


#endif //WORK5_LAWFIRM_H
