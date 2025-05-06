#include <iostream> // for print

using namespace std;

int validID(int givenDigits){
    int num;
    while (true){
        cin >> num;
        
        if (cin.fail() || num <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid... Please enter the correct ID" << endl;
        } else {    // input is int and pos, now check if it is correct digits or not
            int digits = 0;
            int numCopy = num;
            while(numCopy > 0){
                numCopy /= 10;
                digits++;
            }
            if (digits == givenDigits){
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid... Please enter the correct ID" << endl;
        }
    }
    return num;
}
