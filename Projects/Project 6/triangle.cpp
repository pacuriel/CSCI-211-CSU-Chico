// trangle.cpp
// Curiel, Pablo
// pacuriel

#include "triangle.h"

// Method to draw triangle on grid
void Triangle::draw(Grid &grid) {
    if (m_x < 60 && m_y < 24) {
        for (int rows = m_y; rows < 24 && rows < (m_y + 3); rows++) {
            // if at top row of triangle, place + at top
            if (rows == m_y) {
                grid.set(m_x + 2, rows, '+');
            }
            // if at middle row of triangle
            else if (rows == m_y + 1) {
                grid.set(m_x + 1, rows, '+');
                grid.set(m_x + 3, rows, '+');
            }
            // if at last row of triangle
            else if (rows == m_y + 2) {
                // for loop to set + to whole last row
                for (int cols = m_x; cols < (m_x + 5); cols++) {
                    grid.set(cols, rows, '+');
                }
            }
        }
    }
}