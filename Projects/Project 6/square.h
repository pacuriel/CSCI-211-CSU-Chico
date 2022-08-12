// square.h
// Curiel, Pablo
// pacuriel

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

// Derived class Square inheriting from Shape
class Square : public Shape {
public:
    // Square class constructor
    Square(int x, int y, int size);
    // Draw method
    void draw(Grid &grid);
private:
    // Integer storing size of square
    int m_size;
};

#endif