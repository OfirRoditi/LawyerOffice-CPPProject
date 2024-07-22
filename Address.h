
#ifndef WORK5_ADDRESS_H
#define WORK5_ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address
{
private:

   string street;
   string city;
   int postal;

   public:
     Address(string street ="DefualtStreet",string city  ="DefualtCity",int postal =000);
    virtual ~Address();
    void printAdress() const;


};
#endif //WORK5_ADDRESS_H
