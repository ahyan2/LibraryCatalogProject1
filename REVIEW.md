# Peer review
## Code Structure & CMake
Clean source file structure and CMakeLists.txt work as intended.

## Modularity & Readability
The code heavily used global variables without using namespaces or function parameters, which lowered its modularity and readability.

## Test Coverage
The tests cover most edge cases, but don't count on the possibility of ID numbers followed by additional characters, which should be treated as invalid IDs.

## Bugs or Gaps Identified
When the user enters an ID number with the correct number of digits followed by additional characters started with a non digit character, the program will consider the first part of the input as a valid ID number and leave the rest of the characters in the input buffer, which causes the next input check to fail.

## Test Output & Clarity
The tests all have names that clearly state their purpose, which boosts the clarity of the test output.

## Additional test cases
```c++
// Additional validIDTests
TEST(ValidIDTests, NumericStudentIDWithDecimals) {
    istringstream in("12345678.9\n87654321\n");
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();
    // must finally return the 8‑digit number "87654321"
    EXPECT_EQ(validID(8), 87654321);
    cin.rdbuf(old);
}

TEST(ValidIDTests, NumericStudentIDWithAdditionalAlphabets) {
    istringstream in("12345678ABC\n87654321\n");
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();
    // must finally return the 8‑digit number "87654321"
    EXPECT_EQ(validID(8), 87654321);
    cin.rdbuf(old);
}

TEST(ValidIDTests, NumericStudentIDWithSpecialCharacters) {
    istringstream in("12345678！@#\n87654321\n");
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();
    // must finally return the 8‑digit number "87654321"
    EXPECT_EQ(validID(8), 87654321);
    cin.rdbuf(old);
}

TEST(ValidIDTests, NumericBookIDWithDecimals) {
    istringstream in("12345.6\n54321\n");
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();
    // must finally return the 5‑digit number "54321"
    EXPECT_EQ(validID(5), 54321);
    cin.rdbuf(old);
}

TEST(ValidIDTests, NumericBookIDWithAdditionalAlphabets) {
    istringstream in("12345ABC\n54321\n");
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();
    // must finally return the 5‑digit number "54321"
    EXPECT_EQ(validID(5), 54321);
    cin.rdbuf(old);
}

TEST(ValidIDTests, NumericBookIDWithSpecialCharacters) {
    istringstream in("12345！@#\n54321\n");
    auto* old = cin.rdbuf(in.rdbuf());
    cin.clear();
    // must finally return the 5‑digit number "54321"
    EXPECT_EQ(validID(5), 54321);
    cin.rdbuf(old);
}
```

## Architecture & Design Feedback
In real-life scenarios, it's unlikely that a library only has one copy of each book; it should also allow adding & removing books from the catalog, and retain a record of the information as files so they won't reset every time this program runs.
And to improve the modularity and readability of the code, it's better to use function parameters (passing by reference) and namespaces, and create a struct or class to manage books instead of storing the info in multiple separate arrays.