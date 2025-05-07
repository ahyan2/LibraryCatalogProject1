cmake_minimum_required(VERSION 3.15)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add GoogleTest
add_subdirectory(extern/googletest)

# Include paths
include_directories(include)

# Main application
add_executable(MyProjectApp
        main.cpp
        src/awaitingCheckIn.cpp
        src/checkIn.cpp
        src/checkOut.cpp
        src/displayBooks.cpp
        src/displayGoodbye.cpp
        src/displayWelcome.cpp
        src/globalVariables.cpp
        src/userCatalogInteraction.cpp
        src/validChoice.cpp
        src/validFirstName.cpp
        src/validID.cpp
)
target_include_directories(MyProjectApp PRIVATE include)

# Test executable
add_executable(MyProjectTests
        test/utilsTest.cpp
        src/awaitingCheckIn.cpp
        src/checkIn.cpp
        src/checkOut.cpp
        src/displayBooks.cpp
        src/displayGoodbye.cpp
        src/displayWelcome.cpp
        src/globalVariables.cpp
        src/userCatalogInteraction.cpp
        src/validChoice.cpp
        src/validFirstName.cpp
        src/validID.cpp
)
target_include_directories(MyProjectTests PRIVATE include)
target_link_libraries(MyProjectTests gtest_main)

# Enable testing
enable_testing()
include(GoogleTest)
gtest_discover_tests(MyProjectTests)