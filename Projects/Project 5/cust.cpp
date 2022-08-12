// cust.cpp
// Curiel, Pablo
// pacuriel
#include "cust.h"
#include <iostream>
#include <assert.h>

Cust::Cust(string name, bool is_shopper, int arrival_time, int items) {
    m_name = name;
    m_is_shopper = is_shopper;
    m_arrival_time = arrival_time;
    m_items = items;
}

void Cust::print_entered(ostream &os, int clock) {
    // Assert to ensure
    assert(clock == m_arrival_time); // Confirming times match
    os << clock << ": " << m_name << " entered store" << endl;
}

void Cust::print_done_shopping(ostream &os, int clock) {
    os << clock << ": " << m_name << " done shopping" << endl;
}

void Cust::print_start_checkout(ostream &os, int clock, int checker) {
    os << clock << ": " << m_name << " started checkout with checker " << checker << endl;
}

void Cust::print_done_checkout(ostream &os, int clock, int checker, int money) {
    if (!m_is_shopper) { // Output if robber
        if (m_items == 1) {
            os << clock << ": " << m_name << " stole $" << money <<
            " and " << m_items << " item from checker " << checker << endl;
        }
        else if (m_items > 1) {
            os << clock << ": " << m_name << " stole $" << money <<
            " and " << m_items << " items from checker " << checker << endl;
        }
    }
    else if (m_is_shopper) { // Output if shopper
        if (m_items == 1) {
            os << clock << ": " << m_name << " paid $" << money <<
            " for " << m_items << " item to checker " << checker << endl;
        }
        else if (m_items > 1) {
            os << clock << ": " << m_name << " paid $" << money <<
            " for " << m_items << " items to checker " << checker << endl;
        }
    }
}