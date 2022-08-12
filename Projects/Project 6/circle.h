// circle.h
// Curiel, Pablo
// pacuriel

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

// Derived class Circle inheriting from Shape
class Circle : public Shape {
public:
    Circle(int x, int y) : Shape(x, y) {}
    void draw(Grid &grid);
};

#endif
