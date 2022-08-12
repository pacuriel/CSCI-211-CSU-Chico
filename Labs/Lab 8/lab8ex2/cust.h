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
    void print(ostream &os); // Print method
private:
    // Member variables
    string m_name, m_cust_title;
    bool m_is_shopper;
    int m_arrival_time, m_items;
};

#endif
