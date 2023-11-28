/*
Topic 8.1:
https://cplusplus.com/doc/tutorial/pointers/
*/

/*
-) The address of a variable can be obtained by preceding its name with an ampersand sign (&), 
known as the address-of operator.
-) The variable that stores the address of another variable is what in C++ is called a pointer.
By preceding the pointer name with the dereference operator (*), pointers can be used to 
access the variable they point to directly.

The reference and dereference operators are thus complementary:
-) & is the address-of (i.e., reference) operator, and can be read simply as "address of"
-) * is the dereference operator, and can be read as "value -in bits- pointed to by"

The declaration of pointers follows this syntax:
type * ptr_name;
where type is not the type of the pointer itself, but the type of the data the pointer points to.

Pointers can be initialized to point to specific locations at the very moment they are defined:
type * ptr_name = &variable ;

Only addition and subtraction operations are allowed for pointer arithmetics (see examples).

Pointers can be used to access a variable by its address, and this access may include
modifying the value pointed. But it is also possible to declare pointers that can access
the pointed value to read it, but not to modify it. For this, it is enough to qualify
the type pointed to by the pointer as const (see examples).

Pointers to pointers: 
C++ allows the use of pointers that point to pointers that in turn,
point to data (or even to other pointers). The syntax simply requires an asterisk (*) for
each level of indirection in the declaration of the pointer (see examples).

Void pointers:
-) The void type of pointer is a special type that points to a value that has no type 
(and thus also an undetermined length and undetermined dereferencing properties).
-) This gives void pointers great flexibility, by being able to point to any data type,
from an integer value or a float to a string of characters.
-) In exchange, they have a great limitation: the data pointed to by them cannot be directly
dereferenced (which is logical, since we have no type to dereference to), and for that reason,
any address in a void pointer needs to be transformed into some other pointer type that points to
a concrete data type before being dereferenced (see examples). Thus, the new pointer knows the number
of bytes (and bits) it can access and process within the memory.

-) Pointers are meant to point to valid addresses, such as the address of a variable or the
address of an element in an array.
In C++, pointers are allowed to take any address value, no matter whether there actually is
something at that address or not. What can cause an error is to dereference such a pointer
(i.e., actually accessing the value they point to).

-) Sometimes, a pointer really needs to explicitly point to nowhere, and not just an invalid address.
For such cases, there exists a special value that any pointer type can take: the null pointer value.
This value can be expressed in C++ in two ways: 
either with an integer value of zero:		int * pointer1 = 0;
or with the nullptr keyword:				int * pointer2 = nullptr;

-) C++ allows operations with pointers to functions (see examples).

l-value and r-value:
1- "lvalue": refers to memory location which identifies an object. It may appear as either left hand
or right hand side of the assignment operator (=). l-value often represents an identifier.
2- "rvalue": refers to data value that is stored at some address in memory.
An r-value can't have a value assigned to it, which means r-value can appear on right
but not on left hand side of the assignment operator (=).
for example:	int num{ 100 };		// num is an l-value, 100 is an r-value.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void increment_all(int* start, const int* stop)
{
	int* current = start;
	while (current != stop) {
		++(*current);  // increment value pointed
		++current;     // increment pointer
	}
}

void increase(void* data, int psize)
{
	if (psize == sizeof(char))
	{
		char* pchar; pchar = (char*)data; ++(*pchar);
	}
	else if (psize == sizeof(int))
	{
		int* pint; pint = (int*)data; ++(*pint);
	}
}

int* (func_ptr)(int x, int y) {
	int z = x + y;
	return &z;
}

int main() {

	int* number = nullptr;
	char* character = nullptr;
	double* decimals = 0;
	string* strings = 0;
	cout << "The pointer has size of " << sizeof(number) <<
		" for pointers of type int." << endl;
	cout << "The pointer has size of " << sizeof(character) <<
		" for pointers of type char." << endl;	
	cout << "The pointer has size of " << sizeof(decimals) <<
		" for pointers of type double." << endl;
	cout << "The pointer has size of " << sizeof(strings) <<
		" for pointers of type string." << endl;

// Declaring pointers, initialization, and dereferencing
	int firstvalue, secondvalue;
	int* mypointer;				// Declaration

	mypointer = &firstvalue;	// initialization
	*mypointer = 10;			// dereferencing
	cout << "The pointer has size of " << sizeof(mypointer) <<
		" for pointers of type int." << endl;
	mypointer = &secondvalue;	// initialization
	*mypointer = 20;			// dereferencing

	cout << "firstvalue is " << firstvalue << '\n';
	cout << "secondvalue is " << secondvalue << '\n';

	cout << "==================================================================" << '\n';

	double firstvalue1 = 5.58, secondvalue2 = 15.23;
	double * p1, * p2;

	cout << "firstvalue & secondvalue are " << firstvalue1 << "\t" << secondvalue2 << '\n';
	p1 = &firstvalue1;	// p1 = address of firstvalue1
	p2 = &secondvalue2;	// p2 = address of secondvalue2
	*p1 = 555.123;		// value pointed to by p1 = 555.123
	*p2 = *p1;			// value pointed to by p2 = value pointed to by p1
	cout << "firstvalue & secondvalue are " << firstvalue1 << "\t" << secondvalue2 << '\n';
	p1 = p2;			// p1 = p2 (value of pointer is copied)
	*p1 = 333.789;		// value pointed to by p1 = 333.789
	cout << "The pointers have size of " << sizeof(p1) << 
		" and " << sizeof(p2) << " for pointers of type double." << endl;
	cout << "firstvalue is " << firstvalue1 << '\n';
	cout << "secondvalue is " << secondvalue2 << '\n';

	cout << "============================= Pointers and arrays ==========================" << '\n';

// Pointers and arrays
	int numbers[5];
	int* p;
	p = numbers;  *p = 10;	// pointer initialization and setting the first element value.
	cout << "value pointed to by pointer p is the array 1st element is " << *p << "\n";
	cout << "Pointer address is " << p << " & array address is " << numbers << "\n";
	cout << "By moving the address that pointer p points to:" << endl;
	p++;  *p = 20;
	cout << "value pointed to by pointer p is the array 2nd element is " << *p << "\n";
	cout << "Pointer address is " << p << " & array address is " << numbers << "\n";
	p = &numbers[2];  *p = 30;
	cout << "value pointed to by pointer p is the array 3rd element is " << numbers[2] << "\n";
	p = numbers + 3;  *p = 40;
	cout << "value pointed to by pointer p is the array 4th element is " << *p << "\n";
	p = numbers;  *(p + 4) = 50;
	cout << "value pointed to by pointer p is the array 5th element is " << *(p + 4) << "\n";
	cout << "Pointer address is " << p << " & array address is " << numbers << "\n";

	for (int n = 0; n < 5; n++)
		cout << numbers[n] << ", ";

	cout << "\n============================ Pointer arithmetics =========================" << '\n';

// Pointer arithmetics
	cout << "The address before pointer address by 4 bytes (sizeof int) is " << p-1 << endl;
	cout << "Pointer address is " << p << endl;
	cout << "The address after pointer address by 4 bytes (sizeof int) is " << p+1 << endl;
	*p++;  // same as *(p++): increment pointer, and dereference unincremented address
	cout << "Pointer address is " << p << " with value " << *p << endl;
	*++p;  // same as *(++p): increment pointer, and dereference incremented address
	cout << "Pointer address is " << p << " with value " << *p << endl;
	++* p; // same as ++(*p): dereference pointer, and increment the value it points to
	cout << "Pointer address is " << p << " with value " << *p << endl;
	(*p)++;	// dereference pointer, and post-increment the value it points to
	cout << "Pointer address is " << p << " with value " << *p << endl;

	cout << "\n============================ Constant pointers ===========================" << '\n';

//  Constant pointers
	int number_array[] = { 10,20,30 };
	increment_all(number_array, number_array + 3);
	cout << "number_array first element is modified to be:\n" << number_array[0] << endl 
		<< number_array[1] << endl << number_array[2] << endl;
	// Can the pointer change its address?
	// Can pointer change the value of the variable it points to?
	int x = 56;
	int* ptr1;  // non-const pointer to non-const int
	ptr1 = &x;
	cout << "The address " << ptr1 << " has the value: " << *ptr1 << endl;
	*ptr1 = 15;
	cout << "The address " << &x << " has the value: " << *ptr1 << " i.e., x = " << x << endl;
	cout << "The following address " << ++ptr1 << " has garbage: " << *ptr1 << endl;
	const int* ptr2 = &x;  // the value pointed to by this pointer is constant
	cout << "The address " << ptr2 << " has the value: " << *ptr2 << endl;
	// *ptr2 = 90;	// error: this pointer can change only to where it can point
	cout << "The following address " << ++ptr2 << " has garbage: " << *ptr2 << endl;
	int* const ptr3 = &x;  // constant pointer, the variable value it points to is not.
	// Constant pointers must be declared together with an initializer.
	cout << "The address " << ptr3 << " has the value: " << *ptr3 << endl;
	// ++ptr3;	// error: this pointer can change only the variable value it points to
	*ptr3 = 160;
	cout << "The address " << ptr3 << " has the value: " << *ptr3 << endl;
	const int* const ptr4 = &x;  // const pointer (ptr4) to const int (*ptr4)
	cout << "The variable x address " << ptr4 << " has the value: " << *ptr4 << endl;
	// ++ptr4; *ptr4 = 152;	// error

	cout << "\n==================================================================" << '\n';

	char name_arr[] = "My name is Ali";
	const char* ptr_arr = name_arr;	// array address is its first element address
	cout << "pointer " << &ptr_arr << " points to " << *ptr_arr << " or " << name_arr[0] << endl;
	cout << "The next variable address is " << &(ptr_arr)+12 << endl;
	// it seems like the compiler gives sequential memory parts for the workspace variables.

	string name_str = "My name is Ali";
	const char* ptr_str = &name_str[0];
	if(&(ptr_arr)+12 == &ptr_str) 
		cout << "As seen, the address can be guessed " << endl;
	cout << "pointer " << &ptr_str << " points to " << *ptr_str << " or " << ptr_str[0] << endl;
	
	cout << "\n========================= Pointers to pointers ========================" << '\n';
// Pointers to pointers
	char a;
	char* b;
	char** c;
	a = 'x';
	b = &a;
	c = &b;
	cout << "variable (a)  with its following addresses is:\n" << &a <<
		"\nand without them is: " << b[0] <<
		"\nwhile its following addresses are " << &a + 1 << endl;	// weired
	cout << "pointer b has the address:\n" << c << endl;
	cout << " **c & *b & a point to the same value: " << **c << " " << *b << " " << a << endl;
	cout << "The next letter (at the previous letter address) is " << ++(*b) << endl;
/*	memory works in a complex way and the addresses content changes continously even for 
printing out some variables which are already declared. */

	cout << "\n========================== Void pointers ===========================" << '\n';

