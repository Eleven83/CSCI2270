#include <iostream>

using namespace std;


int main()
{
	int n = 3;
	int *a;

	// allocate memory for a dynamic array that is n long
	a = new int[n];

	cout << "Enter 3 ints " << endl;

	// fill the array with user input
	for( int i = 0; i < n ; i++ )
		cin >> a[i];

	int *temp;

	// allocate memory for a dynamic array that is 2n long
	temp = new int[2*n];

	// copy the contents of array pointed to by a into first
	// n elements of array pointed to by temp
	for( int i = 0; i < n ; i++ )
		temp[i] = a[i];

	delete [] a; // return memory to heap

	a = temp; // assign a to point to temp

	// delete [] temp; // DON'T DO THIS here. We don't actually want to free that memory space back to heap.
	temp = nullptr;    // To be safe, we can set temp to null so we don't accidentally do something with it later.

	// We can now ask the user to enter 3 more values into our dynamically allocated array
	cout << "Enter 3 more ints: " << endl;

	for( int i = n; i < 2*n; i++ )
		cin >> a[i];

	// Print the contents of the whole thing
	cout << "\n\n";
	for( int i = 0; i < 2*n; i++ )
		cout << a[i] << endl;

	// Now that we are finished using a, release the memory it's pointing to back into the heap
	delete [] a;

	// To be safe, don't point to a memory space that has now been de-allocated
	a = nullptr;

	return 0;
}
