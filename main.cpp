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

#include <iostream> // for print
#include <string>   // for strings
#include <iomanip>  // for display manip
#include <chrono>   // for time delay
#include <thread>   // for time delay

using namespace std;


string validString(){
    string name;

    while (true) {
        getline(cin, name);

        if (name.empty()) {
            cout << "Invalid... Please enter your first name" << endl;
        } else {
            break;
        }
    }
    return name;
}


int validInt(){
    int num;
    while (true){
        cin >> num;
        
        if (cin.fail() || num <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid... Please enter your 8-digit student ID" << endl;
        } else {    // input is int and pos, now check if it is 8 digits or not
            int digits = 0;
            int numCopy = num;
            while(numCopy > 0){
                numCopy /= 10;
                digits++;
            }
            if (digits == 8){
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid... Please enter your 8-digit student ID" << endl;
        }
    }
    return num;
}


void displayWelcome(){
    cout << setw(40) << setfill('=') << " " << setfill(' ') << endl;
    cout << "Hello, welcome to the virtual library!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    
    cout << "What is your first name?" << endl;
    string name = validString();
    
    cout << "What is your 8-digit student ID?" << endl;
    int studentID = validInt();
    
    cout << setw(40) << setfill('=') << " " << setfill(' ') << endl;
    cout << "Please confirm if this is your first name and SID: " << name << ", " << studentID << endl;

}


int main() {
    displayWelcome();

    
    return 0;
}
