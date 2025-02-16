#include "Utils/displayWelcome.hpp"     // contains validChoice, validFirstName, validStudentID
#include "Utils/displayBooks.hpp"
#include "globalVariables.hpp"
#include "Utils/userCatalogInteraction.hpp"
#include "Utils/displayGoodbye.hpp"

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
