#include <iostream> // for print
#include <iomanip>
#include "globalVariables.hpp"

using namespace std;

void displayGoodbye(){
    cout << setw(60) << setfill('*') << " " << setfill(' ') << endl;

    cout << "Thank you " << name << " for visiting our virtual library, We hope to see you again soon!" << endl;
    
    cout << setw(60) << setfill('*') << " " << setfill(' ') << endl;
}
