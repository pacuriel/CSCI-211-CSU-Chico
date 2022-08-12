// calc.cpp
// Curiel, Pablo
// pacuriel
#include <iostream>
#include <cctype>
#include "dstack.h"
using namespace std;

// Bool function to check for operator
bool isOperator(char& possible_operator) {
    bool result = false; // Setting result to false
    char operators[] = {'+', '-', '*', '/', '^'};
    // for loop checking for correctly inputted operator
    for(int i = 0; i < 5; i++) {
        if (possible_operator == operators[i]) {
            result = true; // Setting result to true if match
        }
    }
    return result;
}

// Method to perform operations; returns a double
double performOperations(char &operators, double value1, double value2) {
    double result; // double to store expression result
    if (operators == '+') { result = (value1 + value2); }
    else if (operators == '-') { result = (value1 - value2); }
    else if (operators == '*') { result = (value1 * value2); }
    else if (operators == '/') { result = (value1 / value2); }
    else if (operators == '^') {
        result = 1; // Setting result equal to 1
        for (int i = 0; i < value2; i++) {
            result *= value1;
        }
    }
    return result; // Returning result
}

// Method to identify inputted operands and decimal errors
bool checkForOperand(Dstack &stack, double &operand) {
    bool result = false; // Initializing result
    // Checking for number with or without decimal
    if (isdigit(cin.peek()) || cin.peek() == '.') {
        cin >> operand; // Inputting operand
        stack.push(operand); // Pushing the operand onto the stack
        // Checking for invalid decimal input
        if (cin.peek() == '.') {
            // Outputting error message using standard error
            cerr << "Error: Invalid expression." << endl;
            exit(1); // Terminating program
        }
        result = true; // Setting result to true
    }
    return result;
}

// Method to ignore inputted spaces
bool checkForSpaces(Dstack &stack, double &operand) {
    bool result = false; // Initializing result
    // Checking for spaces
    if (isspace(cin.peek())) {
        cin.ignore(); // Ignoring space
        result = true; // Setting result to true
    }
    return result;
}

// Method to identify inputted operators and invalid RPN errors
bool checkForOperators(Dstack &stack, char &possible_operator, double &operand, double &value1, double &value2) {
    bool result = false; // Initializing result
    if (ispunct(cin.peek())) {
        // Checking for invalid postfix expression
        if (stack.size() < 2) {
            // Outputting error message using standard error
            cerr << "Error: Invalid expression." << endl;
            exit(1); // Terminating program
        }
        cin >> possible_operator; // Inputting operator
        // Checking for correctly inputted operator
        if (isOperator(possible_operator) && stack.size() >= 2) {
            // Popping off last two operands
            stack.pop(value2);
            stack.pop(value1);
            // Performing inputted operation
            operand = performOperations(possible_operator, value1, value2);
            stack.push(operand); // Pushing result onto the stack
            result = true; // Setting result to true
        }
    }
    return  result;
}

// Method to print result or error message for invalid RPN expression
void printResult(Dstack &stack, double &operand) {
    // Printing result if stack size is 1
    if (stack.size() == 1) {
        cout << operand << endl;
    }
    // Printing error message if stack size is greater than 1
    else {
        // Outputting error message using standard error
        cerr << "Error: Invalid expression." << endl;
        exit(1); // Terminating program
    }
}

// Main function
int main() {
    Dstack stack; // Dstack object
    char possible_operator; // char to store operators
    // Doubles for input and evaluating expressions
    double operand, value1, value2;

    // Looping until end of input
    while (cin.peek() != EOF) {
        // Checking for inputted operands
        if (checkForOperand(stack, operand));
        // Checking for spaces
        else if (checkForSpaces(stack, operand));
        // Checking for operators
        else if (checkForOperators(stack, possible_operator, operand, value1, value2));
    }
    // Printing result of expression or error message
    printResult(stack, operand);

    return 0; // Returning the zero of success
}