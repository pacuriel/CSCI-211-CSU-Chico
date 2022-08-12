#include <iostream>
#include <stdlib.h>
#include <cctype>
using namespace std;

bool legal_int(char *str) {
    bool result = false;
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int j = 0; j < length; j++) {
        if (isdigit(str[j]) == 0) {
            result = false;
        }
        else {
            result = true;
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    int sum = 0;
    int value;
    for (int i = 1; i < argc; i++) {
        if (legal_int(argv[i]) == false) {
            cerr << "Error: illegal integer." << endl;
            return 1;
        }
        value = atoi(argv[i]); // Converting char to integer
        sum += value;
    }
    cout << sum << endl;

    return 0;
}
