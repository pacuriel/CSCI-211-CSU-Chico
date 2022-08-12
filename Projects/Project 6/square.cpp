// square.cpp
// Curiel, Pablo
// pacuriel

#include "square.h"

// Square class constructor
Square::Square(int x, int y, int size) : Shape(x, y) {
    // Setting member size equal to size
    m_size = size;
}

// Method to draw a square on the grid
void Square::draw(Grid &grid) {
    // Making sure origin of square is in grid
    if (m_x < 60 && m_y < 24) {
        // for loop to handle height (rows) of grid
        for (int rows = m_y; (rows < 24 && rows < (m_y + m_size)); rows++) {
            // if at top or bottom line of square, print columns
            if (rows == m_y || rows == (m_y + m_size - 1)) {
                // for loop to handle printing top and bottom lines of square
                for (int cols = m_x; (cols < 60 && cols < (m_x + m_size)); cols++) {
                    // Calling Grid's set method to place an asterisk
                    grid.set(cols, rows, '*');
                }
            }
            else {
                // Placing an asterisk on the left side of the square
                grid.set(m_x, rows, '*');
                // Placing an asterisk on the right side of the square
                grid.set((m_x + m_size - 1), rows, '*');
            }
        }
    }
}