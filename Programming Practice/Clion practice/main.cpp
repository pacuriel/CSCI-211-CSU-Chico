#include <iostream>
#include "video.h" // Including video header file
using namespace std;

int main() {

    // Declaring variables
    string sortMethod, title, url, comment;
    float length;
    int rating;

    // constant int for max video inputs
    const int MAX_VIDEOS = 100;

    // Array of 100 pointers
    Video *videosArray[MAX_VIDEOS];

    // Inputting sorting method for videos
    cin >> sortMethod;
    cin.ignore();

    // while loop to read user input
    while (getline(cin, title)) {
        getline(cin, url);
        getline(cin, comment);
        cin >> length;
        cin >> rating;
        cin.ignore();

        // Creating new Video object with inputted variables as parameters
        Video *videos = new Video(title, url, comment, length, rating);

        videos->print();

        // Storing the nth video inputted in array of pointers
        /* int n = 0;
        videosArray[n] = videos;
        n += 1;
        */
    }

    /*
    // for loop to print each video input
    for (int i = 0; i < MAX_VIDEOS; i++) {

        // Using arrow operator to call print() method
        videosArray[i]->print();
        i++;
    }
    */

    // Exit the program with a success status.
    return 0;
}
