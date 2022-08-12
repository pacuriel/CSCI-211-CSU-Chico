// point.h
// Curiel, Pablo
// pacuriel

#ifndef POINT_H
#define POINT_H
#include "shape.h"

// Derived class Point inheriting from Shape
class Point : public Shape {
public:
    // Point class constructor
    Point(int x, int y, char c);
    void draw(Grid &grid); // Draw method
private:
    // Member variable to store inputted char
    char m_char;
};
#endif
