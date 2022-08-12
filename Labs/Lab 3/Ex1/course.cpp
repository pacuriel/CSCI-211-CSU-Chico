#include <iostream>
#include "course.h"

using namespace std;

// Class constructor
Course::Course(string dept, int number, int time)
{
    // Setting parameter variables to member variables
    department = dept;
    num = number;
    courseTime = time;
}

// print function
void Course::print()
{
    // Outputting course info
    cout << department << " " << num << " at " << courseTime << endl;
}
