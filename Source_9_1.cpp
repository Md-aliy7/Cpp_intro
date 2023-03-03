/*
Topic 9.1:
https://cplusplus.com/doc/tutorial/structures/
*/

/*
-) Data structures
A data structure is a group of data elements (known as members, with different
types and unique memory locations) grouped together under one name.
Syntax:
struct type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3;
} object_names;
Where:
1- type_name is a name for the structure type, 
2- object_names is a set of valid identifiers for objects that have the type of this structure,
3- within braces {},  each data member is declared with a type and a valid identifier.

If all object_names are specified, type_name (product) becomes optional since struct requires
either a type_name or at least one name in object_names, but not necessarily both.
Objects can also be declared from the structure type name (type_name) with syntax:
type_name object_name;
Objects can access their structure type members with syntax: (object_name.member_name)

-) Pointers to structures
Like any other type, structures can be pointed to by its own type of pointers:
type_name object_name;
type_name* ptr_object_name;
ptr_object_name = &object_name;

To access a structure type member_name by pointer 'ptr_object_name', with syntax:
(* ptr_object_name).member_name;	or,
ptr_object_name -> member_name;	// The arrow operator (->) is a dereference operator
Note: For precedence of operators:
*ptr_object_name.member_name; is different from the above syntax with().

Structures can also be nested in such a way that:
an element of a structure is itself another structure.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct fruits_l {
	string color;
	string name;
	int price;
} yours, mine, *ptr_fruit;

fruits_l list_fruit[3];
void printmovie(fruits_l fruit);

int main()
{
	mine.name = "banana";
	mine.color = "yellow";
	mine.price = 21;

	list_fruit[0] = mine;
	for (int i = 1; i < 3; ++i) {
		cout << "Enter a fruit name: ";
		cin >> yours.name;
		cout << "Enter its color: ";
		cin >> yours.color;
		cout << "Enter its price: ";
		cin >> yours.price;
		list_fruit[i] = yours;
	}

	cout << "My favorite fruit is: ";
	printmovie(mine);
	cout << "And yours is: ";
	printmovie(yours);

	cout << "The fruit list is:\n";
	printmovie(list_fruit[0]);
	printmovie(list_fruit[1]);
	printmovie(list_fruit[2]);

	ptr_fruit = &list_fruit[0];
	cout << "Accessed with pointer object: " << ptr_fruit->name << endl;
	cout << "Accessed with pointer object: " << ptr_fruit->color << endl;
	cout << "Accessed with pointer object: " << (*ptr_fruit).price << endl;

	cout << "The object 'mine' referred address is " << ptr_fruit << endl;

	return 0;
}

void printmovie(fruits_l fruit)
{
	cout << fruit.name << endl;
	cout << "Color: " << fruit.color << endl;
	cout << "Price: " << fruit.price << "\n";
}