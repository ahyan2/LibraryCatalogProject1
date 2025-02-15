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

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



int main() {    // display iomanip and call functions here
    
    cout << setw(40) << setfill('=') << " " << setfill(' ') << endl;
    cout << "Hello, welcome to the virtual library!" << endl;

    
    return 0;
}
