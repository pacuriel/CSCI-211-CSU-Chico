#include <iostream>
using namespace std;

// Main function
int main() {

    // Declaring integer variables for input and return from main
    int userInput;

    // Boolean flag assuming values will be all even
    bool allEven = true;

    // while loop for as long as user inputs an integer
    while (cin >> userInput) {

        // if statement checking if input is odd
        if (userInput % 2 != 0) {

            // Set boolean flag to false if odd
            allEven = false;
        }
    }

    // if-else statement deciding what to print
    if (allEven == true) {

        cout << "all even" << endl;
    }
    else {

        cerr << "not all even" << endl;

        // return 1 from main if not all even
        return 1;
    }

    // Returning 0 when program is finished
    return 0;
}
