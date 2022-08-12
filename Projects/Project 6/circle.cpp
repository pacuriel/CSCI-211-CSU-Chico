// circle.cpp
// Curiel, Pablo
// pacuriel

#include "circle.h"

void Circle::draw(Grid &grid) {
    if (m_x < 60 && m_y < 24) {
        for (int rows = m_y; rows < (m_y + 4); rows++) {
            // if at top of circle
            if (rows == m_y) {
                grid.set(m_x + 1, rows, 'o');
                grid.set(m_x + 2, rows, 'o');
            }
            // if at middle two rows of circle
            else if (rows == m_y + 1) {
                grid.set(m_x, rows, 'o');
                grid.set(m_x + 3, rows, 'o');
            }
            else if (rows == m_y + 2) {
                grid.set(m_x, rows, 'o');
                grid.set(m_x + 3, rows, 'o');
            }
            // if at bottom row of circle
            else if (rows == m_y + 3) {
                grid.set(m_x + 1, rows, 'o');
                grid.set(m_x + 2, rows, 'o');
            }
        }
    }
}