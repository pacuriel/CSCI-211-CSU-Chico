#include <iostream>
#include "course.h"
using namespace std;

int main()
{
    // Using Course class to set input
    Course programming("CSCI", 211, 1000);
    Course english("ENGL", 130, 1400);
    Course physics("PHYS", 204, 800);

    // Using print function for program output
    programming.print();
    english.print();
    physics.print();

    return 0;
}
