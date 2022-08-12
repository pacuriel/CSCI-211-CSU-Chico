#include <iostream>
using namespace std;

// swtichToText prototype
void switchToText(int userInput);

// Funtion to switch user input to text form
void switchToText(int userInput) {

    // while loop for as long as user inputs an integer
    while (cin >> userInput) {

        // switch statement to translate integers to text form
        switch (userInput) {

        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "one" << endl;
            break;
        case 2:
            cout << "two" << endl;
            break;
        case 3:
            cout << "three" << endl;
            break;
        case 4:
            cout << "four" << endl;
            break;
        case 5:
            cout << "five" << endl;
            break;
        case 6:
            cout << "six" << endl;
            break;
        case 7:
            cout << "seven" << endl;
            break;
        case 8:
            cout << "eight" << endl;
            break;
        case 9:
            cout << "nine" << endl;
            break;
        }
    }
}

// Main function
int main() {

    // Declaring integer variable
    int userInt = 0;

    // Calling switchToText function
    switchToText(userInt);

    // Returning 0 from main() when program is finished
    return 0;
}
