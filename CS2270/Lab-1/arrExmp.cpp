/*
Recitation 1
#6c
    •Showing how the function parameter is an array which is considered a pointer
*/
#include <iostream>

using namespace std;

void add2(int a[], int len) //takes an array and the size of the array
{
    for(int i=0; i<len; i++) //assigns values to the array
    {
        a[i]+=2;
    }
}

int main()
{
    int a[]={1,2,3}; //create an array
    add2(a, 3); //calls the add2() function and passes the array and the size
                //an array gets treated like an address to a pointer.
    for(int i=0; i<3; i++)
        cout<<a[i]<<endl; //outputs 3 4 5

    return 0;
}
