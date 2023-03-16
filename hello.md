Topic 1:
https://cplusplus.com/doc/tutorial/introduction/
https://cplusplus.com/doc/tutorial/program_structure/
*/

/*
What is a compiler?
Computers understand only one language and that language consists of sets of instructions made
of ones and zeros (called machine language). Because a computer can only understand machine language
and humans wish to write in high level languages, high level languages have to be re-written (translated)
into machine language at some point. This is done by special programs called compilers, interpreters, or
assemblers that are built into the various programming applications.
// my first program in C++
#include <iostream>
int main()
{
  std::cout << "Hello World!";
}
Note:
1- Lines beginning with a hash sign (#) are directives read and interpreted by what is known as the preprocessor.
They are special lines interpreted before the compilation of the program itself begins.
The directive #include <iostream>, instructs the preprocessor to include a section of 
standard C++ code, known as header iostream, that allows to perform standard input and output operations,
such as writing the output of this program (Hello World!) to the screen.
2- Blank lines have no effect on a program. They simply improve readability of the code.
3- All functions use braces { & } to indicate the beginning and end of their definitions.
(std::cout) identifies the (standard character output) device (usually, this is the computer screen). 
The insertion operator (<<) indicates that what follows is inserted into std::cout.
To terminate a statement you must use a semicolon (;).
4- comments:
// for one line &
/ followed by * COMMENTS * followed by / for multiple lines
5- Only one main function must exist in a C++ program.
The C++ main function must return 0 when the program terminates successfully.
Other functions can return anything that we want.
Without arguments from the user:
int main(){
	//code
	return 0;
}
With arguments from the user:
int main(int argc, char *argv[]){
	//code
	return 0;
}
Note:
To reduce using std we define the namespace before int main() function as following:
using namespace std;
or
using std::cin;
using std::cout;
using std::endl;
Error is an illegal operation performed by the user which results in abnormal working of the program.
The error can be detected by debugging or by compiling the source file.
It's better to check using both of them.
You might forget ; at the end of each command.
You might forget one of the :: or "".
You might misspell #include or use // insted of #.
{Syntax errors, Run-time Errors, Linker Errors, Logical Errors, Semantic errors}
