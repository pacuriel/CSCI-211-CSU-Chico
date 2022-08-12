#include <iostream>

using namespace std;

Class MyClass
{
    public:
}

int main()
{

    // Problem 1
    float* salaries[] = (float*) malloc(sizeof(float*) * 10)
    for (int i = 0; i < 10; i++)
    {
        salaries[i] = 0
    }
    free (salaries);

    // Problem 2
    MyClass* my_class_array[] = (MyClass*) malloc(sizeof(MyClass*) * 10)
    for (int i = 0; i < 10; i++)
    {
        my_class_array[i] = NULL
    }
    free (my_class_array);

    return 0;
}


