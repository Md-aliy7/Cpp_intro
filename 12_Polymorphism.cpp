/*
Topic 12:
https://cplusplus.com/doc/tutorial/polymorphism/
*/

/*
1) Pointers to base class:
In class inheritance, a pointer to a derived class is type-compatible with a pointer to its base class.
A pointer to a base class can be assigned the address of a derived class, while by dereferencing it we
can only access the members inherited from the base class. The pointers to the base class cannot access
the derived class members.	(see examples)

2) Virtual members:
A 'virtual member' is a member function that can be redefined -without changing parameters- in a derived
class, while preserving its calling properties through references.

-) Syntax for a virtual function:   virtual type func_name (params|void) { ... definition ... }

Note: Non-virtual members can also be redefined in derived classes, but non-virtual members of derived
classes cannot be accessed through a reference of the base class.
A class that declares or inherits a virtual function is called a 'polymorphic class'.

3) Abstract base classes:
Abstract base classes are classes that can only be used as base classes. They must contain at least one
pure virtual function (virtual function with replacing its definition by (=0)).

-) Syntax for a pure virtual function:  virtual type func_name (params|void) = 0;

An Abstract base class can't be used to instantiate objects, but it can be used to create
pointers - to objects of derived (non-abstract) classes - which can be dereferenced.
*/

#include <iostream>

using namespace std;

class Polygon {
protected:
    int width{}, height{};
public:
    void set_values(int a, int b)
    {
        width = a; height = b;
    }
    int area() {
        return 0;
    }
    virtual int area_clac() { return 0; }   // virtual member function
};

class Rectangle : public Polygon {
public:
    int area()
    {
        return width * height;
    }
    int area_clac() { return width* height; }   // function redefiniton
};

class Triangle : public Polygon {
public:
    int area()
    {
        return width * height / 2;
    }
    int area_clac() { return width * height / 2; }  // function redefiniton
};

class Polygon_abs {
protected:
    int width, height;
public:
    Polygon_abs(int x, int y) { width = x; height = y; }

    virtual int area() = 0;
    void printarea()
    {
        cout << "Object address is: " << this << " with area= " << this->area() << '\n';
    }
};

class Rectangle_1 : public Polygon_abs {
public:
    Rectangle_1(int x, int y) : Polygon_abs(x,y){}
    int area()
    {
        return width * height;
    }
    int area_clac() { return width * height; }   // function redefiniton
};

class Triangle_1 : public Polygon_abs {
public:
    Triangle_1(int x, int y) : Polygon_abs(x, y) {}
    int area()
    {
        return width * height / 2;
    }
    int area_clac() { return width * height / 2; }  // function redefiniton
};

int main() {

cout << "------------------------ Pointers to base class --------------------------" << endl;
    Rectangle rect;
    Triangle trgl;
    Polygon* ppoly1 = &rect;
    Polygon* ppoly2 = &trgl;
    ppoly1->set_values(4, 5);
    ppoly2->set_values(4, 5);
    cout << "Not virtual function" << endl;
    cout << ppoly1->area() << '\n';
    cout << ppoly1->area() << '\n';
    cout << rect.area() << '\n';
    cout << trgl.area() << '\n';

cout << "------------------------ Virtual members --------------------------" << endl;
    Rectangle rect1;
    Triangle trgl1;
    Polygon poly1;
    Polygon* ppoly_1 = &rect1;
    Polygon* ppoly_2 = &trgl1;
    Polygon* ppoly_3 = &poly1;
    ppoly_1->set_values(7, 4);
    (*ppoly_2).set_values(7, 4);
    (*ppoly_3).set_values(7, 4);
    cout << "Virtual function" << endl;
    cout << (*ppoly_1).area_clac() << '\n';
    cout << ppoly_2->area_clac() << '\n';
    cout << ppoly_3->area_clac() << '\n';
    
cout << "------------------------ Abstract base classes --------------------------" << endl;
    Rectangle_1 rect_2(12, 5);
    Triangle_1 trgl_2(20, 3);
    Polygon_abs* ppoly1_ = &rect_2;
    Polygon_abs* ppoly2_ = &trgl_2;
    (*ppoly1_).printarea();
    ppoly2_->printarea();

    return 0;
}
