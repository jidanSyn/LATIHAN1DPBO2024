#include <bits/stdc++.h>
#include "AnggotaDPR.cpp"
#include "DataController.cpp"


// if else for compatibility on clearing console, cmd for windows takes "cls" and linux terminal takes "clear"
#ifdef _WIN32
#define CLEAR "cls"
#elif __linux__
#define CLEAR "clear"
#endif

using namespace std;

// enumeration between menu choices to make code more readable
enum input_choice {
    END,
    CREATE,
    MODIFY,
    DELETE,
    SHOW_ALL 
};


int main() {

    int input_selection = -1; // initialize input selection to -1 for an unused/invalid value

    string selected_id; // helper variable for selecting specific data to modify/delete

    DataController data_controller;     // data controller instantiation with already default empty AnggotaDPR list


    // menu while loop
    while(input_selection != END) {     

        system(CLEAR); // clear console

        cout << "Welcome to DPR Information System!\n";
        cout << "What will you do? Select 1:\n 1. Create a new data\n 2. Modify an existing data\n 3. Delete a data\n 4. Show all existing data\n 0. End program\n";
        
        cin >> input_selection;

        cout << "Selected option: " << input_selection << "\n";

        switch(input_selection) {

            case END:
                cout << "See you next time!\n";
                break;

            case CREATE: 
                data_controller.createData();
                break;
            
            case MODIFY: 
                data_controller.modifyData();
                break;
            
            case DELETE: 
                data_controller.deleteData();
                break;
            
            case SHOW_ALL: 
                data_controller.showContainer();
                break;
            
            default: 
                cout << "Invalid option!\n";
                break;

        }

        // same as system pause in effect, so that outputs of each methods arent immediately cleared
        if(input_selection != END) {
            getchar();
            cout << "\nPress any key to continue...\n";
            getchar();   

        }

        
    }

    return 0;

}