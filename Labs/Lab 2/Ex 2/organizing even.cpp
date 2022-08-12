#include <iostream>
using namespace std;

// Main function
int main() {

    // Declaring integer variables for input and return from main
    int userInput, returnFromMain;

    // Boolean flag assuming values will be all even
    bool allEven = true;

    // while loop for as long as user inputs an integer
    while (cin >> userInput) {

        // if statement checking if input is odd
        if (userInput % 2 != 0) {

            // Set boolean flag to false if odd
            allEven = false;

            // if-else statement to return 0 or 1 from main
            if (allEven = true) {

                returnFromMain = 0;
            }
            else if (allEven = false){

                returnFromMain = 1;
            }
        }
    }

    // if-else statement deciding what to print
    if (returnFromMain = 0) {

        cout << "all even" << endl;
    }
    else if (returnFromMain = 1) {

        cerr << "not all even" << endl;
    }

    // Returning 0 from main() when program is finished
    return returnFromMain;
}
