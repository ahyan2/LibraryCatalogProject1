#include <iostream> // for print
#include <string>   // for strings
#include <iomanip>  // for display manip
#include <chrono>   // for time delay
#include <thread>   // for time delay

#include "globalVariables.hpp"
#include "validChoice.hpp"

using namespace std;

void displayBooks(){
    cout << setw(40) << setfill('=') << " " << setfill(' ') << endl;
    cout << "Hello " << name << ", here is our library catalog!" << endl << endl;
    
    int numberID[] = {1, 2, 3, 4, 5};
    string author[] = {"George Orwell", "Harper Lee", "Suzanne Collins", "George Orwell", "Andy Weir"};
    string title[] = {"Animal Farm", "To Kill a Mockingbird", "The Hunger Games", "1984", "The Martian"};
    string genre[] = {"Satire", "Historic Fiction", "Dystopia", "Dystopia", "SciFi" };
    
    
    cout << right << setw(47) << "* Current Books *" << endl;
    
    cout << left << setw(20) << "ID" << setw(20) << "Author" << setw(20) << "Genre" << "Title" << endl;

    cout << setw(80) << setfill('-') << "" << endl;
    
    for(int i = 0; i < size(numberID); i++){
        cout << right << setw(5) << setfill('0') << numberID[i] << setfill(' ') << setw(10) << "" << left << setw(20) << author[i] << setw(20) << genre[i] << setw(20) << title[i] << endl;
    }
    
    this_thread::sleep_for(chrono::seconds(2));
    cout << endl << "Would you like to checkout a book?" << endl;
    char choice = validChoice();
    if (choice == 'y'){
        cout << "Got it, checking out book now" << endl;        //TODO: add implementation
    }
    cout << endl << "Would you like to donate a book?" << endl;
}
