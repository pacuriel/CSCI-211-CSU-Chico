#include <iostream>
using namespace std;

class Stack {
public:
    Stack(int size()) {
        m_count = 0;
        m_size = size;
        m_values = (int*) malloc(size * sizeof(int))
    }
    ~Stack() { free(m_values) }
    bool isEmpty() { return (m_count == 0); }
    bool push(int value);
    bool pop(int &value_out); //Memory address as a parameter
    int size() { return m_count; }
private:
    int *m_values;
    int m_size;
    int m_count;
};

bool Stack::push(int value) {
    bool result = false;

    // if number of possible slots is greater than
    // number of elements in stack
    if (m_size > m_count) {
        m_values[m_count] = value;
        m_count++;
        result = true;
    }
    return result;
}

bool Stack::pop(int &value_out) {

    bool result = false;
    if (!isEmpty()) {
        value_out = m_values[m_count - 1];
        m_count--;
        result = true;
    }

    return result;
}

int main() {

    Stack obj;
    obj.push(7);
    obj.push(5);
    obj.push(9);
    obj.insertValue(8);

    int value;



    return 0;
}
