// chart
// Curiel, Pablo
// pacuriel

#include <iostream>
using namespace std;

// Function prototypes
void storeInput(int inputValues[], int arraySize);
int findLargestInt(int inputValues[], int arraySize);
void printChart(int inputValues[], int arraySize);

// Function to store using input in an array
void storeInput(int inputValues[], int arraySize) {

    // for loop to store user input with stdin
    for (int i = 0; i < arraySize; i++) {
        cin >> inputValues[i];

        // if statement to end for loop if user inputs 0
        if (inputValues[i] == 0) {
            break;
        }
    }
}

// Function to return the largest integer in an array
int findLargestInt(int inputValues[], int arraySize) {

    // Setting largestInt to 0 to compare to user input
    int largestInt = 0;

    // for loop to find largest integer
    for (int i = 0; i < arraySize; i++) {

        // if statement comparing user input to largestInt
        if (largestInt < inputValues[i]) {
            // Setting largestInt = to user input when less than
            largestInt = inputValues[i];
        }

        // if statement to end for loop if user inputs 0
        if (inputValues[i] == 0) {
            break;
        }
    }

    // Returing largestInt
    return largestInt;
}

// ADD COMMENTS FOR STUFF THAT DOESNT HAVE ONE YET
void printChart(int inputValues[], int arraySize) {

    // Calling findLargestInt to find value for largestInputValue
    int largestInteger = findLargestInt(inputValues, arraySize);

    // for loop to print rows of output
    for (int i = largestInteger; i > 0; i--) {

        // for loop to print columns of output
        for (int j = 0; j < arraySize; j++) {

            // if statement to end for loop if user inputs 0
            if (inputValues[j] == 0) {
                break;
            }

            // if-else-if statement to print asterisk or space
            if (inputValues[j] >= i) {
                cout << "*";
            }
            else if (inputValues[j] < i){
                cout << " ";
            }
        }

        // endl to print on new row
        cout << endl;
    }
}

// Main function
int main() {

    // Declaring a constant int for max array size
    const int MAX_VALUES = 100;

    // Declaring array to store user inputs
    int userValues[MAX_VALUES];

    // Calling storeInput to store user input using stdin
    storeInput(userValues, MAX_VALUES);

    // Calling printChart to print output
    printChart(userValues, MAX_VALUES);

    // Returning 0 from main when program is finished
    return 0;
}
