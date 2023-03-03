/*
Topic 10.3:
https://cplusplus.com/doc/tutorial/classes2/
*/

/*
Special member functions are member functions that are implicitly defined as
member of classes under certain circumstances. There are six:
_________________________________________________________
Member function			|	typical form for class C:	|
=========================================================
Default constructor		|	C::C();						|
Destructor				|	C::~C();					|
Copy constructor		|	C::C (const C&);			|
Copy assignment			|	C& operator= (const C&);	|
Move constructor		|	C::C (C&&);					|
Move assignment			|	C& operator= (C&&);			|
---------------------------------------------------------

1) Default constructor:	(notice exapmles of previous sections)
The default constructor is the constructor called when objects of a class are declared, but
are not initialized with any arguments (no private or protected members need to be initialized).
If a class definition has no constructors, the compiler assumes the class to have an implicitly
defined default constructor. 
But when we need to initialize private or protected data members of the class, the constructor
must be explicitly declared with parameters. In this case, the compiler no longer provides an
implicit default constructor, and no longer allows the declaration of new objects of that class
without arguments, except if we explicitly define the default constructor.

2) Destructor:
Destructor is responsible for the necessary cleanup needed by a class when its object lifetime ends.
It is useful when a class allocates dynamic memory to store some data with 'new' keyword.
A destructor is a member function called automatically at the end of the object's life, in charge of
releasing an allocated memory. it takes no arguments and returns nothing, not even void.

Syntax as a defined member within a class C:
~C() { delete memory_ptr; }

3,4) Copy constructor and assignment:
A copy constructor is a constructor whose first parameter is of type (Class_name&) and which can be
invoked with a single argument of this type.
Objects also be copied on any assignment operation, the result is like copying on construction.
Note: Here, a copy of the passed object is created with a unique memory.

Copy constructor syntax as a defined member within a class C:
C(C&) { ... definiton_with_deep_copy ... }

Copy assignment syntax as a defined member within a class C:
C operator= (const C& assigned_object) { ... definiton_with_deep_copy ... }  

5,6) Move constructor and assignment:
Similar to copying, moving also uses the value of an object to set the value to another object.
But, unlike copying, the content is actually transferred from one object (source) to the
other (destination). The source loses that content, which is taken over by the destination.
Note: The source memory is transfered to the destination without allocating any new storage.

Move constructor syntax as a defined member within a class C:
// This moving only happens when the source is an unnamed object.
C (C&& source_object) {
definiton (move pointer of source_object to destination pointer and delete the first one)
}

Move assignment syntax as a defined member within a class C:
C& operator= (const C&& source_object) {
definiton (move pointer of source_object to destination pointer and delete the first one)
}

Note: The returned type from operator functions must agree with the parameter type declared
in (copy | move) constructor & assignment. (see examples)
*/

#include <iostream>
#include <string>

using namespace std;

class Paragraph {
    string* ptr;
public:
    // constructors:
    Paragraph() { ptr = new string; }
    Paragraph(const string& str) {
        ptr = new string;
        *ptr = str;
    }
    // destructor:
    ~Paragraph() { delete ptr; }
    // access content:
    const string& content() const { return *ptr; }
    void address() const { cout << ptr << endl; }
};

class Copy_object {
    string* ptr;
public:
    int number1;
    int number2;
    Copy_object(){}
    Copy_object(const string& str, int rank) {
        ptr = new string;
        *ptr = str;
        number1 = rank;
        number2 = rank;
    }
    ~Copy_object() { delete ptr; }

    // copy constructor:
    Copy_object(const Copy_object& passed_object) {
        ptr = new string;
        *ptr = passed_object.content();     // deep copy
        number1 = passed_object.number1;    // deep copy
    }
    // access content:
    const string& content() const { return *ptr; }
    auto adreess_a() const { return ptr; }
    auto address() { return ptr; }

    // Copy assignment:
    Copy_object operator= (const Copy_object& assigned_object) {
        delete ptr; // to garantee freeing any used memory (the only diff. from copy constructor)
        ptr = new string;
        *ptr = assigned_object.content();     // deep copy required
        number1 = assigned_object.number1;    // deep copy required
        return *this;
    }
};

class move_object {
    string* ptr;
    int* ptr2;
public:
    int number1;
    int number2;
    move_object() {}
    move_object(const string& str) {    // constructor used in addition
        ptr = new string;
        *ptr = str;
    }
    move_object(const string& str, int rank) {  // constructor used in subtraction
        ptr = new string;
        *ptr = str;
        ptr2 = new int;
        *ptr2 = rank;
        number1 = rank;
        number2 = rank;
    }
    ~move_object() { delete ptr; }

