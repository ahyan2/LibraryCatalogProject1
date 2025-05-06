#include "include/displayWelcome.hpp"     // contains validChoice, validFirstName, validStudentID
#include "include/displayBooks.hpp"
#include "include/globalVariables.hpp"
#include "include/userCatalogInteraction.hpp"
#include "include/displayGoodbye.hpp"

#include <iostream> // for print
#include <string>   // for strings
#include <iomanip>  // for display manip
#include <chrono>   // for time delay
#include <thread>   // for time delay
#include <cctype>   // for isalpha

using namespace std;


int main() {
    displayWelcome();
    displayBooks();
    userCatalogInteraction();
    displayGoodbye();
    
    return 0;
}
