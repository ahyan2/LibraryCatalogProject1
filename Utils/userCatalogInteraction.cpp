#include <iostream> // for print
#include <chrono>   // for time delay
#include <thread>   // for time delay
#include "globalVariables.hpp"
#include "checkIn.hpp"
#include "checkOut.hpp"
#include "validChoice.hpp"
#include "displayBooks.hpp"
#include "awaitingCheckIn.hpp"

using namespace std;

void userCatalogInteraction(){
    this_thread::sleep_for(chrono::seconds(2));
    cout << endl << "Would you like to checkout a book?" << endl;
    char choice = validChoice();
    if (choice == 'y'){
        checkOut();
        this_thread::sleep_for(chrono::seconds(1));
        cout << endl;
        displayBooks();
        
        this_thread::sleep_for(chrono::seconds(1));
        
        cout << endl << "Would you like to check-in your book?" << endl;       // only able to check-in book after checking out a book
        choice = validChoice();
        if (choice == 'y'){
            checkIn();
            this_thread::sleep_for(chrono::seconds(1));
            cout << endl << "Thank you " << name << " for returning your book!" << endl << endl;
            this_thread::sleep_for(chrono::seconds(1));
        } else{
            awaitingCheckIn();
        }
    }
}
