
#include "LawFirm.h"
#include "Client.h"
#include "Person.h"
#include "Lawyer.h"
#include <iostream>
#include <string>

using namespace std;

LawFirm::LawFirm(string officeName, Address *officeAddress)
        : officeName(officeName), officeAddress(officeAddress), NumberOfPeople(0)
        {
    peopleArray = new Person *[NumberOfPeople];
}

LawFirm::~LawFirm() {
    delete officeAddress;
    for (int i = 0; i < NumberOfPeople; ++i)
    {
        delete peopleArray[i];
    }
    delete[] peopleArray;
}

void LawFirm::menu() {
    int choice;
    do {
        cout << "Menu Options:" << endl;
        cout << "1. Add a client" << endl;
        cout << "2. Add a lawyer" << endl;
        cout << "3. Add client to lawyer" << endl;
        cout << "4. Print all details of lawyer" << endl;
        cout << "5. Print active clients" << endl;
        cout << "6. Print Lawyer's details with max clients" << endl;
        cout << "7. Close client." << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addClient();
                break;
            case 2:
                addLawyer();
                break;
            case 3 :
                chooseLawyerForClient();
                break;
            case 4 :
                printAllDetailsOfLawyers();
                break;
            case 5:
                printActiveClients();
                break;
            case 6:
                printLawyerDetailsWithMaxClients();
                break;
            case 7:
                closeClientCase();
                break;
            case 8:
                "Exit";
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
}

void LawFirm::addClient() {
    string name, city, street;
    int id, postalCode;
    cout << "Add a client:" << endl;
    cout << "Insert client name:" << endl;
    cin >> name;
    cout << "Insert client id:" << endl;
    cin >> id;
    cout << "Insert client street, city, and postal code:" << endl;
    cin >> street >> city >> postalCode;
    Address address(street, city, postalCode);
    Client newClient(name, id, address, false);

// Check if a client with the same ID already exists
    for (int i = 0; i < NumberOfPeople; ++i) {
        if (peopleArray[i]->operator==(newClient)) {
            cout << "Client with ID " << newClient.getId() << " already exists." << endl;
            return; // Exit the method if a matching ID is found
        }
    }

// Create a new array with increased size
    Person **tempPeopleArray = new Person *[NumberOfPeople + 1];

// Copy existing peopleArray to the temporary array
    for (int i = 0; i < NumberOfPeople; i++) {
        tempPeopleArray[i] = peopleArray[i];
    }

// Delete old array
    if (NumberOfPeople != 0) {
        delete[] peopleArray;
    }

// Add the new client to the end of the temporary array
    tempPeopleArray[NumberOfPeople] = new Client(newClient);
    cout << "Client added" << endl;

// Update peopleArray to point to the new array
    peopleArray = tempPeopleArray;

// Delete temp array
    if (NumberOfPeople != 0)
    {
        delete[] tempPeopleArray;
    }

// Increment the number of peopleArray
    NumberOfPeople++;

// Checking if the peopleArray array is updated
    for (int i = 0; i < NumberOfPeople; i++)
    {
        if (Client *client = dynamic_cast<Client *>(peopleArray[i]))
            cout << client->getName() << endl;
    }
    cout << endl;
}

void LawFirm::addLawyer() {
    string name, city, street;
    int id, postalCode, seniority;
    cout << "Add a lawyer:" << endl;
    cout << "Insert lawyer name:" << endl;
    cin >> name;
    cout << "Insert lawyer id:" << endl;
    cin >> id;
    cout << "Insert lawyer seniority:" << endl;
    cin >> seniority;
    cout << "Insert lawyer street ,city and postal code :" << endl;
    cin >> street;
    cin >> city;
    cin >> postalCode;
    Address a1(street, city, postalCode);
    Lawyer newlawyer(name, id, a1, seniority, 0, 0);

    // Check if a client with the same ID already exists
    for (int i = 0; i < NumberOfPeople; ++i) {
        if (peopleArray[i]->operator == (newlawyer))
        {
            cout << "lawyer with ID " << newlawyer.getId() << " already exists." << endl;
            return; // Exit the method if a matching ID is found
        }
    }

    // Create a new array with increased size
    Person **tempPeople = new Person *[NumberOfPeople + 1];

    // Copy existing peopleArray to the temporary array
    for (int i = 0; i < NumberOfPeople; ++i) {
        tempPeople[i] = peopleArray[i];
    }
    //Delete old array.
    if (NumberOfPeople != 0) {
        delete[] peopleArray;
    }

    // Add the new client to the end of the temporary array
    tempPeople[NumberOfPeople] = new Lawyer(newlawyer);
    cout << "lawyer added" << endl;

    // Update peopleArray to point to the new array
    peopleArray = tempPeople;
    //Delete temp array.
    if (NumberOfPeople != 0) {
        delete[] tempPeople;
    }

    // Increment the number of peopleArray
    NumberOfPeople++;
    //Cheaking if the peopleArray array is updated:
    for (int i = 0; i < NumberOfPeople; i++) {
        if (Lawyer *lawyer = dynamic_cast<Lawyer *>(peopleArray[i]))
            cout << lawyer->getName() << endl;
    }
    cout << endl;
}

void LawFirm::chooseLawyerForClient() {
    Lawyer *choosenLawyer = nullptr;
    cout << "These are all the lawyers:" << endl;
    for (int i = 0; i < NumberOfPeople; i++) {
        if (Lawyer *lawyer = dynamic_cast<Lawyer *>(peopleArray[i])) {
            cout << i << " - " << lawyer->getName() << endl;
        }
    }
    cout << "Enter your choise : " << endl;
    int choosenLawyerNumber;
    cin >> choosenLawyerNumber;
    choosenLawyer = dynamic_cast<Lawyer *>(peopleArray[choosenLawyerNumber]);
    cout << endl;

    cout << "Please choose your client :" << endl;
    cout << "There are all the clients:" << endl;
    for (int i = 0; i < NumberOfPeople; i++) {
        if (Client *client = dynamic_cast<Client *>(peopleArray[i])) {
            cout << i << " - " << client->getName() << endl;
        }
    }
    cout << "Enter your choise : " << endl;
    int choosenClientNumber;
    cin >> choosenClientNumber;
    Client *choosenClient = dynamic_cast<Client *>(peopleArray[choosenClientNumber]);
    cout << endl;
    //Adding the client to lawyer array of costumers.
    choosenClient->setIsActive(true);
    choosenLawyer->operator+=(choosenClient);
}

void LawFirm::printAllDetailsOfLawyers() {
    for (int i = 0; i < NumberOfPeople; i++) {
        if (Lawyer *lawyer = dynamic_cast<Lawyer *>(peopleArray[i])) {

            cout << lawyer->getName();
            lawyer->salary();
            cout << endl;
        }
    }
}

void LawFirm::printActiveClients() {
    for (int i = 0; i < NumberOfPeople; i++) {
        if (Client *client = dynamic_cast<Client *>(peopleArray[i])) {
            if (client->getIsActive() == true) {
                client->printPersonData();
                cout << endl;
            }
        }
    }

}

void LawFirm::printLawyerDetailsWithMaxClients() {
    Lawyer *layerWithMaxClient = nullptr;
    int lawyerMaxClientNumber = 0;
    for (int i = 0; i < NumberOfPeople; i++) {
        if (Lawyer *lawyer = dynamic_cast<Lawyer *>(peopleArray[i])) {
            if (lawyer->getNumActiveClients() > lawyerMaxClientNumber) {
                layerWithMaxClient = lawyer;
            }
        }
    }
    layerWithMaxClient->printPersonData();
}

void LawFirm::closeClientCase() {
    //Print and choose lawyer:
    bool flag = true;
    cout << "There are the lawyers , please choose laywer's id : " << endl;
    for (int i = 0; i < NumberOfPeople; i++) {
        if (Lawyer *lawyer = dynamic_cast<Lawyer *>(peopleArray[i])) {
            cout << lawyer->getName() << " - " << lawyer->getId() << endl;
        }
    }
    Lawyer *lawyerChoosen = nullptr;

    while (flag == true) {
        cout << "Enter lawyer ID: " << endl;
        int idOfLawyer;
        cin >> idOfLawyer;
        for (int i = 0; i < NumberOfPeople; i++) {
            if (lawyerChoosen = dynamic_cast<Lawyer *>(peopleArray[i])) {
                if (lawyerChoosen->getId() == idOfLawyer) {
                    flag = false;//Meaning we had a match

                }
            }
        }
        if (flag == true) {
            cout << "Incorrect id, try again";
        }
    }
    //Print and choose client of lawyer:

    cout << "These are all his client : " << endl;
    Client **tempArrayOfClients = lawyerChoosen->getActiveClients();
    int numOfActiveClient = lawyerChoosen->getNumActiveClients();
    for (int i = 0; i < numOfActiveClient; i++) {
        cout << tempArrayOfClients[i]->getName() << " - " << tempArrayOfClients[i]->getId() << endl;
    }
    int idOfUser;
    cout << "Please enter id : " << endl;
    cin >> idOfUser;
    lawyerChoosen->closeClientCase(idOfUser);
}







