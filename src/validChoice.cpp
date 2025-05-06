#include <iostream> // for print

using namespace std;

char validChoice(){
    char choice;
    while (true){
        cout << "Type 'y' for Yes, or 'n' for No." << endl;
        cin >> choice;

        choice = tolower(choice);
        if(choice == 'y' || choice == 'n'){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // remove input buffer if user types multiple characters
            break;
        } else {
            cout << "Invalid... Please type either y or n " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');        // remove input buffer if user types multiple characters
        }
    }
    return choice;
}
