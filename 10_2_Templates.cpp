/*
Topic 10.2:
https://cplusplus.com/doc/tutorial/templates/
*/

/*
-) Overloading operators
C++ allows most operators to be overloaded so that their behavior can be defined for just
about any type, including classes.
Operators are overloaded by means of operator functions, which are regular functions with
special names: their name begins by the 'operator' keyword followed by the operator sign
that is overloaded. The syntax is:
type operator sign (parameters) {... definition ... }

Notice that some operators may be overloaded in two forms: either as a member function or
as a non-member function. (detailed in the reference)
Example: (replace @ by the operator in each case)
_________________________________________________________________________________________
Expression	 |  Operator	         |    Member function	      |  Non-member function |
@a	         |  + - * & ! ~ ++ --	 |    A::operator@()	      |  operator@(A)        |
a@	         |  ++ --	             |    A::operator@(int)	      |  operator@(A,int)    |
a@b	         |  + - * / %            |    A::operator@(B)	      |  operator@(A,B)      |
a@b	         |  = += -= *= /=	     |    A::operator@(B)	      |      -               |
-----------------------------------------------------------------------------------------
Where a is an object of class A, b is an object of class B.

-) The keyword 'this'
The keyword this represents a pointer to the object whose member function is being executed.
It is used within a class's member function to point to the object itself.

-) Static members
A class can contain static members, either (data) or (functions).
Static members have the same properties as non-member variables but they have class scope.
So, static function cannot access non-static members of the class or use keyword 'this'.
The value of a static data member (known as a "class variable") is not different from
one object of this class to another.

-) Const objects
When an object of a class is qualified as a const object with syntax:
const MyClass myobject;
The access to its 'data members' from outside the class is restricted to read-only,
as if all its data members were const for those accessing them from outside the class.

The 'member functions' of a const object can be called if only they are themselves specified
as const members with syntax:
type function_name(params) const {... definitions ...}
but non-const objects can access both const and non-const member functions alike and modify 
non-const data members.
Notice this different syntax (non-const member function returning a const):
const type function_name(params) {... definitions ...}

-) Class templates
Just like we can create function templates, we can also create class templates,
allowing classes to have members that use template parameters as types.
Syntax for example:
template <class T, class U, int X>
class mypair {
    T values[2];
    U name;
public:
    mypair(T first, T second, U user_name)
    {
        values[0] = first; values[1] = second; name = user_name;
    }
    U get_name();
    T get_index() { return X; }
    T get_degree() { return values[0]+values[1]; }
};
template <class T, class U, int X>
U mypair< T,  U, X>::get_name() { return name; }

-) Template specialization
It is possible to define a different implementation (structure) for a template when
a specific type is passed as template argument. This is called a template specialization.
Syntax with a specific type from the previous example template:
template <>
class mypair <string, string, 89> {
    string F_name;
    string S_name;
    int level;
public:
    mypair(string first, string second, int index)
    {
        F_name = first; S_name = second; level = index;
    }
    string get_Fname();
    string get_Lname() { return S_name; }
};
string mypair<string, string, 89>::get_Fname() { return F_name; }

Briefly:
1- template <class T, class U, int X> class mypair { ... }      // generic template
2- template <> class mypair <string, string, 89> { ... }        // specialization

Note: When we declare specializations for a template class, we must also define all its
members, even those identical to the generic template class, because there is
no "inheritance" of members from the generic template to the specialization.
*/

// overloading operators example
#include <iostream>

using namespace std;

class operator_change {
public:
    float x;
    operator_change(){}
    operator_change(float a) : x(a) {}
    float operator + (const operator_change&);
    // keyword 'this' (static functions can not use it.)
    bool check_this(float& object_member) {
        if (this != 0)
            return true;
        else return false;
    }
};

// make + work as * (not a good idea!)    (member function, try different signs)
float operator_change::operator+ (const operator_change& param) {
    operator_change sum;
    sum.x = x * param.x;
    return sum.x;
}

// make - work as /     (non-member function, try different signs)
float operator- (const operator_change& param1, const operator_change& param2) {
    operator_change sum;
    sum.x = param1.x / param2.x;
    return sum.x;
}

