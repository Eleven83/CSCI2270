#include <iostream>
using namespace std;

#include "date.h"

int main()
{
	Date d;
	cout<<d.getMonth()<<d.getDay()<<endl;
	Date d2("June", 4);
	cout<<d2.getMonth()<<d2.getDay()<<endl;

	int x=5;
	d.foo(x);

	float y=5.5;
	d.foo(y);

	return 0;
}