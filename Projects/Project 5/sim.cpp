// sim.cpp
// Curiel, Pablo
// pacuriel
#include <iostream>
#include <fstream>
#include "pqueue.h"
#include "cust.h"
using namespace std;

// Check struct
struct Checker {
    int money_in_register;
    int done_time; // Time when checker is done with customer/break ends
    Cust *current_customer; // Points to current customer or NULL if no customer
};

// Function to return true if integer found
bool legal_int(char *str) {
    bool result = false; // Initializing result to false
    int length = 0;
    // while loop to find length of string
    while (str[length] != '\0') {
        length++;
    }
    // for loop to check string for integers
    for (int i = 0; i < length; i++) {
        if (isdigit(str[i]) == 0) {
            result = false;
        }
        else {
            result = true;
        }
    }
    return result;
}

// Function to read in the input
void get_input(istream &ifile, Pqueue &pqueue_object) {
    // Variables to store customer attributes
    string name, cust_type;
    int arrival_time, items;

    // Looping until all input is read
    while (ifile >> name >> cust_type >> arrival_time >> items) {
        // Creating new Cust object with inputted variables
        Cust *cust_object = new Cust(name, (cust_type == "robber" ? 0 : 1), arrival_time, items);
        // Adding new Cust object to arrival queue
        pqueue_object.enqueue(cust_object, arrival_time);
    }
}

// Function to run simulation
void run_simulation(Pqueue &arrival_queue, int num_checkers, int break_duration, ostream &os) {
    // Setting number of customers equal to length of arrival queue
    int num_customers = arrival_queue.length();

    Cust *cust_object; // Cust object pointer
    Pqueue shopping_queue; // Object for shopping queue
    Pqueue checker_queue; // Object for checker queue

    // Dynamically creating an array of Checker structs
    Checker *checker_array = (Checker*) malloc(sizeof(Checker) * num_checkers);
    // Initializing elements of each checker struct
    for (int i = 0; i < num_checkers; i++) {
        checker_array[i].money_in_register = 250; // Checkers start with 250 in register
        checker_array[i].done_time = 0; // Initializing done time to 0
        checker_array[i].current_customer = NULL; // NULL because no customer assigned yet
    }

    int clock; // Stores current clock value
    // for loop to control the simulation clock
    for (clock = 1; num_customers > 0; clock++) {
        // Implement three priority queues here

        // While loop for arrival queue
        while (arrival_queue.first_priority() == clock) {
            cust_object = arrival_queue.dequeue(); // Dequeueing customer from arrival queue
            cust_object->print_entered(os, clock); // Printing entered message

            // Calculating time done shopping/stealing
            int done_shopping = clock + (cust_object->num_of_items() * 2);
            // Placing customer on shopping queue with time done shopping as priority
            shopping_queue.enqueue(cust_object, done_shopping);
        }

        // While loop for shopping queue
        while(shopping_queue.first_priority() == clock) {
            cust_object = shopping_queue.dequeue(); // Dequeueing customer from shopping queue
            cust_object->print_done_shopping(os, clock); // Printing done shopping message
            // Placing customer on checker queue with priority 0
            checker_queue.enqueue(cust_object, 0);
        }

        // for loop to complete a checkout process and print desired messages
        for (int i = 0; i < num_checkers; i++) {
            // Checker has a matching done time and customer
            if (checker_array[i].done_time == clock && checker_array[i].current_customer != NULL) {
                int money; // Stores money values
                // Increment/decrement cashier's total cash
                if (!checker_array[i].current_customer->is_shopper()) { // Case if customer is a robber
                    money = checker_array[i].money_in_register; // Money stolen equal to register money
                    checker_array[i].money_in_register = 0; // Checker loses all money
                    // Printing done checkout message
                    checker_array[i].current_customer->print_done_checkout(os, clock, i, money);
                    num_customers--; // Decrementing number of customers
                    checker_array[i].done_time = clock + break_duration; // Checker needs break after robbery
                    delete checker_array[i].current_customer; // Deleting current customer
                    checker_array[i].current_customer = NULL; // Checker has no customer
                }
                else if (checker_array[i].current_customer->is_shopper()) { // Case if customer is a shopper
                    // Calculating money customer pays
                    money = checker_array[i].current_customer->num_of_items() * 3;
                    // Incrementing checker's money in register
                    checker_array[i].money_in_register = checker_array[i].money_in_register + money;
                    // Printing done checkout message
                    checker_array[i].current_customer->print_done_checkout(os, clock, i, money);
                    num_customers--; // Decrementing number of customers
                    delete checker_array[i].current_customer; // Deleting current customer
                    checker_array[i].current_customer = NULL; // Checker has no customer
                }
            }
        }

        // while loop to assign customers to checkers
        while (!checker_queue.empty()) {
            int i; // To be used for iteration
            bool keep_going = false; // Bool to keep loop going or not
            for (i = 0; i < num_checkers; i++) { // for loop searching for available checker
                if (checker_array[i].current_customer == NULL) { // Available checker found
                    // Making sure checker is not on break/just got robbed
                    if (checker_array[i].done_time <= clock) {
                        keep_going = true;
                        break;
                    }
                }
            }
            if (!keep_going) { // Killing while loop if there is no available checker
                break;
            }

            cust_object = checker_queue.dequeue(); // Removing customer from checker queue
            checker_array[i].current_customer = cust_object; // Assigning customer to available checker

            int done_checkout; // Will store time customer is done checking out
            if (!cust_object->is_shopper()) { // Case for when customer is a robber
                done_checkout = clock + 7;
            }
            else if (cust_object->is_shopper()) { // Case for when customer is a shopper
                done_checkout = clock + (cust_object->num_of_items() * 1);
            }

            checker_array[i].done_time = done_checkout; // Storing done time for checker
            // Printing start checkout message
            cust_object->print_start_checkout(os, clock, i);
        }
    }
    // Printing register values
    for (int i = 0; i < num_checkers; i++) {
        os << "registers[" << i << "] = $" << checker_array[i].money_in_register << endl;
    }
    // Printing clock value
    os << "time = " << clock << endl;
}

// Main function
int main(int argc, char *argv[]) {
    Pqueue pqueue_object; // Pqueue object

    // Checking for invalid number of arguments
    if (argc != 5) {
        cerr << "Error: invalid number of command line arguments." << endl;
        exit(1);
    }

    ifstream ifile(argv[3], ios::in); // ifstream object to open input file
    if (!ifile) { // Printing error if file can't open
        cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
        exit(1);
    }
    // Calling function to read input
    get_input(ifile, pqueue_object);

    ofstream ofile(argv[4], ios::out); // ofstream object to open output file
    if (!ofile) { // Printing error if file can't open
        cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
        exit(1);
    }

    // Storing number of checks and checking for input error
    int num_of_checkers = atoi(argv[1]);
    if (!(num_of_checkers >= 1) || !legal_int(argv[1])) {
        cerr << "Error: invalid number of checkers specified." << endl;
        exit(1);
    }

    // Storing length of checker breaks and checking for input error
    int break_duration = atoi(argv[2]);
    if (break_duration < 0 || !legal_int(argv[1])) {
        cerr << "Error: invalid checker break duration specified." << endl;
        exit(1);
    }

    // Calling function to run simulation
    run_simulation(pqueue_object, num_of_checkers, break_duration, ofile);

    return 0;
}
