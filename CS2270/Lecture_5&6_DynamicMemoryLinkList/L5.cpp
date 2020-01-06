#include <iostream>

using namespace std;

void passByValue(int a)
{
    a++;
}
void passByPointer(int *ptr)
{
    cout<<"Address stored in pointer: "<<ptr<<endl;
    *ptr=*ptr+1;
    (*ptr)++;
}
voidpassByReference(int &a)
{
    a++;
}
void passByArray(int *a) //could also define using passByArray(int a[])
{
    a[0]=10;
    a[1]=11;
}

int main(int argc, char const *argv[]) {
    int a=5; //regular variable
    cout<<&a<<endl;
    //(*argv+1) equivalent to argv[1];

    //pointer and address it points to have to be the same type
    int *b=&a; //b is a pointer it stores the address of a
    //* has two meanings
    //use it to declare a pointer
    //use it to dereference a pointer
    //dereference- go to address stored in pointer and get the value at that address

    cout<<&b<<", "<<b<<", "<<b<<endl;
    int c=20;
    b=&c; //change the address stored in b to address of c
    cout<<*b<<endl; //prints 20

    int arrayA[5];
    cout<<arrayA<<endl; //name of array gives us address of first element in array

    //functions
    passByValue(a);
    cout<<a<<endl; //prints 10, a remains unchanged
    cout<<"address stored in b: "<<b<<endl;

    passByPointer(b); //updates the value at the address stored in b
    cout<<*b<<endl;

    //a=10 here
    passByReference(a); //a is a regular variable, not a pointer
    //passByPointer(&a);
    cout<<"Check: "<<endl;
    cout<<a<<endl;
    for(int i=0; i<5; i++)
    {
        arrayA[i]=0;
    }
    passByArray(arrayA); //pass array
    for(int i=0; i<5; i++)
    {
        cout<<arrayA[i]<<endl;
    }
    //Stack-finite amount of memory used to control program execution
    //local variable stored here
    //fast
    //memory management done for you
    //relatively small
    //int a[stoi(argv[1])]
    //cin
    //allocating large amounts of memory during execution can crash stack

    //heap-large pool of memory, much larger than the stack
    //large data structures that we want to allocate during run time
    //dynamic memory allocation needed

    //dynamically allocate an array
    //new used to allocate memory on the heap
    //have to use a pointer to access heap memory
    //y is pointer to array of 10 ints
    int *y=new int[10];
    double *x=new double[20]; //array of 20 doubles
    //for every new, there needs to be a delete
    delete [] y; //frees the memory allocated to y
    delete [] x; //frees thememory allocated to x

    int *x2=new int;
    *x2=5;
    y=x2; //y now points to same address as x2
    cout<<*y<<endl;
    //x=x2; does this work? No-doesn't work.
    //programs can slow down
    int *x3=new int[100]; //x3 points to array of 100 ints
    x3[0]=100;
    x3[10]=200;
    x3=x2;
    //how do I get data out of x3?
    //I can't get back to x3 because it now points to the same address as x2
    //array of 100 ints in memory that can't be accessed
    //memory leak

    return 0;
}
