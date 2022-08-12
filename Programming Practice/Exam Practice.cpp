#include <iostream>
using namespace std;

int main () {
    int my_array[10] = {0};
    my_array[2] = 3;
    cout << my_array[2] << endl;
    my_array[2] = 5;
    *(my_array + 2) = 3;
    cout << my_array[2] << endl;
    return 0;
}
