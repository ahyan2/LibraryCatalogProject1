#include <iostream> // for print

using namespace std;

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
