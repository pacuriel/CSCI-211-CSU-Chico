// video.cpp
// Curiel, Pablo
// pacuriel
#include "video.h"
#include <iostream>
using namespace std;

// Video class constructor without parameters
Video::Video() {}

// Calling Video class consructor with parameters
Video::Video(string title, string url, string comment, double length, int rating) {
    // Setting Video constructor parameters to member variables
    videoTitle = title;
    videoURL = url;
    videoComment = comment;
    videoLength = length;
    videoRating = rating;
}

// print() function
void Video::print() {
    // switch statement to print stars for inputted video rating
    switch(videoRating) {
        case 1:
            ratingStars = "*";
            break;
        case 2:
            ratingStars = "**";
            break;
        case 3:
            ratingStars = "***";
            break;
        case 4:
            ratingStars = "****";
            break;
        case 5:
            ratingStars = "*****";
            break;
    }
    // Printing desired output using cout
    cout << videoTitle << ", " << videoURL << ", " << videoComment << ", "
         << videoLength << ", " << ratingStars << endl;
}

// Checking for alphabetically greater titles
bool Video::greaterTitle(Video *videoObj) {
    return (videoTitle > videoObj->videoTitle);
}
// Checking for alphabetically equal titles
bool Video::equalTitle(string title) {
    return (title == videoTitle);
}
