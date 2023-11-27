/*
Topic 6:
https://cplusplus.com/doc/tutorial/ntcs/
*/

/*
// C++ has many libraries, each library has many functions and classes with attributed methods.
The same function can exist in more than one library.

To create a string:
1- For c-style string: (An array of characters is a string):
Example:	(no objects in C language!)
	char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char myword[] = "Hello";
In both cases, the array of characters myword is declared with a size of 6 elements of type char:
a) In the first case, the 5 characters that compose the word "Hello", plus a final null
character ('\0'), which specifies the end of the sequence.
b) In the second case, when using double quotes ("), a null character ('\0') is appended automatically.
Note: we must initialize an array of characters at the moment it is being declared and can not assign values
to them later except by using <cstring> header functions or assigning each element individually myword[i].

To handle c-style string type, as shown below, we use functions from <cstring> header:
https://cplusplus.com/reference/cstring/
#include <cstring>	//functions: strcat, strcpy, strncpy,...

2- For modern string:	(We should use C++ string)
a) We use, from the header <vector>, a class named (vector) to creat a vector object of type 'char' or 'string':
#include <vector>
vector <type> object_name;
b) With (string) class from the header <string>, we creat an object (i.e., instance) from that class.
https://cplusplus.com/reference/string/
#include <string>
string object_name;
Note: many functions are similar in both (class string in header <string>) & (class vector in header <vector>).
*/

#include <iostream>
#include <cstring>	//functions: strcat, strcpy, strcmp,...
#include <string>	//class: string, object functions: c_str, push_back, at, size,...
#include <vector>
#include <cctype>	//isalpha, isblank, isdigit,...
using namespace std;

//////////////////////////// c-style string /////////////////////////////////


int main() {
	char letter[]{ 'A', 'B', 'C', '\0'};
	char first_name1[20]{"Welcome to start"};
	char first_name2[20]{'W','e','l','c','o','m','e',' ','A','L','L', '!','\0'};
	char last_name[20]{};
	char full_name[50];

	cout << letter << endl;
	cout << first_name1 << endl;
	cout << first_name2 << endl;

	cout << "Please enter your first name:\n";
	cin >> first_name1;	// a new value is assigned to the variable.

	cout << "Please enter your last name:\n";
	cin >> last_name;

	cout << "Hello, " << first_name1 << " your first name has " << strlen(first_name1) << " characters" << endl;
	cout << "and your last name " << last_name  << " has " << strlen(last_name) << " characters" << endl;

	strcpy_s(full_name, first_name1);	// content is copied from "first_name1" to "full_name".
	strcat_s(full_name, " ");			// concatenation, like push_back for vector objects.
	strcat_s(full_name, last_name);
	cout << "Your full name is " << full_name << endl;

	cout << "Enter your full name with no space:\n";	//Not recommended with spaces.
	cin >> full_name;	// inserts only characters till first space and saves the rest in isrteam.
	// Using cin.getline() with a delimer is recommended!
	cout << "Your name is: " << full_name << endl;

	cout << "Enter your full name with spaces and a delimer * at the end:\n";
	cin.getline(full_name, 50,'*');	// extracts characters from istream (keyboard) and stores them into string.
	// notice not to read any previously saved values in istream with the newly inserted values.
	cout << "Your name is: " << full_name << endl;

	char temp[50]{};
	char name_full[50]{};
	cout << "Enter your full name with spaces and a delimer - at the end:\n";
	cin.getline(name_full, 50, '-');
	cout << "Your full name is: " << name_full << endl;
	strcpy_s(temp, name_full);
	if (strcmp(temp, name_full) == 0)
		cout << temp << " and " << name_full << " are the same." << endl;
	else
		cout << temp << " and " << name_full << " are different." << endl;

	//Lower case:
	for (size_t i{ 0 }; i < strlen(name_full); ++i) {
		name_full[i] = tolower(name_full[i]);
	}
	cout << "With lower cases, you full name is " << name_full << endl;

	//Upper case:
	for (size_t i{ 0 }; i < strlen(name_full); ++i) {
			name_full[i] = toupper(name_full[i]);
	}
	cout << "With upper cases, you full name is " << name_full << endl;

	if (strcmp(temp, name_full) == 0)
		cout << temp << " and " << name_full << " are the same." << endl;
	else
		cout << temp << " and " << name_full << " are different." << endl;

	return 0;
}

