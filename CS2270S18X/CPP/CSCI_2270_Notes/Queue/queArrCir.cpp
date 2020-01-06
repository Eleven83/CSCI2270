#include <iostream>
using namespace std;

#include "queArrCir.h"

QueArrCir::QueArrCir()
{
	head = 0;
	tail = 0;
	queSize = 0;
}

bool QueArrCir::isEmpty()
{
	if( queSize == 0 )
		return true;
	else
		return false;
}
bool QueArrCir::isFull()
{
	if( queSize == MAXSIZE )
		return true;
	else
		return false;
}
void QueArrCir::enque( string newItem )
{
	// note when enqueing we are only dealing with the tail
	//check to see if que isn't full
	if( !isFull() )
	{
		a[tail] = newItem;
		queSize++;
		if( tail == MAXSIZE - 1)
			tail = 0;
		else
			tail++;
	}
	else
	{
		cout << "queue is full" << endl;
	}
}
string QueArrCir::deque()
{
	string output;
	// when dequeing we are only dealing with the head
	if( !isEmpty() )
	{
		output = a[head];
 		queSize--;
		if( head == MAXSIZE - 1)
			head = 0;
		else
			head++;
	}
	else
	{
		cout << "que empty. Returning empty string." << endl;
		output = "";
	}

	return output;
}
void QueArrCir::disp()
{
	cout << "head " << head << endl;
	cout << "tail " << tail << endl;

	for( int i = 0; i < queSize; i++ )
	{
		cout << a[i] << " ";
	}
	cout << endl;

}
