/*
Topic 4:
https://cplusplus.com/doc/tutorial/operators/
*/

/*
Operators:

1- Assignment operator (=):
Assigns a value to a variable. (from right to left)
x = 5; This statement assigns the integer value 5 to the variable x.
x = y; This statement assigns to variable x the value contained in variable y.

2- Arithmetic operators ( +, -, *, /, % ):
(+)	addition
(-)	subtraction
(*)	multiplication
(/)	division
(%)	modulo	: gives the remainder of a division of two values
x = 11 % 3; results in variable x containing the value 2.

3- Compound assignment (+=, -=, *=, /=, %=, >>=, <<=, &=, ^=, |=):
expression				equivalent to...
y += x;					y = y + x;
x -= 5;					x = x - 5;
x /= y;					x = x / y;
price *= units + 1;		price = price * (units+1);

4- Increment and decrement (++, --):
++x; (the same as) x+=1; (the same as) x=x+1;
--x; (the same as) x-=1; (the same as) x=x-1;
_________________________________________________________________________________
Example (1)				|		Example (2)		|
x = 3;					|		x = 3;			|
y = ++x;				|		y = x++;		|
result: x contains 4, y contains 4	| result: x contains 4, y contains 3	|
---------------------------------------------------------------------------------
Example (1): (++x), the expression evaluates to the final value of x, once it is already increased.
Example (2): (x++), the expression evaluates to the value that x had before being increased.

5- Relational and comparison operators ( ==, !=, >, <, >=, <= ):
The result of such an operation is either true or false (i.e., a Boolean value).
operator	description					Example
==			Equal to					(a == 5)     // evaluates to false if a is not equal to 5
!=			Not equal to				(3 != 2)     // evaluates to true
<			Less than					(5 < 5)      // evaluates to false 
>			Greater than				(b+4 > a*c)  // evaluates to false if (3+4 > 2*6) is false
<=			Less than or equal to		(6 <= 6)     // evaluates to true
>=			Greater than or equal to	(6 >= 6)     // evaluates to true
Note: assignment operator(=) assigns the value on the right-hand to the variable on its left, while 
comparison operator (==) compares whether the values on both sides of the operator are equal.

6- Logical operators ( !: NOT, &&: AND, ||: OR ):
!(6 <= 4)   // evaluates to true
!true       // evaluates to false
( (5 == 5) && (3 > 6) )  // evaluates to false ( true && false )
( (5 == 5) || (3 > 6) )  // evaluates to true ( true || false )

operator:	short-circuit
&&      :	if the left-hand side expression is false, the right-hand side expression is never evaluated.
||      :	if the left-hand side expression is true, the right-hand side expression is never evaluated.
(not evaluated means not executed)

7- Conditional ternary operator ( ? ):
If condition is true, the entire expression evaluates to result1, and otherwise to result2.
condition ? result1 : result2;
c = (8>12) ? 56 : 34;	// c = 34
cout << "number 5 is " << ((5 % 2 == 0) ? "even": "odd") << endl;   // number 5 is odd

//Bitwise Operators are covered later.

-) Precedence of operators:	Detailed in the reference.
The operator of higher precedence is evaluated first.
Parts of the expressions can be enclosed in parenthesis to override this precedence order, 
or to make explicitly clear the intended effect.
x = 5 + (7 % 2);    // x = 6 (same as without parenthesis)
x = (5 + 7) % 2;    // x = 0

-) (static_cast) conversion: Converts between types.
Syntax:
static_cast < new-type > ( expression );    returns a value of type (new-type).

-) std::boolalpha, std::noboolalpha: 
Defined in header <ios> by preprocessing #include <iostream>
When the (boolalpha) format flag is set, bool values are inserted/extracted by their textual
representation: either (true or false), instead of integral values (1 or 0), respectively.
Syntax to set (boolalpha):
std::cout << std::boolalpha;        //must be set to the computer screen (i.e., std::cout) 
This flag can be unset with the (noboolalpha) manipulator:
std::cout << std::noboolalpha;      //must be set to the computer screen (i.e., std::cout) 
*/

#include <iostream>     // std::cout, std::boolalpha, std::noboolalpha
using namespace std;
int main()
{
    // Operators examples are found in the reference.
    float f = 3.59832;
    int b = static_cast<int>(f);
    cout << f << "\t\t" << b << "\t" << static_cast<int>(456.63) << endl;
    cout << boolalpha;
    bool a = true; bool c = false;
    cout <<a << '\t' << c << '\n';
    cout << noboolalpha;
    cout << a << '\t' << c << '\n';
    return 0;
}
