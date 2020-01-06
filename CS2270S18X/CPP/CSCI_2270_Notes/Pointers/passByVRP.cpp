#include <iostream>
using namespace std;

void passByVal( int a );
void passByRef( int &a );
void passByPtr( int *a );
void passByArray( int a[], int n);

int main()
{
	int billy = 2, jimmy = 2, jenny = 2;
	//int *jennyPtr = &jenny;

	cout << "BEFORE FUNCTION CALLS: billy:" << billy << " jimmy: " << jimmy << " jenny: " << jenny << endl;

	passByVal( billy );
	passByRef( jimmy );
	passByPtr( &jenny );

	cout << "AFTER FUNCTION CALLS: billy: " << billy << " jimmy: " << jimmy <<  " jenny: " << jenny << endl;

	int n = 10;
	int arr[n];
	passByArray( arr, n );


	// Iterate through array and display (A)
	for( int i = 0; i < n; i++)
		cout << arr[i] << endl;

	int *ptr;

	ptr = arr;

	// Using pointer arithmetic, result same as (A)
	for( int i = 0; i < n; i++)
		cout << *(arr + i) << endl;

	// arr = ptr; // ILLEGAL
	
	return 0;
}

void passByVal( int a ){
	++a;
}

void passByRef( int &a ){
	++a;
}

void passByPtr( int *a ){
	*a = *a + 1;
}

void passByArray( int a[], int n){
	for( int i = 0; i < n; i++)
		a[i] = -i;
}