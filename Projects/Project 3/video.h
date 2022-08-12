// video.h
// Curiel, Pablo
// pacuriel
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
using namespace std;

// Video class
class Video {
public:
    // Video constructor without parameters
    Video();
    // Video constructor with parameters
    Video(string title, string url, string comment, double length, int rating);
    void print(); // print() method
    // bool functions for sorting methods
    bool greaterTitle(Video *videoObj);
    bool equalTitle(string lookupTitle);

private:
    // Declaring member variables
    string videoTitle;
    string videoURL;
    string videoComment;
    double videoLength;
    int videoRating;
    string ratingStars;
};
#endif
