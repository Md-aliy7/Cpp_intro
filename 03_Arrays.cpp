/*
Topic 3:
https://cplusplus.com/doc/tutorial/arrays/
https://cplusplus.com/reference/vector/vector/
*/

/*
1- An array is a series of elements of the same type placed in contiguous memory locations that can
be individually referenced by adding an index to a unique identifier.
Like a regular variable, an array must be declared before it is used.

2- A typical declaration for an array in C++ is:
type name [elements_number]; where:
type (int, float...), name (valid identifier) and elements_number (the length of the array).
Arrays are blocks of static memory whose size must be determined at compile time, before the program runs.

3- Initializing arrays:
type name [elements_number]{ initial_values }; or
type name [elements_number] = { initial_values }; or if already declared:
name = { initial_values };

4- Accessing the values of an array: The syntax is:
name[index]

5- Multidimensional arrays can be described as "arrays of arrays".
char century [100][365][24][60][60];
declares an array with an element of type char for each second in a century. This amounts to more
than 3 billion char! So this declaration would consume more than 3 gigabytes of memory!

6- Vectors (use dynamic memory):
Unlike arrays, when a vector is declared, the vector elements are automatically initialized
to 0 unless you specifiy otherwise.
The C++ <vector> std header contains a class named (vector) which has member functions.
#include <vector>	// must for vectors
std::vector <type> object_name;		// std::(header_class) <member_type> object_name;
Some of these member functions are:
1- object_name.at(index)			//Access element
2- object_name.push_back(element)	//Add element at the end
3- object_name.size()				//Return size
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
const char new_line{ '\n' };

// creating (printarray) function:
void printarray(int arg[], int length) {
	for (int n = 0; n < length; ++n)
		cout << arg[n] << ' ';
	cout << '\n';
}

int main() {

// Arrays:
	char vowels[]{ 'a','e','i','o','u' };
	cout << "The first vowel is: " << vowels[0] << endl;
	cout << "The last vowel is: " << vowels[4] << endl;
	
	// cin >> vowels[8];	// Out of bounds, don't do this!

	double hi_tempes[]{90.1,100.97,89.8,77.5,81.6,85.7,79.9};
	cout << "The first element in hi_tempes array is: " << hi_tempes[0] << endl;
	hi_tempes[0] = 83.77 ;
	cout << "The first element in hi_tempes array is: " << hi_tempes[0] << endl;

	int test_scores[7]{68,87,95,79,82};
	for (int i = 0; i <= 6; ++i) {
		cout << "Score in index " << i << " is " << test_scores[i] << endl;
	}
	
	string names_list[4];
	for (int i = 0; i <= 3; ++i) {
		cout << "\nAdd a name to the list: ";
		cin >> names_list[i];
	}		
	cout << "\nThe names in the list are:\n";
	for (int i = 0; i <= 3; ++i) {
		cout << names_list[i] << endl;
	}
	cout << new_line;

// Multidimensional arrays:
	int multi_dim_array[4][3]{
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,11,12}
	};
	for(int i =0; i <=3; ++i){
		for (int n = 0; n <= 2; ++n) {
			cout << multi_dim_array[i][n] << endl;
		}
	}

// Vectors:
	std::vector <char> vowels_v{ 'a','e','i','o','u' };	//'' for char
	std::vector <int> test_scores_v;
	test_scores_v = { 100,122,99,87,98 };
	std::vector <long double> reandoms{ 59.5944,0.19522,25.6952 };
	std::vector <string> names;	//"" for string
	names = { "Mohamed", "ALI", "Abdelsattar", "MAMMA" };
	for (int i = 0; i <= 4; ++i) {
		cout << vowels_v.at(i) << ":  " << test_scores_v[i] << endl;
	}
	vector <char> letters{ 'a','b','c','d','e' };
	letters.push_back('f');
	letters.push_back('g');
	letters.push_back('h');
	letters.push_back('i');
	cout << new_line;
	for (int i = 0; i <= 8; ++i) {
		cout << letters.at(i) << endl;
	}
	// vectors add elemnts only with (.push_back) method
	cout << "Modify the char type element at index 0 to be:\n";
	cin >> letters.at(0);	// valid usage
	// cout << "\nModify the char type element at index 15 to be:\n";
	// cin >> letters.at(15);	// invalid usage (out of range), program crashes.

	vector <int> numbers{11,22,33,44,55,66};
	numbers.push_back(77);
	numbers.push_back(88);
	numbers.push_back(99);
	cout << new_line;
	for (int i = 0; i <= 8; ++i) {
		cout << numbers.at(i) << endl;
	}

// Example of a 2D-vector:
	vector <vector <int>> matrix{
		{11,12,13,14},
		{22,23,24,25},
		{33,34,35,36}
	};
	for (int i=0; i <= 2; ++i) {
		cout << matrix.at(i).at(0) << " ";
		cout << matrix.at(i).at(1) << " ";
		cout << matrix.at(i).at(2) << " ";
		cout << matrix.at(i).at(3) << new_line;
	}
 
// arrays as parameters (i.e. arguments in function)
	cout << new_line;
	int firstarray[] = { 5, 10, 15 };
	int secondarray[] = { 2, 4, 6, 8, 10 };
	printarray(firstarray, 3);
	printarray(secondarray, 5);
/*
note: 1- arrays cannot be directly copied, and thus what is really passed is a pointer.
	  2- C++ treats an array name as the location in memory of first array element.
	printarray({ 5, 10, 15 }, 3);	printarray(secondarray[], 5); are invalid usages.
	*/
	return 0;
}
