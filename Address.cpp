#include "Address.h"
#include <iostream>
using namespace std;


Address::Address(string streetName,string cityName,int postal) : street(streetName),city(cityName),postal(postal)
{};
Address::~Address()
{

}

void Address::printAdress() const
{
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Postal Code: " << postal << endl;
}
