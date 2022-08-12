// trangle.h
// Curiel, Pablo
// pacuriel

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

// Derived class Triangle inheriting from Shape
class Triangle : public Shape {
public:
    // Triangle class constructor
    Triangle(int x, int y) : Shape(x, y) {}
    void draw(Grid &grid); // Draw method
};

#endif
