#include "cust.h"
#include <fstream>

Cust::Cust(string name, bool is_shopper, int arrival_time, int items) {
    m_name = name;
    m_is_shopper = is_shopper;
    m_arrival_time = arrival_time;
    m_items = items;
}

void Cust::print(ostream &os) {
    // if-else statement to display customer title
    if (m_is_shopper) {
        m_cust_title = "robber";
    }
    else {
        m_cust_title = "shopper";
    }

    // Outputting in desired format
    os << m_name << " " << m_cust_title << " " << m_arrival_time << " " << m_items << endl;
}