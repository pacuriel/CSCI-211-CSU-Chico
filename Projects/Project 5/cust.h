// cust.h
// Curiel, Pablo
// pacuriel
#ifndef CUST_H
#define CUST_H
#include <iostream>
#include <fstream>
using namespace std;

// Class Cust
class Cust {
public:
    // Class constructor
    Cust(string name, bool is_robber, int arrival_time, int items);
    int num_of_items() { return m_items; }
    bool is_shopper() { return m_is_shopper; }
    void print_entered(ostream &os, int clock); // Method to print entered store message
    void print_done_shopping(ostream &os, int clock); // Method to print done shopping message
    void print_start_checkout(ostream &os, int clock, int checker);
    void print_done_checkout(ostream &os, int clock, int checker, int money);
private:
    // Member variables
    string m_name, m_cust_type;
    bool m_is_shopper;
    int m_arrival_time, m_items;
};

#endif
