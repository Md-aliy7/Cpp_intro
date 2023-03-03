/*
Topic 7.1:
https://cplusplus.com/doc/tutorial/functions/
https://cplusplus.com/doc/tutorial/functions2/
The C++ standard library provides a wide range of facilities that are usable in standard C++:
https://en.cppreference.com/w/cpp/standard_library
*/

/*
In C++, a function is a group of statements that is given a name, and which can be called from some
point of the program. The most common syntax to define a function is:
type name ( parameter1, parameter2, ...) { statements }
Where:
- type is the type of the value returned by the function.
- name is the identifier by which the function can be called.
- parameters: Each parameter consists of a (type + identifier) with a seperating comma .
- statements is the function's body. It is a block of statements surrounded by braces { },
the last statement is (return variable_of_function_type;).

For functions with no type to be returned, we use the syntax:
void name ( parameter1, parameter2, ...) { statements }

Using parentheses () after the function name in its declaration and for calling it is a must.
The return value of function int main() is:	return 0;	// The program was successful

Arguments passed by value and by reference:
1- (by value) means the parameter is (type + identifier): the arguments values, given during
a function call, are copied into the formal parameters within another memory location.
2- (by reference) :
a) (by reference using a reference) means the parameter is (type + & + identifier).
b) (by reference using a pointer) means the parameter is (type + * + identifier).
what is passed is no longer a copy, but the variable itself, and any modification on its corresponding 
local variable within the function is reflected in the variables passed as arguments in the call.
For passing the variables without modification we use const pointer & const reference.
-) Note: the collection types like strings, vectors, and others have a certain amount of overhead
when thay are copied, so for the sake of not losing any data and saving memory, passing this
type of data by reference is more reasonable since the parameter is expensive to copy.

Inline functions: insert the code of the function where it is called, instead of formally
calling a function, and only specified in the function declaration, not while calling:
inline type name ( parameter1, parameter2, ...) { statements }

Default values in parameters: the function can include a default value for its last parameter,
which is used by the function when called with fewer arguments.

Declaring functions: Functions cannot be called before they are declared.
The prototype of a function can be declared without defining the function completely:
type name ( parameter1, parameter2, ...);
Naturally, the function shall be defined somewhere else, like later in the code.

Recursive function: is a function that calls itself directly or indirectly. The recursion continues
until some condition is met. Recursion provides a clean and simple way to write code.

Overloaded functions:
In C++, two different functions can have the same name if their parameters are different;
-) either because they have a different number of parameters,
-) or because any of their parameters are of a different type.
Two overloaded functions (i.e., two functions with the same name) have entirely different definitions;
they are, for all purposes, different functions, that only happen to have the same name.

Overloaded functions with the same definition can be defined as a function template:
Syantax:
template <template-parameters> function-declaration
or more specificly:
template <class SomeType1, class SomeType2, type identifier1>
SomeType function_name (SomeType1 Param1, SomeType2 Param2) 
{statements deal with Param1, Param2, and identifier1}

Practice the examples shown below.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
int main() {
	double num;
	cout << "Enter a number (double): ";
	cin >> num;

	cout << "The sqrt of " << num << " is " << sqrt(num) << endl;
	cout << "The cubed root of " << num << " is " << cbrt(num) << endl;
	cout << "The sine of " << num << " is " << sin(num) << endl;
	cout << "The cosine of " << num << " is " << cos(num) << endl;
	cout << "The ceil of " << num << " is " << ceil(num) << endl;
	cout << "The floor of " << num << " is " << floor(num) << endl;
	cout << "The round of " << num << " is " << round(num) << endl;

	double power;
	cout << "Enter a power to rasie to that number: ";
	cin >> power;
	cout << num << " is raised to power " << power << " is: " << pow(num,power) << endl;

	// random number
	// std::srand should be seeded once, before any calls to rand(), at the start of the program.
	srand(time(nullptr));	//	srand(time(0));

	cout << "RAND_MAX on my system is : " << RAND_MAX << endl;
	cout << "A random number is: " << rand() << endl;
	cout << "A random number is: " << rand() << endl;
	cout << "A random number is: " << rand() << endl;
	cout << "A random number is: " << rand() << endl;

	return 0;
}
*/

const double pi{3.14159};

double calc_area_circle(double);	//prototype

void area_circle() {
	double radius;
	cout << "Enter the radius of the circle: ";
	cin >> radius;

	cout << "\nThe area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

double cal_volume_cylinder(double , double height);	//prototype
void volume_cylinder();		//prototype
string say_hello(string);	//prototype
void sqrt_func(double&);	//prototype

double calc_cost(double& base_cost, double tax_rate = 0.05, double shipping = 3.8) {
	base_cost = (base_cost * tax_rate) + shipping + base_cost;
	return base_cost;
}

// Inline function:
inline void greeting(string name, string title, string prefix = "Mr.") {
	cout << "\nHello " << prefix << name << "\nCongrats for your " << title << endl;

}

// Overloaded functions:
void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<char>);
void print(vector<vector<string>>, int column_num, int raw_num);

