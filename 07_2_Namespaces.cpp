/*
Topic 7.2:
https://cplusplus.com/doc/tutorial/namespaces/
*/

/*
Scopes:
-) Named entities (such as variables, functions, and compound types) declared outside
any block have global scope, meaning that its name is valid anywhere in the code.
While an entity declared within a block, such as a function or a selective statement, has
block scope (known as local variables), and is only visible within the specific block in
which it is declared, but not outside it.

-) The visibility of an entity with block scope extends until the end of the block, including
inner blocks. Nevertheless, an inner block, because it is a different block, can re-utilize
a name existing in an outer scope to refer to a different entity; in this case, the name will
refer to a different entity only within the inner block, hiding the entity it names outside.
While outside it, it will still refer to the original entity.

Namespaces:
Namespaces allow us to group named entities that otherwise would have global scope into
narrower scopes, giving them namespace scope. Namespaces can be declared anywhere except
within any function or data structure definition.
The syntax to declare a namespace is:
namespace my_identifier
{
  named_entities
}
These named_entities can be accessed from within their namespace normally,
but if accessed from outside the 'my_identifier' namespace they have to be properly qualified
with the scope operator (::) such as:	my_identifier::named_entity
Namespaces are particularly useful to avoid name collisions.

-) The keyword 'using' introduces a name into the current declarative region (such as a block),
thus avoiding the need to qualify the name.
Example: All the entities (variables, types, constants, and functions) of the standard C++
library are declared within the std namespace. So, with (using namespace std;) command,
(std::cout) function can be called directly as (cout).

-) Variables with static storage (such as global variables) that are not explicitly initialized
are automatically initialized to zeroes.
-) Variables with automatic storage (such as local variables) that are not explicitly initialized
are left uninitialized, and thus have an undetermined value or give a compiler error.
*/

#include <iostream>

using namespace std;

namespace first
{
	int x = 5;
	int y = 10;
}

namespace second
{
	double x = 3.1416;
	double y = 2.7183;
	namespace second_2 {
		string x = "Hello from a subscope";
	}
}

int outer_x;		// automatically initialized.

int main() {
	int inner_x{};	// gives a compiler error if not initialized.
	using namespace first;
	cout << "y value from namespace 'first' is : " << y << '\n';
	cout << "y value from namespace 'second' is : " << second::y << '\n';
	cout << "outer_x global automatically initialized variable is : " << outer_x << '\n';

	{
		int x = 1000;
		cout << "x value in this specific scope is : " << x << '\n';
	}

	cout << "x value from namespace 'first' is : " << x << '\n';
	cout << "x value from namespace 'second' is : " << second::x << '\n';
	cout << "x value from namespace 'second_2' from within 'second' is : ("
	     << second::second_2::x << ") a string type variable." << '\n';

	return 0;
}
