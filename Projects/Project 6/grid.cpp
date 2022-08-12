// grid.cpp
// Curiel, Pablo
// pacuriel

#include "grid.h"
#include <iostream>

// Grid constructor initializing grid locations to spaces
Grid::Grid() {
    // Nested for loops to initialize every grid location
    for (int rows = 0; rows < ROWS; rows++) {
        for (int cols = 0; cols < COLS; cols++) {
            // Initializing all characters to be spaces
            m_grid[cols][rows] = ' ';
        }
    }
}

// set method to set character to grid location
void Grid::set(int x, int y, char c) {
    // if statement checking if x,y are inside of grid
    if (x < 60 && y < 24) {
        m_grid[x][y] = c; // Setting the location to char c
    }
}

// print method to print grid
void Grid::print() {
    // Nested for loops to print at every grid location
    for (int rows = 0; rows < ROWS; rows++) {
        for (int cols = 0; cols < COLS; cols++) {
            // Printing current grid location
            std::cout << m_grid[cols][rows];
        }
        std::cout << std::endl; // Outputting new line for new row
    }
}