// Arguments passed by reference:
void pass_by_ref(double& grade, string& name) {
	grade = grade / 100;
	string congrats = "You passed! Congratulations, ";
	name = congrats + name + " Your percentage is " + to_string(grade);
	cout << name;
}

// Recursive factorial function:
unsigned long long factorial(unsigned long n) {
	if (n == 0)	return 1;
	return n * factorial(n - 1);
}

// Function template:
template <class T, class U, int N>
U squared_multiply(T val1, U val2)
{
	if (val1 == val2) {
		cout << "x and y are equal\n" << "Their squared multiplication is ";
		return pow(val1 ^ 2, N);
	}
	else
	{
		cout << "x and y are not equal\n" << "Their squared multiplication is ";
		return pow(val1 * val2, N);
	}
}

int sum_cost = 30;
static int nummy = 900;
int main() {
	cout << nummy << endl;
	cout << sum_cost << endl;
	int sum_cost = 1000;
	cout << sum_cost << endl;
	{	// new scope
		int sum_cost = 450;
		cout << sum_cost << endl;
		nummy = 400;
		cout << nummy << endl;

	}

	cout << "Enter a number to calculate its factorial: ";
	unsigned long int factorial_num;
	cin >> factorial_num;
	cout << "The factorial of " << factorial_num << " is " << factorial(factorial_num) << endl;

	area_circle();
	volume_cylinder();
	say_hello("Mohamed ALI");

// Argument passed by reference:
	double number;
	cout << "Enter a number to get its squar: ";
	cin >> number;
	sqrt_func(number);
	cout << number;

	double init_cost;
	cout << "\nEnter the purchase cost for the product: ";
	cin >> init_cost;
	calc_cost(init_cost);
	cout << init_cost;

	cout << "\nEnter the purchase cost for the product: ";
	cin >> init_cost;
	calc_cost(init_cost, 0.08);
	cout << init_cost;

	greeting("Mohamed", "Ph.D.");

// Overloaded functions:
	print(100);
	print(598.2685);
	print(274.65F);
	print("C-style string");
	string s{ "C++ string" };
	print(s);
	print("C-style string", s);
	vector<char> cha{'A','B','C','D','E','F'};
	print(cha);
	vector<vector<string>> str_vector{ {"First Name: ", "Second Name: ", "Surname: "}, 
		{"Mohamed", "Abdo ", "ALI"},
		{"Hesham", "Ahmed ", "Tarek"}
	};
	print(str_vector, 3, 3);

	double grade = 99;
	string name = "Mohamed ALI";
	pass_by_ref(grade, name);
	cout << "\nYour grade is " << grade << endl;
	cout << name << endl;

// Function template:
	cout << "The function template call results in:\n";
	int x = 10; double y = 10.5;
	double template_func = squared_multiply<int, double, 2>(x, y);
	cout << template_func << '\n';

	return 0;
}

double calc_area_circle(double r) {
	return pi * r;
}

double cal_volume_cylinder(double radius, double height) {
	return calc_area_circle(radius) * height;
}

void volume_cylinder() {
	double radius;
	double height;
	cout << "\nEnter the radius of the cylinder: ";
	cin >> radius;
	cout << "\nEnter the height of the cylinder: ";
	cin >> height;

	cout << "\nThe volume of the cylinder is " << cal_volume_cylinder(radius, height) << endl;
}

string say_hello(string name) {
	cout << "Hello " << name << ".\nNice to meet you.\n";
	return "0";
}

void sqrt_func(double& number) {
	number *= number;
}

void print(int num) {
	cout << "Printing int: " << num <<endl;
}
void print(double num) {
	cout << "Printing double: " << num << endl;
}
void print(string str) {
	cout << "Printing string: " << str << endl;
}
void print(string str1, string str2) {
	cout << "Printing two strings: " << str1 << "\t" << str2 << endl;
}
void print(vector<char> vec_char) {
	cout << "Printing vector object of type char: ";
	for (char i : vec_char) {
		cout << i;
	}
	cout << endl;
}
void print(vector<vector<string>> str_vec, int column_num, int raw_num) {
	cout << "Printing 2D vector of type string: " << endl;
	for (int j = 1; j < raw_num; ++j) {
		for (int i = 0; i < column_num; ++i) {
			cout << str_vec[0][i] << str_vec[j][i];
			cout << endl;
		}
	}
}
