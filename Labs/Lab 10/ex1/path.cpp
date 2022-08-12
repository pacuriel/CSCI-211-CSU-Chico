#include <vector>
#include <iostream>
#include "location.h"
using namespace std;

int main() {
    // Declaring a vector of locations
    vector<Location*> v_obj;

    // Declaring double variables for location
    double latitude, longitude;

    // while loop to get input and store locations
    while (cin.peek() != EOF) {
        cin >> latitude >> longitude;
        // Adding new location to vector
        v_obj.push_back(new Location(latitude, longitude));
    }

    // Setting first element equal to iterator
    vector<Location*>::iterator v_obj_iter = v_obj.begin();
    // Traversing vector elements using an iterator
    while ((v_obj_iter + 1) != v_obj.end()) {
        // Calling print function
        (*v_obj_iter)->print(cout);
        cout << endl; // Moving to next line
        v_obj_iter++; // Incrementing iterator to next element
    }

    return 0;
}