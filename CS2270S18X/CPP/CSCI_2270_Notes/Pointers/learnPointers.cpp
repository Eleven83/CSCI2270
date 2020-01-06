/*
C++ pointers are easy and fun to learn.
Some C++ tasks are performed more easily with pointers, and other C++ tasks,
such as dynamic memory allocation, cannot be performed without them.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //Every variable is a memory location and every memory location has its
    //address defined which can be accessed using ampersand (&) operator
    //which denotes an address in memory.

    int var1; //integer variable
    char var2[10]; //char array of size 10

    cout<<"Address of var1 variable: "<<&var1<<endl; //'&' gives the address in memory rather than the value stored inside
    cout<<"Address of var2 array: "<<&var2<<endl; //address of the array

    return 0;
}

/*
//A pointer is a variable whose value is the address of another variable.
//In other words, a pointer stores an address. That address points to a variable.
//This is how you declare a pointer:
    //type *var-name;
    int    *ip;    // pointer to an integer
    double *dp;    // pointer to a double
    float  *fp;    // pointer to a float
    char   *ch     // pointer to character
*/
/*
int main()
{
    int var=20; //actual variable declaration
    int *ip;    //pointer variable
    ip=&var;     //store the address of var in the pointer

    cout<<"Value of var variable: "<<var<<endl;

    //print the address stored in ip pointer variable
    cout<<"The address stored in the ip variable: "<<ip<<endl;
    //access the value at the address available in the pointer
    cout<<"The value of the *ip variable: "<<*ip<<endl;

    return 0;
}
*/
//RESOURCE:https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm
