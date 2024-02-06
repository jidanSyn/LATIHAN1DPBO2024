#include <bits/stdc++.h>
#include "AnggotaDPR.cpp"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;


enum input_choice {
    END,
    CREATE,
    MODIFY,
    DELETE,
    SHOW_ALL 
};

void show_all(list<AnggotaDPR> llist) {

    if(llist.empty()) {
        cout << "There are no data stored.\n";
        return;
    }

    cout << "\nList of all stored data:\n";
    int i = 1;
    for(auto it = llist.begin(); it != llist.end(); it++, i++) {
        printf("%d. %-25s | %-15s | %-15s | %-15s | %-15s |\n", i, (it->getName()).c_str(), (it->getField()).c_str(), (it->getElectoralDistrict()).c_str(), (it->getPosition()).c_str(), (it->getParty()).c_str());
    }

    cout << "\n";

}

int main() {

    int input_selection = -1;
    char del_confirm_input;
    bool found = false, del_confirm = false;
    list<AnggotaDPR> ListAnggotaDPR;

    string tempId, tempName, tempField, tempElectoralDistrict, tempPosition, tempParty;

    while(input_selection != END) {


        found = false, del_confirm = false;
        
        system(CLEAR);
        cout << "Welcome to DPR Information System!\n";

        cout << "What will you do? Select 1:\n 1. Create a new data\n 2. Modify an existing data\n 3. Delete a data\n 4. Show all existing data\n 0. End program\n";
        
        cin >> input_selection;

        cout << "Selected option: " << input_selection << "\n";

        switch(input_selection) {
            case END: {
                cout << "See you next time!\n";
                break;

            }
            case CREATE: {
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
                AnggotaDPR tempAnggota(tempId, tempName, tempField, tempElectoralDistrict, tempPosition, tempParty);
                ListAnggotaDPR.push_back(tempAnggota);
                
                cout << "Data has been successfully created!\n";
                break;
            }
            case MODIFY: {
                cout << "Please select data to modify by ID\n";
                cin >> tempId;

                auto it = ListAnggotaDPR.begin();
                while(found != true && it != ListAnggotaDPR.end()) {

                    if(it->getId() == tempId) {
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

                        it->setName(tempName);
                        it->setField(tempField);
                        it->setElectoralDistrict(tempElectoralDistrict);
                        it->setPosition(tempPosition);
                        it->setParty(tempParty);
                        found = true;
                    }
                    it++;
                }

                if(found == true) cout << "Data successfully modified!\n";
                else cout << "Data was not found!\n\n";
            
                break;
            }
            case DELETE: {
                cout << "Please select data to delete by ID\n";
                cin >> tempId;

                auto it = ListAnggotaDPR.begin();
                auto it_found = it;
                while(found != true && it != ListAnggotaDPR.end()) {

                    if(it->getId() == tempId) {
                        found = true;
                        it_found = it;
                    }
                    it++;
                }

                if(found) {
                    cout << "Data has been found:\n";
                    cout << it_found->getId() << " | " << it_found->getName() << "\n\nConfirm to delete?(y/n)\n";
                    cin >> del_confirm_input;
                    if(del_confirm_input == 'y') {
                        ListAnggotaDPR.erase(it_found);
                        cout << "Data has successfully been deleted\n";
                    } else {
                        cout << "Canceled data deletion\n";
                    }
                    del_confirm_input = '-';
                    found = false;
                } else {
                    cout << "Data was not found!\n";
                }

                break;
            }
            case SHOW_ALL: {
                
                show_all(ListAnggotaDPR);
                
                break;
            }
            default: {
                cout << "Invalid option!\n";
                break;
            }

        }

        getchar();
        cout << "\nPress any key to continue...\n";
        getchar();   
        
    }

    return 0;

}