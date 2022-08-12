// main.cpp
// Curiel, Pablo
// pacuriel
#include <iostream>
#include "video.h" // Including video header file
using namespace std;

int main() {

    // Declaring variables for video entries
    string sortMethod, title, url, comment;
    float length;
    int rating;
    const int MAX_VIDEOS = 100; // constant for max input

    // Inputting sorting method for videos
    getline(cin, sortMethod);

    // if statement terminates program if wrong sort method inputted
    if (sortMethod != "rating" && sortMethod != "length" && sortMethod != "title") {
        cerr << sortMethod << " is not a legal sorting method, giving up." << endl;
        return 1; // Returning 1 from main
    }

    // Array of 100 pointers
    Video *videosArray[MAX_VIDEOS];

    // Pointer to new Video object
    Video *videoObject = new Video(title, url, comment, length, rating);;

    int i = 0; // Used to iterate through while loop

    // while loop to read user input
    while (getline(cin, title)) {

        // if statement to detect max number of inputs
        if (i >= MAX_VIDEOS) {
            // printing error message
            cerr << "Too many videos, giving up." << endl;
            return 1; // Returning 1 from main
        }

        getline(cin, url);
        getline(cin, comment);
        cin >> length;
        cin >> rating;
        cin.ignore();

        // Declaring new Video object with user input
        videoObject = new Video(title, url, comment, length, rating);

        // Storing the ith video entry in array of pointers
        videosArray[i] = videoObject;
        i++; // Incrementing i by + 1
    }

    // if-else-if statements to sort arrays based on chosen method
    if (sortMethod == "rating") {
        // Bubble sort algorithm to swap video entries
        for (int last = i - 1; last > 0; last--) {
            for (int cur = 0; cur < last; cur++) {
                // Testing if one entry has a higher rate than another
                if (videosArray[cur]->highestRated(videosArray[cur + 1])) {
                    // Swapping the video entries if true
                    swap(videosArray[cur] , videosArray[cur + 1]);
                }
            }
        }
    }
    else if (sortMethod == "length") {
        for (int last = i - 1; last > 0; last--) {
            for (int cur = 0; cur < last; cur++) {
                // Testing if one video entry is longer than the other
                if (videosArray[cur]->longer(videosArray[cur + 1])) {
                    swap(videosArray[cur] , videosArray[cur + 1]);
                }
            }
        }
    }
    else if (sortMethod == "title") {
        for (int last = i - 1; last > 0; last--) {
            for (int cur = 0; cur < last; cur++) {
                // Testing if one video entry is alphabetically greater than the other
                if (videosArray[cur]->title(videosArray[cur + 1])) {
                    swap(videosArray[cur] , videosArray[cur + 1]);
                }
            }
        }
    }

    // for loop to print each video input
    for (int n = 0; n < i; n++) {
        // Using arrow operator to call print() method
        videosArray[n]->print();
    }

    delete videoObject; // freeing videoObject memory

    // Exit the program with a success status.
    return 0;
}
