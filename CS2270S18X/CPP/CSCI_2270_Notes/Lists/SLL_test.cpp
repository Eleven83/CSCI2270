#include <iostream>
#include "SLL.h"

using namespace std;

int main()
{
	SLL l;
	string arr[] = {"jeden","dwa","trzy"};
	int arrLen = 3;
	for(int i=0; i<arrLen; i++)
		l.growList(arr[i]);
	l.displayList();

	return 0;
}
