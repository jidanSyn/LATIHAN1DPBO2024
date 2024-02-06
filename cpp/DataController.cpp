#pragma once
#include <iostream>
#include <string>
#include <list>

#include "AnggotaDPR.cpp"

using namespace std;

class DataController
{
    private:
        list<AnggotaDPR> container; // container for all the data
    
    public:

        DataController() {
            // empty constructor, container will be initialized as an empty list
        }

        // getter and setter for container

        list<AnggotaDPR>& getContainer() {
            return this->container;
        }
        
        void setContainer(list<AnggotaDPR>& container) {
            this->container = container;
        }

        // searching a specific data using id
        list<AnggotaDPR>::iterator searchByID(string id) {

            bool found = false;
            list<AnggotaDPR>::iterator it = this->container.begin();    // iterator to find
            list<AnggotaDPR>::iterator it_found = it;   // iterator copy to store found data
            while(found != true && it != this->container.end()) {
                if(it->getId() == id) {
                    found = true;
                    it_found = it;  // store found data location
                }
                it++;
            }

            if(found) {
                return it_found;    // return found data location
            } else {
                return this->container.end(); // else return .end() to indicate data wasnt found
            }
        }

        void createData() {

            // temp variables for inputs
            string tempId, tempName, tempField, tempElectoralDistrict, tempPosition, tempParty;

            cout << "Please give attributes for new data:\n";
            cout << "ID : ";
            cin >> tempId;
            cout << "Name : ";
            cin >> tempName;
            cout << "Field : ";
            cin >> tempField;
            cout << "Electoral District : ";
            cin >> tempElectoralDistrict;
            cout << "Position : ";
            cin >> tempPosition;
            cout << "Party : ";
            cin >> tempParty;

            // instantiate an AnggotaDPR object with inputted values
            AnggotaDPR new_data(tempId, tempName, tempField, tempElectoralDistrict, tempPosition, tempParty);
            // push back new data to container
            this->container.push_back(new_data);

            cout << "Data has been successfully created!\n";

        }

        void modifyData() {

            string target_id;
            cout << "Please select data to modify by ID\n";
            cin >> target_id;
            list<AnggotaDPR>::iterator target = searchByID(target_id);
            if(target == this->container.end()) {
                cout << "Data was not found!\n";
                return;
            }

            string tempName, tempField, tempElectoralDistrict, tempPosition, tempParty;

            cout << "Data found. Please enter new data\n";
            cout << "Name : ";
            cin >> tempName;
            cout << "Field : ";
            cin >> tempField;
            cout << "Electoral District : ";
            cin >> tempElectoralDistrict;
            cout << "Position : ";
            cin >> tempPosition;
            cout << "Party : ";
            cin >> tempParty;

            target->setName(tempName);
            target->setField(tempField);
            target->setElectoralDistrict(tempElectoralDistrict);
            target->setPosition(tempPosition);
            target->setParty(tempParty);

            cout << "Data successfully modified!\n";

        }

        void deleteData() {

            string target_id;
            cout << "Please select data to modify by ID\n";
            cin >> target_id;

            list<AnggotaDPR>::iterator target = searchByID(target_id);
            char del_confirm_input;


            if(target == this->container.end()) {
                cout << "Data was not found!\n";
                return;
            }

            cout << "Data has been found:\n";
            
            // deletion confirmation
            cout << target->getId() << " | " << target->getName() << "\n\nConfirm to delete?(y/n)\n";
            cin >> del_confirm_input;
            if(del_confirm_input == 'y') {
                this->container.erase(target);
                cout << "Data has successfully been deleted\n";
            } else {
                cout << "Canceled data deletion\n";
            }
        }

        // method to show all data inside container
        void showContainer() {
            if(this->container.empty()) {
                cout << "There are no data stored.\n";
                return;
            }

            cout << "\nList of all stored data:\n";
            int i = 1;
            for(auto it = this->container.begin(); it != this->container.end(); it++, i++) {
                printf("%d. %-25s | %-15s | %-15s | %-15s | %-15s |\n", i, (it->getName()).c_str(), (it->getField()).c_str(), (it->getElectoralDistrict()).c_str(), (it->getPosition()).c_str(), (it->getParty()).c_str());
            }

            cout << "\n";
        }

        // destructor
        ~DataController() {

        }



};