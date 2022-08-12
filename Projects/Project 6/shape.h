// shape.h
// Curiel, Pablo
// pacuriel

#ifndef SHAPE_H
#define SHAPE_H
#include "grid.h"

// Base class Shape
class Shape {
public:
    // Shape class constructor
    Shape(int x, int y);
    // Pure virtual draw method
    virtual void draw(Grid &grid) = 0;
// Using protected to be able to access in derived classes
protected:
    // Member variables to store origin
    int m_x, m_y;
};


#endif