    // access content:
    const string& content() const { return *ptr; }
    auto adreess_a() const { return ptr; }
    auto address() { return ptr; }

    // Move constructor:
    move_object (move_object&& source_object) {
        ptr = source_object.ptr;    // move pointer
        ptr2 = source_object.ptr2;
// After moving pointers from the source_object, delete them to release more memory
        source_object.ptr = nullptr;
        source_object.ptr2 = nullptr;
    
}

    // Move assignment:
    move_object& operator= (move_object&& source_object) {
        delete ptr; // to garantee freeing any used memory (the only diff. from move constructor)
        delete ptr2;
        ptr = source_object.ptr;    // move pointer
        ptr2 = source_object.ptr2;
        source_object.ptr = nullptr;    // release more memory
        source_object.ptr2 = nullptr;
        return *this;
    }
// addition:   (return type from addition must agree with the move assignment parameter type)
    move_object operator+ (move_object& rhs) {
        rhs.number2 = number2 + rhs.number2;
        rhs.number1 = 2*(number1 + rhs.number1);
        return move_object((content() + " and " + rhs.content()));
    }
// subtaction:  (return type from subtaction must agree with the move assignment parameter type)
    move_object operator- (move_object& rhs) {
        int subtract = number2 - rhs.number2;
        number2 = subtract;
        number1 = 0.5* subtract;
        return move_object(content(), rhs.number2);
    }
};

int main() {

cout << "...................... Destructor ........................" << endl;
    Paragraph summary1;
    Paragraph summary2("Examples are given individually for each section");
    cout << "summary1's content: " << summary1.content() << '\n';
    cout << "summary2's content: " << summary2.content() << '\n';
    cout << "summary1's address: "; summary1.address();
    cout << "summary2's address: "; summary2.address();

cout << "...................... Copy constructor ........................" << endl;
    Copy_object object1("Example", 15);
    const Copy_object object2 = object1;
    cout << "object1's content: " << object1.content() << '\n';
    cout << "object2's content: " << object2.content() << '\n';
    cout << "Original number1: " << object1.number1 << endl;
    cout << "Deep copy for number2: " << object2.number1 << endl;
    cout << "Original number1: " << object1.number2 << endl;
    cout << "No deep copy for number2: " << object2.number2 << endl;
    cout << "object1 address" << object1.address() << endl;
    // object2.address();   //non-const function, not accessed by a const object.
    cout << "object1 address" << object1.adreess_a() << endl;
    cout << "object2 adreess is taken by deep copy: " << object2.adreess_a() << endl;

cout << "...................... Copy assignment ........................" << endl;
    Copy_object object3("New Example", 54);
    Copy_object object4;
    object4 = object3;  // copy assignment required
    cout << "object3's content: " << object3.content() << '\n';
    cout << "object3's content: " << object3.content() << '\n';
    cout << "Original number1: " << object3.number1 << endl;
    cout << "Deep copy for number2: " << object4.number1 << endl;
    cout << "Original number1: " << object3.number2 << endl;
    cout << "No deep copy for number2: " << object2.number2 << endl;
    cout << "object3 address" << object3.address() << endl;
    cout << "object4 address" << object4.address() << endl;
    cout << "object3 address" << object3.adreess_a() << endl;
    cout << "object4 adreess is taken by deep copy: " << object4.adreess_a() << endl;

cout << "...................... Move constructor ........................" << endl;
    // This moving only happens when the source is an unnamed object.
    const move_object object5 = move_object("unnamed object", 159);
    cout << "object5's content: " << object5.content() << '\n';
    cout << "object5.number1: " << object5.number1 << endl;
    cout << "object5 adreess is a: " << object5.adreess_a() << endl;
    cout << "object5.number2: " << object5.number2 << endl;

cout << "...................... Move assignment ........................" << endl;
    move_object object6 ("move1 object", 987);
    move_object object7("move2 object", 123);
    cout << "object7's content: " << object7.content() << '\n';
    cout << "object7.number1: " << object7.number1 << '\n';
    cout << "object7.number2: " << object7.number2 << '\n';
    object7 = object6 + object7;
    cout << "object7's new content after addition: " << object7.content() << '\n';
    cout << "new object7.number1: " << object7.number1 << '\n';
    cout << "new object7.number2: " << object7.number2 << '\n';
    move_object object8("Last object", 9000);
    cout << "object8's content: " << object8.content() << '\n';
    cout << "object8.number1: " << object8.number1 << '\n';
    cout << "object8.number2: " << object8.number2 << '\n';
    object8 = object8 - object6;
    cout << "object8's new content after subtraction: " << object8.content() << '\n';
    cout << "new object8.number1: " << object8.number1 << '\n';
    cout << "new object8.number2: " << object8.number2 << '\n';

	return 0;
}