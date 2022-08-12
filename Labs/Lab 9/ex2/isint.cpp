#include <iostream>
#include <ctype.h>
#include <assert.h>
using namespace std;

bool is_int(char str[])
{
	// IMPLEMENT A RECURSIVE VERSION OF THIS FUNCTION...
	if (!isdigit(str[0])) {
	    return false;
	}
	else if (str[0] == '\0') {
	    return false;
	}
	else if (str == NULL) {
	    return false;
	}
	else {
	    if (str[1] == '\0') {
	        return true;
	    }
	    is_int(str + 1);
	}
}

int main()
{
	char buf[1000];
	cout << "Enter a string: ";
	cin >> buf;

	if (is_int(buf))
		cout << "<" << buf << "> is an integer.\n";
	else cout << "<" << buf << "> is NOT an integer.\n";
}
