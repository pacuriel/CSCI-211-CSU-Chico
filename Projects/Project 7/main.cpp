// main.cpp
// Curiel, Pablo
// pacuriel

#include <iostream>
#include <vector>
#include "bst.h"
using namespace std;

int main() {

    string command, argument;
    Bst bst_obj;

    // Looping while user enters commands
    while (cin >> command) {
        if (command == "echo") { // Echo command
            cin.ignore(); // Ignoring space before argument
            getline(cin, argument); // Getting string to print
            cout << argument << endl; // Printing string to std out
        }
        else if (command == "insert") { // Insert command
            cin.ignore();
            getline(cin, argument);

            // if string is already in tree
            if (!bst_obj.insert(argument)) { // Calling insert method in condition
                // Printing error statement
                cerr << "insert <" << argument << "> failed. String" <<
                    " already in tree.\n";
            }
        }
        else if (command == "count") { // Count command
            // Printing number of values in tree
            cout << bst_obj.getCount() << endl;
        }
        else if (command == "find") { // Find command
            cin.ignore();
            getline(cin, argument);

            // if string is in tree
            if (bst_obj.find(argument)) { // Calling find method in condition
                cout << "<" << argument << "> is in tree.\n";
            }
            // if string is not in tree
            else {
                cout << "<" << argument << "> is not in tree.\n";
            }
        }
        else if (command == "print") { // Print command
            // Declaring string vector to store values
            vector <string> print_vector;

            // Calling dft method to store in-order values in vector
            bst_obj.dft(print_vector);

            cout << "{";
            // for loop to print vector elements
            for (int i = 0; i < (int)print_vector.size(); i++) {
                cout << print_vector[i];

                // Adding a comma while not at last element
                if ((i + 1) != (int)print_vector.size()) {
                    cout << ", ";
                }
            }
            cout << "}\n";
        }
        else if (command == "breadth") { // Breadth command
            // Declaring string vector to store values
            vector <string> breadth_vector;

            // Calling bft method to store values in vector
            bst_obj.bft(breadth_vector);

            cout << "{";
            // for loop to print vector elements
            for (int i = 0; i < (int)breadth_vector.size(); i++) {
                cout << breadth_vector[i];

                // Adding a comma while not at last element
                if ((i + 1) != (int)breadth_vector.size()) {
                    cout << ", ";
                }
            }
            cout << "}\n";
        }
        else if (command == "height") { // Height command
            // Outputting height with getHeight method
            cout << bst_obj.getHeight() << endl;
        }
        else if (command == "balanced") { // Balanced command
            if (bst_obj.isBalanced()) {
                cout << "Tree is balanced." << endl;
            }
            else {
                cout << "Tree is not balanced." << endl;
            }
        }
        else if (command == "rebalance") { // Rebalanced command
            // Calling method to rebalance a given tree
            bst_obj.rebalance();
        }
        else if (command == "remove") { // Remove command (doesn't work)
            cin.ignore();
            getline(cin, argument); // Getting string to remove

            // Calling public remove method in condition
            if (bst_obj.remove(argument)) {
                cout << "<" << argument << "> removed." << endl;
            }
            else {
                cout << "<" << argument << "> not found." << endl;
            }
        }
        else {
            cerr << "Illegal command <" << command << ">." << endl;
            getline(cin, argument); // Getting rest of line after command
        }
    }
    return 0;
}
