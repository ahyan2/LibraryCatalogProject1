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
            removedNumberID.push_back(numberID[arrIndex]);      // adds value at arrIndex to vector
            removedAuthor.push_back(author[arrIndex]);
            removedGenre.push_back(genre[arrIndex]);
            removedTitle.push_back(title[arrIndex]);
            
            numberID.erase(numberID.begin() + arrIndex);     // removes value at arrIndex from vector
            author.erase(author.begin() + arrIndex);
            genre.erase(genre.begin() + arrIndex);
            title.erase(title.begin() + arrIndex);
            break;
        }
    }
}

bool checkIn(){
    for (int index = 0; index < numberID.size();  index++){
        if (removedNumberID[0] < numberID[index]){
            numberID.insert(numberID.begin() + index, removedNumberID[0]);
            author.insert(author.begin() + index, removedAuthor[0]);
            genre.insert(genre.begin() + index, removedGenre[0]);
            title.insert(title.begin() + index, removedTitle[0]);
            
            removedNumberID.erase(removedNumberID.begin());
            removedAuthor.erase(removedAuthor.begin());
            removedGenre.erase(removedGenre.begin());
            removedTitle.erase(removedTitle.begin());
            
            displayBooks();     // will only display books again once user checks book back in via this function.
            return true;    // doesn't execute final code segment if book info already inserted (true value doesn't matter)
        }
    }
    numberID.push_back(removedNumberID[0]);
    author.push_back(removedAuthor[0]);
    genre.push_back(removedGenre[0]);
    title.push_back(removedTitle[0]);
    
    displayBooks();
    return true;    // in case element removed was largest in original arrays. (true value doesn't matter)
}



void awaitingCheckIn(){
    this_thread::sleep_for(chrono::seconds(1));
    for(int i = 0; i < 15; i++){
        cout << '.' << endl;
    }
    int daysPassed = 1;
    while (daysPassed <= 7){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Days passed since checkout: "<< daysPassed << endl;
        daysPassed++;
    }
    while(true){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Hello " << name << " (SID " << studentID << "), your book is overdue! Please check it back in." << endl;
        cout << endl << "Would you like to check-in your book?" << endl;
        char choice = validChoice();
        if (choice == 'y'){
            checkIn();
            this_thread::sleep_for(chrono::seconds(2));
            cout << endl << "Thank you " << name << " for returning your book!" << endl << endl;
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

void displayGoodbye(){
    cout << setw(60) << setfill('*') << " " << setfill(' ') << endl;

    cout << "Thank you " << name << " for visiting our virtual library, We hope to see you again soon!" << endl;
    
    cout << setw(60) << setfill('*') << " " << setfill(' ') << endl;
}


int main() {
    displayWelcome();
    displayBooks();
    userCatalogInteraction();
    displayGoodbye();
    
    return 0;
}
