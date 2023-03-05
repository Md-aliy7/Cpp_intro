/*
Topic 11:
https://cplusplus.com/doc/tutorial/inheritance/
*/

/*
Friends are functions or classes declared with the 'friend' keyword.
A friend can access class members through that class objects.
1) Friend function:
A non-member function (declared a friend of a class) can access the private and protected
members of that class. That is done by including a declaration of this external function
within the class, and preceding it with the keyword 'friend'.   (see examples)

2) Friend class:
A friend class is a class whose members have access to the private or protected members of another class.

3) Inheritance between classes:
Classes in C++ can be extended, creating new classes which retain characteristics of the base class.
This process, known as inheritance, involves a base class and a derived class: 
The derived class inherits the members of the base class, on top of which it can add its own members.

-) Derived classes definitions use the following syntax:
class derived_class_name: public base_class_name
{ ... definition ... };

-) Multiple inheritance: A class may inherit from more than one class with syntax:
class derived_class_name: public base_class1_name, public base_class2_name, public base3_class_name
{ ... definition ... };

Note: The 'public' access specifier may be replaced by any one of the other access specifiers
(protected or private). This access specifier limits the most accessible level for the members
inherited from the base class such that:
-) The members with a more accessible level are inherited with this level instead.
-) The members with an equal or more restrictive access level keep their level in the derived class.
_____________________________________________________________________
Access                      |  public   |  protected    |   private |
=====================================================================
members of the same class   |    yes    |    yes        |    yes    |
members of derived class    |    yes    |    yes        |    no     |
not members	(objects)       |    yes    |    no         |    no     |
---------------------------------------------------------------------
A publicly derived class inherits access to every member of a base class except:
- its constructors and its destructor 
- its assignment operator members (operator=)
- its friends
- its private members

Note: Access to the constructors and destructor of the base class is not inherited, but their
defaults are automatically called by the constructors and destructor of the derived class.
For base class constructors with parameters, they must be called explicitly after the derived
class constructors with syntax:
derived_constructor_name (parameters) : base_constructor_name (parameters) {...}
*/

#include <iostream>

using namespace std;

class Square;
class Rectangle {
    int width{}, height{};
public:
    Rectangle() {}
    Rectangle(int x, int y) : width(x), height(y) {}
    int area() { return width * height; }
    friend Rectangle duplicate(const Rectangle&);   // friend function
    void convert(Square a);
};

Rectangle duplicate(const Rectangle& param)
{
    Rectangle duplic;
    duplic.width = param.width * 2;
    duplic.height = param.height * 2;
    return duplic;
}

class Square {
    friend class Rectangle;     // friend class
private:
    int side;
public:
    Square(int a) : side(a) {}
};

void Rectangle::convert(Square a) {
    width = a.side;
    height = a.side;
}

// Inheritance
class Mother {
public:
    Mother()
    {
        cout << "Mother: no parameters\n";
    }
    Mother(int a)
    {
        cout << "Mother: int parameter\n";
    }
};

class Daughter : public Mother {
public:
    Daughter()
    {
        cout << "Daughter: no parameter\n\n";
    }
    Daughter(int a)
    {
        cout << "Daughter: int parameter\n\n";
    }
};

class Son : public Mother {
public:
    Son()
    {
        cout << "Son: no parameter\n\n";
    }
    Son(int a) : Mother()
    {
        cout << "Son: int parameter\n\n";
    }
};

int main() {
    // friend function
    Rectangle foo;
    Rectangle bar(2, 3);
    foo = duplicate(bar);
    cout << foo.area() << '\n';
    cout << bar.area() << '\n';

    // friend class
    Rectangle rect;
    Square sqr(4);
    rect.convert(sqr);
    cout << rect.area() << "\n\n";

    // constructors and derived classes
    Daughter Aliya(10);
    Son Ibrahim(10);
    Daughter Aysha;
    Son Ali;
    return 0;
}
