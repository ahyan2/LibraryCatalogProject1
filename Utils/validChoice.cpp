#include <iostream> // for print

using namespace std;

char validChoice(){
    char choice;
    while (true){
        cout << "Type 'y' for Yes, or 'n' for No." << endl;
        cin >> choice;

        choice = tolower(choice);
        if(choice == 'y' || choice == 'n'){
            break;
        } else {
            cout << "Invalid... Please type either y or n " << endl;
        }
    }
    return choice;
}
