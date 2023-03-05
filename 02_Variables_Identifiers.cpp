/*
Topic 2:
https://cplusplus.com/doc/tutorial/variables/
https://cplusplus.com/doc/tutorial/constants/
https://cplusplus.com/doc/tutorial/basic_io/	// to be read again.
*/

/*
A variable is a portion of memory to store a value.
A valid identifier (valid variable name) is a sequence of one or more letters, digits, or underscore characters (_).
Spaces, punctuation marks, and symbols cannot be part of an identifier. In no case can they begin with a digit.
The values of variables are stored somewhere in an unspecified location in the computer memory as zeros and ones.

Fundamental data types are basic types implemented directly by the language that represent the basic storage 
units supported natively by most systems.
They can mainly be classified into:

1- Character types: They can represent a single character, such as 'A' or '$'.
char:		Exactly one byte in size. At least 8 bits.
char16_t:	Not smaller than char. At least 16 bits.
char32_t:	Not smaller than char16_t. At least 32 bits.
wchar_t:	Can represent the largest supported character set.

2- Numerical integer types: They can store a whole number value, such as 7 or 1024. They exist in a variety of
sizes, and can either be signed or unsigned, depending on whether they support negative values or not.
signed char:				Same size as char. At least 8 bits.
(signed) short (int):		Not smaller than char. At least 16 bits.
(signed) int:				Not smaller than short. At least 16 bits.
(signed) long (int):		Not smaller than int. At least 32 bits.
(signed) long long (int):	Not smaller than long. At least 64 bits.
unsigned char	(same size as their signed counterparts)
unsigned short (int)
unsigned (int)
unsigned long (int)
unsigned long long (int)
Note: The names with () can be removed and we still get the same type.

3- Floating-point types: They can represent real values, such as 3.14 or 0.01, with different levels of precision,
depending on which of the three floating-point types is used.
float
double:			Precision not less than float
long double:	Precision not less than double

4- Boolean type: The boolean type, known in C++ as bool, can only represent one of two states, true or false.

Declaration of variables is like:
type identifier; type identifier1, identifier2, identifier3;

Initialization of variables is like:
type identifier = initial_value; type identifier (initial_value); type identifier {initial_value};

-) string type:
The C++ <string> std header contains a class named (string) which has member functions.
#include <string>
std::string identifier{initial_value};----------->// std::(header_class) object_name;
Some of these member functions are:
1- object_name.at(index)			//Access element
2- object_name.push_back(element)	//Add element at the end
3- object_name.size()				//Return size

(sizeof) operator: Queries size of the object or type.
Used when actual size of the object must be known.
Syntax:
sizeof( type )	(1)
sizeof expression	(2)
Explanation:
1) Yields the size in bytes of the object representation of type.
2) Yields the size in bytes of the object representation of the type of expression, if that expression is evaluated.

Constants are expressions with a fixed value.
const type identifier = replacement (i.e. value);	or:
const type identifier (replacement) ;	or:
const type identifier {replacement} ;	or:
#define identifier replacement		// no semi-colon (;) is used.

The following special characters can be used within a string or as a constant:
Escape:		code Description
\n:			newline
\r:			carriage return
\t:			tab
\v:			vertical tab
\b:			backspace
\f:			form feed (page feed)
\a:			alert (beep)
\':			single quote (')
\":			double quote (")
\?:			question mark (?)
\\:			backslash (\)
Can be used as shown below:
const char newline = '\n';
#define newline '\n'
*/


#include <iostream>
#include <climits>

using namespace std;

/*
///////////////////////////Start///////////////////////////////

int room_number{34};	// Global variables. defined outside all functions

int main() {
	int room_width{ 0 };	// Local variables. defined within a specific function
	int room_length{ 0 };
	cout << "Your room number is " << room_number << endl;
	cout << "Enter the width of the room:\n";
	cin >> room_width;

	cout << "\nEnter the length of the room:\n";
	cin >> room_length;

	cout << "\nThe room area is " << room_length * room_width << endl;
	return 0;
}

///////////////////////////End/////////////////////////////////
*/

/*
///////////////////////////Start///////////////////////////////
int main() {
	// Variable Types
	string my_name;
	my_name = "Mohamed Abdelsattar ALI" ;
	char first_char{ 'M' };
	cout << "My first character is " << first_char << endl;

	unsigned short int exam_score{ 66 };
	cout << "My grade is " << exam_score << endl << "My name is " << my_name << endl;

	long people_in_Turkey{ 86'678'540 };
	cout << "Total number of people in Turkey is " << people_in_Turkey << endl;

	long long people_in_world1{ 7'794'798'739 };
	long people_in_world2 = 7'794'798'739;
	// long people_in_world3{ 7'794'798'739 }; This will raise an error direcly instread of overflow.
	cout << people_in_world1 << endl << people_in_world2 << endl;

	float Pi{ 3.14159265359 };
	double pi{ 3.14159265359 };
	cout << "Pi value is " << Pi << endl << "Pi value is " << pi << endl;

	bool game_over{ false };
	cout << "The game over value is " << game_over << endl;

	short value1{ 30000 };
	short value2{ 4000 };
	short product{ value1 * value2 };	// Overflow happens
	cout << "The product of " << value1 << " and " << value2 << " is overflowed to be" << product;
	return 0;
}
*/
///////////////////////////End/////////////////////////////////

