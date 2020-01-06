/*
Recitation 1
#6b
    •Showing how the function call in main() passes the address of the variable
     rather than the variable itself. That means that the value of 'a' in main()
     is able to be changed now.
*/
#include <iostream>

using namespace std;

void add2(int* num) //function parameter is a pointer
{
    *num=*num+2;
}

int main()
{
    int a=10;
    add2(&a); //passing the address of 'a' to the add2() funtion
    cout<<a; //returns 12

    return 0;
}
