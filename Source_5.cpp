/*
Topic 5:
https://cplusplus.com/doc/tutorial/control/
*/

/*
A simple C++ statement is each of the individual instructions of a program. They always end
with a semicolon (;), and are executed in the same order in which they appear in a program.

A compound statement is a group of statements (each of them terminated by its own semicolon),
but all grouped together in a block, enclosed in curly braces: {}:
{ statement1; statement2; statement3; }

Many of the flow control statements explained in this section require a generic (sub)statement as part of 
its syntax. This statement may either be a simple C++ statement, -such as a single instruction, terminated 
with a semicolon (;) - or a compound statement.

1- Selection statements: if and else:
	if (condition) simple_statement1; or {compound_statement1} 
	else if simple_statement2; or {compound_statement2} 
	else simple_statement3; or {compound_statement3} 
2- Iteration statements (loops):
	a) while (condition) statement; or {compound_statement}
	b) do statement; or {compound_statement} while (condition);
	c) for (initialization; condition; increase) statement; or {compound_statement}
	Example:	for (;;) {cout << "This will run forever";}
	d) for ( declaration : range ) statement; or {compound_statement}
The (break;) statement leaves a loop, even if the condition for its end is not fulfilled.
The (continue;) statement causes the program to skip the rest of the loop statements in
the current iteration and to jump to the start of the following iteration.
The (goto label;) statement: no particular use cases in modern C++. Shown in the reference.
3- switch (identifier){
  case constant1:
     group-of-statements-1;
     break;
  case constant2: case constant3:	//when constants 2 & 3 have the same statements.
     group-of-statements-2;
     break;
  default:
     default-group-of-statements
}


*/

