#ifndef COURSE_H
#define COURSE_H
#include <iostream>

using namespace std;

class Course
{
    public:
        // Course function
        Course(string dept, int number, int time);
        // print function
        void print();

    private:
        // member variables
        string department;
        int num;
        int courseTime;
};

#endif
