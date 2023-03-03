/*
Topic 10.1:
https://cplusplus.com/doc/tutorial/classes/
*/

/*
Classes are an expanded concept of data structures: they can contain data members, 
and can also contain functions as members.
So, members can either be data or function declarations.
An object is an instantiation of a class.
Classes are defined using 'class' or 'struct' keywords, with the following syntax:
class class_name {
  access_specifier_1:
    member1;
  access_specifier_2:
    member2;
} object_name(optional);

-) An access specifier is one of the three keywords:
a) 'private' members are accessible only from other members of the same class or from their "friends".
In other words, direct access to 'private' members from outside the class is not allowed.
b) 'protected' members are accessible from other members of the same class (or from their "friends"),
and also from members of their derived classes (inheritance).
c) 'public' members are accessible from anywhere where the object is visible.
By default, a class declared with 'class' have all its members with private access.
By default, a class declared with 'struct' have all its members with public access.

Any of the public members of object object_name can be accessed by simply inserting
a dot (.) between object name and member name.

Constructors:   (declared as a public access member function with no type)
Constructor is a function automatically called whenever a new object of a class is created,
allowing the class to initialize member variables or allocate storage with syntax:
class_name (params) {definition}    , or
Like any other function, a constructor can also be overloaded.

-) To declare an object of a class that has no constructor or default constructor:
class_name object_name;
class_name object_name{};
The default constructor is the constructor that takes no parameters.
-) To declare an object of a class that has a constructor (with parameters):
class_name object_name (initialization_value);      or,
class_name object_name = initialization_value;      or,
class_name object_name { initialization_value };    or,
class_name object_name = { initialization_value };

-) The scope operator (::) is used to define functions, that already declared within a class
but not defined, with syntax:    ('type' is removed for constructor functions)
type class_name::function_name( params ){ definition }
// other syntaxes exist for constructor like:   (see examples)
class_name::class_name(type1 param1, type2 param2) {data_member1 = param1, data_member2 = param2}

-) If inner_object is a member within class 'class_name', it can be initialized within that
class constructor or member functions similar to the syntaxes shown below: (see examples)
class_name::class_name(type1 param1, type2 param2) : inner_object(param1), data_member(param2) {}
class_name::function_name(type1 param1, type2 param2) : inner_object(param1) {data_member = param2;}

-) Pointers to classes
Objects can also be pointed to by pointers: a declared class is itself a valid type,
so it can be used as the type pointed to by a pointer.
class_name object_name;
class_name* ptr_object_name;
ptr_object_name = &object_name;
To access a structure type class_name by pointer 'ptr_object_name', with syntax:
(* ptr_object_name).member_name;	or,
ptr_object_name -> member_name;	// The arrow operator (->) is a dereference operator.
*/

#include <iostream>

using namespace std;

class Rectangle {
    int width, height;  // private access
public:
    Rectangle();    // default constructor prototype.
    Rectangle(int, int);    // constructor prototype.
    int area(void) { return (width * height); }
    /*functions defined within a class are automatically considered 
    an inline member function by the compiler.*/
};

Rectangle::Rectangle() : width{ 5 }, height(5) {}

Rectangle::Rectangle(int a, int b): width(a){height = b;}

class Circle {
    double radius;
public:
    Circle(double r) : radius(r) { }
    double area() { return radius * radius * 3.14159265; }
};

class Cylinder {
    Circle base;    // data member of type Circle declared but not initialized.
    double height;
public:
    Cylinder(double r, double h) : base(r) { height = h; }
    double volume() { return base.area() * height; }
};
/*
In this example, class Cylinder has a member object whose type is another class
(base's type is Circle). Because objects of class Circle can only be constructed
with a parameter, Cylinder's constructor needs to call base's constructor, and the
only way to do this is in the member initializer list.
*/

int main() {
    Rectangle rect(3, 4);
    Rectangle rectb;
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;

    // member initialization
    Cylinder foo(10, 20);
    cout << "foo's volume: " << foo.volume() << '\n';

    // Pointers to classes
    Rectangle obj(3, 4);
    Rectangle * bar, * baz;
    bar = &obj;
    baz = new Rectangle[2]{ {2,5}, {3,6} };
    cout << "obj's area: " << obj.area() << '\n';
    cout << "*bar's area: " << bar->area() << '\n';
    cout << "baz[0]'s area:" << baz[0].area() << '\n';
    cout << "baz[1]'s area:" << baz[1].area() << '\n';
    delete[] baz;
    return 0;
}
