#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;

int main()
{
	Stack<int> s;
	s.push(4);
	s.push(20);
	s.push(34);
	s.push(13);
	cout << s.empty();
	cout << endl << s.size();
	cout << endl << s.top();
	s.pop();
	cout << endl << s.top();

	Stack<string> q;
	q.push("Hello");
	q.push("World");
	q.push("Hiya");
	q.push(":)");
	cout << endl << q.empty();
	cout << endl << q.size();
	cout << endl << q.top();
	q.pop();
	cout << endl << q.top() << endl;

	//To test an empty stack
	Stack<int> m;
	cout << m.empty() <<endl;

	try{
		m.pop();
	}
	catch(const exception& e){
		cerr << e.what() << endl;
	}

	try{
		cout << m.top();
	}
	catch(const exception& e){
		cerr << e.what() << endl;
	}

	

}