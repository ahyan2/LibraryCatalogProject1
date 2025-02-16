#include <iostream> // for print
#include <string>   // for strings
#include <iomanip>  // for display manip
#include <vector>


#include "globalVariables.hpp"
#include "validChoice.hpp"

using namespace std;

void displayBooks(){
    cout << setw(40) << setfill('=') << " " << setfill(' ') << endl;
    cout << "Hello " << name << ", here is our library catalog!" << endl << endl;
    
    cout << right << setw(47) << "* Current Books *" << endl;
    
    cout << left << setw(20) << "ID" << setw(20) << "Author" << setw(20) << "Genre" << "Title" << endl;

    cout << setw(80) << setfill('-') << "" << endl;
    
    for(int i = 0; i < numberID.size(); i++){
        cout << right << setw(5) << setfill('1') << numberID[i] << setfill(' ') << setw(10) << "" << left << setw(20) << author[i] << setw(20) << genre[i] << setw(20) << title[i] << endl;
    }
    
}
