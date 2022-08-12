#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>

using namespace std;

// Video class
class Video
{
    public:
        // Video constructor
        Video(string title, string url, string comment, double length, int rating);
        // print() method
        void print();

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
