// test/utilsTest.cpp

#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <functional>
#include "../include/globalVariables.hpp"
#include "../include/validID.hpp"
#include "../include/validFirstName.hpp"
#include "../include/validChoice.hpp"
#include "../include/checkOut.hpp"
#include "../include/checkIn.hpp"
#include "../include/displayBooks.hpp"
#include "../include/displayWelcome.hpp"
#include "../include/displayGoodbye.hpp"

using namespace std;

// Helper function
static string captureOutput(function<void()> fn) {
    ostringstream buf;
    auto* old = cout.rdbuf(buf.rdbuf());
    fn();
    cout.rdbuf(old);
    return buf.str();
}

// validID
TEST(ValidIDTests, RejectsNonNumericAndNegativeThenAccepts) {
    istringstream in("foo\n-1\n123\n001234\n54321\n");
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();
    // must finally return the 5‑digit number "54321"
    EXPECT_EQ(validID(5), 54321);
    cin.rdbuf(old);
}

// validFirstName
TEST(ValidFirstNameTests, RejectsEmptyAndNonAlphaThenAccepts) {
    istringstream in("\nJohn3\nAlice\n");
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();
    EXPECT_EQ(validFirstName(), "Alice");
    cin.rdbuf(old);
}

// validChoice
TEST(ValidChoiceTests, RejectsInvalidThenAcceptsYandN) {
    // first Y test
    {
      istringstream in("maybe\nY\n");
      auto* old = cin.rdbuf(in.rdbuf());
      cin.clear();
      EXPECT_EQ(validChoice(), 'y');
      cin.rdbuf(old);
    }
    // then N test
    {
      istringstream in("z\nn\n");
      auto* old = cin.rdbuf(in.rdbuf());
      cin.clear();
      EXPECT_EQ(validChoice(), 'n');
      cin.rdbuf(old);
    }
}

// checkOut / checkIn
TEST(CheckOutCheckInTests, MovesOneBookAndReturnsIt) {
    // reset globals to three sample books with 5-digit IDs
    numberID    = {11111, 11112, 11113};
    author      = {"A","B","C"};
    genre       = {"G1","G2","G3"};
    title       = {"T1","T2","T3"};
    removedNumberID.clear();
    removedAuthor.clear();
    removedGenre.clear();
    removedTitle.clear();

    // simulate input: pick ID=11112 (index 1), then 'y'
    istringstream in("11112\ny\n");
    auto* oldCin = cin.rdbuf(in.rdbuf());
    cin.clear();

    checkOut();
    cin.rdbuf(oldCin);

    // after checkout, removed vectors size ==1, original shrunk
    EXPECT_EQ(removedNumberID.size(), 1u);
    EXPECT_EQ(numberID.size(), 2u);
    EXPECT_EQ(removedTitle[0], "T2");

    // now checkIn()
    string out = captureOutput([](){
        EXPECT_TRUE(checkIn());
    });
    // removed cleared, original back to size 3
    EXPECT_TRUE(removedNumberID.empty());
    EXPECT_EQ(numberID.size(), 3u);
    // displayBooks printed the header with "* Current Books *"
    EXPECT_NE(out.find("* Current Books *"), string::npos);
}

// displayBooks
TEST(DisplayBooksTests, PrintsCatalogHeaderAndEntries) {
    numberID = {1,2};
    author   = {"X","Y"};
    genre    = {"Gx","Gy"};
    title    = {"Tx","Ty"};
    name     = "Tester";

    string out = captureOutput([](){ displayBooks(); });
    EXPECT_NE(out.find("Current Books"), string::npos);
    EXPECT_NE(out.find("1"), string::npos);
    EXPECT_NE(out.find("2"), string::npos);
}

// displayWelcome
TEST(DisplayWelcomeTests, RejectsBadNameAndIDThenAccepts) {
    // simulate: bad first name, then good; bad ID, then good; then confirm 'y'
    // no second loop iteration
    istringstream in(
      "Bob3\n"       // invalid name
      "Bob\n"        // valid name
      "00000001\n"   // invalid 8‑digit ID (leading zero → 1 digit)
      "12345678\n"   // valid 8‑digit ID
      "y\n"          // confirm and exit
    );
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();

    string out = captureOutput([](){ displayWelcome(); });
    // must at least greet
    EXPECT_NE(out.find("Hello, welcome to the virtual library!"), string::npos);
    // should have prompted for name and for student ID
    EXPECT_NE(out.find("What is your first name?"), string::npos);
    EXPECT_NE(out.find("What is your 8-digit student ID?"), string::npos);

    cin.rdbuf(old);
}


// displayGoodbye
TEST(DisplayGoodbyeTests, PrintsFarewell) {
    name = "Alice";
    string out = captureOutput([](){ displayGoodbye(); });
    EXPECT_NE(out.find("Thank you Alice"), string::npos);
}
