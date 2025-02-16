#include "displayBooks.hpp"
#include "globalVariables.hpp"

#include <iostream> // for print

using namespace std;

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
