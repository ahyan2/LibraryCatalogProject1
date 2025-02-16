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
#include <cctype>   // for isalpha

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

string validFirstName(){
    string name;
    while (true) {
        getline(cin, name);
        bool isValid = true;

        if (!name.empty()) {    // if input is not empty, continue  with check
            for (char c : name) {   // check if each character is in the alphabet (only letters)
                if (!isalpha(static_cast<unsigned char>(c))) { // correct handling of char values
                    isValid = false;    // if any char is not a letter, set bool false, invalid input
                    break;
                }
            }
        }

        if (!isValid) {
            cout << "Invalid... Please enter only your first name" << endl;
        } else {
            break;
        }
    }
    return name;
}


int validStudentID(){
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
    
    while (true){
        cout << "What is your first name?" << endl;
        string name = validFirstName();
        
        cout << "What is your 8-digit student ID?" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "*** NOTE: A valid student ID does not start with zero (0) ***" << endl;
        int studentID = validStudentID();
        
        cout << setw(40) << setfill('=') << " " << setfill(' ') << endl;
        cout << "Please confirm if this is your first name and SID: " << name << ", " << studentID << endl;
        this_thread::sleep_for(chrono::seconds(1));
        char choice = validChoice();
        if (choice == 'y'){
            break;
        } else {
            cout << "Got it, let's start over." << endl;
            cout << setw(40) << setfill('=') << " " << setfill(' ') << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // clearing buffer for fresh inputs
            this_thread::sleep_for(chrono::seconds(2));
        }
    }

}


int main() {
    displayWelcome();
    cout << "Complete!" << endl;

    
    return 0;
}
