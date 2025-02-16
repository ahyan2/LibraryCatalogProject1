/*
Library Catalog System.
A program which properly displays available books by: Author name, book title, and book genre (Fiction, History, Poetry, etc.).
Ability to check-out books to students and check-in books back to library, updating availability in catalog with a status label.
Allowing students to place a hold on checked-out books, which will automatically put the book in their name after it is returned by the previous student.
Ability to “donate” books, giving new books to library and adding them to overall catalog.
Ensuring only one book can be checked out to each student at a time.
Using I/O manipulation to display catalog. Using overloaded methods to search for books via author, title, genre. Ensuring user input for such commands is valid, (such as entering a value between a range of integers to select a predefined action, or using get_line to accept inputs containing multiple words).
*/

//Ensure that system integrity is maintained by implementing rules such as one book per student, requiring checks for existing checkouts before allowing further transactions.


#include "Utils/displayWelcome.hpp"     // contains validChoice, validFirstName, validStudentID
#include "Utils/displayBooks.hpp"
#include "globalVariables.hpp"

#include <iostream> // for print
#include <string>   // for strings
#include <iomanip>  // for display manip
#include <chrono>   // for time delay
#include <thread>   // for time delay
#include <cctype>   // for isalpha

using namespace std;



void checkOut(){
    while (true){
        cout << "Enter the 5-digit book ID:" << endl;
        int arrIndex = -1;
        while(true){
            int bookID = validID(5);
            if (bookID >= 11111 && bookID <= 11115){
                arrIndex = (bookID % 10) - 1;
                break;
            } else {
                cout << "Invalid, try again." << endl;
            }
        }
        cout << "Is this the book you would like to checkout?" << endl;
        cout << "*** " << title[arrIndex] << ", by " << author[arrIndex] << " ***" << endl;
        char choice = validChoice();
        if (choice == 'y'){
            numberID.erase(numberID.begin() + arrIndex);     // removes value at arrIndex from vector
            author.erase(author.begin() + arrIndex);
            genre.erase(genre.begin() + arrIndex);
            title.erase(title.begin() + arrIndex);
            break;
        }
    }
}


void userCatalogInteraction(){
    this_thread::sleep_for(chrono::seconds(2));
    cout << endl << "Would you like to checkout a book?" << endl;
    char choice = validChoice();
    if (choice == 'y'){
        checkOut();
    }
    cout << endl << "Would you like to donate/check-in a book?" << endl;
    choice = validChoice();
    if (choice == 'y'){
        //
    }
}


int main() {
//    displayWelcome();
    displayBooks();
    userCatalogInteraction();
    displayBooks();

    
    return 0;
}
