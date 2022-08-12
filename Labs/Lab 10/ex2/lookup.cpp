#include "location.h"
#include <map>
#include <iostream>
using namespace std;

int main() {

    // Declaring a map with string keys and location pointers on stack
    map<string, Location*> map_obj;

    double latitude, longitude; // Doubles to store location
    string location_title; // string to store title

    // Looping while latitude not equal to 0
    while (cin >> latitude) {
        if (latitude == 0) {
            break; // Killing loop.
        }
        else {
            // Inputting variables
            cin >> longitude >> location_title;
            // Creating new map element w/ title as index
            map_obj[location_title] = new Location(latitude, longitude);
        }
    }
    // Loop is dead.

    // Creating map iterator and setting it to first element
    map<string, Location*>::iterator map_obj_iter = map_obj.begin();

    string title; // string to store titles

    // Looping while title is inputted
    while (cin >> title) {
        // Using iterator to find title
        map_obj_iter = map_obj.find(title);

        // if title not found in map
        if (map_obj_iter == map_obj.end()) {
            cout << title << " not in database" << endl;
        }
        // if title found in map
        else {
            cout << map_obj_iter->first << " is at ";
            map_obj_iter->second->print(cout);
            cout << endl;
        }
    }

    return 0;
}