#include <iostream>
#include <iomanip>      // std::setprecision
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int main() {
	int num{ };
	const int min{ 0 };
	const int max{ 100 };
	long double pre = 25253.14159;

	cout << "The 4 round for 25253.14159 is" << " is " << setprecision(4) << pre << endl;

	enum Foo { a, b, c = 10, d, e = 1, f, g = f + c };
	//a = 0, b = 1, c = 10, d = 11, e = 1, f = 2, g = 12
	cout <<"a: "<< a <<"\tb: "<< b <<"\tc:"<< c <<"\td:"<< d <<"\te:"<< e <<"\tf:"<< f <<"\tg:"<< g << endl;

	cout << "\n======================= if - statement =======================" << endl;
	cout << "Enter your score on the exam between " << min << " and " << max << endl;
	cin >> num;
	char num_check[]{ num };
	if (num <= max && num >= min && isdigit(num_check[0])) {
		if (num > 90) {
			if (num == max) {
				cout << "Your grade is 100!" << endl;
			}
			cout << "Your grade is A\nCongrats!\n";
		}

		else if (num < 90 && num > 75) cout << "Your grade is B\nWell done!\n";

		else if (num < 75 && num > 50) cout << "Your grade is C\nYou passed the course.\n";

		else if (num < 50 && num > 0) cout << "Your grade is F\nYou failed the course.\n";

	}

	else if (!isdigit(num_check[0])) {cout << "Out of range" << endl;}

	cout << "======================= switch - statement =======================" << endl;
	char letter_grade;

	cout << "Enter the letter grade you expect on the exam:\n";
	cin >> letter_grade;

	switch (letter_grade)
	{
	case 'A':
	case 'a':
		cout << "You need a 90 or above, study hard";
		break;

	case 'B':
	case 'b':
		cout << "You need between 75 and 90, study hard";
		break;

	case 'C':
	case 'c':
		cout << "You need between 50 and 75, study hard";
		break;

	case 'F':
	case 'f': {
		char confirm;
		cout << "Atr you sure? Y/N: ";
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y') { cout << "Ok, I guess you didn't study"; }
		else if (confirm == 'n' || confirm == 'N') { cout << "Ok, go study"; }
		else { cout << "Invalid choice!"; }
		break;
	}

	default:
		cout << "Sorry, not a valid grade";
	}

	cout << "\n======================= ? - conditional operator =======================" << endl;
	cout << "number 5 is " << ((5 % 2 == 0) ? "even" : "odd") << endl;

	int num1{}, num2{};
	cout << "Enter two inteeger numbers seperated by a space:\n";
	cin >> num1 >> num2;

	if (num1 < num2);	//  With this condition true, nothing is done with its if-statement.
	if (num1 != num2) {
		cout << "The large number is " << ((num1 > num2) ? num1 : num2) << endl;
		cout << "The small number is " << ((num1 < num2) ? num1 : num2) << endl;
	}
	else { cout << "The numbers are the same!" << endl; }

	cout << "======================= for - loop =======================" << endl;
	int list[]{ 1,2,3,4,5,6,7,8,9,10 };
	for (int x{ 0 }, y{ 30 }; x < 11 && y != 0; ++x, y -= 3) {
		if (x == 5) continue;
		cout << "Element " << list[x] << " * " << y << ":  " << list[x] * y << endl;
	}

	cout << "======================= range-based for - loop =======================" << endl;
	char letters[]{ 'a','b','c','d','e','f' };
	for (auto i : letters) { cout << i << endl; }
	// or: for (char letter : letters) { cout << letter << endl; }

	float samples[]{ 5.43 , 4.57, 59.25, 263.485 };
	float sum = 0;
	for (auto sample : samples) sum += sample;
	cout << "The sum of the array elements is " << sum << endl;
	cout << "The average of the array elements is " << sum / 4 << endl;
	int number_of_s = 0;
	string test{ "This string is used with for loop." };
	for (auto letter : test) {
		if (letter == ' ') cout << "\t";
		if (letter == 's') { number_of_s++; cout << letter; }
		else cout << letter;
	}
	cout << "\nIn the string\n" << test << "\n, we have " << number_of_s << " s letters.";

	vector <string> names{ "Mohamed", "Ahmed", "Osama", "Ali", "Ibrahim" };
	for (auto name : names) {
		if (name == "Ali") break;
		cout << name << "\t";
	}
	cout << "Do you want to a new name? Y | N \n";
	char answer;
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		string new_name;
		cout << "Enter here:\n";
		cin >> new_name;
		names.push_back(new_name);
		cout << "The added new name is: " << new_name;
	}
	else cout << "Ok, See you soon.";

	cout << "\n======================= while - loop =======================" << endl;
	int num_count{ 0 };

	int t{ 0 };
	bool done(false);
	while (!done)
	{
	cout << "Enter an even integer and less than 50 you want to count up to:\n";
	cin >> num_count;
	if (num_count % 2 == 0 && num_count < 50) {
		while (t < num_count) {
			cout << t << endl;
			t++;
			if (t == num_count) done = true;
		}
	}
	else {
		cout << "Try again please!\n";
		
	}
	}


	done = false ;
	while (!done)
	{
		cout << "Rate your experience between 1 and 5\n";
		int exp_rate;
		cin >> exp_rate;
		if (exp_rate < 1 || exp_rate > 5)
			cout << "Please try again." << endl;
		else {
			cout << "Thank you!\n";
			done = true;
		}
	}

	cout << "\n======================= do while - loop =======================" << endl;
	vector <string> list_names;
	int num_insterted;
	do {
		cout << "Enter 1 to add a new name to the names list:\n";
		cin >> num_insterted;
		if (num_insterted == 1) {
			cout << "Enter the name here:\n";
			string named;
			cin >> named;
			list_names.push_back(named);
		}
		else {
			cout << "Ok, thanks!\n";
			num_insterted = 0;
		}
	} while (num_insterted == 1);

	cout << "\n======================= Nested Loops =======================" << endl;
	// Example of a 2D-vector:
	vector <vector <int>> matrix{
		{11,12,13,14},
		{22,23,24,25,26,27},
		{33,34,35,36,37,38,39,40}
	};
	cout << "The vector matrix is of size: " << matrix.size() << endl;
	for (vector <int> mat1 : matrix) {
		for (int mat2 : mat1) {
			cout << mat2 << "\t";
		}
		cout << "\n";
	}

	return 0;
}

//enum