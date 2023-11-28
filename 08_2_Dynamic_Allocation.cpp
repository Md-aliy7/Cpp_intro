/*
Topic 8.2:
https://cplusplus.com/doc/tutorial/dynamic/
*/

/*
Dynamic memory allocation in C++ refers to performing memory allocation manually by a programmer.
If sufficient memory is available, a 'new' operator allocates the memory and returns the address 
of the newly allocated memory to the pointer variable.

Dynamic memory is allocated using the operator 'new' with the following syntax:
a) for one element of type 'type_x':
type_x *pointer = new type_x;
b) to allocate a block(an array) of memory of type 'type_x':
type_x *pointer = new type_x [number_of_elements];	// pointer has the first element address.

Initialization:
a) type_x *pointer = new type_x(value);
b) type_x *pointer = new type_x [number_of_elements]{type_x_values};

Deallocation:
For dynamically allocated memory like 'int *ptr = new int[10]', it is the programmer's
responsibility to deallocate memory when no longer needed. Dynamically allocated memory is 
a memory dedicated to be used only by its pointer as long as that pointer is not deleted.
If you lose that pointer identifier (name) before deleting it, its allocated memory can't be used 
by any other variable causing a memory leak (memory is not deallocated until the program terminates).
Memory leaks are particularly serious issues for programs like daemons and servers
which by definition never terminate.

For this purpose, we use the operator 'delete', whose syntax is:
a) delete pointer;
b) delete[] pointer;

Note:
If enough memory is not available in the heap to allocate, the 'new' request indicates failure by
throwing an exception of type 'std::bad_alloc', unless 'nothrow' is used with the new operator,
in which case it returns a NULL pointer (i.e., pointer = 0, or pointer = nullptr)

Exception handling topic gives a better understanding of handling failures to allocate memory.
*/

#include <iostream>
#include <new>

using namespace std;

int main()
{
    int i, n;
    int* p;
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p = new (nothrow) int[i];
    if (p == nullptr)   // or (p == 0), or (!p)
        cout << "Error: memory could not be allocated";
    else
    {
        for (n = 0; n < i; n++)
        {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n = 0; n < i; n++)
            cout << p[n] << ", ";
        delete[] p;
    }

    try {
        int* pointer = new int[5585444556];
        cout << "memory is allocated, press (Y) to deallocate it!\n";
        char release;
        cin >> release;
        if (release == ('Y' || 'y'))    //OR:         if (release == 'Y' || release == 'y') 
        {
            delete[] pointer;
            cout << "memory is deallocated\n";
        }
    }
    catch (bad_alloc) {
        cout << "Couldn't allocate memory";
    }

    return 0;
}
