// Topic: https://cplusplus.com/reference/thread/

/*
Multithreading is a feature that allows concurrent execution of two or more parts of a program for
maximum utilization of the CPU. Each part of such a program is called a thread.
So, threads are lightweight processes within a process.

The thread classes and related functions are defined in the <thread> header file.
Syntax:
std::thread thread_object (callable);
Where:
1- "std::thread" is the thread class that represents a single thread in C++.
To start a thread, we simply need to create a new thread object and pass the executing code to be
called (i.e, a callable object) into the constructor of the object.
Once the object is created, a new thread is launched which will execute the code specified in callable.

2- A "callable" can be either of the three:

2.1) Function Pointer:
With syntax:

void foo(params)
{
  Statements;
}
// The parameters to the function are put after the comma
std::thread thread_obj(foo, params);

2.2) Function Object:
With syntax:

// Define the class of function object
class fn_object_class {
	// Overload () operator
	void operator()(params)
	{
	  Statements;
	}
}

// Create thread object
std::thread thread_object(fn_object_class(), params)

2.3) Lambda Expression (later)

After defining the callable, we pass it to the constructor.
Note: We always pass parameters of the callable separately as arguments to the thread constructor.
*/

#include <iostream>
#include <thread>

using namespace std;

static bool s_finished = false;

std::thread::id main_thread_id = std::this_thread::get_id();

/*
Values of the type (thread id) are returned by "thread::get_id()" and "this_thread::get_id()" to identify threads.
*/

void is_main_thread() {
	if (main_thread_id == std::this_thread::get_id())
		std::cout << "This is the main thread.\n";
	else
		std::cout << "This is not the main thread.\n";
}

void out_func1(int number) {

	cout << "Execution starts on the out thread 1 of ID: " << this_thread::get_id() << endl;
	
	while (!s_finished) {

		cout << number << " : while-loop, out thread 1 of ID: " << this_thread::get_id() << endl;
		this_thread::sleep_for(1.3s);
		is_main_thread();
	}
	for (int i = 0; i < 4; ++i) {

		cout << "for-loop, out thread 1 of ID: " << this_thread::get_id() << endl;
		this_thread::sleep_for(1s);

	}
}

void out_func2(string number) {

	cout << "Execution on the out thread 2 of ID: " << this_thread::get_id() << endl;

	while (!s_finished) {

		cout << number << " : while-loop, out thread 2 of ID: " << this_thread::get_id() << endl;
		this_thread::sleep_for(1.3s);
		is_main_thread();
	}
	for (int i = 0; i < 4; ++i) {

		cout << "for-loop, out thread 2 of ID: " << this_thread::get_id() << endl;
		this_thread::sleep_for(1s);

	}
}

void out_func3() {

	cout << "Execution on the out thread 3 of ID: " << this_thread::get_id() << endl;

	for (int i = 0; i < 7; ++i) {

		cout << "for-loop, out thread 3 of ID: " << this_thread::get_id() << endl;
		this_thread::sleep_for(1s);

	}
}

class thread_obj {
public:
	void operator()(int x)
	{
		for (int i = 0; i < x; i++)
		{
			is_main_thread();
			cout << "Thread using function object as callable, ID: " << this_thread::get_id() << endl;
		}
	}
};

int main() {

	cout << "Execution starts on the main thread of ID: " << this_thread::get_id() << endl;
	thread out_thread1(out_func1, 1);
	thread out_thread2(out_func2, "Two");
	cin.get();
	s_finished = true;
	out_thread1.join();
	out_thread2.join();
	
	thread out_thread3(out_func3);
	thread out_thread4(thread_obj(), 3);

	cout << "In Main thread: out thread ID is: " << out_thread1.get_id() << endl;
	for (int i = 0; i<4; ++i){

		cout << "main thread of ID: " << this_thread::get_id() << endl;
		this_thread::sleep_for(0.8s);
		is_main_thread();
	}

	cin.get();
	s_finished = true;
	for (int i = 0; i < 4; ++i) {

		cout << "main thread of ID: " << this_thread::get_id() << endl;
		this_thread::sleep_for(0.8s);

	}
	cout << "The main thread waites for the out threads to finish executing.\n";
	out_thread3.join();
	out_thread4.join();
	
	/*
	void join();
	This function returns when the thread execution has completed.
	This blocks the execution of the thread that calls this function until
	the function called on construction returns (if it hasn't yet).
	*/

	cout << "main thread alone continues\n";
	cout << "main thread of ID: " << this_thread::get_id() << endl;

	cin.get();
	return 0;
}
