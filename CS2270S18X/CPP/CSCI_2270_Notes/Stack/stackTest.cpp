#include <iostream>
using namespace std;

#include "stack.h"

int main()
{
	Stack s;
	Node *temp;
	s.push("I");
	s.push("caught");
	s.push("you");
	
	cout<<s.isEmpty()<<endl;

	return 0;
}
