// main.cpp
// Curiel, Pablo
// pacuriel
#include <iostream>
#include "video.h"
#include "vlist.h"
using namespace std;

int main() {

    // Declaring variables for video entries
    string title, url, comment;
    float length;
    int rating;
    Vlist listObject; // Vlist object

    // New pointer to video object
    Video *videoObject = new Video(title, url, comment, length, rating);
    string command; // Store user input for commands

    // Looping while user enters commands
    while (getline(cin, command)) {
        // Printing error message if user inputs wrong command
        if (command != "insert" && command != "print" && command != "length"
            && command != "lookup" && command != "remove") {
            cerr << "<" << command << ">" << " is not a legal command, giving up." << endl;
            return 1; // Returning 1 from main
        }
        else if (command == "insert") {
            // Inputting video variables
            getline(cin, title);
            getline(cin, url);
            getline(cin, comment);
            cin >> length;
            cin >> rating;
            cin.ignore();
            Video *videoObject = new Video(title, url, comment, length, rating);
            // Error message if video title is already in list
            if (!listObject.insert(videoObject, title)) {
                cerr << "Could not insert video <" << title << ">, already in list." << endl;
            }
        }
        else if (command == "print") {
            listObject.callingVideoPrint();
        }
        else if (command == "length") {
            cout << listObject.length() << endl;
        }
        else if (command == "lookup") {
            string lookupTitle;
            getline(cin, lookupTitle);
            // Error message if video title is not in list
            if (!listObject.lookup(lookupTitle)) {
                cerr << "Title <" << lookupTitle << "> not in list." << endl;
            }
        }
        else if (command == "remove") {
            string removeTitle;
            getline(cin, removeTitle);
            // Error message if video title is not in list
            if (!listObject.remove(removeTitle)) {
                cerr << "Title <" << removeTitle << "> not in list, could not delete." << endl;
            }
        }
    }
    delete videoObject; // deleting videoObject memory
    return 0; // Returning 0 for success
}