// Void pointers
	char letter1 = 'x';
	int number1 = 1602;
	increase(&letter1, sizeof(letter1));
	increase(&number1, sizeof(number1));
	cout << letter1 << ", " << number1 << '\n';

	cout << "\n========================= Pointers to functions =======================" << '\n';

// Pointers to functions (or Function Pointers)
	int* (function1) = func_ptr(100, 8);
	cout << "The function func_ptr has an output " << *function1++ <<
		", its output address is not clear." << endl;
	// or a better way:
	int function2 = *func_ptr(100, 8);
	cout << "The function func_ptr has an output " << function2 <<
		", its output address is " << &function2 << endl;

	cout << "\n========================= References =======================" << '\n';

// References (&: address of an l-value)
// will be detailed later

	int num{ 100 };			// num is an lvalue, 100 is an rvalue
	int& ref{ num };		// ref is an lvalue, also an alias to the lvalue called "num".
	cout << "The lvalue 'num' address is: " << &num << " with an rvalue: " << num << endl;
	cout << "The lvalue 'ref' (which is an alias to lvalue 'num') has the address: "
		<< &ref << " with an rvalue: " << ref << endl;

	num = 350;
	cout << num << endl;
	cout << ref << endl;
	cout << "With assigning 350 to the lvalue 'num':\n";
	cout << "The lvalue 'num' address is: " << &num << " with an rvalue: " << num << endl;
	cout << "The lvalue 'ref' address is : "<< &ref << " with an rvalue: " << ref << endl;

	cout << "To modify vector elements: " << endl;
	vector <string> stooges{ "Larry", "Moe", "Curly" };
	for (auto str : stooges)	// like:"Larry" = "Funny"; "Moe" = "Funny"; but no compiler error.
		str = "Funny";	// no change
	for (auto str : stooges)	cout << str << " , ";	cout << endl;

	for (int i = 0; i < 3; ++i)		// stooges[0] = "Funny1"
		stooges[i] = "Funny"+ to_string(i+1);	// changed
	for (auto str : stooges)	cout << str << " , ";	cout << endl;

	for (auto& str : stooges)	// using reference to obtain the alias (str=stooges[0 or 1 or 2])
		str = "changed with alias";		// changed
	for (auto str : stooges)	cout << str << " , ";	cout << endl;

	cout << "Another similar example to modify vector elements: " << endl;
	vector <int> number_vec{1,2,3,4,5,6,7,8,9};
	for (auto num_vec : number_vec)		num_vec = 2;	// no change
	for (auto num_vec : number_vec)	cout << num_vec << " , ";	cout << endl;

	for (int i = 0; i < 3; ++i)			number_vec[i] = i + 10;	// changed
	for (auto num_vec : number_vec)	cout << num_vec << " , ";	cout << endl;

	for (auto& num_vec : number_vec)		num_vec = 99;		// changed
	for (auto num_vec : number_vec)	cout << num_vec << " , ";	cout << endl;

	return 0;
}
