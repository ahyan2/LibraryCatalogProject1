High-level overview:
- A C++ Program which acts as an interactable library catalog.



Components:
- main()
- displayWelcome()
- validID(int givenDigits)
- validChoice()
- validFirstName()
- displayBooks()
- userCatalogInteraction()
- checkOut()
- awaitingCheckIn()
- checkIn()
- displayGoodbye()
- globalVariables



Link to Video Presentation:
- https://drive.google.com/drive/folders/1TRdiC10MAbiSnj9Ho0OVQU5c3khyNXtt?usp=drive_link



Sources Used:
- https://www.geeksforgeeks.org/
- https://stackoverflow.com/



In-depth functionality:
- main()
    - Calls functions necessary to complete a proper library-user interaction, (display functions and interaction functions)
- displayWelcome()
    - Displays a welcome message with IO manipulation formatting.
    - Pauses for 2 seconds using chrono and thread libraries.
    - Prompts the user to enter their first name and validates it.
    - Prompts the user to enter an 8-digit student ID and validates it.
    - Asks for user confirmation of name and ID.
    - Loops until valid input is confirmed.
- validID(int givenDigits)
    - Prompts the user to enter an integer ID.
    - Validates the input is a positive integer.
    - If invalid, function will discard input, display error message, and restates prompt.
    - Counts the number of digits in the input.
    - If the number of digits matches givenDigits, the function returns the valid ID.
    - If invalid, Repeats process until valid input is provided.
- validChoice()
    - Prompts the user to enter 'y' for Yes or 'n' for No.
    - Converts the input to lowercase using tolower(choice).
    - If input is 'y' or 'n', clears input buffer and breaks the loop to return the value.
    - If input is invalid, displays an error message and clears input buffer before looping to start again.
- validFirstName()
    - Checks if input is empty and re-prompts if it is.
    - Validates that all characters are alphabetic via isalpha function
    - Returns first name once input is properly validated.
- displayBooks()
    - Uses IO manipulation to display books to user
    - Added time delay for better readability
    - Prints book info (numberID, author, title, genre) from respective vectors by using a for-loop with an iterable.
- userCatalogInteraction()
    - Asks user if they would like to checkout a book
    - If so, user is redirected to checkOut() function and then new display of books is printed. User is then also able to check-in their book.
    - Potential calls to checkOut(), checkIn(), and awaitingCheckIn()
    - Check-in portion is skipped if user does not checkout a book.
- checkOut()
    - User asked to check out book using numberID
    - Validates numberID
    - Adds checked-out book information to respective vectors (removedNumberID, removedAuthor, etc.)
    - Removes checked-out book information from original respective vectors (numberID, author, etc.)
- awaitingCheckIn()
    - If user declines initial check-in prompt, automated message beings simulating passing of time
    - User now forced to check-in their book via a call to validChoice() and then to checkIn()
- checkIn()
    - Loops through original book info vectors and checks compares numberID values to see where removed book info vector should be inserted
    - Special check to see if original book info vector is placed at the end
    - Properly inserts book back to original book info vectors, and erases the information from removed book info vectors
- displayGoodbye()
    - uses IO manipulation to display a goodbye message to the user
    - Specifically refers to user by the name they input earlier via global variable usage
- globalVariables
    - Stores global variables used across multiple functions via extern keyword
    - Holds vectors with book info (numberID, author, title, genre) and removed (checked-out) book info.
    - Holds information regarding student first name and student ID number.
