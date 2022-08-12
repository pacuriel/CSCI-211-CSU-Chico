#include "video.h"
#include <iostream>

using namespace std;

// Calling Video class consructor
Video::Video(string title, string url, string comment, double length, int rating)
{
    // Setting Video constructor parameters to member variables
    videoTitle = title;
    videoURL = url;
    videoComment = comment;
    videoLength = length;
    videoRating = rating;
}

// print() function
void Video::print()
{
    // switch statement to print stars for inputted video rating
    switch(videoRating)
    {
    case 1:
        ratingStars = "*";
        break;
    case 2:
        ratingStars = "**";
        break;
    }

    // Printing desired output using cout
    cout << videoTitle << ", " << videoURL << ", " << videoComment << ", " << videoLength << ", " << ratingStars << endl;
}