//////////////////////////// c++ string /////////////////////////////////

/*
int main() {

	string s1{ "apple" };
	string s2{ "APPLE" };
	string s3{ "name12" };
	string s4{ "name1234" };
	string s5{ "Kiwi" };
	string s6{ "aapplllee" };
	string s7{ "Banana" };

	cout << "apple != APPLE is " << (s1 < s2 ? "true" : "false") << endl;
	cout << "name12 > name1234 is " << (s3 > s4 ? "true" : "false") << endl;
	cout << "Kiwi == APPLE is " << (s5 == s2 ? "true" : "false") << endl;
	cout << "aapplllee > APPLE is " << (s6 > s2 ? "true" : "false") << endl;
	cout << "APPLE == APPLE is " << (s2 == s1 ? "true" : "false") << endl;
	cout << "apple <  Banana is " << (s1 < s7 ? "true" : "false") << endl;

	s1[2] = 'P';
	s5 = s5 + " and " + s1 + " are fruits\n";
	cout << s5 << endl;
	vector <char> name_char = { 'F', 'a', 't', 'm', 'a' };
	cout << name_char[0] << name_char[1] << name_char[2] << name_char[3] << name_char[4] << endl;

	vector <string> name_vec = { "Fatma", "Ali" };
	cout << name_vec[0] << " and " << name_vec[1] << endl;
	name_vec.push_back("Hassan");
	cout << name_vec[2] << endl;

	string part1{ "C++" };
	string part2{ " is a powerful " };
	string part3;
	part3 = "language";
	string sentence = part1 + part2 + part3;
	for(auto val : sentence){
		cout << val << "*";
	}
	cout << "\n";
	for (int i{ 0 }; i < sentence.length(); ++i) {
		cout << sentence[i] << "|";
	}
	cout << "\n";

	cout << sentence << endl;
	string sentence1;
	sentence1 = sentence.substr(0, 4);		// from element 0 count 4 elments to be included in a one substring.
	cout << sentence1 << endl;
	cout << sentence.substr(4, 2) << endl;	// from element 4 count 2 elments to be included in a one substring.
	cout << sentence.substr(7,2) << endl;	// from element 7 count 2 elments to be included in a one substring.
	cout << sentence.substr(9, 8) << endl;	// from element 9 count 8 elments to be included in a one substring.
	cout << sentence.substr(18, 9) << endl;	// from element 18 count 9 elments to be included in a one substring.

	string one_word;
	cout << "Enter a word to find its position:\n";
	cin >> one_word;
	size_t position = sentence.find(one_word);
	if (position != string::npos)
		cout << "The word " << one_word << " starts at position " << position << " in the string\n";
	else 
		cout << "Word is not found" << endl;
	
	cout << "The length before erasing is: " << sentence.length() << endl;
	sentence.erase(0,9);	// from element 0 count 9 elments to be erased from the string.
	cout << "The new string after erasing is: " << sentence << endl;
	cout << "with a new length is " << sentence.length() << endl;
	
	sentence.clear();		// all elments to be erased from the string.
	cout << "The new length after clear function is " << sentence.length() << endl;
	
	cout << "maximum value for size_t is: " << std::string::npos << endl;
	
	// Notice that cout and string are functions defined in 'std' once their headers are included.
	std::string pi = "pi is " + std::to_string(3.1415926);	// Convert numerical value to string
	std::string perfect = std::to_string(1 + 2 + 4 + 7 + 14) + " is a perfect number";
	std::cout << pi << '\n';
	std::cout << perfect << '\n';

	return 0;
}
*/
