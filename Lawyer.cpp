
#include "Lawyer.h"
#include <iostream>
#include <string>

using namespace std;


Lawyer::Lawyer(string name, int id, const Address &personAddress, int yearsOfSeniority, int numActiveClients = 0,
               int numPastClients = 0) : Person(name, id, personAddress), yearsOfSeniority(yearsOfSeniority),
                                         numActiveClients(numActiveClients),
                                         numPastClients(numPastClients) {
    activeClients = new Client *[numActiveClients];
    pastClients = new Client *[numPastClients];

}

Lawyer::~Lawyer() {
    if (activeClients != nullptr) {
        for (int i = 0; i < numActiveClients; i++) {
            delete activeClients[i];
        }
        delete[] activeClients;
    }
    delete[] activeClients;

    if (pastClients != nullptr) {
        for (int i = 0; i < numPastClients; i++) {
            delete pastClients[i];
        }
        delete[] pastClients;
    }

}

void Lawyer::printPersonData() const {
    cout << "Name: " << getName() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Address: ";
    getPersonAddress().printAdress();
    cout << "Active clients: " << endl;
    for (int i = 0; i < numActiveClients; ++i) {
        cout << activeClients[i];
    }

}

void Lawyer::salary() const {
    int totalSalary = numActiveClients * 1000 + yearsOfSeniority * 500;
    cout << "Total Salary :" << totalSalary;
}

void Lawyer::closeClientCase(int clientId) {
    //Creating new arr with 1 less spot
    Client **tempActiveClients = new Client *[numActiveClients - 1];
    //Choosen client.
    Client *clientToClose = nullptr;

    int index = 0;
    for (int i = 0; i < numActiveClients; i++) {
        if (activeClients[i]->getId() != clientId) {
            tempActiveClients[index] = activeClients[i];
            index++;
        } else {
            clientToClose = activeClients[i];
        }
    }
    if (numActiveClients != 0) {
        delete[]activeClients;
    }
    numActiveClients--;

    activeClients = tempActiveClients;

    if (numActiveClients != 0) {
        delete[]tempActiveClients;
    }

    //Creating new past client with +1 spot
    Client **tempPastClients = new Client *[numPastClients + 1];

    for (int i = 0; i < numPastClients; i++) {
        tempPastClients[i] = pastClients[i];
    }
    if (numPastClients != 0) {
        delete[]pastClients;
    }
    tempPastClients[numPastClients] = clientToClose;

    pastClients = tempPastClients;
    if (numPastClients != 0) {
        delete[]tempPastClients;
    }
    numPastClients++;
    if (clientToClose != nullptr) {
        clientToClose->setIsActive(false);
        cout << "Client with ID " << clientId << " case closed successfully." << endl;
        return;
    }
    cout << "Client with ID " << clientId << " is not in your clients!" << endl;
    return;
}

Lawyer &Lawyer::operator+=(Client *client) {
    // Create a new temporary array with increased size
    Client **tempActiveClients = new Client *[numActiveClients + 1];

    // Copy existing active clients to the temporary array
    for (int i = 0; i < numActiveClients; i++) {
        tempActiveClients[i] = activeClients[i];
    }

    // Add the new client at the end of the temporary array
    tempActiveClients[numActiveClients] = client;

    // Delete the old activeClients array
    if (numActiveClients != 0) {
        delete[] activeClients;
    }

    // Update activeClients to point to the new array
    activeClients = tempActiveClients;

// Increment the number of active clients
    numActiveClients++;

    if (numActiveClients != 0) {
        delete[] tempActiveClients;
    }
    //Print all the clients of the laywer:
    cout << "Print all the clients of the laywer : " << endl;
    for (int i = 0; i < numActiveClients; i++) {
        cout << activeClients[i]->getName() << endl;
    }
    return *this;
}

int Lawyer::getNumActiveClients() const {
    return numActiveClients;
}

int Lawyer::getNumPastClients() const {
    return numPastClients;
}

Client **Lawyer::getActiveClients() const {
    return activeClients;
}

Client **Lawyer::getPastClients() const {
    return pastClients;
}
