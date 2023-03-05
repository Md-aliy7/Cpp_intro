/*
Topic 9.2:
https://cplusplus.com/doc/tutorial/other_data_types/
*/

/*
-) Type aliases (typedef / using)
A type alias is a different name by which a type can be identified.
In C++, any valid type can be aliased so that it can be referred to with a different identifier.
Two syntaxes for creating such type aliases:
a) typedef existing_type new_type_name;	// 'typedef' keyword inherited from the C language.
b) using new_type_name = existing_type ;
'using' is more generic than 'typedef' which has certain limitations in the realm of templates.

Once an alias is defined, it can be used in any declaration just like any other valid type:

-) Unions
Unions allow one portion of memory to be accessed as different data types.
Its declaration and use is similar to the one of structures, but all its member elements 
occupy (share) the same physical space in memory.
Syntax:
union type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3;
} object_names;
Each of these members can be of a different data type, but the modification of one of
the members will affect the value of all of them.
The exact alignment and order of the members of a union in memory depends on the system.

When unions are members of a class (or structure), they can be declared with no name.
In this case, their members are directly accessible from objects by their names.

-) Enumerated types
An enumeration is a complete, ordered listing of all the items in a collection.
Enumerated types are types that are defined with a set of custom identifiers (items), known as enumerators,
as possible values.	(see examples)
Syntax:
enum type_name {
  identifier1,
  identifier2,
  identifier3,
} object_name;	
enum type declaration includes no other type, neither fundamental nor compound, in its definition.
The possible values that object_name can take are the enumerators listed within braces.
Each enumerator is assigned an integer numerical equivalent internally, which can be modified.
//Review "Enumerated types with enum class" from the reference.
*/

#include <iostream>

using namespace std;

union book1_t {
	int pages;
	int price;
	char c[3];
} book, *ptr;

struct {
	short hi;
	short lo;
	union {
		float dollars;
		int yen;
	};
} s;

enum months_t {
	january = 1, february, march, april,
	may, june, july, august,
	september, october, november, december
} month;

int main() {
	// Type aliases
	typedef char C;						using C1 = char;
	typedef unsigned int WORD;			using WORD1 = unsigned int;
	typedef char* pChar;				using pChar1 = char*;
	typedef char field[50];				using field1 = char[50];

	C mychar, anotherchar, * ptc1;		C1 mychar1, anotherchar1, * ptc11;
	WORD myword;						WORD1 myword1;
	pChar ptc2;							pChar1 ptc21;
	field name;							field1 name1;

	cout << sizeof(char) << endl;		cout << sizeof(C1) << endl;
	cout << sizeof(WORD) << endl;		cout << sizeof(unsigned int) << endl;
	cout << sizeof(char*) << endl;		cout << sizeof(pChar1) << endl;
	cout << sizeof(field) << endl;		cout << sizeof(char[50]) << endl;

	// Unions
	ptr = &book;
	s.dollars = 50.5;
	s.lo = 33;
	book.pages = 594;

	cout << "1: " << book.pages << endl;
	cout << "2: " << s.lo << endl;
	cout << "3: " << s.dollars << endl;
	cout << "4: " << book.c[2] << endl;
	book.c[0] = 'M';
	book.c[1] = 'a';
	cout << "5: " << book.c[0] << endl;
	cout << "*(ptr->c): " << *(ptr->c) << endl;
	book.price = 100;
	cout << "6: " << book.price << endl;
	cout << "7: " << book.c[1] << endl;
	cout << "*(ptr->c): " << *(ptr->c) << endl;
	cout << "As you can see, memory management for a union structure type is a confusing work.\n";

	// Enumerated types
	enum family {
		Grandpa, Grandma = 100, Father, Mother,
		Sister, Brother = 55, Son, daughter,
		Grandson = 0, Granddaugther
	}member1;

	family member2, member3, member4;
	family member5;

	member1 = Son;
	member2 = Grandpa;
	member3 = daughter;
	member4 = Granddaugther;
	member5 = Sister;

	cout << member1 << endl;
	cout << member2 << endl;
	cout << member3 << endl;
	cout << member4 << endl;
	cout << member5 << endl;

	months_t my_birth = september;
	cout << "My birth was in month number: " << my_birth << endl;
	
	return 0;
}