/*
///////////////////////////Start///////////////////////////////
int main() {
	cout << "Size of int is " << sizeof(int) << " bytes" << endl;
	cout << "Size of unsigned int is " << sizeof(unsigned int) << " bytes" << endl;
	cout << "Size of float is " << sizeof(float) << " bytes" << endl;
	cout << "Size of double is " << sizeof(double) << " bytes" << endl;
	cout << "Size of char is " << sizeof(char) << " bytes" << endl;
	cout << "Size of string is " << sizeof(string) << " bytes" << endl;

	cout << "===========================================================\n";

	cout << "Size of short is " << sizeof(short) << " bytes" << endl;
	cout << "Size of long is " << sizeof(long) << " bytes" << endl;
	cout << "Size of long long is " << sizeof(long long) << " bytes" << endl;
	cout << "Size of long double is " << sizeof(long double) << " bytes" << endl;
	cout << "Size of long float is " << sizeof(long float) << " bytes" << endl;
	cout << "Size of long float is " << sizeof(long int) << " bytes" << endl;
	cout << "Size of long float is " << sizeof(unsigned long int) << " bytes" << endl;

	cout << "===========================================================\n";

	cout << "Size of INT16_MAX is " << sizeof(INT16_MAX) << " bytes" << endl;
	cout << "Size of INT16_MIN is " << sizeof(INT16_MIN) << " bytes" << endl;

	cout << "Size of INT16_MIN is " << sizeof(INT_FAST32_MAX) << " bytes" << endl;
	cout << "Size of INT16_MIN is " << sizeof(INT_FAST32_MIN) << " bytes" << endl;

	cout << "Size of CHAR_MAX is " << sizeof(CHAR_MAX) << " bytes" << endl;
	cout << "Size of CHAR_MIN is " << sizeof(CHAR_MIN) << " bytes" << endl;

	cout << "Size of INT_MAX is " << sizeof(INT_MAX) << " bytes" << endl;
	cout << "Size of INT_MIN is " << sizeof(INT_MIN) << " bytes" << endl;

	cout << "Size of SHRT_MAX is " << sizeof(SHRT_MAX) << " bytes" << endl;
	cout << "Size of SHRT_MIN is " << sizeof(SHRT_MIN) << " bytes" << endl;

	cout << "Size of USHRT_MAX is " << sizeof(USHRT_MAX) << " bytes" << endl;

	cout << "Size of LONG_MAX is " << sizeof(LONG_MAX) << " bytes" << endl;
	cout << "Size of LONG_MIN is " << sizeof(LONG_MIN) << " bytes" << endl;

	cout << "Size of LLONG_MAX is " << sizeof(LLONG_MAX) << " bytes" << endl;
	cout << "Size of LLONG_MIN is " << sizeof(LLONG_MIN) << " bytes" << endl;

	cout << "===========================================================\n";

	cout << "Value of INT16_MAX is " << (INT16_MAX) << " bytes" << endl;
	cout << "Value of INT16_MIN is " << (INT16_MIN) << " bytes" << endl;

	cout << "Value of CHAR_MAX is " << (CHAR_MAX) << " bytes" << endl;
	cout << "Value of CHAR_MIN is " << (CHAR_MIN) << " bytes" << endl;

	cout << "Value of INT_MAX is " << (INT_MAX) << " bytes" << endl;
	cout << "Value of INT_MIN is " << (INT_MIN) << " bytes" << endl;

	cout << "Value of SHRT_MAX is " << (SHRT_MAX) << " bytes" << endl;
	cout << "Value of SHRT_MIN is " << (SHRT_MIN) << " bytes" << endl;

	cout << "Value of USHRT_MAX is " << (USHRT_MAX) << " bytes" << endl;

	cout << "Value of LONG_MAX is " << (LONG_MAX) << " bytes" << endl;
	cout << "Value of LONG_MIN is " << (LONG_MIN) << " bytes" << endl;

	cout << "Value of LLONG_MAX is " << (LLONG_MAX) << " bytes" << endl;
	cout << "Value of LLONG_MIN is " << (LLONG_MIN) << " bytes" << endl;

	cout << "===========================================================\n";

	cout << "(sizeof) using variable name" << endl;
	int age{ 24 };
	cout << "Size of age is " << sizeof(age) << " bytes" << endl;
	// or
	cout << "Size of age is " << sizeof age << " bytes" << endl;
	double wage{ 3000.546 };
	cout << "Size of wage is " << sizeof(wage) << " bytes" << endl;
	// or
	cout << "Size of wage is " << sizeof wage << " bytes" << endl;	
	
	cout << "===========================================================\n";

	// Constants:
	const long double pi = 3.1415926;
	cout << pi;		// pi value cannot be modified later on.

	return 0;
}
///////////////////////////End/////////////////////////////////
*/


int main() {
	cout << "Hello, Welcome to Monta's Carpet Cleaning Service" << endl;
	
	cout << "\nHow many small rooms would you like cleaned?\n";
	int number_of_small_rooms;
	cin >> number_of_small_rooms;

	cout << "\nHow many large rooms would you like cleaned?\n";
	int number_of_large_rooms;
	cin >> number_of_large_rooms;

	const double price_per_small_room{ 25 };
	const double price_per_large_room{ 36 };

	const double sales_tax{0.06};
	const int estimate_expiry{30};

	cout << "Estimate for carpet cleaning service" << endl;
	cout << "Number of small rooms: " << number_of_small_rooms << endl;
	cout << "Number of large rooms: " << number_of_large_rooms << endl;

	cout << "Price per small room: $" << price_per_small_room << endl;
	cout << "Price per large room: $" << price_per_large_room << endl;

	double cost = (price_per_small_room * number_of_small_rooms) + (price_per_large_room * number_of_large_rooms);
	double tax = cost * sales_tax;
	cout << "Cost: $" << cost  << endl;
	cout << "Tax: $" << tax << endl;

	cout << "=============================================" << endl;
	cout << "Total estimate: $" << cost + tax << endl;
	cout << "This estimate is valid for " << estimate_expiry << " days" << endl;

}
