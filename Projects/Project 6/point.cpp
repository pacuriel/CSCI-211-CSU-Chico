// point.cpp
// Curiel, Pablo
// pacuriel

#include "point.h"

// Point class constructor
Point::Point(int x, int y, char c) : Shape(x, y) {
    // Setting member variable equal to c
    m_char = c;
}

// Method to draw character on grid at specified location
void Point::draw(Grid &grid) {
    // Checking point location is in grid
    if (m_x < 60 && m_y < 24) {
        grid.set(m_x, m_y, m_char);
    }
}