#include <iostream> // for print

#include "validChoice.hpp"
#include "validID.hpp"
#include "globalVariables.hpp"

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
