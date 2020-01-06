#include <iostream>
using namespace std;

#include "date.h"

Date::Date(string monthVal , int dayVal) //Overloading the constructor
{
	if (dayVal>0 && dayVal<32)
		day=dayVal;
	else
		cout<<"invalid day range "<<endl;

	month=monthVal;

}

Date::Date()
{
	day=1;
	month="January";
}

string Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

void Date::foo( int a )
{
	cout << "store " << a << " as int" << endl;
}

void Date::foo( float a )
{
	cout << "store " << a << " as float" << endl;
}
