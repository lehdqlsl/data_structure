#include <iostream>
#include "stack.h"
#include "List.h"

using namespace std;

int main(void){

	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	cout << "s1 size : " << s1.size() << endl;
	cout << "s1 peek : " << s1.Peek() << endl;
	while (!s1.isEmpty()){
		cout << "s1 pop : " << s1.Pop() << endl;
	}

	cout << "s1 pop : " << s1.Pop() << endl;
	cout << "s1 peek : " << s1.Peek() << endl;

	return 0;
}