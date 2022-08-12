#include <iostream>
#include <assert.h>
using namespace std;

int largest_in_array(int values[], int size)
{
	// IMPLEMENT A RECURSIVE VERSION OF THIS FUNCTION...
	assert(size > 0);
	if (size == 1) {
	    return values[0];
	}
	else {
	    return max(values[0], largest_in_array(values + 1, size - 1));
	}
}

int main()
{
	int values[1000];
	int size;
	cout << "Enter integers.  Type control-D when done\n";
	for (size = 0; cin >> values[size]; size++);
	cout << "The largest value is " << largest_in_array(values, size) << endl;
}