// addition operation of two cartesian vectors:
class CVector {
public:
    int x, y;
    CVector() {}
    CVector(int a, int b) : x(a), y(b) {}
   
  /* CVector operator= (const CVector& param)
    {
        x = param.x;
        y = param.y;
        return *this;
    }*/
};

CVector operator+ (const CVector& lhs, const CVector& rhs) {
    CVector temp;
    temp.x = lhs.x + rhs.x;
    temp.y = lhs.y + rhs.y;
    return temp;
}

// static member
class Dummy {
public:
    static int n, h;
    Dummy() { n++; h++; };
};
int Dummy::n = 0; // must be initialized outside its class.
int Dummy::h = 15;

// Const objects
class myclass {
    int var;
public:
    myclass(int x) { var = x; }
    const string name() { return "I am func 1"; }
    string name1() { return "I am func 2"; }
    string name1() const { return "I am func 2"; }
    int get() const { return var; }
    int get2()  { return var; }
    void set(int new_var) { var = new_var; }
    const void set2(int new_var) { var = new_var; }
};

// Class templates
template <class T, class U, int X>
class mypair {
    T values[2];
    U name;
public:
    mypair(T first, T second, U user_name)
    {
        values[0] = first; values[1] = second; name = user_name;
    }
    U get_name();
    T get_index() { return X; }
    T get_degree() { return values[0]+values[1]; }
};
template <class T, class U, int X>
U mypair< T,  U, X>::get_name() { return name; }

// Template specialization
template <>
class mypair <string, string, 100> {
    string F_name;
    string S_name;
    int index_c;
public:
    mypair(string first, string second, int index)
    {
        F_name = first; S_name = second; index_c = index;
        cout << "Student is ranked 1st.\n";
    }
    string get_Fname();
    string get_Lname() { return S_name; }
    int get_index() { return index_c; }
};
string mypair<string, string, 100>::get_Fname() { return F_name; }

int main() {

cout << "------------------------ class operator_change ------------------------" << endl;
    operator_change number1(3);
    operator_change number2(7);
    operator_change result1, result2, result3, result4;
    result1 = number1 + number2;
    result2 = number1.operator+ (number2);
    result3 = number1 - number2;
    //result4 = number1.operator- (number2);  object has no member called operator-
    cout << "+ result is: " << int(result1.x) << '\n';
    cout << "or result is: " << int(result2.x) << '\n';
    cout << "- result is: " << float(result3.x) << '\n';
    if (number2.check_this(number2.x))
        cout << "Yes, object member value is passed as: " << number2.x << endl;

cout << "------------------------ class CVector ------------------------" << endl;
    CVector foo(3, 1);
    CVector bar(1, 2);
    CVector result;
    result = foo + bar;
    cout << "CV (x1+x2) & (y1+y2) is: " << result.x << " and " << result.y << '\n';
    
cout << "------------------------ static member ------------------------" << endl;
    Dummy a;
    Dummy b[5];
    cout << a.n << '\n';
    cout << (*b).h << '\n';
    Dummy* c = new Dummy;
    cout << Dummy::n << '\n';
    cout << Dummy::h << '\n';
    delete c;
    Dummy v;
    cout << v.n << '\n';
    cout << Dummy::h << '\n';

cout << "------------------------ Const objects ------------------------" << endl;
    const myclass object1(5);
    myclass object2(13);
    cout << object1.get() << "\n";
    cout << object1.name1() << "\n";    // other members are not accessable
    cout << object2.get2() << "\n";
    cout << object2.get() << "\n";
    cout << object2.name() << "\n";
    cout << object2.name1() << "\n";
    object2.set(564);
    cout << object2.get() << "\n";      // all members are accessable.

cout << "------------------------ Class templates ------------------------" << endl;
    mypair <int, string, 45> object_temp(45, 48, "Mohamed");
    cout << object_temp.get_index() << endl;
    cout << object_temp.get_name() << endl;
    cout << object_temp.get_degree() << endl;

cout << "------------------------ Template specialization ------------------------" << endl;
    mypair <string, string, 100> first_student("Mohamed", "Ali", 89);
    cout << "Student index: " << first_student.get_index() << endl;
    cout << "Student first name: " << first_student.get_Fname() << endl;
    cout << "Student last naem: " << first_student.get_Lname() << endl;

    return 0;
}
